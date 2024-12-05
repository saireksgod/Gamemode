#define MAX_HOUSE 500
#define IsBuyHouse(%0)			(g_houses[%0][hOwnerID] > 0) 

enum hInfo {
    hSqlID,
    hPrice,
    hOwnerID,
    hOwnerName[MAX_PLAYER_NAME],
    hImprovements,
    hRentDate,
    hRentPrice,
    hLock,
    hType,
    Float:hPos[3],
    Float:hExitPos[4],
    hPickup,
    hIcon,
    hSphere,
    hESphere
}

enum hTypeS {
    hName[32],
    Float:hInteriorP[4],
    hInterior,
    hRooms
}

new g_houses[MAX_HOUSE][hInfo];
new g_player_house[MAX_PLAYERS];
new g_listitem_h[15];
new g_type_houses[7][hTypeS] = {
    {"Деревенский дом", {2346.3789, -2459.9546, 1199.3516, 269.3445}, 2, 1},
    {"Эконом класс", {-2506.7422,-2802.6072,1049.8594, 359.3930}, 5, 3},
    {"Низкий класс", {2344.7966, -2460.0222, 999.3516, 273.5191}, 2, 3},
    {"Средний класс", {435.5241, 1316.0438, 1615.5300, 358.1994}, 3, 4}, 
    {"VIP класс", {1604.4670, -411.6531, 1051.0000, 0.0}, 10, 5},
    {"Премиум класс+", {-1707.0907, 2752.7971, 1001.0391, 180.5050}, 4, 2}, 
    {"Элитный класс", {-2546.2422, -1248.9615, 1001.0000, 268.9145}, 4, 5}
};

stock LoadHouse() {
    new Cache:result = mysql_query(mysql, "SELECT * FROM houses");
    
    new rows = cache_num_rows();
    if(!rows) return cache_delete(result),print(!"[Houses] Error to load");

    for(new i; i < rows; i++) {
        g_houses[i][hSqlID] = cache_get_field_content_int(i, "id");
        g_houses[i][hPrice] = cache_get_field_content_int(i, "price");
        g_houses[i][hOwnerID] = cache_get_field_content_int(i, "owner_id");
        if(g_houses[i][hOwnerID] == -1) format(g_houses[i][hOwnerName],18,"Государство");
        else cache_get_field_content(i, "owner_name", g_houses[i][hOwnerName]);
        g_houses[i][hImprovements] = cache_get_field_content_int(i, "improvements");
        g_houses[i][hRentDate] = cache_get_field_content_int(i, "rent_date");
        g_houses[i][hRentPrice] = cache_get_field_content_int(i, "rent_price");
        g_houses[i][hLock] = cache_get_field_content_int(i, "lock");
        g_houses[i][hType] = cache_get_field_content_int(i, "type");
        new pos[36];
        cache_get_field_content(i, "pos", pos);
        sscanf(pos, "P<,>fff", g_houses[i][hPos][0], g_houses[i][hPos][1], g_houses[i][hPos][2]);
        pos[0] = EOS;
        cache_get_field_content(i, "exit_pos", pos);
        sscanf(pos,"p<,>ffff", g_houses[i][hExitPos][0], g_houses[i][hExitPos][1], g_houses[i][hExitPos][2], g_houses[i][hExitPos][3]);

        UpdateHouseView(i, 1);
        g_houses[i][hSphere] = CreateDynamicSphere(g_houses[i][hPos][0], g_houses[i][hPos][1], g_houses[i][hPos][2], 3.0, 0, 0, -1);
        new type = g_houses[i][hType];
        g_houses[i][hESphere] = CreateDynamicSphere(g_type_houses[type][hInteriorP][0], g_type_houses[type][hInteriorP][1], g_type_houses[type][hInteriorP][2], 3.0, 0, 0, -1);
    }
    cache_delete(result);
    return 1;
}

stock UpdateHouseView(houseid, load = 0) {
    if(load == 1){
        // if(IsValidPickup(g_houses[houseid][hPickup])) {
        //     DestroyPickup(g_houses[houseid][hPickup]);
        // }

        if(IsValidDynamicMapIcon(g_houses[houseid][hIcon])) {
            DestroyDynamicMapIcon(g_houses[houseid][hIcon]);
        }
    }
    g_houses[houseid][hPickup] = CreatePickup((IsBuyHouse(houseid) ? 1272 : 1273), 23, g_houses[houseid][hPos][0], g_houses[houseid][hPos][1], g_houses[houseid][hPos][2]);
    g_houses[houseid][hIcon] = CreateDynamicMapIcon(g_houses[houseid][hPos][0], g_houses[houseid][hPos][1], g_houses[houseid][hPos][2], (IsBuyHouse(houseid) ? 32 : 31), 0);
}

public OnPlayerEnterDynamicArea(playerid, areaid)
{
    for(new i; i < MAX_HOUSE; i++) {
        if(areaid == g_houses[i][hSphere]) {
            g_player_house[playerid] = i;
            str_1[0] = EOS;
            format(str_1, sizeof str_1, "[%d, \"Дом №%d\", \"%s\", \"%s\", %d, %d, %d]",
            g_houses[i][hLock], i, g_houses[i][hOwnerName], g_type_houses[g_houses[i][hType]][hName],
	        g_type_houses[g_houses[i][hType]][hRooms], g_houses[i][hRentPrice],g_houses[i][hPrice]);
            SendPacket( playerid, CefShow, "Appartament", str_1);
            break;
        }
        if(areaid == g_houses[i][hESphere]) {
            SendPacket( playerid, CefShow, "Interactions", "[[0, \"Использовать дверь\"]]");
        }
    }
    #if defined House_OnPlayerEnterDynamicArea
        return House_OnPlayerEnterDynamicArea(playerid,areaid);
    #endif
}
#if defined _ALS_OnPlayerEnterDynamicArea
    #undef OnPlayerEnterDynamicArea
#else
    #define _ALS_OnPlayerEnterDynamicArea
#endif
#define OnPlayerEnterDynamicArea House_OnPlayerEnterDynamicArea
#if defined House_OnPlayerEnterDynamicArea
	forward House_OnPlayerEnterDynamicArea(playerid, areaid);
#endif

public OnPlayerLeaveDynamicArea(playerid, areaid)
{
    for(new i; i < MAX_HOUSE; i++) {
        if(areaid == g_houses[i][hSphere]) {
            g_player_house[playerid] = -1;
            SendPacket( playerid, CefHide, "Appartament");
            break;
        }
        if(areaid == g_houses[i][hESphere]) {
            SendPacket( playerid, CefHide, "Interactions");
            break;
        }
    }
    #if defined House_OnPlayerLeaveDynamicArea
        return House_OnPlayerLeaveDynamicArea(playerid,areaid);
    #endif
}
#if defined _ALS_OnPlayerLeaveDynamicArea
    #undef OnPlayerLeaveDynamicArea
#else
    #define _ALS_OnPlayerLeaveDynamicArea
#endif
#define OnPlayerLeaveDynamicArea House_OnPlayerLeaveDynamicArea
#if defined House_OnPlayerLeaveDynamicArea
	forward House_OnPlayerLeaveDynamicArea(playerid, areaid);
#endif

public OnPlayerConnect(playerid)
{
    g_player_house[playerid] = -1;
    #if defined House_OnPlayerConnect
        return House_OnPlayerConnect(playerid);
    #endif
}
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect House_OnPlayerConnect
#if defined House_OnPlayerConnect
	forward House_OnPlayerConnect(playerid);
#endif


public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys == 1024) {
        if(g_player_house[playerid] == -1) {
            SendPacket( playerid, CefHide, "Appartament");
            new houseid = g_player_house[playerid];
            if(houseid == -1) return SendClientMessage(playerid, 0xCECECEFF, !"Произошла техническая ошибка.");
            new house_type = g_houses[houseid][hType];
            str_1[0] = EOS;
            format(str_1, sizeof str_1, 
            "{FFFFFF}Тип:\t\t\t\t%s\n"\
            "Номер дома:\t\t\t%d\n\n"\
            "Количество комнат:\t\t%d\n"\
            "Стоимость:\t\t\t%s руб\n"\
            "Ежедневная квартплата:\t%s руб",
            g_type_houses[house_type][hName],houseid, g_type_houses[house_type][hRooms], g_houses[houseid][hPrice],
            g_houses[houseid][hRentPrice]);
            ShowDialog(playerid, dHouse, DIALOG_STYLE_MSGBOX, IsBuyHouse(houseid) ? ("Дом занят") : ("Дом свободен"),
            str_1, IsBuyHouse(houseid) ? ("Войти") : ("Купить"), "Отмена");
        }   

    }
    
    #if defined House_OnPlayerKeyStateChange
        return House_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
    #endif
    return 1;
}
#if defined _ALS_OnPlayerKeyStateChange
    #undef OnPlayerKeyStateChange
#else
    #define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange House_OnPlayerKeyStateChange
#if defined House_OnPlayerKeyStateChange
	forward House_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid) {
        case dHouse: {
            if(!response) return 1;
            new houseid = g_player_house[playerid];
            new house_type = g_houses[houseid][hType];
            if(houseid == -1) return SendClientMessage(playerid, 0xCECECEFF, !"Произошла техническая ошибка.");
            if(IsBuyHouse(houseid)) {
                if(g_houses[houseid][hLock] == 1) 
                    return SendClientMessage(playerid, 0xCECECEFF, !"Дом закрыт!");

                SetPlayerPos(playerid, g_type_houses[house_type][hInteriorP][0], g_type_houses[house_type][hInteriorP][1], g_type_houses[house_type][hInteriorP][2]);
                SetPlayerFacingAngle(playerid, g_type_houses[house_type][hInteriorP][3]);
                SetPlayerVirtualWorld(playerid, houseid+333);
                SetPlayerInterior(playerid, g_type_houses[house_type][hInterior]);
            }
            else {
                if(GetPlayerMoneyEx(playerid) < g_houses[houseid][hPrice]) 
                    return SendClientMessage(playerid, 0xCECECEFF, !"У вас недостаточно денег для покупки дома");

                SetPlayerPos(playerid, g_type_houses[house_type][hInteriorP][0], g_type_houses[house_type][hInteriorP][1], g_type_houses[house_type][hInteriorP][2]);
                SetPlayerFacingAngle(playerid, g_type_houses[house_type][hInteriorP][3]);
                SetPlayerVirtualWorld(playerid, houseid+333);
                SetPlayerInterior(playerid, g_type_houses[house_type][hInterior]);

                SendClientMessage(playerid, -1, !"Поздравляем! Вы приобрели дом");
                SendClientMessage(playerid, -1, !"{66CC00}Напишите {3399FF}/home {66CC00}чтобы узнать о возможностях}");

                ShowDialog(playerid, dInvalid, DIALOG_STYLE_MSGBOX, "{FFFFFF}Новый дом", 
                "{FFFFFF}Вам нужно заплатить за дом в ближайшем отделением банка {FFCD00}(/gps)", "Ок", "");

                BuyHouse(playerid, houseid);
            }
        }
        case dIDHouse: {
            if(!response) return 1;

            new houseid = g_listitem_h[listitem];
            new type = g_houses[houseid][hType];
            new type_k[16];
            if(g_houses[houseid][hImprovements] >= 3) format(type_k, 16, "Уменьшеная");
            else format(type_k, 16, "Обычная");
            SetPVarInt(playerid, #GetHouseID, houseid);
            str_1[0] = EOS;
            format(str_1, sizeof(str_1), 
            "{FFFFFF}Тип / название:\t\t\t{339999}%s\n"\
            "{FFFFFF}Номер дома:\t\t\t\t%d\n"\
            "{FFFFFF}Город / поселок:\t\t\tNone\n"\
            "{FFFFFF}Район:\t\t\t\t\t[нет данных]\n"\
            "{FFFFFF}Стоимость:\t\t\t\t%s руб\n"\
            "{FFFFFF}Дом оплачен на:<t><t><t>%d/30 дней\n"\
            "{FFFFFF}Количество комнат:<t><t><t>%d\n"\
            "{FFFFFF}Уровень улучшений:<t><t><t>%d\n"\
            "{FFFFFF}Модель домашнего авто:<t><t>{FF3333}Нет\n"\
            "{FFFFFF}Квартплата:<t><t><t><t>%d руб в день\n"\
            "{FFFFFF}Тип квартплаты:<t><t><t>%s\n"\
            "{FFFFFF}Статус:<t><t><t><t><t>%s\n\n"\
            "{669966}Для открытия панели управления вашим домом\n"\
            "нажмите кнопку Изменить",
            g_type_houses[type][hName], houseid, g_houses[houseid][hPrice], g_houses[houseid][hRentDate],
            g_type_houses[type][hRooms], g_houses[houseid][hImprovements], g_houses[houseid][hRentPrice],
            type_k, g_houses[houseid][hLock] ? ("{00FF0D}Дом открыт") : ("{FF0000}Дом закрыт"));
            ShowDialog(playerid, dHouseMenu, DIALOG_STYLE_LIST, "Информация о доме", str_1, "Изменить", "Отмена");
        }
    }
    #if defined House_OnDialogResponse
        return House_OnDialogResponse(playerid,dialogid, response, listitem, inputtext);
    #endif
}
#if defined _ALS_OnDialogResponse
    #undef OnDialogResponse
#else
    #define _ALS_OnDialogResponse
#endif
#define OnDialogResponse House_OnDialogResponse
#if defined House_OnDialogResponse
	forward House_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif

stock BuyHouse(playerid, houseid) {
    g_houses[houseid][hOwnerID] = GetPlayerAccountID(playerid);
    pInfo[playerid][pHomeUseSlot]++;
    format(g_houses[houseid][hOwnerName], MAX_PLAYER_NAME, pInfo[playerid][P_NAME]);
    g_houses[houseid][hImprovements] = 0;
    g_houses[houseid][hLock] = 0;
    str_q[0] = EOS;
    format(str_q, sizeof(str_q), "UPDATE houses SET owner_id = %d, owner_name = '%s', improvements = 0, lock = 0 WHERE id=%d", 
    g_houses[houseid][hOwnerID], g_houses[houseid][hOwnerName], houseid);
    mysql_tquery(mysql, str_q);
    UpdateHouseView(houseid, 1);
}

stock House_InteractionsClick(playerid, eventid) {
    if(eventid == 0) {
        new houseid = g_player_house[playerid];
        SetPlayerPos(playerid, g_houses[houseid][hExitPos][0], g_houses[houseid][hExitPos][1], g_houses[houseid][hExitPos][2]);
        SetPlayerFacingAngle(playerid, g_houses[houseid][hExitPos][3]);
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerInterior(playerid, 0);
        g_player_house[playerid] = -1;
    }
}

CMD:home(playerid) {
    str_q[0] = EOS;
    format(str_q, sizeof(str_q), "SELECT * FROM houses WHERE owner_id=%d", GetPlayerAccountID(playerid));
    mysql_query(mysql, str_q);

    new rows = cache_num_rows();
    if(!rows)
        return SendClientMessage(playerid, 0xCECECEFF, !"У вас нету дома");
    str_1[0] = EOS;
    for(new i; i < rows; i++) {
        new ids = cache_get_field_content_int(i, "id");
        format(str_1, sizeof(str_1), "%s{FFFFFF}-Дом: %d\n", str_1, ids);
        g_listitem_h[i] = ids;
    }

    ShowDialog(playerid, dIDHouse, DIALOG_STYLE_LIST, "{FFCD00}Выберите дом", str_1, "Выбрать", "Отмена");
    return 1;
}
