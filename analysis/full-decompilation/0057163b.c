
undefined1 FUN_0057163b(void)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  int extraout_ECX;
  undefined1 uVar9;
  int unaff_EBP;
  char *pcVar10;
  
  FUN_00634c24();
  FUN_005d499c();
  FUN_005d499c();
  FUN_005d499c();
  *(undefined ***)(unaff_EBP + -0x54) = &PTR_LAB_00669c88;
  *(int **)(extraout_ECX + 0x10) = &DAT_006f6398;
  iVar2 = DAT_006f6398;
  *(int **)(unaff_EBP + -0x50) = &DAT_006f6398;
  (**(code **)(iVar2 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00412a04();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b86bd();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401729();
  FUN_00412a04();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b86bd();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_00401729();
  DAT_006fecc4 = (int *)(**(code **)(*DAT_006fe8bc + 0x14))();
  iVar2 = (**(code **)(*DAT_006fecc4 + 0x14))();
  if (iVar2 == 0) {
    uVar9 = 0;
  }
  else {
    pvVar3 = operator_new(0x21a8);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    if (pvVar3 == (void *)0x0) {
      DAT_006f6a78 = 0;
    }
    else {
      DAT_006f6a78 = FUN_0057c69a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_0057ca49();
    FUN_005725c4();
    puVar8 = *(undefined4 **)(extraout_ECX + 0xd0);
    puVar4 = (undefined4 *)*puVar8;
    *(undefined4 **)(unaff_EBP + -0x40) = puVar4;
    while (*(undefined4 **)(unaff_EBP + 8) = puVar4, puVar4 != puVar8) {
      FUN_005725c4();
      puVar4 = (undefined4 *)**(undefined4 **)(unaff_EBP + 8);
    }
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff6c;
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff68;
    FUN_00602c56();
    FUN_00575efb();
    FUN_0057c0d8();
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 0x3c) = pvVar3;
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 0x40) = pvVar3;
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 0x44) = pvVar3;
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 0x48) = pvVar3;
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 0x4c) = pvVar3;
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 0x50) = pvVar3;
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 0x54) = pvVar3;
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 0x58) = pvVar3;
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 0x5c) = pvVar3;
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 0x60) = pvVar3;
    pvVar3 = operator_new(0x10);
    *(void **)(extraout_ECX + 100) = pvVar3;
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0xb4) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0xb8) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0xbc) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0xc0) = pvVar3;
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0xa4) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0xa8) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0xac) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0xb0) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x98) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x9c) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0xa0) = pvVar3;
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x8c) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x90) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x94) = pvVar3;
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x88) = pvVar3;
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x84) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x7c) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x80) = pvVar3;
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 2) != 0) {
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x68) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x6c) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x70) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x74) = pvVar3;
      pvVar3 = operator_new(0x10);
      *(void **)(extraout_ECX + 0x78) = pvVar3;
    }
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
    FUN_005d4956(s_Music_Stations_Country_006cef6c);
    FUN_00574d8b(extraout_ECX,0x104,0);
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
    FUN_005d4956(s_Music_Stations_Rock_006cef58);
    FUN_00574d8b(extraout_ECX,0x118,0);
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
    FUN_005d4956(s_Music_Stations_Latin_006cef40);
    FUN_00574d8b(extraout_ECX,0x10e,0);
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
    FUN_005d4956(s_Music_Stations_Classica_006cef28);
    FUN_00574d8b(extraout_ECX,0x10d,0);
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
    FUN_005d4956(s_Music_Modes_Buy_006cef18);
    FUN_00574d8b(extraout_ECX,0,1);
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
    FUN_005d4956(s_Music_Modes_Build_006cef04);
    FUN_00574d8b(extraout_ECX,0,1);
    if (*(char *)(DAT_006e486c + 100) == '\x01') {
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      pcVar10 = s_Music_Modes_NhoodUS_006ceef0;
    }
    else {
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      pcVar10 = s_Music_Modes_Nhood_006ceedc;
    }
    FUN_005d4956(pcVar10);
    FUN_00574d8b(extraout_ECX,0,1);
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Modes_MakinMagic_006ceec4);
      FUN_00574d8b(extraout_ECX,0,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Modes_MM_Credits_006ceeac);
      FUN_00574d8b(extraout_ECX,0,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Modes_MM_Build_006cee94);
      FUN_00574d8b(extraout_ECX,0,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Modes_MM_Buy_006cee80);
      FUN_00574d8b(extraout_ECX,0,1);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_ExpansionPack6_Sound_TVStations__006cee58);
      FUN_00574d8b(extraout_ECX,0x19258,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_ExpansionPack6_Sound_TVStations__006cee28);
      FUN_00574d8b(extraout_ECX,0x19259,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_ExpansionPack6_Sound_TVStations__006cee00);
      FUN_00574d8b(extraout_ECX,0x1925a,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_ExpansionPack6_Sound_TVStations__006cedd8);
      FUN_00574d8b(extraout_ECX,0x1925b,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_Superstar_006cedbc);
      FUN_00574d8b(extraout_ECX,0x18704,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Modes_SuperStar_006ceda4);
      FUN_00574d8b(extraout_ECX,0,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_Superstar_006cedbc);
      FUN_00574d8b(extraout_ECX,0,1);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_UnlCheap_006ced8c);
      FUN_00574d8b(extraout_ECX,0x5974,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_UnlSpeak_006ced74);
      FUN_00574d8b(extraout_ECX,0x5975,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_UnlSpeak_006ced74);
      FUN_00574d8b(extraout_ECX,0x5976,1);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Modes_Vacation_006ced5c);
      FUN_00574d8b(extraout_ECX,0,1);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Modes_dt_nhood_006ced44);
      FUN_00574d8b(extraout_ECX,0,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_EZ_006ced30);
      FUN_00574d8b(extraout_ECX,0x10000,1);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_EZExp_006ced18);
      FUN_00574d8b(extraout_ECX,0x10001,1);
    }
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
    FUN_005d4956(s_SoundData_TVStations_TV_Action_006cecf8);
    FUN_00574d8b(extraout_ECX,0x1c,1);
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
    FUN_005d4956(s_SoundData_TVStations_TV_Comedy_C_006cecd0);
    FUN_00574d8b(extraout_ECX,0x1d,1);
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
    FUN_005d4956(s_SoundData_TVStations_TV_Romance_006cecb0);
    FUN_00574d8b(extraout_ECX,0x1a,1);
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
    FUN_005d4956(s_SoundData_TVStations_TV_Mystery_006cec90);
    FUN_00574d8b(extraout_ECX,0x1b,1);
    if ((*(byte *)(DAT_006e486c + 0x66) & 2) != 0) {
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_CountryD_006cec78);
      FUN_00574d8b(extraout_ECX,0x1a19,0);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_Rap_006cec64);
      FUN_00574d8b(extraout_ECX,0x1a1a,0);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_Rave_006cec50);
      FUN_00574d8b(extraout_ECX,0x1a1b,0);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_Disco_006cec38);
      FUN_00574d8b(extraout_ECX,0x1a1c,0);
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff60;
      FUN_005d4956(s_Music_Stations_Beach_006cec20);
      FUN_00574d8b(extraout_ECX,0x1a1d,0);
    }
    FUN_00576a4f();
    FUN_00576a4f();
    FUN_00576a4f();
    FUN_00576a4f();
    if ((*(byte *)(DAT_006e486c + 0x66) & 2) != 0) {
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
      FUN_00576a4f();
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
      FUN_00576a4f();
    }
    pvVar3 = operator_new(0x2c);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    if (pvVar3 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_0057710a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(extraout_ECX + 0xfc) = uVar5;
    FUN_005d4956();
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_00412ab1();
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_005b86bd();
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    FUN_00401729();
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    FUN_005b8770();
    pvVar3 = operator_new(0x40c0);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    if (pvVar3 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00577522();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    *(undefined4 *)(extraout_ECX + 0x104) = uVar5;
    FUN_005d4956();
    piVar1 = *(int **)(extraout_ECX + 0x104);
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    (**(code **)(*piVar1 + 100))();
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    FUN_005b8770();
    if ((*(byte *)(DAT_006e486c + 0x66) & 0xc) != 0) {
      uVar5 = FUN_005d4956(s_ExpansionShared_Sound_Beach__006cebe0);
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      uVar5 = FUN_00412ab1(unaff_EBP + -0x3c,&DAT_006f6388,uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_005b86bd(uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      FUN_005d499c(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
      pvVar3 = operator_new(0x40c0);
      *(void **)(unaff_EBP + 8) = pvVar3;
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      if (pvVar3 == (void *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_00577522();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      *(undefined4 *)(extraout_ECX + 0x108) = uVar5;
      uVar6 = FUN_005d4956(s_beach_fsc_006cebd4);
      piVar1 = *(int **)(extraout_ECX + 0x108);
      uVar5 = *(undefined4 *)(extraout_ECX + 0xfc);
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      (**(code **)(*piVar1 + 100))(unaff_EBP + -0x30,uVar6,uVar5,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
      uVar5 = FUN_005d4956(s_ExpansionShared_Sound_Park__006cebb8);
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      uVar5 = FUN_00412ab1(unaff_EBP + -0x24,&DAT_006f6388,uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0x16;
      FUN_005b86bd(uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0x17;
      FUN_005d499c(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 0x16;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
      pvVar3 = operator_new(0x40c0);
      *(void **)(unaff_EBP + 8) = pvVar3;
      *(undefined1 *)(unaff_EBP + -4) = 0x18;
      if (pvVar3 == (void *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_00577522();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      *(undefined4 *)(extraout_ECX + 0x10c) = uVar5;
      uVar5 = FUN_005d4956(s_hotdatepark_amb_fsc_006ceba4);
      piVar1 = *(int **)(extraout_ECX + 0x10c);
      *(undefined1 *)(unaff_EBP + -4) = 0x19;
      (**(code **)(*piVar1 + 100))(unaff_EBP + -0x30,uVar5,*(undefined4 *)(extraout_ECX + 0xfc),0);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
      uVar5 = FUN_005d4956(s_SoundData_MTOutdoors__006ceb8c);
      *(undefined1 *)(unaff_EBP + -4) = 0x1a;
      uVar5 = FUN_00412ab1(unaff_EBP + -0x24,&DAT_006f6388,uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0x1b;
      FUN_005b86bd(uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0x1c;
      FUN_005d499c(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 0x1b;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0x1a;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
      pvVar3 = operator_new(0x40c0);
      *(void **)(unaff_EBP + 8) = pvVar3;
      *(undefined1 *)(unaff_EBP + -4) = 0x1d;
      if (pvVar3 == (void *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_00577522();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      *(undefined4 *)(extraout_ECX + 0x110) = uVar5;
      uVar6 = FUN_005d4956(s_magic_amb_fsc_006ceb7c);
      piVar1 = *(int **)(extraout_ECX + 0x110);
      uVar5 = *(undefined4 *)(extraout_ECX + 0xfc);
      *(undefined1 *)(unaff_EBP + -4) = 0x1e;
      (**(code **)(*piVar1 + 100))(unaff_EBP + -0x30,uVar6,uVar5,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
    }
    FUN_00574acc();
    puVar7 = operator_new(8);
    *(undefined1 **)(extraout_ECX + 0x14) = puVar7;
    *puVar7 = 0;
    *(undefined4 *)(puVar7 + 4) = 0;
    puVar7 = *(undefined1 **)(extraout_ECX + 0x14);
    piVar1 = (int *)(puVar7 + 4);
    *piVar1 = *piVar1 + 1;
    *puVar7 = 1;
    pvVar3 = operator_new(0x20);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 0x1f;
    if (pvVar3 == (void *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8 = (undefined4 *)FUN_005ed88f();
    }
    *(undefined4 **)(extraout_ECX + 0x1c) = puVar8;
    puVar8 = (undefined4 *)*puVar8;
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    (*(code *)*puVar8)(5);
    (**(code **)(**(int **)(extraout_ECX + 0x1c) + 0x20))(FUN_00573076,extraout_ECX);
    FUN_0057310e();
    *(undefined4 *)(extraout_ECX + 8) = 0;
    *(undefined4 *)(extraout_ECX + 0x18) = 0;
    *(undefined1 *)(extraout_ECX + 0xe) = 1;
    *(undefined1 *)(extraout_ECX + 0xf) = 1;
    DAT_006f63bc = 1;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005b8770();
    uVar9 = 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  iVar2 = DAT_006f6398;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar2 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar9;
}

