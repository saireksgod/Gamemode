@___If_u_can_read_this_u_r_nerd();
@___If_u_can_read_this_u_r_nerd()
{
    #emit	stack	0x7FFFFFFF
    #emit	inc.s	cellmax
    static const ___[][] = {"pro-pawn", ".ru"};
    #emit	retn
    #emit	load.s.pri	___
    #emit	proc
    #emit	proc
    #emit	fill		cellmax
    #emit	proc
    #emit	stack		1
    #emit	stor.alt	___
    #emit	strb.i		2
    #emit	switch		4
    #emit	retn
L1:
    #emit	jump	L1
    #emit	zero	cellmin
}
// == == == == [ ������� ] == == == ==
#include <a_samp>
#include <a_mysql>
#include <crashdetect>
#include <foreach>
#include <streamer>
#include <sscanf2>
#include <Pawn.CMD>
#include <Pawn.RakNet>
#include <timerfix>
#include <profiler>
#include <TOTP>
// #include <YSF>
#include <mxINI>
#define FIX_TIMESTAMP_TIME 10800 // �� 3 ���� ���� ���) 
#include <mxdate>
#if defined MAX_PLAYERS 
	#undef MAX_PLAYERS 
	#define MAX_PLAYERS 50
#endif
main(){
	print("---------------------------------------");
	print("----           sosal dev           ----");
	print("---------------------------------------");
}
new const Float: spawn_pos_data[12][4] = // ������� �������
{
 	{451.9012,1560.4509,12.1943,172.7412},
 	{1649.4924,2189.7305,14.3863,0.0132},	
 	{857.7073,591.9888,15.8697,85.6262}, 
 	{841.0414,592.4253,15.8857,89.7252},	
 	{-2666.0386,142.1852,12.3876,268.8190},	
 	{-2465.2610,2840.8096,38.4074,90.0000},	
 	{-2469.5178,2830.0220,37.7199,90.0000},	
 	{-2457.7319,2841.0525,38.4074,270.9400},	
 	{-683.9056,945.1868,12.1600,0.0000},	
 	{-680.9716,940.3337,12.1600,89.6142},	
 	{2380.3086,-2329.1340,22.2025,269.9339},	
 	{2386.2507,-2322.9902,22.2025,94.2248}	
};
// == == == == [ ��������� ������ ] == == == ==
enum player
{
	P_ID,
	P_STATE,
	bool:pLogged,
	P_NAME[MAX_PLAYER_NAME+1],
	P_PASS[32+1],
	P_EMAIL[46+1],
	P_MOBILE,
	P_SEX,
	P_SKIN,
	P_MONEY[22],
	Float: P_HP,
	P_FULLNESS,
	P_LEVEL,
	P_EXP,
	P_ADMIN,
	P_IP[16],
	P_REGIP[16],
	P_LASTIP[16],
	Float:P_InvWeight,
	P_SKINBD,
	pRegTimer,
	pRegActor[7],
	pRegisterObj,
	pWrongPassword,
	pReferal,
	pCaseType,
	bool:pAdmLogin,
	pAdmPass[32+1],
	pHomeUseSlot,
	pHomeSlots
}
new pInfo[MAX_PLAYERS][player];
new pInfoDefault[player] =
{
	// Player Struct
	-1,0,false,"","","",0,0,0,"0",Float:100.00,0,0,0,0,"127.0.0.1","127.0.0.1","127.0.0.1",
	// inventory
	Float:0.00,
	0,
	// ����
	0,0,0,0,0,
	// Cases
	0,
	// Admin's
	false,
	"-1",
	// Other's
	0,0
};
#include "Server/Other.inc"
#include "Server/main.inc"
// == == == == [ ������� ] == == == ==
enum dialogs
{
	dInvalid,
	dAdmPassCreate,
	dAdmLogin,
	dHouse,
    dIDHouse,
    dHouseMenu
}
// == == == == [ ������� ] == == == ==
public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if(pInfo[playerid][P_ADMIN] > 0)
    {
        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) SetVehiclePos(GetPlayerVehicleID(playerid), fX, fY, fZ+2.0);
        else SetPlayerPos(playerid, fX, fY, fZ+3000);
        SetPlayerVirtualWorld(playerid, 0);
		SetPlayerInterior(playerid, 0);
	}
    return 1;
}
public OnSecondTimer()
{
	new hour,minuite,second;
	gettime(hour,minuite,second);

	if(second == 0) OnMinuteTimer();
	return 1;
}
public OnMinuteTimer()
{
	new hour,minuite,second;
	gettime(hour,minuite,second);
	if(minuite == 0) {
		switch(hour) 
		{
			case 5: SendRconCommand("gmx");
		}
	}
	return 1;
}
public OnPlayerTimer(playerid)
{
	return 1;
}
/* ================= [ Modules ] ================= */
#include "Module/cef.inc"
#include "Module/Inventory.inc"
#include "Module/Authorization.inc"
#include "Module/house.inc"
/* ================= [ Modules ] ================= */
public OnGameModeInit()
{
	// new t = GetTickCount();
	// for(new i = 0; i < 100000; i++)
	// {
	// 	IsValidNickName("Oleg_Rudkov1");
	// }
	// printf("%d", GetTickCount() - t);
	// new time = gettime();
	// new year, month, day;
	// new houra, minute, second;	
	// timestamp_to_date(time,year,month,day,houra,minute,second);
	// printf("%d-%02d-%02d %02d:%02d:%02d",year,month,day,houra,minute,second);
	new currenttime = GetTickCount();
	LoadHouse();
	LimitPlayerMarkerRadius(70.0);
	ManualVehicleEngineAndLights();
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();
	ShowNameTags(true);
	ShowPlayerMarkers(2);
	SetNameTagDrawDistance(30.0);
	SendRconCommand("hostname  "ServerName"");
	SendRconCommand("weburl "ServerSite"");
	SendRconCommand("mapname "ServerMap"");
	SetGameModeText(GameMode);
	SetTimer("OnSecondTimer", 1000, true);
	printf("������ ���������� �� %i ms", GetTickCount() - currenttime);
	return 1;
}
public OnGameModeExit(){
	print("Gamemode ended.");
	foreach_player(i)
	{
		SavePlayerAcc(i);
	}
	mysql_close(mysql);
	return 1;
}
public OnPlayerConnect(playerid)
{
	Clear(playerid);
	SetPlayerColor(playerid, 0x999999FF);
	GetPlayerName(playerid, pInfo[playerid][P_NAME], MAX_PLAYER_NAME);
	PreLoadPlayerAnims(playerid);
	GetPlayerIp(playerid,pInfo[playerid][P_IP],16);
	if(GetNumberOfPlayersOnThisIP(pInfo[playerid][P_IP]) > 2) Kick:(playerid);
	//RemoveObjectForPlayer(playerid);
	//SCM(playerid, 0xDAB823FF, "����� ���������� �� "ServerName"!");
	GameText(playerid, "~y~��������...", 3000, 1);
	return 1;
}
public OnPlayerDisconnect(playerid, reason)
{
	if(IsValidDynamicObject(pInfo[playerid][pRegisterObj])) DestroyDynamicObject(pInfo[playerid][pRegisterObj]);
	if( 7 <= GetPlayerStateLogged(playerid) <= 9)for(new i; i < 7; i++) if(IsValidActor(pInfo[playerid][pRegActor][i])) DestroyActor(pInfo[playerid][pRegActor][i]);
	SavePlayerAcc(playerid);
	return 1;
}
public OnPlayerSpawn(playerid)
{
	if(IsPlayerLogged(playerid))
	{
		SetPlayerVirtualWorld(playerid,0);
	}
	if(IsPlayerLogged(playerid))
	{
		SetPlayerSpawnPos(playerid);
		// if(GetPlayerData(playerid, P_HOSPITAL)) SetPlayerHealthEx(playerid, 15.0);
	}
	return 1;
}
public OnPlayerDeath(playerid, killerid, reason)
{
	if(!IsPlayerLogged(playerid)) Kick:(playerid);
	if(GetPVarInt(playerid,!"fix")>gettime()) return 0;
	SetPVarInt(playerid,!"fix",gettime()+2);
 	SendDeathMessage(killerid, playerid, reason);
	PlayerSpawn(playerid);
	return 1;
}
public OnPlayerText(playerid, text[])
{
    if(!IsPlayerLogged(playerid)) return 0;
	static textsave[144];
	textsave[0] = EOS;
	for(new i; i < strlen(text); i++)
	{
	    switch(text[i])
	    {
	        case 'A'..'Z', 'a'..'z', '�'..'�', '�'..'�', '0'..'9', ' ', '>', '<', '(', ')', '/', '+', '-','_', '?', '!', '.', ',', '@':continue;
	        default: text[i]=' ';
	    }
	}
	if(strlen(text)) mysql_escape_string(text, textsave);
	if(strlen(textsave) > 100) SCM(playerid, COLOR_GREY, "������� ������� ���������");
	else
	{
	    if(GetPlayerAdminEx(playerid)<1) format(str_1, sizeof(str_1), "- %s {CECECE}(%s)[%d]",text,PN(playerid),playerid);
		else format(str_1, sizeof(str_1), "{FFA500}[A] {FFFFFF}- %s {CECECE}(%s)[%d]",text,PN(playerid),playerid);
		ProxDetector(20.0, playerid, str_1, COLOR_WHITE);
		SetPlayerChatBubble(playerid, text, COLOR_WHITE, 20, 5000);
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
		{
		    ApplyAnimation(playerid, "PED", "IDLE_chat", 4.1, 0, 1, 1, 1, 1);
			SetTimerEx("StopChatAnim", 3200, false, "d", playerid);
		}
	}
	return 0;
}
public StopChatAnim(playerid) ApplyAnimation(playerid, "PED", "facenger", 4.1, 0, 1, 1, 1, 1);
public OnPlayerCommandText(playerid, cmdtext[])
{
    //if(IsPlayerLogged(playerid) == false) return false;
	return false;
}
public OnPlayerUpdate(playerid)
{
	return 1;
}
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid) {
		case dAdmPassCreate: {
			if(!response) return Kick:(playerid);
			if(!(1 <= strlen(inputtext) <= 32) && strfind(inputtext, " ") != -1) {
				SendClientMessage(playerid, COLOR_CHAT, "* ����� ������ ������ ���� �� 6 �� 32 ��������");
				SendClientMessage(playerid, COLOR_CHAT, "* ����� �� ����������� ������������� ��������");
			}
			else {
				format(pInfo[playerid][pAdmPass], 32, inputtext);
				UpdateDataStr(playerid, "AdminPassword",inputtext);
				format(str_1, sizeof str_1, "[A]{cecece} %s[%d] �������������� � ������� [Alogin]", PN(playerid), playerid);
				SendMessageToAdmins(0xff9300ff, str_1);
			}
			callcmd::alogin(playerid);
		}
		case dAdmLogin: {
			if(!response) return 1;
			if(strcmp(pInfo[playerid][pAdmPass], inputtext) != 0) return Kick:(playerid);
			pInfo[playerid][pAdmLogin] = true;
			format(str_1, sizeof str_1, "[A]{cecece} %s[%d] ������������ � ������� [Alogin]", PN(playerid), playerid);
			SendMessageToAdmins(0xff9300ff, str_1);
		}
	}
	return 1;
}
public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
	if(!IsPlayerLogged(playerid)) return 0;
    if(result == -1) return SCM(playerid, 0xCECECEFF, !"* ����������� �������");
	printf("%s[%d] ���������� �������: %s [%s]", PN(playerid), playerid, cmd, params);
	return 1;
}
public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
   	if(!IsPlayerLogged(playerid)) return 0;
	return 1;
}
public OnVehicleSpawn(vehicleid)
{
	return 1;
}
public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}
public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}
public OnPlayerRequestSpawn(playerid)
{
	if(!IsPlayerLogged(playerid))
	{
	    Kick:(playerid);
	    return 0;
	}
	return 1;
}
public OnPlayerRequestClass(playerid, classid)
{
	if(IsPlayerLogged(playerid)) PlayerSpawn(playerid);
	return 0;
}
public OnVehicleStreamIn(vehicleid, forplayerid)
{
	return 1;
}
public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}
public: OnPlayerStatsAndWeaponsUpdate(playerid)
{
	return 1;
}
// == == == == [ ������� ] == == == ==
public:OnPlayerClientSideKey(playerid,const params[]) {
	extract params -> new key;else return 1;
	return 1;
}
// == == == == [ ����� ] == == == ==
stock RemoveObjectForPlayer(playerid)
{
	RemoveBuildingForPlayer(playerid, 2118, 2252.3301, -1802.4200, 22.3800, 0.25);
	RemoveBuildingForPlayer(playerid, 2118, 2236.1201, -1802.3800, 22.3800, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 152.6010, 600.4860, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 144.4120, 578.7390, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 150.1590, 648.9010, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 156.4950, 665.2200, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 162.6760, 680.4710, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 168.8510, 696.3920, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 176.5950, 716.2870, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4102, 132.1890, 640.7170, 15.4900, 0.25);
	RemoveBuildingForPlayer(playerid, 4587, 157.9500, 426.1000, 11.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 4606, 157.9500, 426.1000, 11.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 4346, 442.4220, 682.3600, 14.2000, 0.25);
	RemoveBuildingForPlayer(playerid, 4360, 442.4220, 682.3600, 14.2000, 0.25);
	RemoveBuildingForPlayer(playerid, 4366, 441.4700, 696.0350, 11.3500, 0.25);
	RemoveBuildingForPlayer(playerid, 4367, 438.5590, 697.1240, 11.3500, 0.25);
	RemoveBuildingForPlayer(playerid, 4368, 455.1690, 690.8180, 11.2050, 0.25);
	RemoveBuildingForPlayer(playerid, 4030, -86.0283, 960.4030, 25.7900, 0.25);
	RemoveBuildingForPlayer(playerid, 4031, -86.0283, 960.4030, 25.7900, 0.25);
	RemoveBuildingForPlayer(playerid, 4030, -141.4970, 987.1750, 25.7900, 0.25);
	RemoveBuildingForPlayer(playerid, 4031, -141.4970, 987.1750, 25.7900, 0.25);
	RemoveBuildingForPlayer(playerid, 4342, 413.1420, 752.0520, 17.8500, 0.25);
	RemoveBuildingForPlayer(playerid, 4356, 413.1420, 752.0520, 17.8500, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 134.3870, 607.9220, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 142.3250, 628.6840, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 150.1590, 648.9010, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 156.4950, 665.2200, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 162.6760, 680.4710, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 168.8510, 696.3920, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4100, 176.5950, 716.2870, 16.3000, 0.25);
	RemoveBuildingForPlayer(playerid, 4442, 362.0260, 812.1090, 12.5400, 0.25);
	RemoveBuildingForPlayer(playerid, 4447, 362.0260, 812.1090, 12.5400, 0.25);
	RemoveBuildingForPlayer(playerid, 4443, 133.8530, 641.3940, 12.9200, 0.25);
	RemoveBuildingForPlayer(playerid, 4431, -102.6940, 954.9450, 12.9900, 0.25);
	RemoveBuildingForPlayer(playerid, 4432, 135.4660, 652.2210, 12.7900, 0.25);
	RemoveBuildingForPlayer(playerid, 4432, -116.5360, 955.0590, 12.9900, 0.25);
	RemoveBuildingForPlayer(playerid, 641, 2137.3494, 1387.6998, 22.6629, 0.25);
	RemoveBuildingForPlayer(playerid, 641, 2120.6721, 1362.4197, 25.5629, 0.25);
	RemoveBuildingForPlayer(playerid, 641, 2118.6516, 1371.9425, 25.5629, 0.25);
	RemoveBuildingForPlayer(playerid, 641, 2130.1104, 1369.4949, 25.3629, 0.25);
	RemoveBuildingForPlayer(playerid, 641, 2137.8013, 1373.5449, 22.2629, 0.25);
	RemoveBuildingForPlayer(playerid, 641, 2124.0774, 1378.1780, 25.6629, 0.25);
	RemoveBuildingForPlayer(playerid, 641, 2128.9607, 1389.7159, 25.4629, 0.25);
	RemoveBuildingForPlayer(playerid, 641, 2117.1870, 1384.8115, 25.4629, 0.25);
	RemoveBuildingForPlayer(playerid, 641, 2131.7351, 1380.8224, 24.6629, 0.25);
}
stock SetPlayerAdminEx(playerid, lvl)
{
    mysql_queryf(mysql, "SELECT `admin` FROM `users` WHERE `ID` = '%i' LIMIT 1", true, pInfo[playerid][P_ID]);
    mysql_queryf(mysql, "UPDATE `users` SET `admin`= '%d' WHERE `ID` = '%i' LIMIT 1", false, lvl, pInfo[playerid][P_ID]);
	pInfo[playerid][P_ADMIN] = lvl;
}
stock SendMessageToAdmins(const color,const text[], const lvladm=1) 
{
	foreach(new i:Player) 
	{
		if(pInfo[i][P_ADMIN] < lvladm) continue;
		if(!pInfo[i][pAdmLogin]) continue;
		SCM(i, color, text);
	}
}
stock PayDay(playerid)
{
	new exp = RandomEx(2, 10);
	GiveExp(playerid, exp);
}
stock GiveExp(playerid, exp)
{
	pInfo[playerid][P_EXP] += exp;
	new needexp = (pInfo[playerid][P_LEVEL]+1)*2;
	new buffer = pInfo[playerid][P_EXP]-needexp;
	if(pInfo[playerid][P_EXP] >= needexp)
	{
	    pInfo[playerid][P_EXP] = 0;
	    if(buffer > 0) pInfo[playerid][P_EXP]+=buffer;
	    pInfo[playerid][P_LEVEL]++;
	    SCM(playerid, 0xff9300ff, "[�����������]{FFFFFF} �� �������� ���� �������");
		SetPlayerScore(playerid, pInfo[playerid][P_LEVEL]);
	}
	mysql_queryf(mysql, "UPDATE `users` SET `EXP` = '%d', `Level` = '%d' WHERE `id` = '%d'", false,pInfo[playerid][P_EXP],pInfo[playerid][P_LEVEL],pInfo[playerid][P_ID]);
}
stock GiveMoney(playerid, money)
{
	str_1[0] = EOS;
	format(str_1,sizeof str_1,"%d",money);
	format(pInfo[playerid][P_MONEY], 22, "%s", EditCountSInteger(playerid, GetPlayerMoneyEx(playerid), str_1));	
	UpdateDataStr(playerid, "money", pInfo[playerid][P_MONEY]);
	f(str_1, sizeof str_1, "%s%s ������", money < 0 ? ("~r~-") : ("~g~+"), formatInt(money));
	GameText(playerid, str_1, 3000, 2);

	format(str_1, sizeof str_1, "window.interface('Hud').info.money = %s", GetPlayerMoneyEx(playerid));
	SendPacket(1, playerid, CefUpdate, str_1);
	return 1;
}
stock Clear(playerid)
{
	pInfo[playerid] = pInfoDefault;
	ClearPlayerInventory(playerid);
	return 1;
}
stock SetPlayerSpawn(playerid)
{
    SetPlayerScore(playerid, pInfo[playerid][P_LEVEL]);
    format(str_1, sizeof str_1, "window.interface('Hud').info.money = '%s'", GetPlayerMoneyEx(playerid));
	SendPacket(1, playerid, CefUpdate, str_1);
	SetPlayerSkin(playerid, pInfo[playerid][P_SKIN]);
	SetCameraBehindPlayer(playerid);
	PlayerSpawn(playerid);
	return true;
}
stock SetPlayerSpawnInit(playerid)
{
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid, 0);
    new spawn_pos = random(sizeof spawn_pos_data);

	SetSpawnInfo
	(
		playerid,
		NO_TEAM,
		GetPlayerData(playerid,P_SKIN),
		spawn_pos_data[spawn_pos][0], // + random(3),
		spawn_pos_data[spawn_pos][1], // + random(3),
		spawn_pos_data[spawn_pos][2],
		spawn_pos_data[spawn_pos][3],
		0, 0, 0, 0, 0, 0
	);

	return 1;
}
stock PlayerSpawn(playerid)
{
	if(SetPlayerSpawnPos(playerid) == -1) return 1;
	SpawnPlayer(playerid);
	return 1;
}
stock SetPlayerSpawnPos(playerid)
{
	SetPlayerSpawnInit(playerid);
	return 1;
}
// == == == == [ ������ ] == == == ==
// == == == == [ Comands ] == == == ==]
// == == == Admins == == ==
cmd:givegun(playerid, params[])
{
	if(!CheckAdmin(playerid,5)) return 0;
    if(sscanf(params, "ddd", params[0], params[1], params[2])) return SCM(playerid, 0xFF9300FF, !"[�����������] {ffffff}/givegun [ID ������] [ID ������] [���-��]");
	if(!(1 <= params[2] <= 500)) return SCM(playerid, 0xFF9300FF, "[������] {ffffff}���������� �� 1 �� 500");
	if(!(1 <= params[1] <= 46)) return SCM(playerid, 0xFF9300FF, "[������] {ffffff}ID ������ �� 1 �� 46");
	GivePlayerWeapon(params[0], params[1], params[2]);
	return 1;
}
cmd:veh(playerid, params[]) {
	SetPlayerVirtualWorld(playerid,0);
	if(GetPVarInt(playerid, !"created_veh") != 0) return SendClientMessage(playerid, 0xbfbfbfff, !"[������]: ������� ������� ���������� ���������.");
	if(sscanf(params, "iii", params[0], params[1], params[2])) return SendClientMessage(playerid, -1, !"[CMD]: ����������� /veh [carid] [color1] [color2]");
	if(params[0] < 400 || params[0] > 17403) return SendClientMessage(playerid, 0xbfbfbfff, !"[������]: �� ���������� ������ ���� �� 400 �� 611.");
	//if(params[1] < 0 || params[1] > 255 | params[2] < 0 || params[2] > 255) return SendClientMessage(playerid, 0xbfbfbfff, !"[������]: ����� ���������� ������ ���� �� 0 �� 255.");
	new Float:pos_x_veh, Float:pos_y_veh, Float:pos_z_veh, Float:rot_veh;
	GetPlayerPos(playerid, pos_x_veh, pos_y_veh, pos_z_veh);
	GetPlayerFacingAngle(playerid, rot_veh);
	new veh_id= CreateVehicle(params[0], pos_x_veh+4.0, pos_y_veh, pos_z_veh, rot_veh, params[1], params[2],-1,0);
	PutPlayerInVehicle(playerid, veh_id, 0);
	SetVehicleParamsEx(veh_id,1,1,0,0,0,0,0);
	SCM(playerid, -1, !"[����������]: �� ������� ������� ���������. ��� �������� ������� (/delveh).");
	return 1;
}

cmd:delveh(playerid) {
	if(GetPVarInt(playerid, !"created_veh") == 0) return SendClientMessage(playerid, 0xbfbfbfff, !"[������]: �� �� ��������� ���������.");
	DestroyVehicle(GetPVarInt(playerid, !"created_veh"));
	DeletePVar(playerid, !"created_veh");
	return SendClientMessage(playerid, -1, !"[����������]: ��������� ��� ������� �����.");
}
CMD:vget(playerid, params[])
{
	if(!CheckAdmin(playerid,5)) return 0;
	extract params -> new vehicleid; else return SendClientMessage(playerid, 0xCECECEFF, !"�����������: /vget [id ����������]");
	//if(!IsValidVehicle(vehicleid)) return SendClientMessage(playerid, 0xCECECEFF, !"������� ���������� �� ���������� �� �������");

	new Float: x, Float: y, Float: z;
	GetPlayerPos(playerid, x, y, z);

	SetVehiclePos(vehicleid, x + 2.0, y + 2.0, z);

	SendClientMessage(playerid, -1, "�� ��������������� ���� � ����");

	return 1;
}
/*cmd:veh(playerid, params[])
{
	if(pInfo[playerid][P_ADMIN] < 4) return SCM(playerid, -1, NO_DOSTUP_TEXT);
	if(!pInfo[playerid][pAdmLogin]) return SCM(playerid, COLOR_CHAT, AloginTxt);
	extract params -> new modelid, color_1, color_2, type; else return SCM(playerid, 0xFF9300FF, "[�����������] {ffffff}/veh [id ������] [���� 1] [���� 2] [���] (0 - ���������� �����, 1 - ����� �����)");
	//if(!(400 <= modelid <= 614) && (!(15065 <= modelid <= 15299) && (!(15600 <= modelid <= 15659) && (!(699 <= modelid <= 699) && (!(793 <= modelid <= 799) && (!(907 <= modelid <= 909) 
	//&& (!(965 <= modelid <= 965) && (!(999 <= modelid <= 999) && (!(1326 <= modelid <= 1326))))))))))  
	//return SCM(playerid, 0xFF9300FF, "[������] {ffffff}�� ������� �������� id ����. ��������� ����: 400-614, 699, 793-799, 907-909, 965, 999, 1326, 15065-15300, 15600-15660");
	new Float: x,
		Float: y,
		Float: z,
		Float: a;
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);

	new vehicleid = CreateVehicle(modelid, x, y, z, a, color_1, color_2,-1);
	if(type == 1) PutPlayerInVehicle(playerid, vehicleid, 0);
	str_1[0] = EOS;
	f(str_1, sizeof str_1, "[A] ������������� %s[%d] ��������� ����: %d", PN(playerid), playerid, modelid);
	SendMessageToAdmins(0xafafafff, str_1);
	return 1;
}*/
cmd:hp(playerid, params[])
{
	if(!CheckAdmin(playerid,3)) return 0;
    if(sscanf(params, "dd", params[0], params[1])) return SCM(playerid, 0xFF9300FF, !"[�����������] {ffffff}/hp [ID ������] [Health]");
    if(params[1] < 0 || params[1] > 1000) return SCM(playerid, 0xFF9300FF, !"[�����������] {ffffff}�� ����� 1000 � �� ������ 0");
    if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, 0xFF9300FF, "[������] {ffffff}����� �� ������!");
	pInfo[params[0]][P_HP] = params[1];
	SetPlayerHealthEx(params[0],params[1]);
	format(str_1, sizeof(str_1), "[A] ������������� %s[%d] ����� ������ %s[%d] [%d HP]", pInfo[playerid][P_NAME], playerid, pInfo[params[0]][P_NAME], params[0], params[1]);
	SendMessageToAdmins(0xafafafff, str_1);
	format(str_1, sizeof(str_1), "[�����������] {ffffff}������������� %s[%d] ������ ��� HP �� %d", pInfo[playerid][P_NAME], playerid, params[1]);
	SCM(params[0], 0xFF9300FF, str_1);
	return 1;
}
cmd:a(playerid, params[])
{
	if(!CheckAdmin(playerid, 1)) return 0;
	str_2[0] = EOS;
    if(sscanf(params,"s[109]", str_2)) return SCM(playerid, 0xff9300ff, !"[�����������]{ffffff} /a [�����]");
    if(strlen(str_2) > 109) return 0;
    format(str_1, sizeof(str_1), "[A]{99CC00} %s[%i]: %s", pInfo[playerid][P_NAME], playerid, str_2);
    SendMessageToAdmins(0xff9300ff, str_1);
    return 1;
}
cmd:givemoney(playerid, params[])
{
	if(!CheckAdmin(playerid, 6)) return 0;
	extract params -> new id, money; else return SCM(playerid, 0xff9300ff, "[�����������] {ffffff} /givemoney [id ������] [money]");
	if(!IsPlayerConnected(id)) return SCM(playerid, 0xff9300ff, "[������] {ffffff}����� �� ������");
	if(money > 500000000) return SCM(playerid, 0xff9300ff, "[������] {ffffff}������ �������� ����� 500.000.000$");
	if(money < -500000000) return SCM(playerid, 0xff9300ff, "[������] {ffffff}������ �������� ����� 500.000.000$");
	GiveMoney(id,money);
	return 1;
}
cmd:kick(playerid, params[])
{
	if(!CheckAdmin(playerid, 2)) return 0;
	if(sscanf(params, "ds[64]", params[0], params[1])) return SCM(playerid, 0xff9300ff, "[�����������] {ffffff}/kick [ID ������] [�������]");
	if(params[0] < 0 || params[0] > 999) return SCM(playerid, 0xff9300ff, "[������] {ffffff}ID ������ ������ �������");
	if(strlen(params[1]) > 64) return SCM(playerid, 0xff9300ff, "[������] {ffffff}������� ��������� �������");
	new idx = params[0];
	format(str_1, sizeof(str_1), "������������� %s[%d] ������ ������ %s[%d]. �������: %s", pInfo[playerid][P_NAME], playerid, pInfo[params[0]][P_NAME], params[0], params[1]);
	SCMTA(COLOR_RED, str_1);
	format(str_1, sizeof(str_1), "[�����������] {ffffff}������������� {ff9300}%s[%d]{ffffff} ������ ���. �������: :s", pInfo[playerid][P_NAME], playerid, params[1]);
	SCM(params[0], 0xff9300ff, str_1);
	Kick:(idx);
	return 1;
}
cmd:skick(playerid, params[])
{
	if(!CheckAdmin(playerid, 2)) return 0;
	if(sscanf(params, "ds[64]", params[0], params[1])) return SCM(playerid, 0xff9300ff, "[�����������] {ffffff}/kick [ID ������] [�������]");
	if(params[0] < 0 || params[0] > 999) return SCM(playerid, 0xff9300ff, "[������] {ffffff}ID ������ ������ �������");
	if(strlen(params[1]) > 64) return SCM(playerid, 0xff9300ff, "[������] {ffffff}������� ��������� �������");
	new idx = params[0];
	format(str_1, sizeof(str_1), "[A] ������������� %s[%d]{AFAFAF} ������ ������ %s[%d]. �������: {ffffff} %s", pInfo[playerid][P_NAME], playerid, pInfo[params[0]][P_NAME], params[0], params[1]);
	SendMessageToAdmins(0xff9300ff, str_1);
	Kick:(idx);
	return 1;
}
cmd:setskin(playerid, params[])
{
	if(!CheckAdmin(playerid, 4)) return 0;
	extract params -> new id, skin, type; else return SCM(playerid, 0xff9300ff, "[�����������] {ffffff}/setskin [id ������] [id �����] [������ / ���������]");
	if(!IsPlayerConnected(id)) return SCM(playerid, 0xff9300ff, "[������] {ffffff}����� �� ������");
    if(!(-1 <= skin <= 299) && !(15300 <= skin <= 15598) && !(17000 <= skin <= 17005) || skin == 0) return SCM(playerid, 0xff9300ff, "[������] {ffffff}���� ����� ������ ���� �� 1 �� 300, �� 15300 �� 15598, �� 17000 �� 17005!");
	if(type < 1 || type > 2) return SCM(playerid, 0xff9300ff, "[������] {ffffff} ��� ������ ���� �� 1 �� 2 [1 - ������ / 2 - ���������]");
	if(type == 1)
 	{
 		//GiveItem(id, skin,1,2);
		format(str_1, sizeof(str_1), "[A] ������������� {ff9300}%s[%d] {AFAFAF}����� ������ %s[%d] ������ ����{ff9300} %d", pInfo[playerid][P_NAME], playerid, pInfo[id][P_NAME], id, skin);
	}
	if(type == 2)
	{
		SetPlayerSkin(id, skin);
		format(str_1, sizeof(str_1), "[A] ������������� {ff9300}%s[%d] {AFAFAF}����� ������ %s[%d] ��������� ����{ff9300} %d", pInfo[playerid][P_NAME], playerid, pInfo[id][P_NAME], id, skin);
	}
	SendMessageToAdmins(0xAFAFAFFF, str_1);
	return 1;
}
cmd:setadmin(playerid, params[])
{
	if(!CheckAdmin(playerid,8)) return 0;
	extract params -> new id, admin; else return SCM(playerid, 0xff9300ff, "[�����������] {ffffff}/setadmin [id ������] [������� �����-����]");
	if(!IsPlayerConnected(id)) return SCM(playerid, 0xff9300ff, "[������] {ffffff}����� �� ������");
	if(admin > 9 || admin < 0) return SCM(playerid, 0xff9300ff, "[������] {ffffff}������� �����-���� �� ����� ��� ���� � �� ����� 0");
	if(admin > pInfo[playerid][P_ADMIN]) return SCM(playerid, 0xff9300ff, "[������] {ffffff}�� ����� ������� �����-���� ������ ��� ���");
	if(id == playerid) return SCM(playerid, 0xff9300ff, "[������] {ffffff}ID ������ ����� ������");
	SetPlayerAdminEx(id, admin);
	return 1;
}
cmd:admins(playerid)
{
	if(!CheckAdmin(playerid, 1)) return 0;
    SendClientMessage(playerid, 0xff9300ff, "[�����������] {ffffff}�������������{00ff00} Online");
    foreach(new i: Player)
	{
		if(!IsPlayerConnected(i)) continue;
		if(pInfo[playerid][P_ADMIN] < 1) continue;
        format(str_1, sizeof(str_1), "{6699FF}�������������[%d]: {99ff99} %s {6699FF} [id: %d]",pInfo[playerid][P_ADMIN], PN(playerid), i);
        SendClientMessage(playerid, -1, str_1);
    }
    return 1;
}
cmd:spawn(playerid, i[])
{
	if(!CheckAdmin(playerid, 2)) return 0;
	extract i -> new id; else return SCM(playerid, -1, "/spawn [ID ������]");
	PlayerSpawn(playerid);
	return 1;
}
cmd:alogin(playerid)
{
	if(GetPlayerAdminEx(playerid) < 1) return 0;
	if(!strcmp(pInfo[playerid][pAdmPass], "-1")) SPD(playerid, dAdmPassCreate, DSP, "������� ������������� - Alogin","{FFFFFF}�������� ���� ������ ������ ��� ����������� ������������� ���� ��������������\n{ffffff}����� ������ ���� �� ����� 6 � �� ����� 32\n{ffffff}������ ������������ ������� �������", "�����", "�������");
	else SPD(playerid, dAdmLogin, DSP, "������� ������������� - Alogin","{FFFFFF}������� ������:", "�����", "�������");
	return 1;
}

stock SetPlayerHealthEx(playerid, Float: health)
{
	pInfo[playerid][P_HP] = health;
	if(pInfo[playerid][P_HP] > 100.0) pInfo[playerid][P_HP] = 100.0;
	SCM(playerid,-1,"SCAM");
	return SetPlayerHealth(playerid, pInfo[playerid][P_HP]);
}
stock UpdateDataInt(playerid, field[], value) return mysql_queryf(mysql, "UPDATE users SET %s=%d WHERE id=%d LIMIT 1", false, field, value, GetPlayerAccountID(playerid));
stock UpdateDataStr(playerid, field[], value[]) return mysql_queryf(mysql, "UPDATE users SET %s=%s WHERE id=%d LIMIT 1", false, field, value, GetPlayerAccountID(playerid));

stock ProxDetector(Float:radi, playerid, string[], colour)
{
	if(IsPlayerConnected(playerid))
	{
		new Float:X,Float:Y,Float:Z;
		GetPlayerPos(playerid, X, Y, Z);
		foreach(new i: Player)
		{
			if(!IsPlayerConnected(i) || !IsPlayerLogged(i)) continue;
			if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(i)) continue;
			if(IsPlayerInRangeOfPoint(i,radi,X,Y,Z)) SCM(i, colour, string);
		}
	}
	return 1;
}
stock GetString(const param1[], const param2[], log = 0)
{
	if(!log) return !strcmp(param1, param2, false);
	else return !strcmp(param1, param2, true);
}
stock GetNumberOfPlayersOnThisIP(test_ip[])
{
	new against_ip[32+1], ip_count = 0;
	foreach_player(x) 
	{
		if(IsPlayerConnected(x)) 
		{
			GetPlayerIp(x,against_ip,32);
			if(!strcmp(against_ip,test_ip)) ip_count++;
		}
	}
	return ip_count;
}
static const g_anim_libs[][13] =
{
	"attractors","BAR", "BASEBALL","bd_fire", "BEACH", "BENCHPRESS","bf_injection","biked","bikeh","bikeleap","bikes", "BLOWJOBZ", "BOMBER",
	"BSKTBALL", "CAMERA", "CARRY", "COP_AMBIENT", "CRACK", "CRIB",
	"DANCING", "DEALER", "FOOD", "GANGS", "GHANDS", "GRAVEYARD", 
	"INT_HOUSE", "INT_OFFICE", "INT_SHOP", "JST_BUISNESS", "KISSING", "LOWRIDER",
	"MEDIC", "MISC", "ON_LOOKERS", "OTB", "PARK", "PAULNMAC",
	"PED", "POLICE", "RAPPING", "RIOT", "SHOP", "SMOKING", "SWAT", "SWEET"
};
stock PreLoadPlayerAnims(playerid)
{
	for(new idx; idx < sizeof g_anim_libs; idx ++)
	{
		PreloadAnimLib(playerid, g_anim_libs[idx]);
	}
	return 1;
}
stock PreloadAnimLib(playerid, animlib[])
{
   ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0);
   return 1;
}
stock OnInteractionsClick(playerid, eventid) {
    House_InteractionsClick(playerid, eventid);
    return 1;
}
CMD:giveslot(playerid) {
    SendClientMessage(playerid, -1, "yes");
    pInfo[playerid][pHomeSlots]++;
}
stock SavePlayerAcc(playerid) {
	SavePlayerInventory(playerid);
	SavePlayerInventory(playerid,0);
	return true;
}
CMD:gmx(playerid) {
	if(!CheckAdmin(playerid,8)) return 1;
	SendRconCommand("gmx");
	return 1;
}