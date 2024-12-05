#define ID_CEF_RPC			 				215
enum CefStyle {
	s_CefNone,
	s_CefInterface = 2,
	s_CefPlate = 32
};
enum CefType {
	CefNone,
	CefUpdate = 2,
	CefXz = 3,
	CefShow = 4,
	CefHide = 5,
	CefNumber = 6,
};
// public OnIncomingRawPacket(playerid, packetid, BitStream:bs)
// {
// 	printf("RawPacket: %d | %d",playerid,packetid);
// 	if(packetid == 215)
// 	{

// 	}
// 	return 1;
// }
// public OnIncomingRPC(playerid, rpcid, BitStream:bs)
// {
// 	printf("IncomingRPC: %d | %d",playerid,rpcid);
// 	return 1;
// }
public OnIncomingPacket(playerid, packetid, BitStream:bs)
{
	switch (packetid)
	{
		case 207:
		{
			if(!IsPlayerLogged(playerid) && (!IsPlayerInRangeOfPoint(playerid, 100.0, 201.4014, 2774.1199, 22.4900) || !IsPlayerInRangeOfPoint(playerid, 10.0, 0.0, 0.0, 0.0)))
			{
				Kick:(playerid);
				return 0;
			}
		}
		case ID_CEF_RPC:
		{
			new bytes,style, types;
			BS_GetNumberOfBytesUsed(bs, bytes);
			if(bytes < 6) return 0;
			
			// new ida;
			// str_1[0] = EOS;
			// for(new i; i < bytes; i++) {
			// 	BS_ReadUint8(bs,ida);
			// 	format(str_1,sizeof str_1,"%s%d,",str_1,ida);}
			// printf("\n%s",str_1);

			// BS_ResetReadPointer(bs);
			BS_IgnoreBits(bs, 8);
			BS_ReadUint16(bs, style);
			BS_ReadUint32(bs, types);
			if(style == 29)
			{
				foreach(new i: Player)
				{
					if(i == playerid) continue;
					SendPacket_Chat(i, playerid, types);
				}
			}
			if(style == 1) {
				if(GetPlayerStateLogged(playerid) != 0) return 1;
				static hardware_str[250];
				new mobile;
				BS_ReadUint8(bs, mobile);
				BS_ReadString32(bs, hardware_str);
				SetPlayerData(playerid,P_MOBILE,mobile);

				printf("[CONNECTION] Name: %s[%d] | Hardware: %s | Device: %s | Type: %d", PN(playerid),playerid, hardware_str, mobile == 1 ? ("Hassle") : ("Radmir"),types);
				GetHardwareIDBanned(playerid, hardware_str);
			}
			if(style == 2) {

				new call[64 + 1];
				BS_ReadString32(bs, call);
				SCM(playerid,-1,call);
				new id = SearchCefPublic(call);
				ShowCefPublic(playerid, id, bs);
			}
		}
	}
	return 1;
}
enum Interfaces {
	IF_NONE,
	IF_AUTH,
	IF_INVENTORY,
}
new PlayerInterfaces[MAX_PLAYERS][Interfaces];

enum CefInterfaceStruct {
	CI_NAME[24+6+3],
	Interfaces:CI_TYPE,
}
static const CefInterface[][CefInterfaceStruct] = {
	{"None",Interfaces:IF_NONE},
	{"Authorization",Interfaces:IF_AUTH},
	{"InventoryNew",Interfaces:IF_INVENTORY}
};
stock GetInterfaceID(const name[]) {
	for(new i; i<sizeof CefInterface;i++) if(!strcmp(name,CefInterface[i][CI_NAME],true)) return i;
	return 0;
}


#define MAX_CEF_PARAMS 6
enum CefPublicStruct {
    CP_ID,
    CP_PRIVATE, 
    CP_NAME[24+6+3],
	CP_CALLBACK[36],
    CP_LOAD[MAX_CEF_PARAMS]
};

static const CefPublic[][CefPublicStruct] = {
    {0, -1, "EndedInitializeBrowser", "EndedInitializeBrowser", {-1}},
    {1, -1, "OnDialogResponse", "CC_OnDialogResponse", {0, 0, 0, 1, -1}},
    {2, -1, "OnAuthorizationStart", "OnAuthorizationStart", {1, -1}},
    {3, -1, "OnAuthorizationCode", "OnAuthorizationCode", {1, -1}},
    {4, -1, "OnRegistrationBonuses", "OnRegistrationBonuses", {1, -1}},
    {5, -1, "OnRegistrationData", "OnRegistrationData", {1, 1, -1}},
    {6, -1, "OnRegistrationCharacter", "OnRegistrationCharacter", {0, 0, 0, -1}},
    {7, -1, "OnInteractionsClick", "OnInteractionsClick", {0, -1}},
    {8, -1, "OnInventoryDisplayChange", "OnInventoryDisplayChange", {-1}},
    {9, -1, "OnItemsInterfaceClose", "OnItemsInterfaceClose", {-1}},
    {10, -1, "OnInventoryItemMove", "OnInventoryItemMove", {0, 0, 0, 0, 0,-1}},
    {11, -1, "OnInventoryItemUse", "OnInventoryItemUse", {0, 0, -1}},
    {12, -1, "OnInventoryItemDrop", "OnInventoryItemDrop", {0, 0, 0, -1}},
    {13, -1, "OnInventoryItemTake", "OnInventoryItemTake", {0, 0, 0, -1}},
    {14, -1, "OnInventoryItemGive", "OnInventoryItemGive", {0, 0, 0, -1}},
    {15, -1, "OnInventoryItemSell", "OnInventoryItemSell", {0, 0, -1}},
    {16, -1, "OnInventoryItemUse", "OnInventoryItemUse", {0, 0, -1}},
    {17, -1, "AY_OnPlayerEdit", "AY_OnPlayerEdit", {0, 0, -1}},
    {18, -1, "I_OnPlayerFetchSkateboard", "I_OnPlayerFetchSkateboard", {0, 0, -1}},
    {19, -1, "Fishing_RemoveFishingLine", "Fishing_RemoveFishingLine", {0, 0, -1}},
    {20, -1, "OnPlayerClientSideKey", "OnPlayerClientSideKey", {0,-1}},
    {21, -1, "OnPlayerDeviceLost", "OnPlayerDeviceLost", {-1}},//אפך
    {22, -1, "OnPlayerDeviceRestore", "OnPlayerDeviceRestore", {-1}}//גûרוכ טח אפך
};
stock SearchCefPublic(const call[])
{
	for(new i; i < sizeof CefPublic; i++) if(!strcmp(call, CefPublic[i][CP_NAME])) return i;
	return -1;
}
stock ShowCefPublic(playerid, const id, BitStream:bsd) {
	if(id < 0 || id >= sizeof(CefPublic)) return 1;

	format(str_1,sizeof str_1,"");
	format(str_q,sizeof str_q,"");

	new CefLoad_INT;
	for(new i,j=0;i < MAX_CEF_PARAMS && CefPublic[id][CP_LOAD][i] != -1;i++)
	{
		if(j == 0) BS_IgnoreBits(bsd, 40),j=1;
		else BS_IgnoreBits(bsd, 8);
		if(CefPublic[id][CP_LOAD][i] == 0) BS_ReadUint32(bsd,CefLoad_INT),format(str_1,sizeof str_1,"%s%d ",str_1,CefLoad_INT);
		else BS_ReadString32(bsd,str_q),format(str_1,sizeof str_1,"%s%s ",str_1,(isnull(str_q)) ? ("None") : (str_q));
	}
	if(strlen(str_1) > 0) strdel(str_1, strlen(str_1) - 1, strlen(str_1));
	CallLocalFunction(CefPublic[id][CP_CALLBACK],"ds",playerid,isnull(str_1) ? ("\1") : (str_1));
	return 1;
}

stock GameText(playerid, const string[], time, style)
{
	f(str_1, sizeof str_1, "interface('GameText').add('[%d,\"%s\",%d,0,-1,1]')", style, string, time);
	SendPacket(1,playerid, CefUpdate, str_1);
 	SendPacket(1, playerid, CefShow, "GameText");
	return 1;
}

stock ShowDialog(playerid, dialogid, style,const caption[],const info[],const button1[],const button2[],const Zagalovok[]="", BackButton=0, FrontButton=0, IDButton=0)
{
	static str_d[4024];
	str_d[0] = '\0';
	strcat(str_d, info);
	for (new i = strfind(str_d, "\n", true); i != -1; i = strfind(str_d, "\n", true, i)) {
		strdel(str_d, i, i + 1);
		strins(str_d, "<n>", i);
	}
	format(str_d, sizeof str_d, "window.addDialogInQueue('[%i,%i,\"%s\",\"%s\",\"%s\",\"%s\",%d,%d]', \"%s\", %d)", dialogid, style, caption,Zagalovok, button1, button2, BackButton,FrontButton,str_d,IDButton);
	SendPacket(1,playerid, CefUpdate, str_d);
	return 1;
}
stock SendPacket_Chat(playerid, g, status)
{
	new BitStream:bsn = BS_New();
	BS_WriteValue(bsn, PR_UINT8, ID_CEF_RPC);
	BS_WriteValue(bsn, PR_UINT16, 29);
	BS_WriteValue(bsn, PR_UINT32, g);
	BS_WriteValue(bsn, PR_UINT32, status);
	PR_SendPacket(bsn, playerid);
	return BS_Delete(bsn);
}
stock SendPacket(view, playerid, CefType:type, const string[], const string2[]="")
{
	if(type == CefHide || type == CefShow) {
		new id = GetInterfaceID(string);
		if(id) PlayerInterfaces[playerid][CefInterface[id][CI_TYPE]] = type == CefShow ? 1 : 0;
	}
    new BitStream:bsn = BS_New();
    BS_WriteValue(bsn, 
		PR_UINT8, 215,
		PR_UINT16, 2,
		PR_UINT32, _:type,
		PR_UINT8, view
	);
	BS_WriteValue(bsn,PR_UINT32, strlen(string),PR_STRING, string, strlen(string));

	if(view == 2) BS_WriteValue(bsn,PR_UINT32, strlen(string2),PR_STRING, string2, strlen(string2));

    PR_SendPacket(bsn, playerid);
    return BS_Delete(bsn);
}
stock SendPacket_Plate(playerid, vehicleid, type, number[], region[])
{
    new BitStream:bsn = BS_New();

    BS_WriteValue(bsn, PR_UINT8, ID_CEF_RPC,
		PR_UINT16, _:s_CefPlate,
		PR_UINT32, vehicleid,
		PR_UINT32, 0,
		PR_UINT16, 256,
		PR_UINT32, type
	);
	BS_WriteValue( bsn,
		PR_UINT32, strlen(number),
		PR_STRING, number, strlen(number)
	);
	BS_WriteValue(
		bsn,
		PR_UINT32, strlen(region),
		PR_STRING, region, strlen(region)
	);
    PR_SendPacket(bsn, playerid);
	return BS_Delete(bsn);
}
stock SetPlayerGameStateConnection(playerid)
{
    new BitStream:bsn = BS_New();
    BS_WriteValue(bsn, PR_UINT8, 33);
	PR_SendPacket(bsn, playerid);
	BS_Delete(bsn);
	return 1;
}
public: EndedInitializeBrowser(playerid,const dest[]) return SendPacket(1,playerid, CefUpdate, "confirmBrowserInitialize()");