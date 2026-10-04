
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0054a15f(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  void *pvVar9;
  char *pcVar10;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  FUN_00636080();
  cVar5 = (**(code **)(*extraout_ECX + 200))();
  if (cVar5 != '\0') {
    uVar6 = FUN_005dbf32();
    goto LAB_0054ae6c;
  }
  uVar6 = FUN_005dbf32();
  if ((char)uVar6 == '\0') goto LAB_0054ae6c;
  FUN_0046f824(unaff_EBP + -0x2c0,0,0x104);
  *(undefined ***)(unaff_EBP + -0x2cc) = &PTR_FUN_006664e8;
  FUN_00425531(unaff_EBP + -0x2cc);
  FUN_006358b0(unaff_EBP + -0xacc,*(undefined4 *)(unaff_EBP + -0x2c8));
  FUN_006358c0(unaff_EBP + -0xacc,s__Houses_House21_iff_006cd9b8);
  FUN_005d4956(unaff_EBP + -0xacc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar5 = FUN_005ed4a5(unaff_EBP + -0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(char *)(unaff_EBP + -0x11) = '\x01' - (cVar5 != '\0');
  FUN_005b8770();
  if (*(char *)(unaff_EBP + -0x11) != '\0') {
    iVar11 = 0x15;
    do {
      FUN_006358b0(unaff_EBP + -0xacc,*(undefined4 *)(unaff_EBP + -0x2c8));
      FUN_00635858(unaff_EBP + -0x108,s_____TemplateDowntown_House_d_iff_006cd994,iVar11);
      FUN_006358c0(unaff_EBP + -0xacc,unaff_EBP + -0x108);
      FUN_006358b0(unaff_EBP + -0x12cc,*(undefined4 *)(unaff_EBP + -0x2c8));
      FUN_00635858(unaff_EBP + -0x108,s__Houses_House_d_iff_006cd980,iVar11);
      FUN_006358c0(unaff_EBP + -0x12cc,unaff_EBP + -0x108);
      FUN_005d4956(unaff_EBP + -0x12cc);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005d4956(unaff_EBP + -0xacc);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005ed4f0(unaff_EBP + -0x20,unaff_EBP + -0x30,1);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar11 = iVar11 + 1;
    } while (iVar11 < 0x1f);
    FUN_006358b0(unaff_EBP + -0xacc,*(undefined4 *)(unaff_EBP + -0x2c8));
    FUN_006358c0(unaff_EBP + -0xacc,s_____TemplateDowntown_DTDesc_iff_006cd960);
    FUN_006358b0(unaff_EBP + -0x12cc,*(undefined4 *)(unaff_EBP + -0x2c8));
    FUN_006358c0(unaff_EBP + -0x12cc,s__Houses_DTDesc_iff_006cd94c);
    FUN_005d4956(unaff_EBP + -0x12cc);
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_005d4956(unaff_EBP + -0xacc);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005ed4f0(unaff_EBP + -0x20,unaff_EBP + -0x30,1);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  FUN_0057a7f7(s_station_dtnhood_006cd93c,0xffffffff);
  FUN_0057a7f7(s_setambience_downtown_006cd924,0xffffffff);
  iVar11 = _strcmp(DAT_006f52b0,&DAT_006de560);
  if (iVar11 == 0) {
    FUN_0054c71c();
  }
  if ((char)extraout_ECX[0x4a] == '\0') {
    (**(code **)(*extraout_ECX + 0x90))(0x20,1);
  }
  FUN_005e47ab(0,s_UI_Nhood_click_006cd914,0,0);
  piVar7 = extraout_ECX + 0x4b;
  if ((undefined4 *)extraout_ECX[0x4b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[0x4b])(1);
    *piVar7 = 0;
  }
  if (*piVar7 == 0) {
    FUN_0046f824(unaff_EBP + -0x144,0,0x104);
    *(undefined ***)(unaff_EBP + -0x150) = &PTR_FUN_006664e8;
    FUN_00425531(unaff_EBP + -0x150);
    FUN_006358b0(unaff_EBP + -0xacc,*(undefined4 *)(unaff_EBP + -0x14c));
    FUN_006358c0(unaff_EBP + -0xacc,s_downtown_jpg_006cd904);
    iVar11 = FUN_004b845d(unaff_EBP + -0xacc);
    *piVar7 = iVar11;
    if (iVar11 != 0) {
      FUN_006358b0(unaff_EBP + -0xacc,*(undefined4 *)(unaff_EBP + -0x14c));
      FUN_006358c0(unaff_EBP + -0xacc,s_downtown0_jpg_006cd8f4);
      iVar11 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x73] = iVar11;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_downtown1_jpg_006cd8e4);
      iVar11 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x74] = iVar11;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_downtown2_jpg_006cd8d4);
      iVar11 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x75] = iVar11;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_downtown3_jpg_006cd8c4);
      iVar11 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x76] = iVar11;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_downtown4_jpg_006cd8b4);
      iVar11 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x77] = iVar11;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_downtown5_jpg_006cd8a4);
      iVar11 = FUN_004b845d(unaff_EBP + -0xacc);
      extraout_ECX[0x78] = iVar11;
    }
    if (*piVar7 == 0) {
      FUN_005a5631(0x14c8,piVar7,4);
      FUN_005a5631(0x1518,extraout_ECX + 0x73,4);
      FUN_005a5631(0x1519,extraout_ECX + 0x74,4);
      FUN_005a5631(0x151a,extraout_ECX + 0x75,4);
      FUN_005a5631(0x151b,extraout_ECX + 0x76,4);
      FUN_005a5631(0x151c,extraout_ECX + 0x77,4);
      FUN_005a5631(0x151d,extraout_ECX + 0x78,4);
    }
  }
  if (extraout_ECX[0x4d] == 0) {
    if ((char)extraout_ECX[0x4a] == '\0') {
      uVar6 = 0x13b5;
    }
    else {
      uVar6 = 0x152e;
    }
    FUN_005a5631(uVar6,extraout_ECX + 0x4d,4);
    piVar7 = (int *)extraout_ECX[0x4d];
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 0x68))(DAT_006f2a64);
    }
  }
  if ((extraout_ECX[0x4f] == 0) && ((char)extraout_ECX[0x4a] == '\0')) {
    FUN_005a5631(0x1538,extraout_ECX + 0x4f,4);
    piVar7 = (int *)extraout_ECX[0x4f];
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 0x68))(DAT_006f2a64);
    }
  }
  if ((extraout_ECX[0x4c] == 0) && (800 < extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    FUN_005a5631(0x1389,extraout_ECX + 0x4c,4);
  }
  cVar5 = *(char *)(DAT_006e486c + 100);
  if (cVar5 != '\x01') {
    if (cVar5 == '\x03') {
      _DAT_006cd778 = 0x1534;
    }
    else if (cVar5 == '\x04') {
      _DAT_006cd778 = 0x1535;
    }
    else if (cVar5 == '\x06') {
      _DAT_006cd778 = 0x1533;
    }
    else if (cVar5 == '\x0f') {
      _DAT_006cd778 = 0x1536;
    }
    else {
      _DAT_006cd778 = 0x152d;
    }
  }
  piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
  piVar7 = (int *)(**(code **)(*piVar7 + 0x10))(1,0xc,0,0);
  extraout_ECX[0x50] = (int)piVar7;
  if (piVar7 != (int *)0x0) {
    iVar11 = *piVar7;
    uVar6 = FUN_005dd5e1(0xff,0xff,0xff);
    (**(code **)(iVar11 + 0x20))(uVar6);
  }
  uVar8 = *(uint *)(extraout_ECX[0x4b] + 0x1c);
  uVar2 = *(uint *)(extraout_ECX[0x4b] + 0x20);
  if (uVar8 < (uint)(extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    uVar8 = (extraout_ECX[0x21] - extraout_ECX[0x1f]) - uVar8 >> 1;
  }
  else {
    uVar8 = 0;
  }
  extraout_ECX[0x51] = uVar8;
  if (uVar2 < (uint)(extraout_ECX[0x22] - extraout_ECX[0x20])) {
    uVar8 = (extraout_ECX[0x22] - extraout_ECX[0x20]) - uVar2 >> 1;
  }
  else {
    uVar8 = 0;
  }
  extraout_ECX[0x52] = uVar8;
  *(undefined1 *)(extraout_ECX + 0x71) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1c5) = 1;
  FUN_005dadff(extraout_ECX,1000,0);
  if (((char)extraout_ECX[0x4a] == '\0') && (800 < extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    pvVar9 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x28) = pvVar9;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    if (pvVar9 == (void *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = (int *)FUN_005e372a();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[100] = (int)piVar7;
    (**(code **)(*piVar7 + 0x19c))(extraout_ECX[0x4c],1,1);
    *(undefined1 *)(extraout_ECX[100] + 0x16b) = 0;
    FUN_005e4817(0,0,0,0);
    piVar7 = (int *)extraout_ECX[100];
    if ((char)piVar7[0x5a] != '\0') {
      *(undefined1 *)(piVar7 + 0x5a) = 0;
      (**(code **)(*piVar7 + 0x168))();
    }
    (**(code **)(*(int *)extraout_ECX[100] + 0x90))(0x10,0);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[100]);
    (**(code **)(*(int *)extraout_ECX[100] + 0x90))(0x400,0);
  }
  else {
    extraout_ECX[100] = 0;
  }
  pvVar9 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x28) = pvVar9;
  *(undefined4 *)(unaff_EBP + -4) = 6;
  if (pvVar9 == (void *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[99] = (int)piVar7;
  (**(code **)(*piVar7 + 0x19c))(extraout_ECX[0x4b],1,1);
  FUN_004cb21d(extraout_ECX[0x51],extraout_ECX[0x52]);
  *(undefined1 *)(extraout_ECX[99] + 0x16b) = 0;
  FUN_005e4817(0,0,0,0);
  piVar7 = (int *)extraout_ECX[99];
  if ((char)piVar7[0x5a] != '\0') {
    *(undefined1 *)(piVar7 + 0x5a) = 0;
    (**(code **)(*piVar7 + 0x168))();
  }
  (**(code **)(*(int *)extraout_ECX[99] + 0x90))(0x400,0);
  (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[99]);
  iVar11 = extraout_ECX[0x52];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x28) = iVar11;
  *(int *)(unaff_EBP + -0x24) = extraout_ECX[0x51];
  do {
    pvVar9 = operator_new(0x26c);
    *(void **)(unaff_EBP + -0x34) = pvVar9;
    *(undefined4 *)(unaff_EBP + -4) = 7;
    if (pvVar9 == (void *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = (int *)FUN_0054e08e(extraout_ECX);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    piVar1 = extraout_ECX + *(int *)(unaff_EBP + -0x10) + 0x53;
    *piVar1 = (int)piVar7;
    cVar5 = (**(code **)(*piVar7 + 0xc))();
    if (cVar5 != '\0') {
      iVar11 = *(int *)(unaff_EBP + -0x10);
      switch(iVar11) {
      case 0:
        iVar11 = 3;
        break;
      case 1:
        iVar11 = 2;
        break;
      case 2:
        iVar11 = 1;
        break;
      case 3:
        iVar11 = 7;
        break;
      case 4:
        iVar11 = 6;
        break;
      case 5:
        iVar11 = 5;
        break;
      case 6:
        iVar11 = 4;
        break;
      case 7:
        iVar11 = 10;
        break;
      case 8:
        iVar11 = 9;
        break;
      case 9:
        iVar11 = 8;
      }
      FUN_0054e5e9(iVar11 + 0x14);
      iVar11 = *piVar1;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (iVar11 != -0x194) {
        *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar11 + 0x208);
        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar11 + 0x20c);
        if (*(int *)(iVar11 + 0x1ec) < 0) {
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *(int *)(iVar11 + 0x1ec);
        }
        if (*(int *)(iVar11 + 0x1f0) < 0) {
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + *(int *)(iVar11 + 0x1f0);
        }
      }
      Sleep(0x32);
      FUN_0054ec7a(unaff_EBP + -0x1c);
      iVar11 = *piVar1;
      iVar3 = *(int *)(unaff_EBP + -0x24);
      iVar4 = *(int *)(unaff_EBP + -0x28);
      *(int *)(iVar11 + 0x230) = iVar3;
      *(int *)(iVar11 + 0x234) = iVar4;
      *(int *)(iVar11 + 0x238) = iVar3 + 800;
      *(int *)(iVar11 + 0x23c) = iVar4 + 600;
      (**(code **)(*(int *)*piVar1 + 0x90))(0x10,0);
      (**(code **)(*(int *)extraout_ECX[99] + 0x20))(*piVar1);
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 10);
  _DAT_006f5374 = 0;
  _DAT_006f5370 = 5;
  pvVar9 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x34) = pvVar9;
  *(undefined4 *)(unaff_EBP + -4) = 8;
  if (pvVar9 == (void *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x62] = (int)piVar7;
  (**(code **)(*piVar7 + 0x19c))(extraout_ECX[0x4d],1,1);
  (**(code **)(*(int *)extraout_ECX[0x62] + 0x90))(0x400,0);
  *(undefined1 *)(extraout_ECX[0x62] + 0x16b) = 0;
  FUN_005e4817(0,0,0,0);
  piVar7 = (int *)extraout_ECX[0x62];
  if ((char)piVar7[0x5a] != '\0') {
    *(undefined1 *)(piVar7 + 0x5a) = 0;
    (**(code **)(*piVar7 + 0x168))();
  }
  (**(code **)(*(int *)extraout_ECX[99] + 0x20))(extraout_ECX[0x62]);
  if ((char)extraout_ECX[0x4a] == '\0') {
LAB_0054ad0e:
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x1bc) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0xe;
    uVar6 = FUN_0041532c(9,unaff_EBP + -0x1bc,0);
    cVar5 = FUN_004fff98(0xd4,uVar6);
    if (cVar5 == '\0') {
      pcVar10 = s_Choose_Destination____006cd88c;
    }
    else {
      uVar6 = 0xffffffff;
      iVar11 = _rand();
      pcVar10 = (char *)FUN_004705f2(iVar11 % 3 + 1,uVar6);
    }
    FUN_005d4bbf(pcVar10);
    uVar6 = FUN_0054dd0a();
    FUN_0054d114();
    FUN_0054de9c(uVar6);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  else {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xac) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 9;
    uVar6 = FUN_0041532c(9,unaff_EBP + -0xac,0);
    cVar5 = FUN_004fff98(0xa9,uVar6);
    if (cVar5 != '\0') {
      FUN_00471655(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      do {
        pvVar9 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x34) = pvVar9;
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        if (pvVar9 == (void *)0x0) {
          iVar11 = 0;
        }
        else {
          iVar11 = FUN_005e372a();
        }
        iVar3 = *(int *)(unaff_EBP + -0x10);
        *(undefined1 *)(unaff_EBP + -4) = 10;
        piVar7 = extraout_ECX + iVar3 + 0x5d;
        *piVar7 = iVar11;
        if (iVar11 != 0) {
          FUN_005a5631(*(undefined4 *)(&DAT_006cd770 + iVar3 * 4),unaff_EBP + -0x24,4);
          uVar6 = 0;
          if (*(int **)(unaff_EBP + -0x24) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x68))(DAT_006f2a64);
            uVar6 = *(undefined4 *)(unaff_EBP + -0x24);
          }
          if (*(int *)(unaff_EBP + -0x10) == 2) {
            uVar12 = 1;
            iVar11 = *(int *)extraout_ECX[0x5f];
          }
          else {
            uVar12 = 4;
            iVar11 = *(int *)*piVar7;
          }
          (**(code **)(iVar11 + 0x19c))(uVar6,uVar12,1);
          FUN_004cb21d(*(undefined4 *)(&DAT_006f5360 + *(int *)(unaff_EBP + -0x10) * 8),
                       *(undefined4 *)(&DAT_006f5364 + *(int *)(unaff_EBP + -0x10) * 8));
          *(undefined1 *)(*piVar7 + 0x16b) = 1;
          FUN_0046fc87(unaff_EBP + -0x2c,0);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          uVar6 = FUN_0046fc7a();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 0xd;
          FUN_005dd9c8(unaff_EBP + -0x40);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_0042004f();
          FUN_005e4817(0,s_UI_Nhood_click_006cd914,0,0);
          (**(code **)(*(int *)extraout_ECX[0x62] + 0x20))(*piVar7);
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < 5);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_0042004f();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
    if ((char)extraout_ECX[0x4a] == '\0') goto LAB_0054ad0e;
  }
  FUN_0054c4af(0);
  FUN_005e6125(&DAT_006c9c58,FUN_0054ca00,extraout_ECX,s_Usage__load__house_num___between_006cd860);
  FUN_005e6125(s_stream_fps_006cd81c,FUN_0054ca00,extraout_ECX,
               s_Usage__stream_fps__max_frames_pe_006cd828);
  FUN_005e6125(s_nessie_006cd7f4,FUN_0054ca00,extraout_ECX,
               s_Usage__nessie__Same_as_SimCity__006cd7fc);
  FUN_005e6125(s_move_lots_006cd7a4,FUN_0054ca00,extraout_ECX,
               s_Usage__move_lots_to_enter_lot_mo_006cd7b0);
  *(undefined1 *)(extraout_ECX + 0x1b) = 1;
  extraout_ECX[0x7b] = *(int *)(DAT_006fe8f4 + 0x1fc);
  *(int **)(DAT_006fe8f4 + 0x1fc) = extraout_ECX;
  FUN_005dadbc(0,1);
  FUN_005db1e2();
  FUN_0054cb4f();
  iVar11 = 0;
  if ((DAT_006e486c != 0) && (iVar11 = *(int *)(DAT_006e486c + 0x2c), iVar11 != 0)) {
    *(undefined4 *)(iVar11 + 0x60) = 100;
  }
  uVar6 = CONCAT31((int3)((uint)iVar11 >> 8),1);
LAB_0054ae6c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

