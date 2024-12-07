// == == == == [ Диалоги ] == == == ==
#define Dialog 									ShowDialog
#define SPD 									ShowDialog
#define SCM 									SendClientMessage
#define SCMTA 									SendClientMessageToAll
#define DSL 									DIALOG_STYLE_LIST
#define DSI 									DIALOG_STYLE_INPUT
#define DSM 									DIALOG_STYLE_MSGBOX
#define DSP 									DIALOG_STYLE_PASSWORD
// == == == ==[ Макросы ]== == == ==
#define GetPlayerData(%0,%1)					pInfo[%0][%1]
#define SetPlayerData(%0,%1,%2)					pInfo[%0][%1]=%2
#define AddPlayerData(%0,%1,%2,%3) 				pInfo[%0][%1] %2= %3

#define GetPlayerStateLogged(%0)				pInfo[%0][P_STATE]
#define IsPlayerLogged(%0)						pInfo[%0][pLogged]
#define GetPlayerNameEx(%0)						pInfo[%0][P_NAME]
#define GetPlayerAccountID(%0)					pInfo[%0][P_ID]
#define GetPlayerAdminEx(%0)					pInfo[%0][P_ADMIN]
#define GetPlayerMoneyEx(%0)					pInfo[%0][P_MONEY]
#define IsPlayerMoney(%0,%1)					GetILPlayerInt(%0,%1)

#define scmf(%0,%1,%2,%3) 						format(str_1, sizeof(str_1),%2,%3) && SCM(%0, %1, str_1)
#define foreach_player(%0)              		foreach(new %0 : Player)
#define f(%0,%1,%2,%3) 							format(%0,%1,%2,%3)
#define PN(%0)  								pInfo[%0][P_NAME]
#define public:%0(%1)  							forward %0(%1); public %0(%1)
#define mysql_queryf(%0,%1,%2,%3) 				str_q[0] = EOS, mysql_format(%0, str_q, sizeof(str_q), %1, %3) && mysql_query(%0, str_q, %2)
#define RandomEx(%1,%2) 						(random(%2-%1)+%1)
#define Kick:(%0) FixKick(%0)
#define strdellast(%0)							strdel(%0, strlen(%0)-1,strlen(%0))
// == == == == [ Admin ] == == == ==
new const NO_DOSTUP_TEXT[]   =       		"{ff9300}[Ошибка]{ffffff} У вас нет доступа к этой команде!";
new const AloginTxt[] =						"{ff9300}[Ошибка]{ffffff} Вы не авторизированы, используйте /alogin";

// == == == == [ Цвета ] == == == ==
#define COLOR_WHITE 							0xFFFFFFFF
#define COLOR_ORANGE                    		0xFAAC58FF
#define COLOR_GREEN                     		0x42B02CFF
#define COLOR_GOLD                      		0xFFD700FF
#define COLOR_RED                       		0xBE2D2DFF
#define COLOR_LIGHTRED                  		0xFF6347FF
#define COLOR_LIGHTBLUE                 		0x6495EDFF
#define COLOR_LIGHTGREEN                		0x9ACD32FF
#define COLOR_YELLOW                    		0xFFFF00FF
#define COLOR_BLUENEW                   		0xB8CEF6FF
#define COLOR_BLUE                      		0x94B0C1FF
#define COLOR_PURPLE                    		0xC2A2DAFF
#define COLOR_LIME                      		0x10F441FF
#define COLOR_GREY                      		0xAFAFAFFF
#define COLOR_CHAT                      		0xCECECEFF
// == == == == [ Форврады ] == == == ==
forward OnSecondTimer();
forward OnMinuteTimer();
forward StopChatAnim(playerid);
forward OnPlayerTimer(playerid);

// == == == == [ Переменные ] == == == ==
new str_1[4096],
	str_2[4096],
	str_q[2512];
stock CheckAdmin(playerid, level=1, CheckAutorizaction=1)
{
	if GetPlayerAdminEx(playerid) < level *then 
	{
		SCM(playerid, -1, NO_DOSTUP_TEXT);
		return 0;	
	}
	else if !pInfo[playerid][pAdmLogin] && CheckAutorizaction *then 
	{
		SCM(playerid, -1, AloginTxt);
		return 0;
	}
	return 1;
}
stock TextFind(const text[], const charect[]) return (strfind(text,charect) != -1);
stock formatInt(number)
{
    static number_text[17];
    format(number_text, sizeof(number_text), "%d", number);

    for(new i = (strlen(number_text) - 3); i > (number < 0 ? 1 : 0); i -= 3)
        strins(number_text[i], "." , 0);

    return number_text;
}
#define MAX_MONEY_SYMBOLS	23

new player_int_count_1[MAX_PLAYERS][MAX_MONEY_SYMBOLS];
new player_int_count_2[MAX_PLAYERS][MAX_MONEY_SYMBOLS];
new player_length_count_1[MAX_PLAYERS];
new player_length_count_2[MAX_PLAYERS];

stock EditCountSInteger(playerid, count_1[], count_2[])
{
	new fmt_text[MAX_MONEY_SYMBOLS];
	if(strlen(count_1) > 0 && strlen(count_1) < 20 && strlen(count_2) < 20)
	{
		new status = 1;

		if(strfind(count_2,"-") != -1) status = 0, strdel(count_2, 0, 1);
		
		SettingsCountSInteger(playerid, count_1, count_2);
		
		if(status == 1)
		{
			if(player_length_count_1[playerid] >= player_length_count_2[playerid])
			{
				for(new i; i < player_length_count_1[playerid]; i++)
				{
					if(player_int_count_1[playerid][i] + player_int_count_2[playerid][i] <= 9)
					{
						player_int_count_1[playerid][i] = player_int_count_1[playerid][i] + player_int_count_2[playerid][i];
					}
					else if(player_int_count_1[playerid][i] + player_int_count_2[playerid][i] > 9)
					{
						player_int_count_1[playerid][i] = (player_int_count_1[playerid][i] + player_int_count_2[playerid][i]) - 10;
						if(player_length_count_1[playerid] == i + 1) player_length_count_1[playerid]++;
						player_int_count_1[playerid][i + 1]++;
					}
				}
			}
			else
			{
				for(new i; i < player_length_count_2[playerid]; i++)
				{
					if(player_int_count_2[playerid][i] + player_int_count_1[playerid][i] <= 9) 
					{
						player_int_count_1[playerid][i] = player_int_count_2[playerid][i] + player_int_count_1[playerid][i];
					}
					else if(player_int_count_2[playerid][i] + player_int_count_1[playerid][i] > 9)
					{
						player_int_count_1[playerid][i] = (player_int_count_2[playerid][i] + player_int_count_1[playerid][i]) - 10;
						if(player_length_count_2[playerid] == i + 1) player_length_count_2[playerid]++;
						player_int_count_1[playerid][i + 1]++;
					}
				}
				player_length_count_1[playerid] = player_length_count_2[playerid];
			}
		}
		else
		{
			new get_count_int = GetCountSInteger(playerid);
			
			if(get_count_int != 0)
			{
				if(get_count_int == 1)
				{
					for(new i; i < player_length_count_1[playerid]; i++)
					{
						if(player_int_count_1[playerid][i] >= player_int_count_2[playerid][i])
						{
							player_int_count_1[playerid][i] = player_int_count_1[playerid][i] - player_int_count_2[playerid][i];
							
							if(player_int_count_1[playerid][i] == 0 && player_length_count_1[playerid] == i) player_length_count_1[playerid]--;
						}
						else if(player_int_count_1[playerid][i] < player_int_count_2[playerid][i])
						{
							player_int_count_1[playerid][i] = (player_int_count_1[playerid][i] + 10) - player_int_count_2[playerid][i];
							player_int_count_1[playerid][i + 1]--;
							if(player_int_count_1[playerid][i + 1] == 0 && player_length_count_1[playerid] == i + 1) player_length_count_1[playerid]--;
						}
					}
					new i = player_length_count_1[playerid];
					while(0 < i)
					{
						i--;
						if(player_int_count_1[playerid][i] == 0) player_length_count_1[playerid]--;
						else break;
					}
				}
				else if(get_count_int == 2)
				{
					player_int_count_1[playerid][0] = 0;
					player_length_count_1[playerid] = 1;
				}
			}
		}

		format(fmt_text, MAX_MONEY_SYMBOLS, "%s", SettingsCountSString(playerid));

		return fmt_text;
	}
	return fmt_text;
}
stock SettingsCountSString(playerid)
{
	new integer_count[MAX_MONEY_SYMBOLS];
	for(new i; i < player_length_count_1[playerid]; i ++)
	{
		new count_id = player_length_count_1[playerid] - 1;
		new query[MAX_MONEY_SYMBOLS];
		format(query, sizeof query, "%d", player_int_count_1[playerid][count_id - i]);
		strcat(integer_count, query);
	}
	return integer_count;
}
stock SettingsCountSInteger(playerid, count_1[], count_2[])
{
	for(new i; i < MAX_MONEY_SYMBOLS; i++)
	{
		player_int_count_1[playerid][i] = 0;
		player_int_count_2[playerid][i] = 0;
	}
	new format_count[MAX_MONEY_SYMBOLS];
	player_length_count_1[playerid] = strlen(count_1);
	for(new i; i < player_length_count_1[playerid]; i ++)
	{
		format(format_count, sizeof format_count, "%s", count_1);

		strdel(format_count, 0, strlen(format_count) - (i + 1));
		strdel(format_count, strlen(format_count) - i, strlen(format_count));
		player_int_count_1[playerid][i] = strval(format_count);
	}
	player_length_count_2[playerid] = strlen(count_2);
	for(new i; i < player_length_count_2[playerid]; i ++)
	{
		format(format_count, sizeof format_count, "%s", count_2);

		strdel(format_count, 0, strlen(format_count) - (i + 1));
		strdel(format_count, strlen(format_count) - i, strlen(format_count));
		player_int_count_2[playerid][i] = strval(format_count);
	}
	return 1;
}

stock GetCountSInteger(playerid)
{
    if(player_length_count_1[playerid] < player_length_count_2[playerid]) return 0;

    new id = player_length_count_1[playerid];
    while(0 < id)
    {
        id--;

        if(player_int_count_1[playerid][id] > player_int_count_2[playerid][id]) return 1; 
        else if(player_int_count_1[playerid][id] < player_int_count_2[playerid][id]) return 0;
    }
    if(id == 0) return 2;
 
    return 1;
}

stock SetILPlayerInt(playerid, const count_1[], count_2)
{
	new query[MAX_MONEY_SYMBOLS];

	format(query, sizeof query, "%d", count_2);
	format(query, sizeof query, "%s", EditCountSInteger(playerid, count_1, query));
	return query;
}
stock SetILPlayerStr(playerid, const count_1[], const count_2[])
{
	new query[MAX_MONEY_SYMBOLS];

	format(query, sizeof query, "%s", EditCountSInteger(playerid, count_1, count_2));
	return query;
}

stock GetILPlayerInt(const count_1[], count_2)
{
	new query[MAX_MONEY_SYMBOLS];
	format(query, sizeof query, "%d", count_2);
	if(IsILStringStatus(count_1, query)) return 1;
	else return 0;
}
stock GetILPlayerStr(const count_1[], const count_2[])
{
	if(IsILStringStatus(count_1, count_2)) return 1;
	else return 0;
}
stock IsILStringStatus(const count_1[], const count_2[])
{
	new format_count[MAX_MONEY_SYMBOLS];
	new int_count_1[MAX_MONEY_SYMBOLS];
	new int_count_2[MAX_MONEY_SYMBOLS];
	new length_count_1 = strlen(count_1);
	new length_count_2 = strlen(count_2);

	if(length_count_1 < length_count_2) return 0;

	for(new i; i < length_count_1; i ++)
	{
		format(format_count, sizeof format_count, "%s", count_1);
		strdel(format_count, 0, strlen(format_count) - (i + 1));
		strdel(format_count, strlen(format_count) - i, strlen(format_count));
		int_count_1[i] = strval(format_count);
	}

	for(new i; i < length_count_2; i ++)
	{
		format(format_count, sizeof format_count, "%s", count_2);
		strdel(format_count, 0, strlen(format_count) - (i + 1));
		strdel(format_count, strlen(format_count) - i, strlen(format_count));
		int_count_2[i] = strval(format_count);
	}
    new id = length_count_1;
    while(0 < id)
    {
        id--;

        if(int_count_1[id] > int_count_2[id]) return 1; 
        else if(int_count_1[id] < int_count_2[id]) return 0;
    }
    if(id == 0) return 1;

	return -1;
}

stock FixKick(playerid) 
{
	SendClientMessage(playerid, 0xff0000FF, "Вы были отключены от сервера!");
	SendClientMessage(playerid, 0xff0000FF, "Введите /q (/quit) чтобы выйти");
	new ping = GetPlayerPing(playerid);
	if ping > 2500 *then ping = 2500;
	else if ping < 300 *then ping = 300;
	SetTimerEx("FixKickTimer",ping, false, "i", playerid);
	return 1;
}
public: FixKickTimer(playerid) return Kick(playerid);

stock IsValidText(const text[]) {
	for(new i; i < strlen(text); i++)
	{
	    switch(text[i])
	    {
	        case 'A'..'Z', 'a'..'z', 'А'..'Я', 'а'..'я', '0'..'9', ' ', '>', '<', '(', ')', '/', '+', '-','_', '?', '!', '.', ',', '@', '*', '`',':',';','#','=':continue;
	        default: return 0;
	    }
	}
	return 1;
}
#if defined _ALS_IsValidNickName
	#undef IsValidNickName
#endif
#define IsValidNickName IsValidNickNamea
stock IsValidNickName(const nickname[])
{
	if(strlen(nickname) < 6 || strlen(nickname) > 24) return 0;
	new namesa[2][24];
	if(sscanf(nickname,"p<_>s[24]s[24]",namesa[0],namesa[1])) return 0;
	for(new i;i<2;i++)
	{
		for(new j,k=strlen(namesa[i]);j<k;j++)
		{
			switch(namesa[i][j]){
				case 'A'..'Z', 'a'..'z': continue;
				default: return 0;	
			}	
		}		
	}
	return 1;
}
static const NumberSimbols[5][7] = {
    {0,1,1,1,0,0,-1},
    {1,1,1,3,3,3,-1},
    {1,1,1,1,-1,-1,-1},
    {0,0,0,0,-1,-1,-1},
    {2,2,2,2,2,2,2}
};
static const RegionSimbols[4][4] = {
    {1,1,1,-1},
    {1,-1,-1,-1},
    {0,0,2,1},
    {1,1,1,1}
};
stock IsValidNumber(const number[],const typenumber)
{
    if(!(1<=typenumber<=5)) return 0;
	if(!(4 <= strlen(number)<= 7)) return 0;
    for(new i, j=strlen(number); i<j;i++)
    {
        switch(NumberSimbols[typenumber-1][i]) 
        {
            case -1: return 1;
            case 0: {
                switch(number[i]) {
                    case 'A','B','E','K','M','X','O','P','C','H','T','Y':continue;
                    default: return 0;
                }
            }
            case 1: {
                switch(number[i]) {
                    case '0'..'9': continue;
                    default: return 0;
                }
            }
			case 2: {
				switch(number[i]) {
					case 'A'..'Z','0'..'9':continue;
                    default: return 0;
                }
			}
            case 3: {
                switch(number[i]) {
					case 'A','B','D','E','K','M','X','O','P','C','H','T','Y':continue;
                    default: return 0;
                }
            }
        }
    }
    return 1;
}
stock IsValidRegion(const region[], const typenumber) {
    if(typenumber == 5) return 1;
    if(!(1<=typenumber<=4)) return 0;
	if(!(1 <= strlen(region)<= 4)) return 0;
    for(new i, j=strlen(region); i<j;i++)
    {
        switch(RegionSimbols[typenumber-1][i]) 
        {
            case -1: return 1;
            case 0: {
                switch(region[i]) {
                    case 'A','B','E','K','M','X','O','P','C','H','T','Y':continue;
                    default: return 0;
                }
            }
            case 1: {
                switch(region[i]) {
                    case '0'..'9': continue;
                    default: return 0;
                }
            }
			case 2: {
				switch(region[i]) {
					case '-', ' ': continue;
                    default: return 0;
                }
			}
        }
    }
    return 1;
}