/*
	Module: Auth And Register
	Author: Tema_Kovalev
	By sosal?
*/

enum RegisterStruct
{
	rSkin,
	Float: rPos[4],
	rAnim1[16],
	rAnim2[16],
}
static const RegActor[7][RegisterStruct] =
{
	{47, {230.2223, 0.00, 0.00, 0.00}, "ON_LOOKERS", "wave_loop"},
	{63, {230.2223, 2767.7996, 12.9784, 357.8067}, "ON_LOOKERS", "wave_loop"},
	{59, {232.4592, 2769.0559, 12.9784, 356.5633}, "PLAYIDLES", "SHIFT"},
	{8, {235.9353, 2771.7383, 13.3922, 268.3904}, "MISC", "SEAT_LR"},
	{21, {234.2099, 2772.4832, 13.3922, 86.63566}, "MISC", "SEAT_LR"},
	{44, {234.1653, 2771.7383, 13.3922, 269.2678}, "MISC", "SEAT_LR"},
	{78, {237.7539, 2772.2974, 13.3922, 332.5087}, "COP_AMBIENT", "Coplook_nod"}
};

public: OnRegistrationData(playerid,params[])
{
	extract params-> new string:email[64],string:password[33];else return 1;
    if(GetPlayerStateLogged(playerid) != 7) return Kick:(playerid);
    if(GetPlayerData(playerid, P_ID) != -1) return 1;
	if(!( 4 < strlen(password) < 32)) return GameText(playerid, "~r~�������� ����� ������", 3000, 2);
	if(!( 7 < strlen(email) < 46)) return GameText(playerid, "~r~�������� ����� �����", 3000, 2);
	if(!IsValidText(password)) return GameText(playerid, "~r~�� ����� ������������ ������", 3000, 2);
	if(!IsValidEMail(email)) return GameText(playerid, "~y~�� ����� ������������ �����", 3000, 2);

	f(pInfo[playerid][P_PASS], 32, "%s", password);
	f(pInfo[playerid][P_EMAIL], 46, "%s", email);

	SendPacket(1,playerid, CefUpdate, "interface('Authorization').setRegistrationStage(2)");
    GetPlayerStateLogged(playerid)++;
    return 1;
}
public: OnRegistrationCharacter(playerid,const params[])
{
	extract params-> new event,sex,skin;else return 1;
    if(GetPlayerStateLogged(playerid) != 8) return Kick:(playerid);
    static const skins[] = {89,15345,15352,88,39,38,75,15522,78,135,137,212,213,230,15327,15353,15354,15355,15524,15525};
    switch(event)
    {
         case 1: SendPacket(1,playerid, CefUpdate, "interface('Authorization').setRegistrationStage(3)"),GetPlayerStateLogged(playerid)++;
         case 0:
         {
            switch(sex) {
                case 0: {
                    SendPacket(1,playerid, CefUpdate, "interface('Authorization').setSkins('[78,135,137,212,213,230,15327,15353,15354,15355,15524,15525]')");
                    pInfo[playerid][P_SKIN] = skins[skin+8];
                    pInfo[playerid][P_SEX] = 1;
	            }
	            case 1: {
	                SendPacket(1,playerid, CefUpdate, "interface('Authorization').setSkins('[89,15345,15352,88,39,38,75,15522]')");
                    pInfo[playerid][P_SKIN] = skins[skin];
                    pInfo[playerid][P_SEX] = 2;
	            }
				default: return 1;
            }
			if(IsValidActor(pInfo[playerid][pRegActor][6])) DestroyActor(pInfo[playerid][pRegActor][6]);
			pInfo[playerid][pRegActor][6] = CreateActor(pInfo[playerid][P_SKIN], 237.7539, 2772.2974, 13.3922, 332.5087);
			SetActorVirtualWorld(pInfo[playerid][pRegActor][6], playerid + 5);
			SetActorInvulnerable(pInfo[playerid][pRegActor][6], true);
			ApplyActorAnimation(pInfo[playerid][pRegActor][6], RegActor[6][rAnim1], RegActor[6][rAnim2],  4.1, 1, 0, 0, 1, 0);
         }
    }
    return 1;
}
public: OnRegistrationBonuses(playerid,const name[])
{
    if(GetPlayerStateLogged(playerid) != 9) return Kick:(playerid);
    if(strlen(name) > 0)
    {
        str_q[0] = EOS;
		format(str_q, sizeof str_q, "SELECT * FROM users WHERE Name='%s' LIMIT 1", name);
		new Cache:result = mysql_query(mysql, str_q, true);
        if(!cache_num_rows()) return SendPacket(1,playerid, CefUpdate, "interface('Authorization').setError(\"referral\", \"������������ ��� ������\")"),cache_delete(result);
		new id = cache_get_field_content_int(0, "id");
        cache_delete(result);
        CreatePlayerAccount(playerid);
        UpdateDataInt(playerid, "Referal", id);
        pInfo[playerid][pReferal] = id;
    }
    GetPlayerStateLogged(playerid)=1;
    CreatePlayerAccount(playerid);
    return 1;
}
stock CreatePlayerAccount(playerid)
{   
    if(IsPlayerLogged(playerid)) return 0;
	if(!pInfo[playerid][P_EMAIL]) return GameText(playerid, "~r~�� �� ����� �����", 3000, 2);
	if(!pInfo[playerid][P_PASS]) return GameText(playerid, "~r~�� �� ����� ������", 3000, 2);
    if(IsValidDynamicObject(pInfo[playerid][pRegisterObj])) DestroyDynamicObject(pInfo[playerid][pRegisterObj]);
    for(new i; i < 7; i++) if(IsValidActor(pInfo[playerid][pRegActor][i])) DestroyActor(pInfo[playerid][pRegActor][i]);
    mysql_format(mysql, str_q, sizeof str_q, "INSERT INTO users (Name,Pass,Email, Sex, Skin, Level,reg_ip,last_ip,Money) \
    VALUES ('%e','%e','%e','%d','%d','2','%e','%e','"ServerBonus"')",PN(playerid), pInfo[playerid][P_PASS], pInfo[playerid][P_EMAIL],pInfo[playerid][P_SEX],pInfo[playerid][P_SKIN],pInfo[playerid][P_IP],pInfo[playerid][P_IP]);
    new Cache:result = mysql_query(mysql, str_q, true);
    pInfo[playerid][P_ID] = cache_insert_id();
    //GiveItem(playerid, 0,0,3);
   // GiveItem(playerid, pInfo[playerid][P_SKIN],1,2);
    cache_delete(result);
    SendPacket(1,playerid, CefHide, "Authorization");
    LoadPlayerData(playerid);
    return 1;
}

stock IsValidEMail(const email[])
{
	for(new i;i < strlen(email);i ++) if(!ValidEmailChar(email[i])) return 0;
	if(!TextFind(email,"@")) return 0;
  	return 1;
}

stock ValidEmailChar(mailchar)
{
	if((mailchar >= 'A' && mailchar <= 'Z') || (mailchar >= 'a' && mailchar <= 'z') || (mailchar >= '0' && mailchar <= '9') || (mailchar == '-') || (mailchar == '_') || (mailchar == '@') || (mailchar == '.')) return 1;
	return 0;
}


public: CheckPlayerAccount(playerid)
{
	SendPacket(1,playerid, CefUpdate, "confirmBrowserInitialize()");
	SetPlayerWeather(playerid,1);
	mysql_format(mysql, str_q, sizeof str_q, "SELECT * FROM users WHERE Name = '%s' LIMIT 1", PN(playerid));
	new Cache:result = mysql_query(mysql, str_q,true);
	if(!mysql_errno()) 
	{
		TogglePlayerSpectating(playerid, true);
		if(cache_num_rows())
		{
			InterpolateCameraPos(playerid,11.953300476074, 768.94561767578, 17.864999771118, 8.4843997955322, 727.46252441406, 46.009498596191, 90000);
	        InterpolateCameraLookAt(playerid,-128.65589904785, 751.34857177734, 43.817401885986, -128.65589904785, 751.34857177734, 43.817401885986, 90000);
			
			SetPlayerData(playerid, P_ID, cache_get_field_content_int(0, "id"));
            cache_get_field_content(0, "reg_ip", GetPlayerData(playerid,P_REGIP));
            cache_get_field_content(0, "last_ip", GetPlayerData(playerid,P_LASTIP));
			cache_get_field_content(0,"Pass",pInfo[playerid][P_PASS],mysql,33);
			format(str_1, sizeof str_1, "[\"auth\", \"%s\", "ServerNumber", 1, "ServerHalloween", "ServerNewYear","ServerPasha"]", PN(playerid));
			SendPacket(2,playerid, CefShow, "Authorization", str_1);
            GetPlayerStateLogged(playerid) = 2;
		}
		else {
            GetPlayerStateLogged(playerid) = 7;
			SetPlayerVirtualWorld(playerid, playerid + 5);
			pInfo[playerid][P_SKIN] = 78;
			pInfo[playerid][P_SEX] = 1;
			pInfo[playerid][P_ID] = -1;
			GameText(playerid, "~y~��������", 2000, 1);
			SendPacket(1, playerid, CefUpdate, "playSound('sounds/train/stop.mp3', 0, 1)");
			SendPacket(1, playerid, CefUpdate, "hideInterface('Hud')");
			SendPacket(2, playerid, CefShow, "Overlay", "[1000, 3000]");
			SendPacket(2, playerid, CefShow, "Authorization", "[\"register\", [78,135,137,212,213,230,15327,15353,15354,15355,15524,15525], "ServerNumber", 1, "ServerHalloween", "ServerNewYear","ServerPasha"]");
			pInfo[playerid][pRegisterObj] = CreateDynamicObject(10926, 231.011900, 2773.229980,13.400000, 0.000000, 0.000000, -90.0, playerid + 5);
			for(new i; i < 7; i++)
			{
				pInfo[playerid][pRegActor][i] = CreateActor(RegActor[i][rSkin], RegActor[i][rPos][0], RegActor[i][rPos][1], RegActor[i][rPos][2], RegActor[i][rPos][3]);
				SetActorVirtualWorld(pInfo[playerid][pRegActor][i], playerid + 5);
				SetActorInvulnerable(pInfo[playerid][pRegActor][i], true);
				ApplyActorAnimation(pInfo[playerid][pRegActor][i], RegActor[i][rAnim1], RegActor[i][rAnim2],  4.1, 1, 0, 0, 1, 0);
				ApplyActorAnimation(pInfo[playerid][pRegActor][i], RegActor[i][rAnim1], RegActor[i][rAnim2],  4.1, 1, 0, 0, 1, 0);
			}
			SetSpawnInfo(playerid, 0, 78, 245.5628, 2772.1128, 12.9705, 337.2245, 0, 0, 0, 0, 0, 0);
			InterpolateCameraPos(playerid, 230.5000, 2774.1299, 13.9000, 238.5000, 2774.1299, 13.9000, 10000, CAMERA_MOVE),
			InterpolateCameraLookAt(playerid, 230.5000, 2772.3301, 13.9000, 238.2000, 2772.3301, 13.9000, 10000, CAMERA_MOVE);
		}
	}
	else Kick:(playerid);
	cache_delete(result);
	return 1;
}
stock GetHardwareIDBanned(playerid, const hardware[])
{
    GetPlayerStateLogged(playerid) = 10;
	mysql_format(mysql, str_q, 250, "SELECT * FROM hardware_bans WHERE hardware_id = '%s' LIMIT 1", hardware);
	mysql_tquery(mysql, str_q, "CB_GetHardwareIDBanned", "i", playerid);
	return 1;
}
public: CB_GetHardwareIDBanned(playerid)
{
	if(cache_num_rows()) SetPlayerGameStateConnection(playerid),Kick(playerid);
    else SetTimerEx("CheckPlayerAccount",4000,false,"i",playerid);
	return true;
}
//==================================================================================//
//	AUTHORIZATION

public: OnAuthorizationStart(playerid,const dest[])
{
	extract dest-> new string:password[32];else printf("�����");
    if(GetPlayerStateLogged(playerid) != 2 || IsPlayerLogged(playerid)) return 0;
	if(1 <= strlen(password) <= 32)
    {
        if(strcmp(password, pInfo[playerid][P_PASS], false) != 0)
        {
            pInfo[playerid][pWrongPassword] ++;
            f(str_1, sizeof str_1, "interface('Authorization').$refs.auth.setError(\"password\", \"�������� ������. �������� �������: %d\")",3-pInfo[playerid][pWrongPassword]);
			SendPacket(1,playerid, CefUpdate, str_1);
			if(pInfo[playerid][pWrongPassword] == 3) return Kick:(playerid);
        }
        else {
            SendPacket(1,playerid, CefHide, "Authorization");
            SendPacket(2,playerid, CefShow, "Loading", "[3000]");
			pInfo[playerid][pWrongPassword]=0;
            GetPlayerStateLogged(playerid) = 1;
            LoadPlayerData(playerid);
        }
    }
	else SendPacket(1, playerid, CefUpdate, "interface('Authorization').$refs.auth.setError(\"password\", \"������������ ������ ������\")");
    return 1;
}
stock OnAuthorizationCode(playerid,code[])
{
    #pragma unused playerid, code
    if(GetPlayerStateLogged(playerid) != 2) return 0;
    return 1;
}

stock LoadPlayerData(playerid)
{
	str_q[0] = EOS;
	mysql_format(mysql, str_q, sizeof str_q, "SELECT * FROM users WHERE Name='%s' LIMIT 1", PN(playerid));
	new Cache:result = mysql_query(mysql, str_q,true);
	if(cache_num_rows())
	{
		IsPlayerLogged(playerid) = true;
		cache_get_field_content(0, "Email", pInfo[playerid][P_EMAIL], mysql, 46+1);
		cache_get_field_content(0, "Pass", pInfo[playerid][P_PASS], mysql, 32+1);
		pInfo[playerid][P_SEX] = cache_get_field_content_int(0, "Sex");
		pInfo[playerid][P_SKIN] = cache_get_field_content_int(0, "Skin");
		cache_get_field_content(0, "Money", pInfo[playerid][P_MONEY], mysql, 22);
		pInfo[playerid][P_LEVEL] = cache_get_field_content_int(0, "Level");
		pInfo[playerid][P_EXP] = cache_get_field_content_int(0, "EXP");
		pInfo[playerid][P_ADMIN] = cache_get_field_content_int(0, "admin");
		pInfo[playerid][P_SKINBD] = cache_get_field_content_int(0, "SkinBD");
		pInfo[playerid][P_FULLNESS] = cache_get_field_content_int(0, "Fullness");
		pInfo[playerid][pReferal] = cache_get_field_content_int(0, "Referal");
		cache_get_field_content(0, "AdminPassword", pInfo[playerid][pAdmPass], mysql, 32+1);
		SendPacket(1,playerid, CefUpdate, "showInterface('Hud')");
		SendPacket(1,playerid, CefUpdate, "client.setHudStatus(true)");
		SendPacket(1,playerid, CefUpdate, "client.setChatStatus(true)");
		LoadInventory(playerid);
		callcmd::alogin(playerid);
		TogglePlayerSpectating(playerid, false);
        SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerSpawn(playerid);
	}
	else Kick(playerid);
	cache_delete(result);
	return true;
}