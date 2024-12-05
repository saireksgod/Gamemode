#define MySQL_Host 								"127.0.0.1"
#define MySQL_User 								"gs277741"
#define MySQL_Base 								"gs277741"
#define MySQL_Pass 								"sVmazQBnLJm3"

#define GameMode 								"Radmir v0.1"
#define ServerSite 								"vk.com/vjope"
#define ServerName 								"Radmir RolePlay | Сервер: 01"
#define ServerMap 								"Russia"

#define ServerNumber 							"1"
#define ServerHalloween 						"1"
#define ServerNewYear 							"0"
#define ServerPasha 							"0"
#define ServerBonus 							"150000000"

new mysql;

public OnGameModeInit()
{
    mysql = mysql_connect(MySQL_Host, MySQL_User, MySQL_Base, MySQL_Pass);
	mysql_set_charset("cp1251");

	if(mysql_errno() == 0)
		print("Подключение к базе данных удалось");

	else return printf("Подключение к базе данных не удалось [Неизвестная ошибка. Код ошибки: %d]", mysql_errno());

    #if defined SET_OnGameModeInit
        return SET_OnGameModeInit();
    #endif
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit SET_OnGameModeInit
#if defined SET_OnGameModeInit
	forward SET_OnGameModeInit();
#endif
public: CC_OnDialogResponse(playerid,const dest[]) 
{
	if(!IsPlayerLogged(playerid) || !IsPlayerConnected(playerid)) return 0;
	
	extract dest-> new dialogid, response, listitem, string:inputtext[160];else return 1;
	static inputtextsave[160];
	inputtextsave[0] = EOS;
	for(new i; i < strlen(inputtext); i++)
	{
	    switch(inputtext[i])
	    {
	        case 'A'..'Z', 'a'..'z', 'А'..'Я', 'а'..'я', '0'..'9', ' ', '>', '<', '(', ')', '/', '+', '-','_', '?', '!', '.', ',', '@': continue;
	        default: inputtext[i]=' ';
	    }
	}
	if(strlen(inputtext)) mysql_escape_string(inputtext, inputtextsave);
	return OnDialogResponse(playerid, dialogid, response, listitem, inputtextsave);
}
// public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
// {
//    	#if defined SET_OnDialogResponse
//         return SET_OnDialogResponse(playerid,dialogid, response, listitem, inputtextsave);
//     #endif
// }
// #if defined _ALS_OnDialogResponse
//     #undef OnDialogResponse
// #else
//     #define _ALS_OnDialogResponse
// #endif
// #define OnDialogResponse SET_OnDialogResponse
// #if defined SET_OnDialogResponse
// 	forward SET_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
// #endif