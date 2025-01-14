enum
{
	PROMO_TYPE_MONEY = 0, 	// ������
	PROMO_TYPE_DONATE,		// �����
	PROMO_TYPE_EXP,			// ����
}

enum E_PROMO_STRUCT
{
	E_PLAYER_STRUCT: P_DATA,
	P_SQL_NAME[16],
	P_NAME[7]
}

new promo_info[3][E_PROMO_STRUCT] =
{
	{P_MONEY, "money", "������"},
	{P_DONATE_CURRENT, "donate_current", "�����"},
	{P_EXP, "exp", "Exp"}
};
enum DIALOGIDa {
    DIALOG_PROMO_CREATE = 4917,			// �������� ���������
	DIALOG_PROMO_ACTIVATE = 4918			// ��������� ���������
}
// � public OnDialogResponse()
stock PR_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(DIALOGIDa) {
        case DIALOG_PROMO_CREATE:
        {
            if(response)
            {
                new code[32], type, amount, usings, paydays;

                if(sscanf(inputtext, "P<,>s[32]dddd", code, type, amount, usings, paydays))
                {
                    SCM(playerid, 0x999999FF, "������������ ����");
                    callcmd::createpromo(playerid, "");

                    return 1;
                }
                else
                {
                    if(!(0 <= type <= 2))
                    {
                        SCM(playerid, 0x999999FF, "��� ������ ���� �� 0 �� 2 (������, �����, exp)");
                        callcmd::createpromo(playerid, "");

                        return 1;
                    }

                    if(!(1 <= amount <= 1_000_000))
                    {
                        SCM(playerid, 0x999999FF, "���������� ������ ���� �� 1 �� 1.000.000");
                        callcmd::createpromo(playerid, "");

                        return 1;
                    }

                    if(!(1 <= usings <= 1_000))
                    {
                        SCM(playerid, 0x999999FF, "���������� ������������� ������ ���� �� 1 �� 1000");
                        callcmd::createpromo(playerid, "");

                        return 1;
                    }

                    if(!(0 <= paydays <= 20))
                    {
                        SCM(playerid, 0x999999FF, "���������� PayDay ������ ���� �� 0 �� 20");
                        callcmd::createpromo(playerid, "");

                        return 1;
                    }

                    new query[128],
                        Cache: result,
                        rows;

                    mysql_format(mysql, query, sizeof query, "SELECT * FROM promocode WHERE code='%s' LIMIT 1;", code);
                    result = mysql_query(mysql, query, true);

                    rows = cache_num_rows();

                    safecache_delete(result);

                    if(rows)
                    {
                        SCM(playerid, 0x999999FF, "����� �������� ��� ���� � ���� ������");
                        callcmd::createpromo(playerid, "");

                        return 1;
                    }

                    mysql_format(mysql, query, sizeof query, "INSERT INTO promocode (code, type, amount, usings, paydays) VALUES ('%s', %d, %d, %d, %d)",
                    code, type, amount, usings, paydays);

                    mysql_query(mysql, query);

                    format(query, sizeof query, "�������� \"%s\" ������ (�: %s, �: %d, �: %d, PD: %d)", code, promo_info[type][P_NAME], amount, usings, paydays);
                    SCM(playerid, 0x66CC33FF, query);
                }
            }
        }
        case DIALOG_PROMO_ACTIVATE:
        {
            if(response)
            {
                if(!strlen(inputtext))
                {
                    callcmd::pcode(playerid, "");

                    return 1;
                }

                new query[256],
                    Cache: result,
                    rows,
                    type,
                    amount,
                    paydays,
                    usings;

                mysql_format(mysql, query, sizeof query, "SELECT * FROM promocode_activations WHERE uid='%d' AND code='%s' LIMIT 1;", GetPlayerAccountID(playerid), inputtext);
                result = mysql_query(mysql, query, true);

                rows = cache_num_rows();

                if(rows)
                {
                    cache_get_int(0, "paydays",paydays);
                    format(query, sizeof query, "�� ��� ������������ ���� ��������");
                    if(paydays) format(query, sizeof query, "%s. �� �������� ���� ���� ����� %d PayDay", query, paydays);
                    SCM(playerid, 0x3399FFFF, query);
                    safecache_delete(result);
                    return 1;
                }

                safecache_delete(result);

                mysql_format(mysql, query, sizeof query, "SELECT * FROM promocode WHERE code='%s' AND usings > 0", inputtext);
                result = mysql_query(mysql, query, true);

                rows = cache_num_rows();

                if(rows)
                {
                    cache_get_int(0, "type",type);
                    cache_get_int(0, "amount",amount);
                    cache_get_int(0, "usings",usings);
                    cache_get_int(0, "paydays",paydays);
                }

                safecache_delete(result);

                if(!rows)
                {
                    SCM(playerid, 0x999999FF, "��������� �������� �� ����������");
                    callcmd::pcode(playerid, "");

                    return 1;
                }

                if(usings > 0)
                {
                    if(!paydays)
                    {
                        AddPlayerData(playerid, promo_info[type][P_DATA], +, amount);
                        SavePlayerDataInt(playerid, promo_info[type][P_SQL_NAME], GetPlayerData(playerid, promo_info[type][P_DATA]));
                    }

                    format(query, sizeof query, "�� ������������ �������� \"%s\"", inputtext);

                    if(paydays > 0)
                        format(query, sizeof query, "%s. �� �������� ���� ���� ����� %d PayDay", query, paydays);

                    SCM(playerid, 0x66CC33FF, query);
                    mysql_pqueryf(mysql, "UPDATE promocode SET usings='%d' WHERE code='%s' LIMIT 1;", usings - 1, inputtext);
                    mysql_tqueryf(mysql, "INSERT INTO promocode_activations (uid, code, paydays) VALUES (%d, '%s', %d)",\
                    GetPlayerAccountID(playerid), inputtext, paydays);
                }
                else
                {
                    SCM(playerid, 0x999999FF, "����� ������������� ��������� ��������");
                    callcmd::pcode(playerid, "");
                }
            }
        }
    }
    return 1;
}

// � public OnPayDay()
stock PromoPayDay(playerid)
{
    new rows, 
        fmt_str[144],
        Cache: result;

    mysql_format(mysql, fmt_str, sizeof fmt_str, "SELECT id, paydays, code FROM promocode_activations WHERE uid=%d AND paydays > 0", GetPlayerAccountID(playerid));
    result = mysql_query(mysql, fmt_str, true);

    rows = cache_num_rows();

    if(rows)
    {
        for(new idx; idx < rows; idx ++)
        {
            new id,
                paydays,
                code[32];
            cache_get_int(idx, "id", id);
            cache_get_int(idx, "paydays", paydays);
            cache_get_string(idx, "code", code);

            mysql_format(mysql, fmt_str, sizeof fmt_str, "UPDATE promocode_activations SET paydays='%d' WHERE id='%d'", paydays - 1, id);
            mysql_query(mysql, fmt_str, false);

            if(paydays == 1)
            {
                new Cache: p_cache;

                mysql_format(mysql, fmt_str, sizeof fmt_str, "SELECT type, amount FROM promocode WHERE code='%s' LIMIT 1;", code);
                p_cache = mysql_query(mysql, fmt_str, true);

                new type,
                    amount;
                cache_get_int(0, "type", type);
                cache_get_int(0, "amount", amount);
                safecache_delete(p_cache);

                AddPlayerData(playerid, promo_info[type][P_DATA], +, amount);
                SavePlayerDataInt(playerid, promo_info[type][P_SQL_NAME], GetPlayerData(playerid, promo_info[type][P_DATA]));

                SCM(playerid, -1, !"");

                format(fmt_str, sizeof fmt_str, "������� ���� �� �������� \"%s\"", code);
                SCM(playerid, 0x66CC33FF, fmt_str);
            }
        }
    }
    return 1;
}
CMD:createpromo(playerid, params[])
{
	if(GetPlayerAdminEx(playerid) < 7) return 1;

	Dialog
	(
		playerid, DIALOG_PROMO_CREATE, DIALOG_STYLE_INPUT,
		"{FFCD00}�������� ���������",
		"{FFFFFF}��� �������� ��������� �������\n"\
		"��������� ��������� � ���� ����:\n\n"\
		"{33CC66}���������: ���, ���, ���-��, �������������, PayDay\n\n"\
		"{888888}����������:\n"\
		"{FFFFFF}- ��� ����� ��������� �� 1 �� 30 ��������\n"\
		"- ��� �� 0 �� 2 (������, �����, exp)\n"\
		"- ���������� �� 1 �� 1.000.000\n"\
		"- ���������� ������������� �� 1 �� 1000\n"\
		"- ���������� PayDay �� 0 �� 20",
		"�����", "������"
	);

	return 1;
}
CMD:pcode(playerid, params[])
{
    if(GetPlayerAdminEx(playerid) < 0) return 1;

	Dialog
	(
		playerid, DIALOG_PROMO_ACTIVATE, DIALOG_STYLE_INPUT,
		"{FFCD00}��������� ���������",
		"{FFFFFF}������� �������� � ���� ����:",
		"�����", "������"
	);

	return 1;
}