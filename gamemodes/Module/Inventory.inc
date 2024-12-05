enum EItem_struct {
    ITEM_ID,
    ITEM_NAME[42],
    ITEM_PRICE,
    Float:Item_Weight
}
new const ItemsInfo[][EItem_struct] = {
    {0, "������", 500, 0.5,1212},
    {1, "��������", 500, 0.5,1650},
    {2, "�������", 500, 0.5,1241},
    {3, "̸����� �����", 500, 0.5,19315},
    {4, "������������� ����", 500, 0.5,2969},
    {5, "������������", 500, 0.5,366},
    {6, "����� � ��������", 500, 0.5,1550},
    {7, "���", 500, 0.5,335},
    {8, "����", 500, 0.5,336},
    {9, "������", 500, 0.5,339},
    {10, "���������", 500, 0.5,341},
    {11, "�������� ��������", 500, 0.5,344},
    {12, "��������", 500, 0.5,346},
    {13, "������������", 500, 0.5,347},
    {14, "��������", 500, 0.5,349},
    {15, "�����", 500, 0.5,350},
    {16, "������ ��������", 500, 0.5,351},
    {17, "���", 500, 0.5,352},
    {18, "MP5", 500, 0.5,353},
    {19, "Desert Eagle", 500, 0.5,348},
    {20, "M4", 500, 0.5,356},
    {21, "AK-47", 500, 0.5,355},
    {22, "����������� ��������", 500, 0.5,358},
    {23, "���", 500, 0.5,359},
    {24, "�������", 500, 0.5,342},
    {25, "���������", 500, 0.5,2969},
    {26, "�������", 500, 0.5,3016},
    {27, "������", 500, 0.5,2969},
    {28, "�����������", 500, 0.5,2969},
    {29, "�������", 500, 0.5,2969},
    {30, "���� � ���������", 500, 0.5,2969},
    {31, "������", 500, 0.5,331},
    {32, "�������", 500, 0.5,334},
    {33, "������� �����", 500, 0.5,321},
    {34, "����� �����", 500, 0.5,323},
    {35, "��������", 500, 0.5,322},
    {36, "�������� 2", 500, 0.5,324},
    {37, "�����", 500, 0.5,325},
    {38, "�����", 500, 0.5,326},
    {39, "������", 500, 0.5,367},
    {40, "�������", 500, 0.5,371},
    {41, "������� ���������", 500, 0.5,2969},// extra icon
    {42, "��������", 500, 0.5, 357},
    {43, "������������ ���", 500, 0.5, 365},
    {44, "��������� ��������", 500, 0.5, 2969},
    {45, "����������", 500, 0.5, 363},
    {46, "���������", 500, 0.5, 364},
    {47, "������� ���", 500, 0.5, 10478},
    {48, "������������ ���", 500, 0.5, 10479},
    {49, "��� ��������", 500, 0.5, 10480},
    {50, "������� � ��������", 500, 0.5, 10481},
    {51, "������� � �������", 500, 0.5, 10482},
    {52, "������", 500, 0.5, 10483},
    {53, "������������ ������", 500, 0.5, 10484},
    {54, "������ �������", 500, 0.5, 10485},
    {55, "������ ����", 500, 0.5, 10486},
    {56, "��������� (�������)", 500, 0.5, 10487},
    {57, "��������� (������)", 500, 0.5, 10488},
    {58, "��������� (����)", 500, 0.5, 10489},
    {59, "����������� ���", 500, 0.5, 10490},
    {60, "���������� �����", 500, 0.5, 10491},
    {61, "������", 500, 0.5, 10492},
    {62, "������", 500, 0.5, 10493},
    {63, "������� ������", 500, 0.5, 10494},
    {64, "�������� �� ������", 500, 0.5, 10495},
    {65, "�������� � ���������", 500, 0.5, 10496},
    {66, "������", 500, 0.5, 10497},
    {67, "��������� ������", 500, 0.5, 10498},
    {68, "�����������", 500, 0.5, 10499},
    {69, "����������� (������)", 500, 0.5, 10500},
    {70, "�������������", 500, 0.5, 10501},
    {71, "���������� �������", 500, 0.5, 10502},
    {72, "����", 500, 0.5, 10503},
    {73, "����", 500, 0.5, 10504},
    {74, "�������", 500, 0.5, 10505},
    {75, "��������� �������", 500, 0.5, 10506},
    {76, "��������", 500, 0.5, 10507},
    {77, "���������", 500, 0.5, 10508},
    {78, "�������� ���������", 500, 0.5, 10509},
    {79, "�������", 500, 0.5, 10510},
    {80, "XBOX ONE", 500, 0.5, 10511},
    {81, "PS4", 500, 0.5, 10512},
    {82, "������� ������", 500, 0.5, 10513},
    {83, "������� � ����������", 500, 0.5, 10514},
    {84, "����������� �����", 500, 0.5, 10515},
    {85, "����������� ������", 500, 0.5, 10816},
    {86, "����������� ������", 500, 0.5, 10816},
    {87, "����������� ������", 500, 0.5, 10816},
    {88, "����������� ������", 500, 0.5, 10816},
    {89, "����������� ������", 500, 0.5, 10816},
    {90, "����������� ������", 500, 0.5, 10816},
    {91, "����� Radmir", 500, 0.5, 10516},
    {92, "����� �������", 500, 0.5, 10517},
    {93, "������ �������", 500, 0.5, 10518},
    {94, "������ �������", 500, 0.5, 10519},
    {95, "������� �������", 500, 0.5, 10520},
    {96, "����� � ������", 500, 0.5, 10521},
    {97, "��������", 500, 0.5, 10522},
    {98, "�����", 500, 0.5, 10523},
    {99, "������������� �����", 500, 0.5,2969},
    {100, "������", 500, 0.5,10816},
    {101, "������������ �������", 500, 0.5,1672},
    {102, "���� � ���������", 500, 0.5,10702},
    {103, "��������� ��������", 500, 0.5,10703},
    {104, "������ �������", 500, 0.5,10704},
    {105, "������ �������", 500, 0.5,10705},
    {106, "�������� �������", 500, 0.5,10706},
    {107, "������� Brick 3310", 500, 0.5,10707},
    {108, "������� Brick", 500, 0.5,10708},
    {109, "������� Galaxy", 500, 0.5,10709},
    {110, "������� Orange", 500, 0.5,10710},
    {111, "������� �����", 500, 0.5,10711},
    {112, "������� ��� �����", 500, 0.5,10712},
    {113, "������� ��������", 500, 0.5,10713},
    {114, "������� ���������", 500, 0.5,10714},
    {115, "��������� ����", 500, 0.5,10715},
    {116, "�������", 500, 0.5,10716},
    {117, "���� TAZ 2101", 500, 0.5,10717},
    {118, "���� GTR", 500, 0.5,10718},
    {119, "���� Sternchen AMG", 500, 0.5,10719},
    {120, "������ ����", 500, 0.5,10720},
    {121, "��������� �������������", 500, 0.5,10721},
    {122, "�����", 500, 0.5,10722},
    {123, "������� Apple", 500, 0.5,10723},
    {124, "����������", 500, 0.5,10805},
    {125, "������", 500, 0.5,337},
    {126, "�������", 500, 0.5,10806},
    {127, "��������������� B.H Junior", 500, 0.5,10803},
    {128, "��������������� Garrett 250", 500, 0.5,10804},
    {129, "������� ����", 500, 0.5,10808},
    {130, "�������� �����", 500, 0.5,10809},
    {131, "������� �� ����", 500, 0.5,10810},
    {132, "������", 500, 0.5,10811},//icon
    {133, "����", 500, 0.5,10812},//icon
    {134, "������� �����", 500, 0.5,10813},
    {135, "�������", 500, 0.5,10814},
    {136, "���������", 500, 0.5,10815},
    {137, "������ �������", 500, 0.5,10816},
    {138, "������", 500, 0.5,10817},
    {139, "������", 500, 0.5,10818},
    {140, "�������", 500, 0.5,10819},
    {141, "�����", 500, 0.5,10820},
    {142, "����", 500, 0.5,10821},
    {143, "����", 500, 0.5,10822},
    {144, "�����", 500, 0.5,10823},
    {145, "�������", 500, 0.5,10824},
    {146, "������", 500, 0.5,10825},
    {147, "���������", 500, 0.5,10826},
    {148, "��������� iPhone", 500, 0.5,10827},
    {149, "�������� � iPhone", 500, 0.5,10828},
    {150, "�������� � ��������", 500, 0.5,2969},
    {151, "�������� �����.�������", 500, 0.5,10829},
    {152, "�������� � ����.�������", 500, 0.5,10830},
    {153, "�����������", 500, 0.5,10831},
    {154, "������", 500, 0.5,10832},
    {155, "������", 500, 0.5,10833},
    {156, "�����������", 500, 0.5,10834},
    {157, "������ �������", 500, 0.5,10815},
    {158, "������ ������", 500, 0.5,10815},
    {159, "������ �������", 500, 0.5,10815},
    {160, "������ �����.�������", 500, 0.5,10815},
    {161, "���������� �������", 500, 0.5,1487},
    {162, "�������", 500, 0.5,1650},
    {163, "�������� ���� (�����)", 500, 0.5,2969},
    {164, "�������� ���� (�����)", 500, 0.5,2969},
    {165, "�������� �����", 500, 0.5,10930},
    {166, "��������� ������", 500, 0.5,10931},
    {167, "�������� ������", 500, 0.5,10932},
    {168, "�����", 500, 0.5,10939},
    {169, "����������", 500, 0.5,10943},
    {170, "������", 500, 0.5,10941},
    {171, "��������", 500, 0.5,10942},
    {172, "������ �������", 500, 0.5,10940},
    {173, "������ ���������", 500, 0.5,10940},
    {174, "������ �������", 500, 0.5,10940},
    {175, "�����", 500, 0.5,19625},
    {176, "���������", 500, 0.5,11017},
    {177, "���� � �����������", 500, 0.5,2969},
    {178, "���������", 500, 0.5,2969},
    {179, "���������", 500, 0.5,2969},
    {180, "��������", 500, 0.5,2969},
    {181, "����", 500, 0.5,2969},
    {182, "�������", 500, 0.5,2969},
    {183, "�����", 500, 0.5,2969},
    {184, "�����", 500, 0.5,2969},
    {185, "�����", 500, 0.5,2969},
    {186, "�����", 500, 0.5,2969},
    {187, "�����", 500, 0.5,2969},
    {188, "���������", 500, 0.5,2969},
    {189, "������ ���� AMG", 500, 0.5,2969},
    {190, "�������� � ���� AMG", 500, 0.5,2969},
    {191, "������� ������", 500, 0.5,2969},
    {192, "�������", 500, 0.5,2969},
    {193, "�������� (�������)", 500, 0.5,2969},
    {194, "�������� (����������)", 500, 0.5,2969},
    {195, "�������� (�������)", 500, 0.5,2969},
    {196, "�������� (�����)", 500, 0.5,2969},
    {197, "������ Volga", 500, 0.5,2969},
    {198, "������ ��� 2109", 500, 0.5,2969},
    {199, "������ ���-2203", 500, 0.5,2969},
    {200, "����������", 500, 0.5,2969},
    {201, "�������", 500, 0.5,2969},
    {202, "��������", 500, 0.5,2969},
    {203, "������� (Spider Man)", 500, 0.5,2969},
    {204, "������� (Ninja)", 500, 0.5,2969},
    {205, "������� (Bakugan)", 500, 0.5,2969},
    {206, "���������� RGB", 500, 0.5,2969},
    {207, "����������", 500, 0.5,2969},
    {208, "�������", 500, 0.5,2969},
    {209, "�������� ������", 500, 0.5,2969},
    {210, "������", 500, 0.5,2969},
    {211, "���������", 500, 0.5,2969},
    {212, "�������", 500, 0.5,2969},
    {213, "������� ���������", 500, 0.5,2969},
    {214, "������� ����", 500, 0.5,2969},
    {215, "PSP", 500, 0.5,2969},
    {216, "���������", 500, 0.5,2969},
    {217, "��������������", 500, 0.5,2969},
    {218, "�������� � ���������", 500, 0.5,2969},
    {219, "�����", 500, 0.5,2969},
    {220, "��������� �� ����", 500, 0.5,2969},
    {221, "��������� �� ����", 500, 0.5,2969},
    {222, "������", 500, 0.5,2969},
    {223, "�������", 500, 0.5,2969},
    {224, "�������", 500, 0.5,2969},
    {225, "����", 500, 0.5,2969},
    {226, "���������", 500, 0.5,2969},
    {227, "������", 500, 0.5,2969},
    {228, "������", 500, 0.5,2969},
    {229, "������", 500, 0.5,2969},
    {230, "�������������", 500, 0.5,2969},
    {231, "������", 500, 0.5,2969},
    {232, "�����.�������", 500, 0.5,2969},
    {233, "���-��", 500, 0.5,2969},
    {234, "������ ���-��", 500, 0.5,2969},
    {235, "����� ���-�����", 500, 0.5,2969},
    {236, "������� ���", 500, 0.5,2969},
    {237, "������� ���", 500, 0.5,2969},
    {238, "������� ������", 500, 0.5,2969},
    {239, "���-��", 500, 0.5,2969},
    {240, "���-��", 500, 0.5,2969},
    {241, "���������� �������", 500, 0.5,2969},
    {242, "���.�������� � ����.�������", 500, 0.5,2969},
    {243, "�������", 500, 0.5,2969},
    {244, "������� ���������", 500, 0.5,2969},
    {245, "�������������� �������", 500, 0.5,2969},
    {246, "��������� �� ���", 500, 0.5,2969},
    {247, "����������� �����", 500, 0.5,10939},
    {248, "��������", 500, 0.5,14279},//icon
    {249, "����� ��� ��������", 500, 0.5,12296},//icon
    {250, "���� ��� ��������", 500, 0.5,14350},
    {251, "������� ������", 500, 0.5,2969},
    {252, "������� ����", 500, 0.5,2969},
    {253, "����������� ���������", 500, 0.5,14350},
    {254, "������� ��� �����������", 500, 0.5,14348},
    {255, "�����", 500, 0.5,2969},
    {256, "����������������", 500, 0.5,2969},
    {257, "���������� �����", 500, 0.5,2969},
    {258, "���� `������`", 500, 0.5,14512},
    {259, "���� �� �����", 500, 0.5,14511},
    {260, "��������� �� ���", 500, 0.5,2969},
    {261, "���� `������ ����`", 500, 0.5,14595},
    {262, "����� ��������", 500, 0.5,2969},
    {263, "����", 500, 0.5,2969},
    {264, "�������� (���������)", 500, 0.5,2969},
    {265, "�������� (�������)", 500, 0.5,2969},
    {266, "�������� (���������)", 500, 0.5,2969},
    {267, "�������� (�������� ����)", 500, 0.5,2969},
    {268, "����� �������", 500, 0.5,2969},
    {269, "������� ��������", 500, 0.5,2969},
    {270, "������� ����", 500, 0.5,2969},
    {271, "������� ������������", 500, 0.5,2969},
    {272, "���� `�������� ����`", 500, 0.5,14694},
    {273, "������� ��������", 500, 0.5,2969},
    {274, "������� ���������", 500, 0.5,2969},
    {275, "��������� �� ����� �����", 500, 0.5,2969},
    {276, "�������", 500, 0.5,2969},
    {277, "��������� ����������", 500, 0.5,2969},
    {278, "���� `��������`", 500, 0.5,14785},
    {279, "�������� ", 500, 0.5,2969},//icon
    {280, "�������", 500, 0.5,2969},//Extra icon
    {281, "����", 500, 0.5,2969},
    {282, "���������", 500, 0.5,2969},//Extra icon
    {283, "������", 500, 0.5,2969},
    {284, "���� `����������`", 500, 0.5,15711},
    {285, "��������� ��� ����������", 500, 0.5,2969},
    {286, "�������", 500, 0.5,2969},
    {287, "��������� �� �����", 500, 0.5,2969},
    {288, "������ ������", 500, 0.5,2969},
    {289, "��������� � ����", 500, 0.5,2969},
    {290, "���� `������ ������`", 500, 0.5,15846},
    {291, "��������� �� �����", 500, 0.5,2969},
    {292, "��������� �� ����", 500, 0.5,2969},
    {293, "�����", 500, 0.5,2969},
    {294, "��� ��� ����������", 500, 0.5,2969},
    {295, "����� �����", 500, 0.5,2969},
    {296, "����� �������", 500, 0.5,2969},
    {297, "����� �����", 500, 0.5,2969},
    {298, "����� ������", 500, 0.5,2969},
    {299, "�������� ���", 500, 0.5,2969},
    {300, "���� `���������`", 500, 0.5,15963},
    {301, "������� �������", 500, 0.5,2969},
    {302, "��������� ���������", 500, 0.5,2969},
    {303, "�������� �������������", 500, 0.5,2969},
    {304, "��������� ��������", 500, 0.5,2969},
    {305, "�������� ���������", 500, 0.5,2969},
    {306, "��������� ���������������", 500, 0.5,2969},
    {307, "�������� ���������������", 500, 0.5,2969},
    {308, "������� ��� ������", 500, 0.5,2969},
    {309, "������� ��� ������", 500, 0.5,2969},
    {310, "��������� �������� �����-��", 500, 0.5,2969},
    {311, "�������� �������� �����-��", 500, 0.5,2969},
    {312, "������ �������� �����", 500, 0.5,2969},
    {313, "������� �������� �����", 500, 0.5,2969},
    {314, "�������� �������� �����", 500, 0.5,2969},
    {315, "������ �������� �����", 500, 0.5,2969},
    {316, "������� ��� ��������������", 500, 0.5,2969},
    {317, "���������", 500, 0.5,2969},
    {318, "��������", 500, 0.5,2969},
    {319, "������", 500, 0.5,2969},
    {320, "������� ������", 500, 0.5,2969},
    {321, "���������", 500, 0.5,2969},
    {322, "�������������", 500, 0.5,2969},
    {323, "�������������", 500, 0.5,2969},
    {324, "���������", 500, 0.5,2969},
    {325, "���������� �����", 500, 0.5,2969},
    {326, "�������", 500, 0.5,2969},//icon
    {327, "��������� ����", 500, 0.5,2969},
    {328, "���� `���������� ����`", 500, 0.5,16453},
    {329, "������� �����", 500, 0.5,2969},
    {330, "������� ��������", 500, 0.5,2969},
    {331, "�������� ��� ����", 500, 0.5,2969},//Extra
    {332, "������ ��� ������", 500, 0.5,2969},
    {333, "�������", 500, 0.5,2969},
    {334, "��������", 500, 0.5,2969},
    {335, "���������� ���������", 500, 0.5,2969},//Extra icon
    {336, "������", 500, 0.5,2969},//Extra icon
    {337, "������", 500, 0.5,2969},//Extra icon
    {338, "������� ��c��������", 500, 0.5,2969},
    {339, "������� �����������", 500, 0.5,2969},
    {340, "������� ������������", 500, 0.5,2969},
    {341, "������� �����", 500, 0.5,2969},
    {342, "�������", 500, 0.5,2969},
    {343, "�������� (������)", 500, 0.5,2969},
    {344, "���� `�������� ���� 2`", 500, 0.5,16664},
    {345, "����� ������ �������", 500, 0.5,2969},
    {346, "�������� (���)", 500, 0.5,2969},
    {347, "������� �������", 500, 0.5,2969},
    {348, "���� `�������������� ��������`", 500, 0.5,16773},
    {349, "����������� ������", 500, 0.5,2969},
    {350, "���� `���� �����`", 500, 0.5,16966},
    {351, "��������", 500, 0.5,2969},
    {352, "��������", 500, 0.5,2969},
    {353, "�������", 500, 0.5,2969},
    {354, "������ �������", 500, 0.5,2969},
    {355, "���� `���������`", 500, 0.5,17207},
    {356, "���� `���������`", 500, 0.5,17610},
    {357, "������������", 500, 0.5,2969},
    {358, "������ �������", 500, 0.5,2969}
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
#define MAX_INV_ITEMS           20
#define MAX_ACS_ITEMS           10

#define MAX_INV_WIGHT           66

#define SetItem(%0,%1,%2)           g_player_inv[playerid][%0][%1] = %2
#define GetItem(%0,%1)              g_player_inv[playerid][%0][%1]

#define SetItemAcs(%0,%1)           g_player_acs[playerid][%0][%1] = %2
#define GetItemAcs(%0,%1)           g_player_acs[playerid][%0][%1]

// //TYPEITEMS:
// // 0 - ������
// // 1 - ����
// // 2 - ���
// // 3 - �������
// // 4 - ����� �� ����
// // 5 - ������
/*
1(���) = X666AM 35
2(��) = 555AKA 5
3(BY) = 5555 AA-3
4(UA) = XXXX 6666
5(Custom) = NY PON
*/
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
    if(punkt == 1) {
        str_q[0] = EOS;
        for(new i=1;i<MAX_INV_ITEMS+1;i++)
        {
            new str_ff[12];
            format(str_ff,sizeof str_ff,"SLOT%d",i);
            cache_get_field_content(0,str_ff,str_q);
            new code[32];
            sscanf(str_q,"p<;>a<d>[5]s[32]a<f>[9]",g_player_inv[playerid][i-1],code,g_player_inv[playerid][i-1][PI_ACSPOS]);
            format(g_player_inv[playerid][i-1][PI_EXTRANAME],32,code);
        }
    }
    if(punkt == 2) {
        str_q[0] = EOS;
        for(new i=1;i<MAX_ACS_ITEMS+1;i++)
        {
            new str_ff[12];
            format(str_ff,sizeof str_ff,"SLOT%d",i);
            cache_get_field_content(0,str_ff,str_q);
            new code[32];
            sscanf(str_q,"p<;>a<d>[5]s[32]a<f>[9]",g_player_acs[playerid][i-1],code,g_player_acs[playerid][i-1][PI_ACSPOS]);
            format(g_player_acs[playerid][i-1][PI_EXTRANAME],32,code);
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
            format(str_tt,sizeof str_tt,"%s%d;",str_tt,punkt==1 ? GetItem(i-1,InveSoshr[k][INVLOAD_TYPE]) : GetItemAcs(i-1,InveSoshr[k][INVLOAD_TYPE]));
        format(str_acs,sizeof str_acs,"");
        for(new k; k < 9; k++)
            format(str_acs,sizeof str_acs,"%s;%f",str_acs,punkt==1 ? GetItem(i-1,PI_ACSPOS)[k] : GetItemAcs(i-1,PI_ACSPOS)[k]);
        if(punkt == 1) format(str_q,sizeof str_q,"%s SLOT%d='%s%s%s',",str_q,i,str_tt,GetItem(i-1,PI_EXTRANAME), str_acs);
        if(punkt == 0) format(str_q,sizeof str_q,"%s SLOT%d='%s%s%s',",str_q,i,str_tt,GetItemAcs(i-1,PI_EXTRANAME), str_acs);
    }
    strdel(str_q, strlen(str_q)-1,strlen(str_q));
    mysql_format(mysql,str_q,sizeof str_q,"UPDATE items SET%s WHERE uid=%d AND container=%d",str_q,GetPlayerAccountID(playerid),punkt);
    mysql_query(mysql,str_q,false);
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
public: OnItemsInterfaceClose(playerid) return SendPacket(1, playerid, CefHide, "InventoryNew");
public: OnInventoryDisplayChange(playerid) {
    if(PlayerInterfaces[playerid][IF_INVENTORY]) SendPacket(1, playerid, CefHide, "InventoryNew");
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
                new number[2][32];
                if(GetItem(i,PI_EXTRATYPE) != 5) {
                    sscanf(GetItem(i,PI_EXTRANAME),"p<|>a<s[32]>[2]",number);
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
        SendPacket(2, playerid, CefShow, "InventoryNew", str_1);
    }
    else {
        format(str_1,sizeof str_1, "interface('InventoryNew').setItems([%s])",str_1);
        SendPacket(1,playerid,CefUpdate,str_1);
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
        case 181: strcat(fmt_tt,"����");
        case 182: strcat(fmt_tt,"�������");
        case 183: strcat(fmt_tt,"�����");
        case 184: strcat(fmt_tt,"�����");
        case 185: strcat(fmt_tt,"�����");
        case 219: strcat(fmt_tt,"�����");
        case 220: strcat(fmt_tt,"������");
        case 221: strcat(fmt_tt,"��������� �� ����");
        case 222: strcat(fmt_tt,"������");
        case 246: strcat(fmt_tt,"��������� �� ���");
        case 260: strcat(fmt_tt,"��������� �� ���");
        case 263: strcat(fmt_tt,"����");
        case 275: strcat(fmt_tt,"��������� �� ����� �����");
        case 277: strcat(fmt_tt,"��������� ����������");
        case 285: strcat(fmt_tt,"��������� ��� ����������");
        case 287: strcat(fmt_tt,"��������� �� �����");
        case 289: strcat(fmt_tt,"��������� � ����");
        case 291: strcat(fmt_tt,"��������� �� �����");
        case 292: strcat(fmt_tt,"��������� �� ����");
        case 324: strcat(fmt_tt,"���������");
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
            if(GetItem(slot,PI_COUNT) < count || count < 1) return GameText(playerid, "~r~�������� ����������!",2000, 1), OpenInventory(playerid);
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
        if(GetItem(slot,PI_TYPE) != 2) return GameText(playerid, "~r~������ ����������!",2000, 1), OpenInventory(playerid);
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
            GameText(playerid,"~r~��� ��������� �����!",3000,2);
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
    extract invparams-> new to_player;else return SCM(playerid,0xCECECEFF, !"�����������: /givemoneyinv [id ������]");
    if(!IsPlayerLogged(to_player) || !IsPlayerConnected(to_player)) return SCM(playerid,0xCECECEFF,!"����� �� � ����.");
    if(GiveMoneyToInv(to_player))  SCM(playerid,0xCAA500E8, !"�������!");
    else SCM(playerid,0xCA6200E8, !"�������� ������");
    return true;
}
CMD:giveitem(playerid,params[]) 
{
    if(!CheckAdmin(playerid,6)) return 0;
    extract params-> new itemid, count; else return SCM(playerid,0xCECECEFF, !"�����������: /giveitem [id ��������] [���-��]");
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
//                     SCM(playerid,-1,"�� ���");
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
//         SendPacket(2, playerid, CefShow, "InventoryNew", str_1);
//     }
//     else
//     {
//         InterfaceStatus[playerid][iInventory] = 0;
// 		SendPacket(1,playerid, CefHide, "InventoryNew");
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
// 		if(typeitem == 1) // �������
// 		{
// 			f(str_q, sizeof str_q, "[1,%d,%d,0,\"\",0,%d,1.0],", slot, item, count);
// 	 		pInfo[playerid][P_InvWeight] += 1.00;
// 		}
//         if(typeitem == 2) // ����
//         {
// 			f(str_q, sizeof str_q, "[1,%d,100,%d,\"\",%d,1,5.0,%d],", slot, skin_id,slot,iznos+1);
// 	 	    pInfo[playerid][P_InvWeight] += 5.00;
//         }
//         if(typeitem == 3) f(str_q, sizeof str_q, "[1,%d,0,0,\"\",0,%d,0.0],", slot, pInfo[playerid][P_MONEY]); // ������
//         if(typeitem == 4) { // ���������
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
// 	extract params -> new to_player, item, count; else return SendClientMessage(playerid, 0xff9300ff, "�����������: {cecece}/giveitem [ID ������] [����] [���-��]");
//     if(to_player == INVALID_PLAYER_ID) return SCM(playerid, 0xff9300ff, "������: {cecece}����� �� ������!");
//     if(InventorySlot(to_player) == -1) return scmf(playerid, 0xff9300ff, "������: {cecece}� %s[%d]: ������������ ������ � ���������", PN(to_player), to_player);
//     GiveItem(to_player, item, count, 1);
//     scmf(to_player, 0xff9300ff, "������������� %s[%d]:{cecece} ����� ��� �������: %d, � ����������: %d", PN(playerid), playerid,item, count);
//     scmf(playerid, 0xff9300ff, "�� ������ �������: {cecece}%s[%d] %d, � ����������: %d",PN(to_player), to_player, item, count);
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
//                     scmf(playerid, 0xff9300ff, "[�����������] {ffffff}�� ������� ������ ������: �%d",skin_id);
//                     UpdateDataInt(playerid, "SkinBD", id);
//                     UpdateDataInt(playerid, "Skin", skin_id);
//                     pInfo[playerid][P_SKINBD] = id;
//                     SetPlayerSkin(playerid, skin_id);
//                 }
//                 else {
//                     scmf(playerid, 0xff9300ff, "[�����������] {ffffff}�� ������� ����� ������: �%d",skin_id);
//                     if(pInfo[playerid][P_SEX] == 1) skin_id = 252;
//                     else skin_id = 75;
//                     pInfo[playerid][P_SKINBD] = -1;
//                     UpdateDataInt(playerid, "SkinBD", -1);
//                     UpdateDataInt(playerid, "Skin", skin_id);
//                     SetPlayerSkin(playerid, skin_id);
//                 }
//                 SendPacket(1, playerid, CefHide, "InventoryNew");
//             }
//             case 4: {
//                 GameText(playerid, "����������� ��������� � ������ ��� �����������", 2000, 2);
//                 LoadInventory(playerid);
//                 format(str_q, sizeof str_q, "interface('InventoryNew').setItems([%s])",str_1);
//                 SendPacket(1,playerid, CefUpdate, str_q);
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