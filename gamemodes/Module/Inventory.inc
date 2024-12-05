enum EItem_struct {
    ITEM_ID,
    ITEM_NAME[42],
    ITEM_PRICE,
    Float:Item_Weight
}
new const ItemsInfo[][EItem_struct] = {
    {0, "Деньги", 500, 0.5,1212},
    {1, "Канистра", 500, 0.5,1650},
    {2, "Аптечка", 500, 0.5,1241},
    {3, "Мёртвый олень", 500, 0.5,19315},
    {4, "Буксировочный трос", 500, 0.5,2969},
    {5, "Огнетушитель", 500, 0.5,366},
    {6, "Мешок с деньгами", 500, 0.5,1550},
    {7, "Нож", 500, 0.5,335},
    {8, "Бита", 500, 0.5,336},
    {9, "Катана", 500, 0.5,339},
    {10, "Бензопила", 500, 0.5,341},
    {11, "Коктейль Молотова", 500, 0.5,344},
    {12, "Пистолет", 500, 0.5,346},
    {13, "Электрошокер", 500, 0.5,347},
    {14, "Дробовик", 500, 0.5,349},
    {15, "Обрез", 500, 0.5,350},
    {16, "Боевой дробовик", 500, 0.5,351},
    {17, "УЗИ", 500, 0.5,352},
    {18, "MP5", 500, 0.5,353},
    {19, "Desert Eagle", 500, 0.5,348},
    {20, "M4", 500, 0.5,356},
    {21, "AK-47", 500, 0.5,355},
    {22, "Снайперская винтовка", 500, 0.5,358},
    {23, "РПГ", 500, 0.5,359},
    {24, "Гранаты", 500, 0.5,342},
    {25, "Наркотики", 500, 0.5,2969},
    {26, "Патроны", 500, 0.5,3016},
    {27, "Металл", 500, 0.5,2969},
    {28, "Контрабанда", 500, 0.5,2969},
    {29, "Отмычка", 500, 0.5,2969},
    {30, "Ящик с патронами", 500, 0.5,2969},
    {31, "Кастет", 500, 0.5,331},
    {32, "Дубинка", 500, 0.5,334},
    {33, "Двойной дилдо", 500, 0.5,321},
    {34, "Малый дилдо", 500, 0.5,323},
    {35, "Вибратор", 500, 0.5,322},
    {36, "Вибратор 2", 500, 0.5,324},
    {37, "Цветы", 500, 0.5,325},
    {38, "Топор", 500, 0.5,326},
    {39, "Камера", 500, 0.5,367},
    {40, "Парашют", 500, 0.5,371},
    {41, "Предмет интерьера", 500, 0.5,2969},// extra icon
    {42, "Воздушка", 500, 0.5, 357},
    {43, "Слезоточивый газ", 500, 0.5, 365},
    {44, "Ремонтный комплект", 500, 0.5, 2969},
    {45, "Взрывпакет", 500, 0.5, 363},
    {46, "Детонатор", 500, 0.5, 364},
    {47, "Обычный нож", 500, 0.5, 10478},
    {48, "Позолоченный нож", 500, 0.5, 10479},
    {49, "Рог изобилия", 500, 0.5, 10480},
    {50, "Картина с пейзажем", 500, 0.5, 10481},
    {51, "Картина с пятнами", 500, 0.5, 10482},
    {52, "Мушкет", 500, 0.5, 10483},
    {53, "Позолоченный мушкет", 500, 0.5, 10484},
    {54, "Старый телефон", 500, 0.5, 10485},
    {55, "Оленьи рога", 500, 0.5, 10486},
    {56, "Статуэтка (человек)", 500, 0.5, 10487},
    {57, "Стутуэтка (мамонт)", 500, 0.5, 10488},
    {58, "Статуэтка (луна)", 500, 0.5, 10489},
    {59, "Самурайский меч", 500, 0.5, 10490},
    {60, "Настольная лампа", 500, 0.5, 10491},
    {61, "Кувшин", 500, 0.5, 10492},
    {62, "Корона", 500, 0.5, 10493},
    {63, "Золотая корона", 500, 0.5, 10494},
    {64, "Шкатулка из дерева", 500, 0.5, 10495},
    {65, "Шкатулка с позолотой", 500, 0.5, 10496},
    {66, "Гитара", 500, 0.5, 10497},
    {67, "Рокерская гитара", 500, 0.5, 10498},
    {68, "Холодильник", 500, 0.5, 10499},
    {69, "Холодильник (черный)", 500, 0.5, 10500},
    {70, "Микроволновка", 500, 0.5, 10501},
    {71, "Стиральная машинка", 500, 0.5, 10502},
    {72, "Утюг", 500, 0.5, 10503},
    {73, "Утюг", 500, 0.5, 10504},
    {74, "Ноутбук", 500, 0.5, 10505},
    {75, "Сломанный ноутбук", 500, 0.5, 10506},
    {76, "Смартфон", 500, 0.5, 10507},
    {77, "Телевизор", 500, 0.5, 10508},
    {78, "Разбитый телевизор", 500, 0.5, 10509},
    {79, "Пылесос", 500, 0.5, 10510},
    {80, "XBOX ONE", 500, 0.5, 10511},
    {81, "PS4", 500, 0.5, 10512},
    {82, "Большая плазма", 500, 0.5, 10513},
    {83, "Коробка с микрофоном", 500, 0.5, 10514},
    {84, "Музыкальный центр", 500, 0.5, 10515},
    {85, "Антикварный костюм", 500, 0.5, 10816},
    {86, "Антикварный костюм", 500, 0.5, 10816},
    {87, "Антикварный костюм", 500, 0.5, 10816},
    {88, "Антикварный костюм", 500, 0.5, 10816},
    {89, "Антикварный костюм", 500, 0.5, 10816},
    {90, "Антикварный костюм", 500, 0.5, 10816},
    {91, "Кепка Radmir", 500, 0.5, 10516},
    {92, "Серая бандана", 500, 0.5, 10517},
    {93, "Темная бандана", 500, 0.5, 10518},
    {94, "Черная бандана", 500, 0.5, 10519},
    {95, "Зеленая бандана", 500, 0.5, 10520},
    {96, "Сумка с ремнем", 500, 0.5, 10521},
    {97, "Портфель", 500, 0.5, 10522},
    {98, "Куфия", 500, 0.5, 10523},
    {99, "Автомобильный номер", 500, 0.5,2969},
    {100, "Одежда", 500, 0.5,10816},
    {101, "Слезоточивые гранаты", 500, 0.5,1672},
    {102, "Ящик с патронами", 500, 0.5,10702},
    {103, "Сломанный банкомат", 500, 0.5,10703},
    {104, "Старое сиденье", 500, 0.5,10704},
    {105, "Черное сиденье", 500, 0.5,10705},
    {106, "Гоночное сиденье", 500, 0.5,10706},
    {107, "Телефон Brick 3310", 500, 0.5,10707},
    {108, "Телефон Brick", 500, 0.5,10708},
    {109, "Телефон Galaxy", 500, 0.5,10709},
    {110, "Телефон Orange", 500, 0.5,10710},
    {111, "Золотой рубль", 500, 0.5,10711},
    {112, "Золотые два рубля", 500, 0.5,10712},
    {113, "Золотой червонец", 500, 0.5,10713},
    {114, "Золотые пятьдесят", 500, 0.5,10714},
    {115, "Системный блок", 500, 0.5,10715},
    {116, "Отмычки", 500, 0.5,10716},
    {117, "Руль TAZ 2101", 500, 0.5,10717},
    {118, "Руль GTR", 500, 0.5,10718},
    {119, "Руль Sternchen AMG", 500, 0.5,10719},
    {120, "Старый сейф", 500, 0.5,10720},
    {121, "Сломанный проигрыватель", 500, 0.5,10721},
    {122, "Диски", 500, 0.5,10722},
    {123, "Ноутбук Apple", 500, 0.5,10723},
    {124, "Металлолом", 500, 0.5,10805},
    {125, "Лопата", 500, 0.5,337},
    {126, "Батареи", 500, 0.5,10806},
    {127, "Металлоискатель B.H Junior", 500, 0.5,10803},
    {128, "Металлоискатель Garrett 250", 500, 0.5,10804},
    {129, "Мертвая утка", 500, 0.5,10808},
    {130, "Надувная лодка", 500, 0.5,10809},
    {131, "Свисток на уток", 500, 0.5,10810},
    {132, "Удочка", 500, 0.5,10811},//icon
    {133, "Улов", 500, 0.5,10812},//icon
    {134, "Кусочки хлеба", 500, 0.5,10813},
    {135, "Лягушки", 500, 0.5,10814},
    {136, "Кузнечики", 500, 0.5,10815},
    {137, "Рецепт отмычки", 500, 0.5,10816},
    {138, "Тряпка", 500, 0.5,10817},
    {139, "Дерево", 500, 0.5,10818},
    {140, "Бутылка", 500, 0.5,10819},
    {141, "Шприц", 500, 0.5,10820},
    {142, "Бинт", 500, 0.5,10821},
    {143, "Жгут", 500, 0.5,10822},
    {144, "Порох", 500, 0.5,10823},
    {145, "Крахмал", 500, 0.5,10824},
    {146, "Прицел", 500, 0.5,10825},
    {147, "Глушитель", 500, 0.5,10826},
    {148, "Сломанный iPhone", 500, 0.5,10827},
    {149, "Запчасти к iPhone", 500, 0.5,10828},
    {150, "Запчасти к ноутбуку", 500, 0.5,2969},
    {151, "Денежная печат.машинка", 500, 0.5,10829},
    {152, "Запчасти к печт.машинке", 500, 0.5,10830},
    {153, "Инструменты", 500, 0.5,10831},
    {154, "Сварка", 500, 0.5,10832},
    {155, "Колесо", 500, 0.5,10833},
    {156, "Аккумулятор", 500, 0.5,10834},
    {157, "Рецепт кастета", 500, 0.5,10815},
    {158, "Рецепт обреза", 500, 0.5,10815},
    {159, "Рецепт глюкозы", 500, 0.5,10815},
    {160, "Рецепт печат.машинки", 500, 0.5,10815},
    {161, "Стеклянная бутылка", 500, 0.5,1487},
    {162, "Солярка", 500, 0.5,1650},
    {163, "Наручные часы (корич)", 500, 0.5,2969},
    {164, "Наручные часы (белые)", 500, 0.5,2969},
    {165, "Моторное масло", 500, 0.5,10930},
    {166, "Воздушный фильтр", 500, 0.5,10931},
    {167, "Масляной фильтр", 500, 0.5,10932},
    {168, "Лейка", 500, 0.5,10939},
    {169, "Марихуанна", 500, 0.5,10943},
    {170, "Огурцы", 500, 0.5,10941},
    {171, "Помидоры", 500, 0.5,10942},
    {172, "Семена конопли", 500, 0.5,10940},
    {173, "Семена помидоров", 500, 0.5,10940},
    {174, "Семена огурцов", 500, 0.5,10940},
    {175, "Косяк", 500, 0.5,19625},
    {176, "Кристаллы", 500, 0.5,11017},
    {177, "Ящик с материалами", 500, 0.5,2969},
    {178, "Болторезы", 500, 0.5,2969},
    {179, "Материалы", 500, 0.5,2969},
    {180, "Сабвуфер", 500, 0.5,2969},
    {181, "Очки", 500, 0.5,2969},
    {182, "Бандана", 500, 0.5,2969},
    {183, "Маска", 500, 0.5,2969},
    {184, "Берет", 500, 0.5,2969},
    {185, "Шляпа", 500, 0.5,2969},
    {186, "Бочка", 500, 0.5,2969},
    {187, "Химия", 500, 0.5,2969},
    {188, "Двигатель", 500, 0.5,2969},
    {189, "Старый руль AMG", 500, 0.5,2969},
    {190, "Запчасти к рулю AMG", 500, 0.5,2969},
    {191, "Лобовое стекло", 500, 0.5,2969},
    {192, "Спутник", 500, 0.5,2969},
    {193, "Кристалл (красный)", 500, 0.5,2969},
    {194, "Кристалл (фиолетовый)", 500, 0.5,2969},
    {195, "Кристалл (зеленый)", 500, 0.5,2969},
    {196, "Кристалл (синий)", 500, 0.5,2969},
    {197, "Модель Volga", 500, 0.5,2969},
    {198, "Модель ВАЗ 2109", 500, 0.5,2969},
    {199, "Модель РАФ-2203", 500, 0.5,2969},
    {200, "Гироскутер", 500, 0.5,2969},
    {201, "Бинокль", 500, 0.5,2969},
    {202, "Телескоп", 500, 0.5,2969},
    {203, "Комиксы (Spider Man)", 500, 0.5,2969},
    {204, "Комиксы (Ninja)", 500, 0.5,2969},
    {205, "Комиксы (Bakugan)", 500, 0.5,2969},
    {206, "Клавиатура RGB", 500, 0.5,2969},
    {207, "Клавиатура", 500, 0.5,2969},
    {208, "Шахматы", 500, 0.5,2969},
    {209, "Складной зонтик", 500, 0.5,2969},
    {210, "Зонтик", 500, 0.5,2969},
    {211, "Пирамидка", 500, 0.5,2969},
    {212, "Самокат", 500, 0.5,2969},
    {213, "Фигурка пришельца", 500, 0.5,2969},
    {214, "Фигурка пони", 500, 0.5,2969},
    {215, "PSP", 500, 0.5,2969},
    {216, "Анаболики", 500, 0.5,2969},
    {217, "Противорвотное", 500, 0.5,2969},
    {218, "Запчасти к двигателю", 500, 0.5,2969},
    {219, "Сумка", 500, 0.5,2969},
    {220, "Аксессуар на пояс", 500, 0.5,2969},
    {221, "Украшение на руку", 500, 0.5,2969},
    {222, "Рюкзак", 500, 0.5,2969},
    {223, "Самовар", 500, 0.5,2969},
    {224, "Фаберже", 500, 0.5,2969},
    {225, "Часы", 500, 0.5,2969},
    {226, "Граммофон", 500, 0.5,2969},
    {227, "Кресло", 500, 0.5,2969},
    {228, "Чайник", 500, 0.5,2969},
    {229, "Статуя", 500, 0.5,2969},
    {230, "Проигрыватель", 500, 0.5,2969},
    {231, "Глобус", 500, 0.5,2969},
    {232, "Печат.машинка", 500, 0.5,2969},
    {233, "Поп-ит", 500, 0.5,2969},
    {234, "Брелок поп-ит", 500, 0.5,2969},
    {235, "Маска Гая-Фокса", 500, 0.5,2969},
    {236, "Красный нож", 500, 0.5,2969},
    {237, "Цветной нож", 500, 0.5,2969},
    {238, "Золотой кастет", 500, 0.5,2969},
    {239, "Поп-ит", 500, 0.5,2969},
    {240, "Поп-ит", 500, 0.5,2969},
    {241, "Стиральный порошок", 500, 0.5,2969},
    {242, "Рем.комплект к стир.машинке", 500, 0.5,2969},
    {243, "Конфеты", 500, 0.5,2969},
    {244, "Ёлочные украшения", 500, 0.5,2969},
    {245, "Снегоуборочная машинка", 500, 0.5,2969},
    {246, "Украшение на шею", 500, 0.5,2969},
    {247, "Наполненная лейка", 500, 0.5,10939},
    {248, "Животное", 500, 0.5,14279},//icon
    {249, "Будка для животных", 500, 0.5,12296},//icon
    {250, "Корм для животных", 500, 0.5,14350},
    {251, "Коробок спичек", 500, 0.5,2969},
    {252, "Жареная рыба", 500, 0.5,2969},
    {253, "Нелегальная продукция", 500, 0.5,14350},
    {254, "Аппарат для диагностики", 500, 0.5,14348},
    {255, "Маска", 500, 0.5,2969},
    {256, "Автосигнализация", 500, 0.5,2969},
    {257, "Лотерейный билет", 500, 0.5,2969},
    {258, "Кейс `Форсаж`", 500, 0.5,14512},
    {259, "Ключ от кейса", 500, 0.5,14511},
    {260, "Украшение на шею", 500, 0.5,2969},
    {261, "Кейс `Темные дела`", 500, 0.5,14595},
    {262, "Книга рецептов", 500, 0.5,2969},
    {263, "Плащ", 500, 0.5,2969},
    {264, "Растение (одуванчик)", 500, 0.5,2969},
    {265, "Растение (крапива)", 500, 0.5,2969},
    {266, "Растение (валериана)", 500, 0.5,2969},
    {267, "Растение (пещерный гриб)", 500, 0.5,2969},
    {268, "Плоть монстра", 500, 0.5,2969},
    {269, "Эликсир здоровья", 500, 0.5,2969},
    {270, "Эликсир силы", 500, 0.5,2969},
    {271, "Эликсир выносливости", 500, 0.5,2969},
    {272, "Кейс `Велесова ночь`", 500, 0.5,14694},
    {273, "Эликсир точности", 500, 0.5,2969},
    {274, "Зеленые кристаллы", 500, 0.5,2969},
    {275, "Акссесуар на левое плечо", 500, 0.5,2969},
    {276, "Тауметр", 500, 0.5,2969},
    {277, "Акссесуар бронежилет", 500, 0.5,2969},
    {278, "Кейс `Оперской`", 500, 0.5,14785},
    {279, "Балончик ", 500, 0.5,2969},//icon
    {280, "Напиток", 500, 0.5,2969},//Extra icon
    {281, "Трап", 500, 0.5,2969},
    {282, "Лекарство", 500, 0.5,2969},//Extra icon
    {283, "Грелка", 500, 0.5,2969},
    {284, "Кейс `Новогодний`", 500, 0.5,15711},
    {285, "Украшение для транспорта", 500, 0.5,2969},
    {286, "Бутылка", 500, 0.5,2969},
    {287, "Аксессуар на спину", 500, 0.5,2969},
    {288, "Ценная бумага", 500, 0.5,2969},
    {289, "Аксессуар в руку", 500, 0.5,2969},
    {290, "Кейс `Черное золото`", 500, 0.5,15846},
    {291, "Аксессуар на спину", 500, 0.5,2969},
    {292, "Аксессуар на ногу", 500, 0.5,2969},
    {293, "Фишка", 500, 0.5,2969},
    {294, "Нож для свежевания", 500, 0.5,2969},
    {295, "Шкура оленя", 500, 0.5,2969},
    {296, "Шкура медведя", 500, 0.5,2969},
    {297, "Шкура заяца", 500, 0.5,2969},
    {298, "Шкура кабана", 500, 0.5,2969},
    {299, "Животный жир", 500, 0.5,2969},
    {300, "Кейс `Охотничий`", 500, 0.5,15963},
    {301, "Игровая консоль", 500, 0.5,2969},
    {302, "Виниловая пластинка", 500, 0.5,2969},
    {303, "Запчасти проигрывателя", 500, 0.5,2969},
    {304, "Сломанный сабвуфер", 500, 0.5,2969},
    {305, "Запчасти сабвуфера", 500, 0.5,2969},
    {306, "Сломанный металлоискатель", 500, 0.5,2969},
    {307, "Запчасти металлоискателя", 500, 0.5,2969},
    {308, "Полотно для лопаты", 500, 0.5,2969},
    {309, "Черенок для лопаты", 500, 0.5,2969},
    {310, "Сломанный аппарата диагн-ки", 500, 0.5,2969},
    {311, "Запчасти аппарата диагн-ки", 500, 0.5,2969},
    {312, "Корпус наручных часов", 500, 0.5,2969},
    {313, "Ремешок наручных часов", 500, 0.5,2969},
    {314, "Механизм наручных часов", 500, 0.5,2969},
    {315, "Стекло наручных часов", 500, 0.5,2969},
    {316, "Мешочек для драгоценностей", 500, 0.5,2969},
    {317, "Кроссовки", 500, 0.5,2969},
    {318, "Футболка", 500, 0.5,2969},
    {319, "Джинсы", 500, 0.5,2969},
    {320, "Золотые серьги", 500, 0.5,2969},
    {321, "Бриллиант", 500, 0.5,2969},
    {322, "Проигрыватель", 500, 0.5,2969},
    {323, "Бронепластина", 500, 0.5,2969},
    {324, "Скейтборд", 500, 0.5,2969},
    {325, "Рыболовная леска", 500, 0.5,2969},
    {326, "Наживка", 500, 0.5,2969},//icon
    {327, "Осетровая икра", 500, 0.5,2969},
    {328, "Кейс `Египетская сила`", 500, 0.5,16453},
    {329, "Золотой череп", 500, 0.5,2969},
    {330, "Древняя табличка", 500, 0.5,2969},
    {331, "Канистра для воды", 500, 0.5,2969},//Extra
    {332, "Рецепт для пошива", 500, 0.5,2969},
    {333, "Известь", 500, 0.5,2969},
    {334, "Гербицид", 500, 0.5,2969},
    {335, "Компостное удобрение", 500, 0.5,2969},//Extra icon
    {336, "Семена", 500, 0.5,2969},//Extra icon
    {337, "Урожай", 500, 0.5,2969},//Extra icon
    {338, "Эликсир беcшумности", 500, 0.5,2969},
    {339, "Эликсир регенерации", 500, 0.5,2969},
    {340, "Эликсир устойчивости", 500, 0.5,2969},
    {341, "Эликсир удачи", 500, 0.5,2969},
    {342, "Планшет", 500, 0.5,2969},
    {343, "Растение (клевер)", 500, 0.5,2969},
    {344, "Кейс `Велесова ночь 2`", 500, 0.5,16664},
    {345, "Шкура белого медведя", 500, 0.5,2969},
    {346, "Растение (мох)", 500, 0.5,2969},
    {347, "Ёлочные игрушки", 500, 0.5,2969},
    {348, "Кейс `Рождественский экспресс`", 500, 0.5,16773},
    {349, "Обручальное кольцо", 500, 0.5,2969},
    {350, "Кейс `Путь воина`", 500, 0.5,16966},
    {351, "Сигареты", 500, 0.5,2969},
    {352, "Глушилка", 500, 0.5,2969},
    {353, "Заточка", 500, 0.5,2969},
    {354, "Чертеж тюнинга", 500, 0.5,2969},
    {355, "Кейс `Пиратский`", 500, 0.5,17207},
    {356, "Кейс `Проклятие`", 500, 0.5,17610},
    {357, "Киберкредиты", 500, 0.5,2969},
    {358, "Чертеж тюнинга", 500, 0.5,2969}
};
/*
const o = {
    SHOW_INVENTORY_MAIN: 0,
    SHOW_INVENTORY_GIVE: 1,
    SHOW_INVENTORY_VEHICLE: 2,
    SHOW_INVENTORY_GANG_OPG: 3,
    SHOW_INVENTORY_HOUSE: 4,
    SHOW_INVENTORY_GARAGE: 5,
    SHOW_INVENTORY_BAG: 6,
    SHOW_INVENTORY_BLACK_PROD: 7
}
*/
// //TYPEITEMS:
// // 0 - ДЕНЬГИ
// // 1 - СКИН
// // 2 - АКС
// // 3 - ПРЕДМЕТ
// // 4 - НОМЕР НА АВТО
// // 5 - Оружия
/*
1(РУС) = X666AM 35
2(КЗ) = 555AKA 5
3(BY) = 5555 AA-3
4(UA) = XXXX 6666
5(Custom) = NY PON
*/
#define MAX_INV_ITEMS           20
#define MAX_ACS_ITEMS           10

#define MAX_INV_WIGHT           66

#define SetItem(%0,%1,%2)           g_player_inv[playerid][%0][%1] = %2
#define GetItem(%0,%1)              g_player_inv[playerid][%0][%1]

#define SetItemAcs(%0,%1)           g_player_acs[playerid][%0][%1] = %2
#define GetItemAcs(%0,%1)           g_player_acs[playerid][%0][%1]

enum CONTAINERS 
{
    CONTAINER_ACS = 0,
    CONTAINER_DEFAULT = 1,
    CONTAINER_BAG = 2
}
enum INV_ITEMS_STRUCT {
    PI_TYPE,
    PI_ID,
    PI_COUNT,
    PI_STATUS,
    PI_EXTRATYPE,
    PI_EXTRANAME[33],
    Float:PI_ACSPOS[9]
}
static const inv_default[INV_ITEMS_STRUCT] = {
    -1,
    -1,
    0,
    0,
    0,
    "None",
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
};
new g_player_inv[MAX_PLAYERS][MAX_INV_ITEMS][INV_ITEMS_STRUCT];
new g_player_acs[MAX_PLAYERS][MAX_ACS_ITEMS][INV_ITEMS_STRUCT];

stock ClearPlayerInventory(playerid) {
    for(new j;j<MAX_INV_ITEMS;j++) g_player_inv[playerid][j] = inv_default;
    for(new j;j<MAX_ACS_ITEMS;j++) g_player_acs[playerid][j] = inv_default;
    return 1;
}
stock LoadInventory(playerid)
{
    str_q[0] = EOS;
    mysql_format(mysql,str_q,sizeof str_q,"SELECT * FROM items WHERE uid=%d AND container=1 LIMIT 1",GetPlayerAccountID(playerid));
    mysql_tquery(mysql,str_q,"CB_LoadInventory", "dd", playerid, 1);

    mysql_format(mysql,str_q,sizeof str_q,"SELECT * FROM items WHERE uid=%d AND container=0 LIMIT 1",GetPlayerAccountID(playerid));
    mysql_tquery(mysql,str_q,"CB_LoadInventory", "dd", playerid, 2);
    return 1;
}
public:CB_LoadInventory(playerid,punkt) {
    if(!IsPlayerConnected(playerid)) return 1;
    if(!cache_num_rows()) return 1;
    new str_ff[12],code[32];
    if(punkt == 1) {
        str_q[0] = EOS;
        for(new i;i<MAX_INV_ITEMS;i++)
        {
            format(str_ff,sizeof str_ff,"SLOT%d",i+1);
            cache_get_field_content(0,str_ff,str_q);

            sscanf(str_q,"p<;>a<d>[5]s[32]a<f>[9]",g_player_inv[playerid][i],code,g_player_inv[playerid][i][PI_ACSPOS]);
            format(g_player_inv[playerid][i][PI_EXTRANAME],32,code);
        }
    }
    if(punkt == 2) {
        str_q[0] = EOS;
        for(new i;i<MAX_ACS_ITEMS;i++)
        {
            format(str_ff,sizeof str_ff,"SLOT%d",i+1);
            cache_get_field_content(0,str_ff,str_q);

            sscanf(str_q,"p<;>a<d>[5]s[32]a<f>[9]",g_player_acs[playerid][i],code,g_player_acs[playerid][i][PI_ACSPOS]);
            format(g_player_acs[playerid][i][PI_EXTRANAME],32,code);
        }
    }
    return 1;
}
enum sInveSoshr {INV_ITEMS_STRUCT:INVLOAD_TYPE};
static const InveSoshr[][sInveSoshr] = {
    {PI_TYPE}, {PI_ID}, {PI_COUNT}, {PI_STATUS}, {PI_EXTRATYPE}
};
stock SavePlayerInventory(playerid,punkt=1) {
    if(!IsPlayerConnected(playerid)) return 1;
    format(str_q,sizeof str_q,"");
    for(new i=1, j=(punkt==1 ? MAX_INV_ITEMS : MAX_ACS_ITEMS);i<j+1;i++)
    {
        new str_tt[100];
        new str_acs[120];
        format(str_tt,sizeof str_tt,"");
        for(new k; k < sizeof InveSoshr; k++)
            format(str_tt,sizeof str_tt,"%s%d;",str_tt,punkt ? GetItem(i-1,InveSoshr[k][INVLOAD_TYPE]) : GetItemAcs(i-1,InveSoshr[k][INVLOAD_TYPE]));
        format(str_acs,sizeof str_acs,"");
        for(new k; k < 9; k++)
            format(str_acs,sizeof str_acs,"%s;%f",str_acs,punkt ? GetItem(i-1,PI_ACSPOS)[k] : GetItemAcs(i-1,PI_ACSPOS)[k]);
        if(punkt == 1) format(str_q,sizeof str_q,"%s SLOT%d='%s%s%s',",str_q,i,str_tt,GetItem(i-1,PI_EXTRANAME), str_acs);
        if(punkt == 0) format(str_q,sizeof str_q,"%s SLOT%d='%s%s%s',",str_q,i,str_tt,GetItemAcs(i-1,PI_EXTRANAME), str_acs);
    }
    strdel(str_q, strlen(str_q)-1,strlen(str_q));
    mysql_format(mysql,str_q,sizeof str_q,"UPDATE items SET%s WHERE uid=%d AND container=%d",str_q,GetPlayerAccountID(playerid),punkt);
    mysql_tquery(mysql,str_q,"");
    return 1;
}

stock GetFreeSlot(playerid)
{
    for(new i; i < MAX_INV_ITEMS; i++) if(GetItem(i, PI_ID) == -1 && GetItem(i, PI_TYPE) == -1) return i;
    return -1;
}
stock GetItemSlot(playerid,item) {
    for(new i; i < MAX_INV_ITEMS; i++) {
        if(GetItem(i, PI_ID) == -1) continue;
        if(GetItem(i, PI_ID) == item) return i;
    }
    return -1;
}
public: OnItemsInterfaceClose(playerid) return SendPacket(playerid, CefHide, "InventoryNew");
public: OnInventoryDisplayChange(playerid) {
    if(PlayerInterfaces[playerid][IF_INVENTORY]) SendPacket(playerid, CefHide, "InventoryNew");
    else OpenInventory(playerid,1);
    return 1;
}
stock OpenInventory(playerid, open=0)
{
    if(!IsPlayerConnected(playerid) || !IsPlayerLogged(playerid)) return 1;
    
    format(str_1,sizeof str_1,"");
    for(new i; i<MAX_ACS_ITEMS;i++)
    {
        if(GetItemAcs(i,PI_ID) == -1) continue;
        format(str_1,sizeof str_1,"%s[0,%d,%d,%d,\"%s\",0,%d,6.00,0],",str_1,i,GetItemAcs(i,PI_ID),GetItemAcs(i,PI_EXTRATYPE),GetItemAcs(i,PI_EXTRANAME), GetItemAcs(i,PI_COUNT));
    }
    for(new i; i<MAX_INV_ITEMS;i++)
    {
        switch(GetItem(i,PI_TYPE))
        {
            case 0: format(str_1,sizeof str_1,"%s[1,%d,0,0,\"\",0,%s,0.00,0],",str_1,i,GetPlayerMoneyEx(playerid));
            case 1: format(str_1,sizeof str_1,"%s[1,%d,100,%d,\"\",0,1,1.00,%d],",str_1,i,GetItem(i,PI_ID),GetItem(i,PI_EXTRATYPE));
            case 2: format(str_1,sizeof str_1,"%s[1,%d,%d,%d,\"\",0,1,2.00,0],",str_1,i,GetItem(i,PI_ID),GetItem(i,PI_EXTRATYPE));
            case 3: format(str_1,sizeof str_1,"%s[1,%d,%d,%d,\"%s\",0,%d,6.00,0],",str_1,i,GetItem(i,PI_ID),GetItem(i,PI_EXTRATYPE),GetItem(i,PI_EXTRANAME),GetItem(i,PI_COUNT));
            case 4: {
                if(!( 1 <= GetItem(i,PI_EXTRATYPE) <= 5)) continue;
                new number[2][16];
                if(GetItem(i,PI_EXTRATYPE) != 5) {
                    sscanf(GetItem(i,PI_EXTRANAME),"p<|>a<s[16]>[2]",number);
                    if(!IsValidNumber(number[0],GetItem(i,PI_EXTRATYPE))) continue;
                    if(!IsValidRegion(number[1],GetItem(i,PI_EXTRATYPE))) continue;
                }
                else if(!IsValidNumber(GetItem(i,PI_EXTRANAME),GetItem(i,PI_EXTRATYPE))) continue;
                switch(GetItem(i,PI_EXTRATYPE)) {
                    case 1..3: format(str_1,sizeof str_1,"%s[1,%d,99,%d,\"%s %s\",0,1,2.00,0],",str_1,i,GetItem(i,PI_EXTRATYPE),number[0], number[1]);
                    case 4: format(str_1,sizeof str_1,"%s[1,%d,99,%d,\"%.2s%s%s\",0,1,2.00,0],",str_1,i,GetItem(i,PI_EXTRATYPE),number[0], number[1],number[0][2]);
                    default: format(str_1,sizeof str_1,"%s[1,%d,99,%d,\"%s %s\",0,1,2.00,0],",str_1,i,GetItem(i,PI_EXTRATYPE),GetItem(i,PI_EXTRANAME));
                }    
            }
            default:continue;
        }
    }
    strdel(str_1,strlen(str_1)-1,strlen(str_1));
    if(open){
        format(str_1, sizeof str_1, "[%d,[\"%s\",%d,%s,%d,%d,%d,0.00,20.00],[],[%s]]", 1, PN(playerid), playerid, GetPlayerMoneyEx(playerid), pInfo[playerid][P_SKIN], 0, 1, str_1);
        SendPacket( playerid, CefShow, "InventoryNew", str_1);
    }
    else {
        format(str_1,sizeof str_1, "interface('InventoryNew').setItems([%s])",str_1);
        SendPacket(playerid,CefUpdate,str_1);
    }
    return 1;
}
CMD:inv(playerid)
{
    SavePlayerInventory(playerid);
    ClearPlayerInventory(playerid);
    LoadInventory(playerid);
    return 1;
}
CMD:inv1(playerid)
{
    ClearPlayerInventory(playerid);
    LoadInventory(playerid);
    return 1;
}
stock GetAcsName(acsid) {
    new fmt_tt[21];
    format(fmt_tt,sizeof fmt_tt,"");
    switch(acsid) {
        case 181: strcat(fmt_tt,"Очки");
        case 182: strcat(fmt_tt,"Бандана");
        case 183: strcat(fmt_tt,"Маска");
        case 184: strcat(fmt_tt,"Берет");
        case 185: strcat(fmt_tt,"Шляпа");
        case 219: strcat(fmt_tt,"Сумка");
        case 220: strcat(fmt_tt,"Ремень");
        case 221: strcat(fmt_tt,"Украшение на руку");
        case 222: strcat(fmt_tt,"Рюкзак");
        case 246: strcat(fmt_tt,"Украшение на шею");
        case 260: strcat(fmt_tt,"Украшение на шею");
        case 263: strcat(fmt_tt,"Плащ");
        case 275: strcat(fmt_tt,"Акссесуар на левое плечо");
        case 277: strcat(fmt_tt,"Акссесуар бронежилет");
        case 285: strcat(fmt_tt,"Украшение для транспорта");
        case 287: strcat(fmt_tt,"Аксессуар на спину");
        case 289: strcat(fmt_tt,"Аксессуар в руку");
        case 291: strcat(fmt_tt,"Аксессуар на спину");
        case 292: strcat(fmt_tt,"Аксессуар на ногу");
        case 324: strcat(fmt_tt,"Скейтборд");
    }
    return fmt_tt;
}
public: OnInventoryItemMove(playerid, const params[])
{
    printf("OnInventoryItemMove: %s",params);
    extract params-> new lastContainer, lastSlot, Container, slot, count;else return 1;
    if(lastContainer == Container && lastSlot == slot) return OpenInventory(playerid);
    if(!(0<=Container<=3)) return OpenInventory(playerid);

    if(Container == 1 && lastContainer == 1) {
        if(GetItem(slot,PI_ID) == GetItem(lastSlot,PI_ID) && (GetItem(slot,PI_TYPE) == 3 && GetItem(lastSlot,PI_TYPE) == 3))
        {
            if(GetItem(slot,PI_COUNT) < count || count < 1) return GameText(playerid, "~r~Неверное количество!",2000, 1), OpenInventory(playerid);
            if(GetItem(slot,PI_COUNT) == count) {
                GetItem(slot,PI_COUNT) += count;
                g_player_inv[playerid][lastSlot] = inv_default;
            }
            else {
               GetItem(slot,PI_COUNT) += count;
               GetItem(lastSlot,PI_COUNT) -= count;
            }
        }
        else {
            if(GetItem(slot,PI_ID) != -1 || GetItem(lastSlot,PI_ID) == -1 || GetItem(slot,PI_TYPE) != -1) return OpenInventory(playerid);
            g_player_inv[playerid][slot] = g_player_inv[playerid][lastSlot];
            g_player_inv[playerid][lastSlot] = inv_default;
        }
    }
    else if(Container == 0 && lastContainer == 0)
    {
        if(GetItemAcs(slot,PI_TYPE) != -1 || GetItemAcs(lastSlot,PI_TYPE) == -1) return OpenInventory(playerid);
        g_player_acs[playerid][slot] = g_player_acs[playerid][lastSlot];
        g_player_acs[playerid][lastSlot] = inv_default;
    }
    else if(Container == 1 && lastContainer == 0)
    {
        if(GetItem(slot,PI_TYPE) != -1 || GetItemAcs(lastSlot,PI_TYPE) == -1) return OpenInventory(playerid);
        g_player_inv[playerid][slot] = g_player_acs[playerid][lastSlot];
        g_player_acs[playerid][lastSlot] = inv_default;
    }
    else if((Container == 0) && (lastContainer == 1))
    {
        if(GetItem(slot,PI_TYPE) != 2) return GameText(playerid, "~r~Только аксессуары!",2000, 1), OpenInventory(playerid);
        if(GetItemAcs(slot,PI_TYPE) != -1 || GetItem(lastSlot,PI_TYPE) == -1) return OpenInventory(playerid);
        g_player_acs[playerid][slot] = g_player_inv[playerid][lastSlot];
        g_player_inv[playerid][lastSlot] = inv_default;
    }
    OpenInventory(playerid);
    return 1;
}
stock GiveItem(playerid,item,count,extra=0) 
{   
    new id = GetItemSlot(playerid,item);
    if(id == -1)
    {
        id = GetFreeSlot(playerid);
        if(id == -1) {
            GameText(playerid,"~r~Ваш инвентарь полон!",3000,2);
            return 0;
        }
        SetItem(id,PI_TYPE,3);
        SetItem(id,PI_ID,item);
        SetItem(id,PI_COUNT,count);
        SetItem(id,PI_EXTRATYPE,extra);
    }
    else {
       GetItem(id,PI_COUNT) = GetItem(id,PI_COUNT) + count;
       if(GetItem(id,PI_COUNT) <= 0) g_player_inv[playerid][id] = inv_default;
    }
    return true;
}
stock GiveMoneyToInv(playerid) {
    for(new i; i < MAX_INV_ITEMS;i++) if(GetItem(i,PI_TYPE) == 0) return 0;
    new id = GetFreeSlot(playerid);
    if(id == -1) return 0;
    else SetItem(id,PI_TYPE,0),SetItem(id,PI_ID,0);
    return 1;
}
CMD:givemoneyinv(playerid,invparams[])
{
    if(!CheckAdmin(playerid,6)) return 0;
    extract invparams-> new to_player;else return SCM(playerid,0xCECECEFF, !"Используйте: /givemoneyinv [id игрока]");
    if(!IsPlayerLogged(to_player) || !IsPlayerConnected(to_player)) return SCM(playerid,0xCECECEFF,!"Игрок не в сети.");
    if(GiveMoneyToInv(to_player))  SCM(playerid,0xCAA500E8, !"Успешно!");
    else SCM(playerid,0xCA6200E8, !"Возникла ошибка");
    return true;
}
CMD:giveitem(playerid,params[]) 
{
    if(!CheckAdmin(playerid,6)) return 0;
    extract params-> new itemid, count; else return SCM(playerid,0xCECECEFF, !"Используйте: /giveitem [id предмета] [кол-во]");
    GiveItem(playerid,itemid,count);
    return true;
}
// static const InvItemGun[51] = {0,0,0,32,7,8,125,0,9,10,33,34,35,36,37,0,24,43,11,0,0,0,12,13,19,14,15,0,17,18,21,20,0,42,22,23,0,0,0,45,46,0,5,39,0,0,40,0};
// stock UpdateGun(playerid)
// {
//     mysql_queryf(mysql,"DELETE FROM `ItemsInv` WHERE owner_id = %d AND typeitem=6",false,GetPlayerAccountID(playerid));
//     for(new i=0;i<12;i++)
//     {
//         new weapon,patron;
// 	    GetPlayerWeaponData(playerid,i,weapon,patron);
//         //scmf(playerid,-1,"%d | %d", weapon, patron);
//         if((patron != 0 && weapon != 0) && InvItemGun[weapon] != 0)
//         {
//             mysql_queryf(mysql,"INSERT INTO `ItemsInv` (`owner_id`,`item`,`count`,`typeitem`, `slot_inv`) VALUES (%d, %d, %d, 6, %d)",false,GetPlayerAccountID(playerid),InvItemGun[weapon],patron,InventorySlot(playerid));
//         }
//     }
//     return 1;
// }
// stock LoadGunInv(playerid) 
// {
//     mysql_format(mysql, str_q, sizeof str_q, "SELECT * FROM `ItemsInv` WHERE `owner_id`='%d' AND `typeitem`=6", GetPlayerAccountID(playerid));
// 	new Cache: result = mysql_query(mysql, str_q, true);
//     scmf(playerid,-1,"PIPS: %d",cache_num_rows());
//     if(cache_num_rows())
//     {
//         for(new i; i < cache_num_rows();i++)
//         {
//             new item = cache_get_field_content_int(i,"item");
//             new count = cache_get_field_content_int(i,"count");
//             for(new j; j<51;j++)
//             {
//                 if(j == 50){ 
//                     item = -1; 
//                     SCM(playerid,-1,"ТЫ ЛОХ");
//                     break;
//                 }
//                 if(InvItemGun[j] != item) continue;
//                 item = j;
//                 break;
//             }
//             scmf(playerid,-1,"item : %d", item);
//             if(item != -1)
//                 GivePlayerWeapon(playerid, item, count);
//         }
//     }
//     cache_delete(result);
//     return 1;
// }
// public: OnInventoryDisplayChange(playerid, bool:status)
// {
//     if(IsPlayerLogged(playerid) != true) return 0;
//     UpdateGun(playerid);
//     if(status)
//     {
//         InterfaceStatus[playerid][iInventory] = 1;
//         LoadInventory(playerid);
//         str_1[0] = EOS;
//         format(str_1, sizeof str_1, "[0,[\"%s\",%d,%d,%d,0,0,%.2f,25.00],[],[%s]]", PN(playerid), playerid, GetPlayerMoney(playerid), GetPlayerSkin(playerid), pInfo[playerid][P_InvWeight], str_2);
//         SendPacket( playerid, CefShow, "InventoryNew", str_1);
//     }
//     else
//     {
//         InterfaceStatus[playerid][iInventory] = 0;
// 		SendPacket(playerid, CefHide, "InventoryNew");
//     }
//     return 1;
// }
// stock LoadInventory(playerid)
// {
//     new Cache:result;
//     pInfo[playerid][P_InvWeight] = 0.00;
//     str_q[0] = EOS,str_2[0] = EOS;
// 	mysql_format(mysql, str_q, sizeof str_q, "SELECT * FROM ItemsInv WHERE owner_id='%d' LIMIT 20", GetPlayerAccountID(playerid));
// 	result = mysql_query(mysql, str_q, true);
//     for(new i = 0; i < cache_num_rows(); i ++)
// 	{
// 		new item = cache_get_field_content_int(i, "item", mysql);
// 		new count = cache_get_field_content_int(i, "count", mysql);
// 		new typeitem = cache_get_field_content_int(i, "typeitem", mysql);
// 		new slot = cache_get_field_content_int(i, "slot_inv", mysql);
// 		new skin_id = cache_get_field_content_int(i, "skin_id", mysql);
// 		new iznos = cache_get_field_content_int(i, "iznos", mysql);
// 		new acsid = cache_get_field_content_int(i, "acsid", mysql);
// 		new modelid = cache_get_field_content_int(i, "modelid", mysql);
// 		if(typeitem == 1) // предмет
// 		{
// 			f(str_q, sizeof str_q, "[1,%d,%d,0,\"\",0,%d,1.0],", slot, item, count);
// 	 		pInfo[playerid][P_InvWeight] += 1.00;
// 		}
//         if(typeitem == 2) // скин
//         {
// 			f(str_q, sizeof str_q, "[1,%d,100,%d,\"\",%d,1,5.0,%d],", slot, skin_id,slot,iznos+1);
// 	 	    pInfo[playerid][P_InvWeight] += 5.00;
//         }
//         if(typeitem == 3) f(str_q, sizeof str_q, "[1,%d,0,0,\"\",0,%d,0.0],", slot, pInfo[playerid][P_MONEY]); // деньги
//         if(typeitem == 4) { // аксессуар
// 		    format(str_q, sizeof str_q, "[1,%d,%d,%d,\"\",%d,1,0.10],",slot,acsid,modelid, slot);
//             pInfo[playerid][P_InvWeight] += 0.10;
//         }
//         if(typeitem == 6) { // guns
// 		    format(str_q, sizeof str_q, "[1,%d,%d,1,\"\",0,%d,%.2f],",slot,item,count, 0.10*count);
//             //SCM(playerid,-1,str_q);
//             pInfo[playerid][P_InvWeight] += 0.10*count;
//         }
//         strcat(str_2, str_q);
//     }
//     new str_len = strlen(str_2);
//     strdel(str_2, str_len - 1, str_len);
//     cache_delete(result);
// }
// cmd:giveitem(playerid, params[])
// {
// 	extract params -> new to_player, item, count; else return SendClientMessage(playerid, 0xff9300ff, "Используйте: {cecece}/giveitem [ID Игрока] [Айди] [Кол-Во]");
//     if(to_player == INVALID_PLAYER_ID) return SCM(playerid, 0xff9300ff, "Ошибка: {cecece}Игрок не найден!");
//     if(InventorySlot(to_player) == -1) return scmf(playerid, 0xff9300ff, "Ошибка: {cecece}У %s[%d]: Недостаточно слотов в инвентаре", PN(to_player), to_player);
//     GiveItem(to_player, item, count, 1);
//     scmf(to_player, 0xff9300ff, "Администратор %s[%d]:{cecece} Выдал вам предмет: %d, в количестве: %d", PN(playerid), playerid,item, count);
//     scmf(playerid, 0xff9300ff, "Вы выдали предмет: {cecece}%s[%d] %d, в количестве: %d",PN(to_player), to_player, item, count);
//     return 1;
// }
// stock InventorySlot(playerid)
// {
//     for(new i; i < 20; i++) if(CheckSlotInventory(playerid, i) != -1) return i; 
//     return -1;
// }
// stock CheckSlotInventory(playerid,slot)
// {
// 	mysql_format(mysql, str_q, sizeof str_q, "SELECT * FROM ItemsInv WHERE owner_id='%d' AND slot_inv='%d'", GetPlayerAccountID(playerid), slot);
// 	new Cache: result = mysql_query(mysql, str_q, true);
// 	if(!cache_num_rows()) return slot;
// 	cache_delete(result);
// 	return -1;
// }
// stock GiveItem(playerid, item, count, typeitem,acsid=0,bonnet=0,modelid=0,slot=0)
// {
//     new Cache:result;
//     switch(typeitem) {
//         case 1:
//         {
//             mysql_format(mysql, str_q, sizeof str_q, "SELECT * FROM ItemsInv WHERE owner_id='%d' AND typeitem=1 AND item=%d", GetPlayerAccountID(playerid),item);
//             result = mysql_query(mysql, str_q, true);
//             if(cache_num_rows()) 
//             {
//                 new id,items;
//                 for(new i; i < cache_num_rows(); i++) id = cache_get_field_content_int(i, "ID", mysql),items = cache_get_field_content_int(i, "count", mysql);
//                 mysql_queryf(mysql,"UPDATE ItemsInv SET count=%d WHERE ID=%d",false, count+items, id);
//             }
//             else mysql_queryf(mysql, "INSERT INTO `ItemsInv` (`owner_id`,`item`,`count`,`typeitem`, `slot_inv`) VALUES (%d, %d, %d, 1, %d)", false,GetPlayerAccountID(playerid), item,count, InventorySlot(playerid)); 
//         }
//         case 2: mysql_queryf(mysql, "INSERT INTO `ItemsInv` (`owner_id`,`skin_id`,`typeitem`, `slot_inv`) VALUES (%d, %d, 2, %d)", false,GetPlayerAccountID(playerid), item, InventorySlot(playerid)); 
//         case 3: mysql_queryf(mysql, "INSERT INTO `ItemsInv` (`owner_id`,`typeitem`, `slot_inv`) VALUES (%d, 3,%d)", false,GetPlayerAccountID(playerid),InventorySlot(playerid)); 
//         case 4: {
//             mysql_queryf(mysql, "INSERT INTO `ItemsInv` (`owner_id`,`modelid`,`acsid`, `slot`, `bonnet`, `typeitem`,`slot_inv`) VALUES (%d, %d, %d, %d, %d, 4,%d)", false,GetPlayerAccountID(playerid), item, modelid, acsid, slot, bonnet,InventorySlot(playerid)); 
//         }   
//     }
//     cache_delete(result);
// }
// stock GetItem(playerid, item, typeitem)
// {
//     mysql_format(mysql, str_q, sizeof str_q, "SELECT * FROM ItemsInv WHERE owner_id='%d' AND item=%d AND typeitem=%d", GetPlayerAccountID(playerid), item, typeitem);
// 	new count, Cache: result = result = mysql_query(mysql, str_q, true);
// 	for(new i; i < cache_num_rows(); i++) count = cache_get_field_content_int(i, "count");
// 	cache_delete(result);
// 	return count;
// }

// stock OnInventoryItemUse(playerid,type,slot)
// {
//     mysql_format(mysql, str_q, sizeof str_q, "SELECT * FROM ItemsInv WHERE owner_id='%d' AND slot_inv=%d", GetPlayerAccountID(playerid),slot);
//     new Cache:result = mysql_query(mysql, str_q, true);
//     new id,item,typeitem,skin_id;
//     for(new i; i < cache_num_rows(); i++)
//     {
//         id = cache_get_field_content_int(i, "ID");
// 		item = cache_get_field_content_int(i, "item");
// 		typeitem = cache_get_field_content_int(i, "typeitem");
// 		skin_id = cache_get_field_content_int(i, "skin_id");
//     }
//     if(type == 1)
//     {
//         switch(typeitem) {
//             case 1: {
//                 #pragma unused item
//             }
//             case 2: {
//                 if(pInfo[playerid][P_SKINBD] != id) {
//                     scmf(playerid, 0xff9300ff, "[Уведомление] {ffffff}Вы успешно надели одежду: №%d",skin_id);
//                     UpdateDataInt(playerid, "SkinBD", id);
//                     UpdateDataInt(playerid, "Skin", skin_id);
//                     pInfo[playerid][P_SKINBD] = id;
//                     SetPlayerSkin(playerid, skin_id);
//                 }
//                 else {
//                     scmf(playerid, 0xff9300ff, "[Уведомление] {ffffff}Вы успешно сняли одежду: №%d",skin_id);
//                     if(pInfo[playerid][P_SEX] == 1) skin_id = 252;
//                     else skin_id = 75;
//                     pInfo[playerid][P_SKINBD] = -1;
//                     UpdateDataInt(playerid, "SkinBD", -1);
//                     UpdateDataInt(playerid, "Skin", skin_id);
//                     SetPlayerSkin(playerid, skin_id);
//                 }
//                 SendPacket( playerid, CefHide, "InventoryNew");
//             }
//             case 4: {
//                 GameText(playerid, "Переместите Акссесуар в ячейку для акссесуаров", 2000, 2);
//                 LoadInventory(playerid);
//                 format(str_q, sizeof str_q, "interface('InventoryNew').setItems([%s])",str_1);
//                 SendPacket(playerid, CefUpdate, str_q);
//             }
//         }
//     }
//     cache_delete(result);
//     return 1;
// }

// stock OnInventoryItemMove(playerid, where, event, from,kyda,kolvo)
// {
//     #pragma unused kolvo
//     #pragma unused where
//     if(from == 1) mysql_queryf(mysql, "UPDATE ItemsInv SET slot_inv=%d WHERE owner_id=%d AND slot_inv=%d", false, kyda, GetPlayerAccountID(playerid), event);
//     return 1;
// }