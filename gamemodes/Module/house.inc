enum E_HOUSE_DATA
{
    H_SQL_ID,
    H_OWNER_ID,
    H_OWNER_NAME[MAX_PLAYER_NAME],
    //------------------------------
    H_TYPE,
    H_PRICE,
    H_RENT_PRICE,
    H_RENT_DATA,
    H_LOCK_STATUS,
    H_IMPROVEMENTS,
    //------------------------------
    H_MAP_ICON,
    H_ENTER_PICKUP,
    H_HOUSE_SHPERE,
    //------------------------------
    Float:H_ENTER_POS[3],
    Float:H_EXIT_POS[4],
    Float:H_VEHICLE_POS[4]
};

enum E_HOUSE_STRUCT
{
    H_NAME[32],
    H_ROOMS,
    H_INTERIOR,
    Float:H_ENTER_POS[4]
};

enum E_IMPROVEMENTS_STRUCT
{
    E_IMPROVEMENTS_NAME[24],
    E_IMPROVEMENTS_PRICE
};

// --------------------------------------------------------------------

static gHouseImprovemets[][E_IMPROVEMENTS_STRUCT] =
{
    {"кровать", 14_500},
    {"совместное проживание", 60_000},
    {"оформление субсидии", 100_000},
    {"шкаф для вещей", 100_000},
    {"холодильник", 50_000},
    {"стиральная машина", 120_000},
    {"домашняя аптечка", 135_000},
    {"гардероб.", 500_000}
};

static gHouseStruct[][E_HOUSE_STRUCT] = 
{
    {"Деревенский дом", 1, 2, {2346.3789, -2459.9546, 1199.3516, 269.3445}},
    {"Эконом класс", 3, 5, {-2506.7422,-2802.6072,1049.8594, 359.3930}},
    {"Низкий класс", 3, 2, {2344.7966, -2460.0222, 999.3516, 273.5191}},
    {"Средний класс", 4, 3, {435.5241, 1316.0438, 1615.5300, 358.1994}}, 
    {"VIP класс", 5, 10, {1604.4670, -411.6531, 1051.0000, 0.0}},
    {"Премиум класс+", 2, 4, {-1707.0907, 2752.7971, 1001.0391, 180.5050}}, 
    {"Элитный класс", 5, 4, {-2546.2422, -1248.9615, 1001.0000, 268.9145}}
};

const MAX_HOUSE = 50;
static gHouseData[MAX_HOUSE][E_HOUSE_DATA];

/* mysql_tquery(mysql, "SELECT ID,OwnerID,OwnerName,Type,Price,RentPrice,Improvements,EnterPos,ExitPos,VehiclePos,RentData FROM House"); */
// --------------------------------------------------------------------
CMD:house(playerid)
{
    ShowPlayerHouse(playerid, dIDHouse);
    return true;
}

CMD:sellhome(playerid)
{
    ShowPlayerHouse(playerid, dIDSellHouse);
    return true;
}
// --------------------------------------------------------------------
public:LoadHouseData()
{
    if(!cache_num_rows()) return true;
    for(new MysqlID; MysqlID < cache_num_rows(); MysqlID++)
    {
        new HouseID = cache_get_row_int(MysqlID, 0);
        gHouseData[HouseID][H_SQL_ID] = HouseID;

        gHouseData[HouseID][H_OWNER_ID] = cache_get_row_int(MysqlID, 1);
        gHouseData[HouseID][H_RENT_DATA] = cache_get_row_int(MysqlID, 10);

        gHouseData[HouseID][H_TYPE] = cache_get_row_int(MysqlID, 3);
        gHouseData[HouseID][H_PRICE] = cache_get_row_int(MysqlID, 4);
        
        gHouseData[HouseID][H_RENT_PRICE] = cache_get_row_int(MysqlID, 5);
        gHouseData[HouseID][H_IMPROVEMENTS] = cache_get_row_int(MysqlID, 6);

        cache_get_row(MysqlID, 7, str_q), sscanf(str_q, "P<,>a<f>[3]", gHouseData[HouseID][H_ENTER_POS]);
        cache_get_row(MysqlID, 8, str_q), sscanf(str_q, "P<,>a<f>[4]", gHouseData[HouseID][H_EXIT_POS]);
        
        House_IsValidDynamicPickup(HouseID);
        cache_get_row(MysqlID, 9, str_q), sscanf(str_q, "P<,>a<f>[4]", gHouseData[HouseID][H_VEHICLE_POS]);
    }
    return true;
}
// --------------------------------------------------------------------
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    str_q[0] = EOS;
    str_1[0] = EOS;

    new HouseID = pInfo[playerid][pListItem][0];
    switch(dialogid)
    {
        case dHouseParams:
        {
            if(!response) return true;
            switch(listitem)
            {
                case 0:
                {
                    gHouseData[HouseID][H_LOCK_STATUS] = !gHouseData[HouseID][H_LOCK_STATUS];
                    SCM(playerid, -1, gHouseData[HouseID][H_LOCK_STATUS] ? "{FF6600}Дом закрыт" : "{66CC00}Дом открыт");
                }
                case 1:
                {
                    for(new idx; idx < sizeof(gHouseImprovemets); idx++)
                    {
                        format
                        (
                            str_q, sizeof(str_q), "%s{bd424d}%d уровень:<t>%s<t>%s", 
                            str_q, idx+1, gHouseImprovemets[idx][E_IMPROVEMENTS_NAME],
                            gHouseData[HouseID][H_IMPROVEMENTS] < idx ? ("{8fce00}Куплено") : ((str_d("%d", gHouseImprovemets[idx][E_IMPROVEMENTS_PRICE])))
                        );
                    }
                    ShowDialog(playerid, dHouseImprovements, DIALOG_STYLE_LIST, "Информация о доме", str_q, "Изменить", "Отмена");
                }
            }
        }
        case dHouseImprovements:
        {
            if(!response) return true;
            if(GetPlayerData(playerid, P_MONEY) < gHouseImprovemets[listitem][E_IMPROVEMENTS_PRICE])
                return SCM(playerid, 0xCECECEFF, (str_d("Для покупки %d уровня улучшений необходимо %d рублей", listitem + 1, gHouseImprovemets[listitem][E_IMPROVEMENTS_PRICE])));

            if(gHouseData[HouseID][H_IMPROVEMENTS] == listitem || gHouseData[HouseID][H_IMPROVEMENTS] > listitem)
                return SCM(playerid, 0x999999FF, !"Вы уже купили этот уровень улучшений");

            if(gHouseData[HouseID][H_IMPROVEMENTS] < listitem)
                return SCM(playerid, 0xCECECEFF, !"Этот уровень улучшений пока недоступен");

            gHouseData[HouseID][H_IMPROVEMENTS] ++ ;
            GiveMoney(playerid, gHouseImprovemets[listitem][E_IMPROVEMENTS_PRICE]);

			SCM(playerid, 0x3399FFFF, (str_d("Вы улучшили свой дом до {FFCD00}%d {3399FF}уровня", listitem)));
			SCM(playerid, 0x3399FFFF, (str_d("Вы успешно приобрели {FFCD00}%s", gHouseImprovemets[listitem][E_IMPROVEMENTS_NAME])));
        }
        case dIDSellHouse:
        {
            if(!response) return true;
            ShowDialog
            (
                playerid, dIDSellHome, DIALOG_STYLE_MSGBOX, "{FFD83D}Продажа дома",
                "{FFFFFF}Вы уверены что хотите продать свой дом государству?\n\n"\
                "Вам будет возвращено ее стоимость за вычитом 40%\n"\
                "Также будет возвращено 60% от стоимости купленных улучшений\n\n"\
                "Если Вы хотите продать дом другому игроку,\n"\
                "используйте команду /sellmyhome", "Да", "Нет"
            );
            pInfo[playerid][pListItem][0] = pInfo[playerid][pListItem][listitem];
        }
        case dIDSellHome:
        {
            if(!response) return true;
            gHouseData[HouseID][H_OWNER_ID] = 0;
            format(gHouseData[HouseID][H_OWNER_NAME], MAX_PLAYER_NAME, "Государство");

            gHouseData[HouseID][H_LOCK_STATUS] = 0;
            gHouseData[HouseID][H_IMPROVEMENTS] = 0;

            House_IsValidDynamicPickup(HouseID);
            GiveMoney(playerid, gHouseData[HouseID][H_PRICE]/2);
        }
        case dHouseMenu:
        {
            if(!response) return true;

            ShowDialog
            (
                playerid, dHouseParams, DIALOG_STYLE_LIST, "Информация о доме",
                "1. {669966}Открыть {FFFFFF}или {CC3333}закрыть {FFFFFF}дом\n2. Улучшить дом\n3. Отметить дом на GPS\n\
                4. Отметить транспорт на GPS\n5. Доставить транспорт к дому{FF6600}(4000 руб)\n6. Список арендаторов", "Изменить", "Отмена"
            );
        }
        case dIDHouse:
        {
            if(!response) return true;
            new idx = pInfo[playerid][pListItem][listitem];
            new gHouseType = gHouseData[idx][H_TYPE];

            format
            (
                str_q, sizeof(str_q), 
                "{FFFFFF}Тип / название:\t\t\t{339999}%s\n{FFFFFF}Номер дома:\t\t\t\t%d\n"\
                "{FFFFFF}Город / поселок:\t\t\tNone\n{FFFFFF}Район:\t\t\t\t\t[нет данных]\n"\
                "{FFFFFF}Стоимость:\t\t\t\t%s руб\n{FFFFFF}Дом оплачен на:<t><t><t>%d/30 дней\n"\
                "{FFFFFF}Количество комнат:<t><t><t>%d\n{FFFFFF}Уровень улучшений:<t><t><t>%d\n"\
                "{FFFFFF}Модель домашнего авто:<t><t>{FF3333}Нет\n{FFFFFF}Квартплата:<t><t><t><t>%d руб в день\n"\
                "{FFFFFF}Тип квартплаты:<t><t><t>%s\n{FFFFFF}Статус:<t><t><t><t><t>%s\n\n"\
                "{669966}Для открытия панели управления вашим домом\nнажмите кнопку Изменить",
                gHouseStruct[gHouseType][H_NAME], idx, gHouseData[idx][H_PRICE], 
                gHouseData[idx][H_RENT_DATA], gHouseStruct[gHouseType][H_ROOMS], gHouseData[idx][H_IMPROVEMENTS], 
                gHouseData[idx][H_RENT_PRICE], gHouseData[idx][H_IMPROVEMENTS] >= 3 ? "Уменьшеная" : "Обычная",
                gHouseData[idx][H_LOCK_STATUS] ? ("{00FF0D}Дом открыт") : ("{FF0000}Дом закрыт")
            );

            pInfo[playerid][pListItem][0] = idx;
            ShowDialog(playerid, dHouseMenu, DIALOG_STYLE_LIST, "Информация о доме", str_q, "Изменить", "Отмена");
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


stock House_IsValidDynamicPickup(HouseID)
{
    if(IsValidDynamicPickup(gHouseData[HouseID][H_ENTER_PICKUP]))
        DestroyPickup(gHouseData[HouseID][H_ENTER_PICKUP]),
        DestroyDynamicMapIcon(gHouseData[HouseID][H_MAP_ICON]);
        
    gHouseData[HouseID][H_ENTER_PICKUP] = CreatePickup
    (
        (gHouseData[HouseID][H_OWNER_ID] ? 1272 : 1273), 23, gHouseData[HouseID][H_ENTER_POS][0],
        gHouseData[HouseID][H_ENTER_POS][1], gHouseData[HouseID][H_ENTER_POS][2], 0
    );
    gHouseData[HouseID][H_MAP_ICON] = CreateDynamicMapIcon
    (
        gHouseData[HouseID][H_ENTER_POS][0], gHouseData[HouseID][H_ENTER_POS][1], 
        gHouseData[HouseID][H_ENTER_POS][2], (gHouseData[HouseID][H_OWNER_ID] ? 1272 : 1273), 0
    );
    return true;
}

stock ShowPlayerHouse(playerid, dialogid)
{
    str_q[0] = EOS; 
    static gHouseId = 0;
    for(new HouseID; HouseID < MAX_HOUSE; HouseID++)
    {
        if(gHouseData[HouseID][H_OWNER_ID] == GetPlayerAccountID(playerid))
        {
            format(str_q, sizeof(str_q), "%s{FFFFFF}-Дом: %d\n", str_q, HouseID);
            pInfo[playerid][pListItem][gHouseId] = HouseID;
            gHouseId++;
        }
    }
    ShowDialog(playerid, dialogid, DIALOG_STYLE_LIST, "{FFCD00}Выберите дом", str_q, "Выбрать", "Отмена");
}
// --------------------------------------------------------------------