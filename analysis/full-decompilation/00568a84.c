
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00568a84(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  void *pvVar10;
  char *pcVar11;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar12;
  
  FUN_00634c24();
  FUN_00636080();
  cVar5 = (**(code **)(*extraout_ECX + 200))();
  if (cVar5 != '\0') {
    uVar6 = FUN_005dbf32();
    goto LAB_00569822;
  }
  uVar6 = FUN_005dbf32();
  if ((char)uVar6 == '\0') goto LAB_00569822;
  FUN_0057a7f7(s_station_vacation_006c7ac4,0xffffffff);
  FUN_0057a7f7(s_setambience_beach_006cabec,0xffffffff);
  FUN_0046f824(unaff_EBP + -0x2c0,0,0x104);
  *(undefined ***)(unaff_EBP + -0x2cc) = &PTR_FUN_006664e8;
  FUN_00425531(unaff_EBP + -0x2cc);
  FUN_006358b0(unaff_EBP + -0xacc,*(undefined4 *)(unaff_EBP + -0x2c8));
  FUN_006358c0(unaff_EBP + -0xacc,s__Houses_House40_iff_006ce440);
  FUN_005d4956(unaff_EBP + -0xacc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar5 = FUN_005ed4a5(unaff_EBP + -0x20);
  *(char *)(unaff_EBP + -0x11) = '\x01' - (cVar5 != '\0');
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  if (*(char *)(unaff_EBP + -0x11) != '\0') {
    *(undefined4 *)(unaff_EBP + -0x10) = 0x28;
    do {
      FUN_006358b0(unaff_EBP + -0xacc,*(undefined4 *)(unaff_EBP + -0x2c8));
      FUN_00635858(unaff_EBP + -0x108,s_____TemplateVacation_House_d_iff_006ce41c,
                   *(undefined4 *)(unaff_EBP + -0x10));
      FUN_006358c0(unaff_EBP + -0xacc,unaff_EBP + -0x108);
      FUN_006358b0(unaff_EBP + -0x12cc,*(undefined4 *)(unaff_EBP + -0x2c8));
      FUN_00635858(unaff_EBP + -0x108,s__Houses_House_d_iff_006cd980,
                   *(undefined4 *)(unaff_EBP + -0x10));
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
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < 0x31);
    FUN_006358b0(unaff_EBP + -0xacc,*(undefined4 *)(unaff_EBP + -0x2c8));
    FUN_006358c0(unaff_EBP + -0xacc,s_____TemplateVacation_VIDesc_iff_006ce3fc);
    FUN_006358b0(unaff_EBP + -0x12cc,*(undefined4 *)(unaff_EBP + -0x2c8));
    FUN_006358c0(unaff_EBP + -0x12cc,s__Houses_VIDesc_iff_006ce3e8);
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
  iVar7 = _strcmp(DAT_006f6188,&DAT_006de560);
  if (iVar7 == 0) {
    FUN_0056b55f();
  }
  if ((char)extraout_ECX[0x4a] == '\0') {
    (**(code **)(*extraout_ECX + 0x90))(0x20,1);
  }
  FUN_005e47ab(0,s_UI_Nhood_click_006cd914,0,0);
  piVar8 = extraout_ECX + 0x4b;
  if ((undefined4 *)extraout_ECX[0x4b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[0x4b])(1);
    *piVar8 = 0;
  }
  if (*piVar8 == 0) {
    FUN_0046f824(unaff_EBP + -0x144,0,0x104);
    *(undefined ***)(unaff_EBP + -0x150) = &PTR_FUN_006664e8;
    FUN_00425531(unaff_EBP + -0x150);
    FUN_006358b0(unaff_EBP + -0xacc,*(undefined4 *)(unaff_EBP + -0x14c));
    FUN_006358c0(unaff_EBP + -0xacc,s_island_jpg_006ce3dc);
    iVar7 = FUN_004b845d(unaff_EBP + -0xacc);
    *piVar8 = iVar7;
    if (iVar7 != 0) {
      FUN_006358b0(unaff_EBP + -0xacc,*(undefined4 *)(unaff_EBP + -0x14c));
      FUN_006358c0(unaff_EBP + -0xacc,s_island0_jpg_006ce3d0);
      iVar7 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x75] = iVar7;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_island1_jpg_006ce3c4);
      iVar7 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x76] = iVar7;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_island2_jpg_006ce3b8);
      iVar7 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x77] = iVar7;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_island3_jpg_006ce3ac);
      iVar7 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x78] = iVar7;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_island4_jpg_006ce3a0);
      iVar7 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x79] = iVar7;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_island5_jpg_006ce394);
      iVar7 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x7a] = iVar7;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_islandPort_jpg_006ce384);
      iVar7 = FUN_004b845d(unaff_EBP + -0xacc);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x14c);
      extraout_ECX[0x50] = iVar7;
      FUN_006358b0(unaff_EBP + -0xacc,uVar6);
      FUN_006358c0(unaff_EBP + -0xacc,s_islandTrees_jpg_006ce374);
      iVar7 = FUN_004b845d(unaff_EBP + -0xacc);
      extraout_ECX[0x51] = iVar7;
    }
    if (*piVar8 == 0) {
      FUN_005a5631(0x1540,piVar8,4);
      FUN_005a5631(0x1542,extraout_ECX + 0x50,4);
      FUN_005a5631(0x1543,extraout_ECX + 0x51,4);
      FUN_005a5631(0x1522,extraout_ECX + 0x75,4);
      FUN_005a5631(0x1523,extraout_ECX + 0x76,4);
      FUN_005a5631(0x1524,extraout_ECX + 0x77,4);
      FUN_005a5631(0x1525,extraout_ECX + 0x78,4);
      FUN_005a5631(0x1526,extraout_ECX + 0x79,4);
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
    piVar8 = (int *)extraout_ECX[0x4d];
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 0x68))(DAT_006f2a64);
    }
  }
  if ((extraout_ECX[0x4f] == 0) && ((char)extraout_ECX[0x4a] == '\0')) {
    FUN_005a5631(0x1538,extraout_ECX + 0x4f,4);
    piVar8 = (int *)extraout_ECX[0x4f];
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 0x68))(DAT_006f2a64);
    }
  }
  if ((extraout_ECX[0x4c] == 0) && (800 < extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    FUN_005a5631(0x1389,extraout_ECX + 0x4c,4);
  }
  cVar5 = *(char *)(DAT_006e486c + 100);
  if (cVar5 != '\x01') {
    if (cVar5 == '\x03') {
      _DAT_006ce348 = 0x1534;
    }
    else if (cVar5 == '\x04') {
      _DAT_006ce348 = 0x1535;
    }
    else if (cVar5 == '\x06') {
      _DAT_006ce348 = 0x1533;
    }
    else if (cVar5 == '\x0f') {
      _DAT_006ce348 = 0x1536;
    }
    else {
      _DAT_006ce348 = 0x152d;
    }
  }
  piVar8 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
  piVar8 = (int *)(**(code **)(*piVar8 + 0x10))(1,0xc,0,0);
  extraout_ECX[0x52] = (int)piVar8;
  if (piVar8 != (int *)0x0) {
    iVar7 = *piVar8;
    uVar6 = FUN_005dd5e1(0xff,0xff,0xff);
    (**(code **)(iVar7 + 0x20))(uVar6);
  }
  uVar9 = *(uint *)(extraout_ECX[0x4b] + 0x1c);
  uVar2 = *(uint *)(extraout_ECX[0x4b] + 0x20);
  if (uVar9 < (uint)(extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    uVar9 = (extraout_ECX[0x21] - extraout_ECX[0x1f]) - uVar9 >> 1;
  }
  else {
    uVar9 = 0;
  }
  extraout_ECX[0x53] = uVar9;
  if (uVar2 < (uint)(extraout_ECX[0x22] - extraout_ECX[0x20])) {
    uVar9 = (extraout_ECX[0x22] - extraout_ECX[0x20]) - uVar2 >> 1;
  }
  else {
    uVar9 = 0;
  }
  extraout_ECX[0x54] = uVar9;
  *(undefined1 *)(extraout_ECX + 0x73) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1cd) = 1;
  FUN_005dadff(extraout_ECX,1000,0);
  if (((char)extraout_ECX[0x4a] == '\0') && (800 < extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    pvVar10 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x28) = pvVar10;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    if (pvVar10 == (void *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)FUN_005e372a();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x66] = (int)piVar8;
    (**(code **)(*piVar8 + 0x19c))(extraout_ECX[0x4c],1,1);
    *(undefined1 *)(extraout_ECX[0x66] + 0x16b) = 0;
    FUN_005e4817(0,0,0,0);
    piVar8 = (int *)extraout_ECX[0x66];
    if ((char)piVar8[0x5a] != '\0') {
      *(undefined1 *)(piVar8 + 0x5a) = 0;
      (**(code **)(*piVar8 + 0x168))();
    }
    (**(code **)(*(int *)extraout_ECX[0x66] + 0x90))(0x10,0);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x66]);
    (**(code **)(*(int *)extraout_ECX[0x66] + 0x90))(0x400,0);
  }
  else {
    extraout_ECX[0x66] = 0;
  }
  pvVar10 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x28) = pvVar10;
  *(undefined4 *)(unaff_EBP + -4) = 6;
  if (pvVar10 == (void *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x65] = (int)piVar8;
  (**(code **)(*piVar8 + 0x19c))(extraout_ECX[0x4b],1,1);
  FUN_004cb21d(extraout_ECX[0x53],extraout_ECX[0x54]);
  *(undefined1 *)(extraout_ECX[0x65] + 0x16b) = 0;
  FUN_005e4817(0,0,0,0);
  piVar8 = (int *)extraout_ECX[0x65];
  if ((char)piVar8[0x5a] != '\0') {
    *(undefined1 *)(piVar8 + 0x5a) = 0;
    (**(code **)(*piVar8 + 0x168))();
  }
  (**(code **)(*(int *)extraout_ECX[0x65] + 0x90))(0x400,0);
  (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x65]);
  iVar7 = extraout_ECX[0x54];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x28) = iVar7;
  *(int *)(unaff_EBP + -0x24) = extraout_ECX[0x53];
  do {
    pvVar10 = operator_new(0x26c);
    *(void **)(unaff_EBP + -0x34) = pvVar10;
    *(undefined4 *)(unaff_EBP + -4) = 7;
    if (pvVar10 == (void *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)FUN_0054e24d(extraout_ECX,(char)extraout_ECX[0x4a] == '\0');
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    piVar1 = extraout_ECX + *(int *)(unaff_EBP + -0x10) + 0x55;
    *piVar1 = (int)piVar8;
    cVar5 = (**(code **)(*piVar8 + 0xc))();
    if (cVar5 != '\0') {
      iVar7 = *(int *)(unaff_EBP + -0x10);
      switch(iVar7) {
      case 0:
        iVar7 = 3;
        break;
      case 1:
        iVar7 = 2;
        break;
      case 2:
        iVar7 = 1;
        break;
      case 3:
        iVar7 = 7;
        break;
      case 4:
        iVar7 = 6;
        break;
      case 5:
        iVar7 = 5;
        break;
      case 6:
        iVar7 = 4;
        break;
      case 7:
        iVar7 = 9;
        break;
      case 8:
        iVar7 = 8;
        break;
      case 9:
        iVar7 = 10;
      }
      FUN_0054e5e9(iVar7 + 0x27);
      iVar7 = *piVar1;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (iVar7 != -0x194) {
        *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar7 + 0x208);
        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar7 + 0x20c);
        if (*(int *)(iVar7 + 0x1ec) < 0) {
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *(int *)(iVar7 + 0x1ec);
        }
        if (*(int *)(iVar7 + 0x1f0) < 0) {
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + *(int *)(iVar7 + 0x1f0);
        }
      }
      Sleep(0x32);
      FUN_0054ec7a(unaff_EBP + -0x1c);
      iVar7 = *piVar1;
      iVar3 = *(int *)(unaff_EBP + -0x24);
      iVar4 = *(int *)(unaff_EBP + -0x28);
      *(int *)(iVar7 + 0x230) = iVar3;
      *(int *)(iVar7 + 0x234) = iVar4;
      *(int *)(iVar7 + 0x238) = iVar3 + 800;
      *(int *)(iVar7 + 0x23c) = iVar4 + 600;
      (**(code **)(*(int *)*piVar1 + 0x90))(0x10,0);
      (**(code **)(*(int *)extraout_ECX[0x65] + 0x20))(*piVar1);
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 9);
  _DAT_006f6264 = 0;
  _DAT_006f6260 = 5;
  pvVar10 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x34) = pvVar10;
  *(undefined4 *)(unaff_EBP + -4) = 8;
  if (pvVar10 == (void *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[100] = (int)piVar8;
  (**(code **)(*piVar8 + 0x19c))(extraout_ECX[0x4d],1,1);
  (**(code **)(*(int *)extraout_ECX[100] + 0x90))(0x400,0);
  *(undefined1 *)(extraout_ECX[100] + 0x16b) = 0;
  FUN_005e4817(0,0,0,0);
  piVar8 = (int *)extraout_ECX[100];
  if ((char)piVar8[0x5a] != '\0') {
    *(undefined1 *)(piVar8 + 0x5a) = 0;
    (**(code **)(*piVar8 + 0x168))();
  }
  (**(code **)(*(int *)extraout_ECX[0x65] + 0x20))(extraout_ECX[100]);
  if ((char)extraout_ECX[0x4a] == '\0') {
LAB_005696c4:
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x1bc) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0xe;
    uVar6 = FUN_0041532c(9,unaff_EBP + -0x1bc,0);
    cVar5 = FUN_004fff98(0xd5,uVar6);
    if (cVar5 == '\0') {
      pcVar11 = s_Choose_Destination____006cd88c;
    }
    else {
      uVar6 = 0xffffffff;
      iVar7 = _rand();
      pcVar11 = (char *)FUN_004705f2(iVar7 % 3 + 1,uVar6);
    }
    FUN_005d4bbf(pcVar11);
    uVar6 = FUN_0056cbbd();
    FUN_0056c0e0();
    FUN_0054de9c(uVar6);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  else {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xac) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 9;
    uVar6 = FUN_0041532c(9,unaff_EBP + -0xac,0);
    cVar5 = FUN_004fff98(0xaa,uVar6);
    if (cVar5 != '\0') {
      FUN_00471655(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      do {
        pvVar10 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x34) = pvVar10;
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        if (pvVar10 == (void *)0x0) {
          iVar7 = 0;
        }
        else {
          iVar7 = FUN_005e372a();
        }
        iVar3 = *(int *)(unaff_EBP + -0x10);
        *(undefined1 *)(unaff_EBP + -4) = 10;
        piVar8 = extraout_ECX + iVar3 + 0x5f;
        *piVar8 = iVar7;
        if (iVar7 != 0) {
          FUN_005a5631(*(undefined4 *)(&DAT_006ce340 + iVar3 * 4),unaff_EBP + -0x24,4);
          uVar6 = 0;
          if (*(int **)(unaff_EBP + -0x24) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x68))(DAT_006f2a64);
            uVar6 = *(undefined4 *)(unaff_EBP + -0x24);
          }
          if (*(int *)(unaff_EBP + -0x10) == 2) {
            uVar12 = 1;
            iVar7 = *(int *)extraout_ECX[0x61];
          }
          else {
            uVar12 = 4;
            iVar7 = *(int *)*piVar8;
          }
          (**(code **)(iVar7 + 0x19c))(uVar6,uVar12,1);
          FUN_004cb21d(*(undefined4 *)(&DAT_006f6250 + *(int *)(unaff_EBP + -0x10) * 8),
                       *(undefined4 *)(&DAT_006f6254 + *(int *)(unaff_EBP + -0x10) * 8));
          *(undefined1 *)(*piVar8 + 0x16b) = 1;
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
          (**(code **)(*(int *)extraout_ECX[100] + 0x20))(*piVar8);
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < 5);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_0042004f();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
    if ((char)extraout_ECX[0x4a] == '\0') goto LAB_005696c4;
  }
  FUN_0056b2f2(0);
  FUN_005e6125(&DAT_006c9c58,FUN_0056b875,extraout_ECX,s_Usage__load__house_num___between_006cd860);
  FUN_005e6125(s_stream_fps_006cd81c,FUN_0056b875,extraout_ECX,
               s_Usage__stream_fps__max_frames_pe_006cd828);
  FUN_005e6125(s_nessie_006cd7f4,FUN_0056b875,extraout_ECX,
               s_Usage__nessie__Same_as_SimCity__006cd7fc);
  FUN_005e6125(s_move_lots_006cd7a4,FUN_0056b875,extraout_ECX,
               s_Usage__move_lots_to_enter_lot_mo_006cd7b0);
  *(undefined1 *)(extraout_ECX + 0x1b) = 1;
  extraout_ECX[0x7d] = *(int *)(DAT_006fe8f4 + 0x1fc);
  *(int **)(DAT_006fe8f4 + 0x1fc) = extraout_ECX;
  FUN_005dadbc(0,1);
  FUN_005db1e2();
  FUN_0056b9c4();
  iVar7 = 0;
  if ((DAT_006e486c != 0) && (iVar7 = *(int *)(DAT_006e486c + 0x2c), iVar7 != 0)) {
    *(undefined4 *)(iVar7 + 0x60) = 100;
  }
  uVar6 = CONCAT31((int3)((uint)iVar7 >> 8),1);
LAB_00569822:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

