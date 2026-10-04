
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00556bc9(void)

{
  uint uVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  void *pvVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 != '\0') {
    uVar3 = FUN_005dbf32();
    goto LAB_00557def;
  }
  cVar2 = FUN_005dbf32();
  uVar3 = 0;
  if (cVar2 == '\0') goto LAB_00557def;
  if (DAT_006f58f8 == 0) {
    FUN_0055bce5();
  }
  if (*(char *)((int)extraout_ECX + 0x121) == '\0') {
    (**(code **)(*extraout_ECX + 0x90))(0x20,1);
  }
  FUN_005e47ab(0,s_UI_Nhood_click_006cd914,0,0);
  piVar5 = extraout_ECX + 0x49;
  if ((undefined4 *)extraout_ECX[0x49] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[0x49])(1);
    *piVar5 = 0;
  }
  if (*piVar5 == 0) {
    FUN_0046f824(unaff_EBP + -0x270,0,0x104);
    *(undefined ***)(unaff_EBP + -0x27c) = &PTR_FUN_006664e8;
    FUN_00425531(unaff_EBP + -0x27c);
    FUN_006358b0(unaff_EBP + -0xa7c,*(undefined4 *)(unaff_EBP + -0x278));
    FUN_006358c0(unaff_EBP + -0xa7c,s_neighborhoodul_jpg_006cdfd0);
    iVar4 = FUN_004b845d(unaff_EBP + -0xa7c);
    *piVar5 = iVar4;
    if (iVar4 != 0) {
      FUN_006358b0(unaff_EBP + -0xa7c,*(undefined4 *)(unaff_EBP + -0x278));
      FUN_006358c0(unaff_EBP + -0xa7c,s_neighborhoodul0_jpg_006cdfbc);
      iVar4 = FUN_004b845d(unaff_EBP + -0xa7c);
      uVar12 = *(undefined4 *)(unaff_EBP + -0x278);
      extraout_ECX[0x78] = iVar4;
      FUN_006358b0(unaff_EBP + -0xa7c,uVar12);
      FUN_006358c0(unaff_EBP + -0xa7c,s_neighborhoodul1_jpg_006cdfa8);
      iVar4 = FUN_004b845d(unaff_EBP + -0xa7c);
      uVar12 = *(undefined4 *)(unaff_EBP + -0x278);
      extraout_ECX[0x79] = iVar4;
      FUN_006358b0(unaff_EBP + -0xa7c,uVar12);
      FUN_006358c0(unaff_EBP + -0xa7c,s_neighborhoodul2_jpg_006cdf94);
      iVar4 = FUN_004b845d(unaff_EBP + -0xa7c);
      uVar12 = *(undefined4 *)(unaff_EBP + -0x278);
      extraout_ECX[0x7a] = iVar4;
      FUN_006358b0(unaff_EBP + -0xa7c,uVar12);
      FUN_006358c0(unaff_EBP + -0xa7c,s_neighborhoodul3_jpg_006cdf80);
      iVar4 = FUN_004b845d(unaff_EBP + -0xa7c);
      uVar12 = *(undefined4 *)(unaff_EBP + -0x278);
      extraout_ECX[0x7b] = iVar4;
      FUN_006358b0(unaff_EBP + -0xa7c,uVar12);
      FUN_006358c0(unaff_EBP + -0xa7c,s_neighborhoodul4_jpg_006cdf6c);
      iVar4 = FUN_004b845d(unaff_EBP + -0xa7c);
      uVar12 = *(undefined4 *)(unaff_EBP + -0x278);
      extraout_ECX[0x7c] = iVar4;
      FUN_006358b0(unaff_EBP + -0xa7c,uVar12);
      FUN_006358c0(unaff_EBP + -0xa7c,s_neighborhoodul5_jpg_006cdf58);
      iVar4 = FUN_004b845d(unaff_EBP + -0xa7c);
      extraout_ECX[0x7d] = iVar4;
    }
    if (*piVar5 == 0) {
      if (*(char *)(DAT_006e486c + 100) == '\x01') {
        uVar12 = 6000;
      }
      else {
        uVar12 = 0x18a4;
      }
      FUN_005a5631(uVar12,piVar5,4);
      if (*(char *)(DAT_006e486c + 100) == '\x01') {
        FUN_005a5631(0x189e,extraout_ECX + 0x78,4);
        FUN_005a5631(0x189f,extraout_ECX + 0x79,4);
        FUN_005a5631(0x18a0,extraout_ECX + 0x7a,4);
        FUN_005a5631(0x18ba,extraout_ECX + 0x7b,4);
        FUN_005a5631(0x18bb,extraout_ECX + 0x7c,4);
        uVar12 = 0x18bc;
      }
      else {
        FUN_005a5631(0x18a5,extraout_ECX + 0x78,4);
        FUN_005a5631(0x18a6,extraout_ECX + 0x79,4);
        FUN_005a5631(0x18a7,extraout_ECX + 0x7a,4);
        FUN_005a5631(0x18c0,extraout_ECX + 0x7b,4);
        FUN_005a5631(0x18c1,extraout_ECX + 0x7c,4);
        uVar12 = 0x18c2;
      }
      FUN_005a5631(uVar12,extraout_ECX + 0x7d,4);
    }
  }
  cVar2 = *(char *)(DAT_006e486c + 100);
  if (cVar2 != '\x01') {
    if (cVar2 == '\x03') {
      DAT_006cddc8 = 0x14c0;
    }
    else if (cVar2 == '\x04') {
      DAT_006cddc8 = 0x14c1;
    }
    else if (cVar2 == '\x06') {
      DAT_006cddc8 = 0x14c2;
    }
    else if (cVar2 == '\x0f') {
      DAT_006cddc8 = 0x14c4;
    }
    else {
      DAT_006cddc8 = 0x14c3;
    }
  }
  FUN_005a5631(DAT_006cddc8,extraout_ECX + 0x4d,4);
  piVar5 = (int *)extraout_ECX[0x4d];
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0x68))(DAT_006f2a64);
  }
  if (extraout_ECX[0x4b] == 0) {
    if (*(char *)((int)extraout_ECX + 0x121) == '\0') {
      uVar12 = 0x13b5;
    }
    else {
      uVar12 = 0x152c;
    }
    FUN_005a5631(uVar12,extraout_ECX + 0x4b,4);
  }
  if ((extraout_ECX[0x4c] == 0) && (*(char *)((int)extraout_ECX + 0x121) == '\0')) {
    FUN_005a5631(0x1538,extraout_ECX + 0x4c,4);
    piVar5 = (int *)extraout_ECX[0x4c];
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x68))(DAT_006f2a64);
    }
  }
  if ((extraout_ECX[0x4a] == 0) && (800 < extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    FUN_005a5631(0x1389,extraout_ECX + 0x4a,4);
  }
  piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x10))(1,0xc,0,0);
  extraout_ECX[0x4f] = (int)piVar5;
  if (piVar5 != (int *)0x0) {
    iVar4 = *piVar5;
    uVar12 = FUN_005dd5e1(0xff,0xff,0xff);
    (**(code **)(iVar4 + 0x20))(uVar12);
  }
  uVar6 = *(uint *)(extraout_ECX[0x49] + 0x1c);
  uVar1 = *(uint *)(extraout_ECX[0x49] + 0x20);
  if (uVar6 < (uint)(extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    uVar6 = (extraout_ECX[0x21] - extraout_ECX[0x1f]) - uVar6 >> 1;
  }
  else {
    uVar6 = 0;
  }
  extraout_ECX[0x50] = uVar6;
  if (uVar1 < (uint)(extraout_ECX[0x22] - extraout_ECX[0x20])) {
    uVar6 = (extraout_ECX[0x22] - extraout_ECX[0x20]) - uVar1 >> 1;
  }
  else {
    uVar6 = 0;
  }
  extraout_ECX[0x51] = uVar6;
  if (extraout_ECX[0x4e] == 0) {
    FUN_005a5631(0x1456,extraout_ECX + 0x4e,4);
    iVar4 = extraout_ECX[0x4e];
    DAT_006f5840 = DAT_006cddb4 + extraout_ECX[0x50];
    _DAT_006f5848 = extraout_ECX[0x50] + *(int *)(iVar4 + 0x1c) + DAT_006cddb4;
    _DAT_006f584c = *(int *)(iVar4 + 0x20) + 3 + extraout_ECX[0x51];
    DAT_006f5844 = extraout_ECX[0x51] + 3;
  }
  *(undefined1 *)(extraout_ECX + 0x75) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1d5) = 1;
  if ((*(char *)((int)extraout_ECX + 0x121) == '\0') &&
     (800 < extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    pvVar7 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x24) = pvVar7;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar7 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_005e372a();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x68] = (int)piVar5;
    (**(code **)(*piVar5 + 0x19c))(extraout_ECX[0x4a],1,1);
    *(undefined1 *)(extraout_ECX[0x68] + 0x16b) = 0;
    FUN_005e4817(0,0,0,0);
    piVar5 = (int *)extraout_ECX[0x68];
    if ((char)piVar5[0x5a] != '\0') {
      *(undefined1 *)(piVar5 + 0x5a) = 0;
      (**(code **)(*piVar5 + 0x168))();
    }
    (**(code **)(*(int *)extraout_ECX[0x68] + 0x90))(0x10,0);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x68]);
    (**(code **)(*(int *)extraout_ECX[0x68] + 0x90))(0x400,0);
  }
  else {
    extraout_ECX[0x68] = 0;
  }
  pvVar7 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x24) = pvVar7;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (pvVar7 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x66] = (int)piVar5;
  (**(code **)(*piVar5 + 0x19c))(extraout_ECX[0x49],1,1);
  FUN_004cb21d(extraout_ECX[0x50],extraout_ECX[0x51]);
  *(undefined1 *)(extraout_ECX[0x66] + 0x16b) = 0;
  FUN_005e4817(0,0,0,0);
  piVar5 = (int *)extraout_ECX[0x66];
  if ((char)piVar5[0x5a] != '\0') {
    *(undefined1 *)(piVar5 + 0x5a) = 0;
    (**(code **)(*piVar5 + 0x168))();
  }
  (**(code **)(*(int *)extraout_ECX[0x66] + 0x90))(0x400,0);
  if ((int *)extraout_ECX[0x68] == (int *)0x0) {
    iVar4 = *extraout_ECX;
    iVar11 = extraout_ECX[0x66];
  }
  else {
    iVar4 = *(int *)extraout_ECX[0x68];
    iVar11 = extraout_ECX[0x66];
  }
  (**(code **)(iVar4 + 0x20))(iVar11);
  pvVar7 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x24) = pvVar7;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (pvVar7 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x67] = (int)piVar5;
  (**(code **)(*piVar5 + 0x19c))(extraout_ECX[0x78],1,1);
  *(undefined1 *)(extraout_ECX[0x67] + 0x16b) = 0;
  FUN_005e4817(0,0,0,0);
  piVar5 = (int *)extraout_ECX[0x67];
  if ((char)piVar5[0x5a] != '\0') {
    *(undefined1 *)(piVar5 + 0x5a) = 0;
    (**(code **)(*piVar5 + 0x168))();
  }
  (**(code **)(*(int *)extraout_ECX[0x67] + 0x90))(0x400,0);
  (**(code **)(*(int *)extraout_ECX[0x66] + 0x20))(extraout_ECX[0x67]);
  *(int *)(unaff_EBP + -0x2c) = extraout_ECX[0x51];
  *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x50];
  iVar4 = *(int *)(*(int *)(DAT_006e486c + 0x24) + 0x178);
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(*(int *)(DAT_006e486c + 0x24) + 0x174);
  *(int *)(unaff_EBP + -0x24) = iVar4;
  FUN_005bc36d();
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_005bc41e();
  if (*(int *)(unaff_EBP + -0x10) != iVar4) {
    do {
      if (0x50 < **(int **)(unaff_EBP + -0x10)) break;
      Sleep(10);
      if (*(char *)((int)extraout_ECX + 0x121) == '\0') {
        pvVar7 = operator_new(0x26c);
        *(void **)(unaff_EBP + -0x20) = pvVar7;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        if (pvVar7 == (void *)0x0) goto LAB_00557406;
        uVar10 = 2;
        uVar12 = 1;
LAB_005573fc:
        piVar5 = (int *)FUN_0054dfdb(extraout_ECX,uVar12,uVar10);
      }
      else {
        pvVar7 = operator_new(0x26c);
        *(void **)(unaff_EBP + -0x20) = pvVar7;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        if (pvVar7 != (void *)0x0) {
          uVar10 = 1;
          uVar12 = 0;
          goto LAB_005573fc;
        }
LAB_00557406:
        piVar5 = (int *)0x0;
      }
      *(undefined1 *)(unaff_EBP + -4) = 3;
      cVar2 = (**(code **)(*piVar5 + 0xc))();
      if (cVar2 != '\0') {
        FUN_0054e5e9(**(undefined4 **)(unaff_EBP + -0x10));
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        if (piVar5 != (int *)0xfffffe6c) {
          *(int *)(unaff_EBP + -0x1c) = piVar5[0x82];
          *(int *)(unaff_EBP + -0x18) = piVar5[0x83];
          if (piVar5[0x80] < 0) {
            *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + piVar5[0x80];
          }
          if (piVar5[0x81] < 0) {
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + piVar5[0x81];
          }
        }
        Sleep(0x32);
        FUN_0054ec7a(unaff_EBP + -0x1c);
        iVar4 = *(int *)(unaff_EBP + -0x14);
        iVar11 = *(int *)(unaff_EBP + -0x2c);
        piVar5[0x8c] = iVar4;
        piVar5[0x8d] = iVar11;
        piVar5[0x8e] = iVar4 + 800;
        piVar5[0x8f] = iVar11 + 600;
        (**(code **)(*piVar5 + 0x90))(0x10,0);
        (**(code **)(*piVar5 + 0x90))(0x400,0);
        (**(code **)(*(int *)extraout_ECX[0x67] + 0x20))(piVar5);
        puVar8 = (undefined4 *)FUN_005e7f2f(*(undefined4 *)(unaff_EBP + -0x10));
        *puVar8 = piVar5;
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 8;
    } while (*(int *)(unaff_EBP + -0x10) != *(int *)(unaff_EBP + -0x24));
  }
  FUN_005bc436();
  FUN_005bc44e(unaff_EBP + -0x1c);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  uVar12 = FUN_005bc676();
  wsprintfA((LPSTR)(unaff_EBP + -0xc70),s_Loading_thumbnails_took___d_usec_006cdf34,uVar12);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0042004f();
  OutputDebugStringA((LPCSTR)(unaff_EBP + -0xc70));
  cVar2 = *(char *)(DAT_006e486c + 100);
  if (cVar2 != '\x01') {
    if (cVar2 == '\x03') {
      DAT_006cddc8 = 0x14c0;
      _DAT_006cdddc = 0x1534;
    }
    else if (cVar2 == '\x04') {
      DAT_006cddc8 = 0x14c1;
      _DAT_006cdddc = 0x1535;
    }
    else if (cVar2 == '\x06') {
      DAT_006cddc8 = 0x14c2;
      _DAT_006cdddc = 0x1533;
    }
    else if (cVar2 == '\x0f') {
      DAT_006cddc8 = 0x14c4;
      _DAT_006cdddc = 0x1536;
    }
    else {
      DAT_006cddc8 = 0x14c3;
      _DAT_006cdddc = 0x152d;
    }
  }
  pvVar7 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x20) = pvVar7;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  if (pvVar7 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_005e372a();
  }
  extraout_ECX[99] = (int)piVar5;
  iVar4 = *piVar5;
  iVar11 = extraout_ECX[0x4b];
  *(undefined1 *)(unaff_EBP + -4) = 3;
  (**(code **)(iVar4 + 0x19c))(iVar11,1,1);
  (**(code **)(*(int *)extraout_ECX[99] + 0x90))(0x400,0);
  *(undefined1 *)(extraout_ECX[99] + 0x16b) = 0;
  FUN_005e4817(0,0,0,0);
  piVar5 = (int *)extraout_ECX[99];
  if ((char)piVar5[0x5a] != '\0') {
    *(undefined1 *)(piVar5 + 0x5a) = 0;
    (**(code **)(*piVar5 + 0x168))();
  }
  (**(code **)(*(int *)extraout_ECX[0x67] + 0x20))(extraout_ECX[99]);
  if (*(char *)((int)extraout_ECX + 0x121) == '\0') {
    pvVar7 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x20) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 0x13;
    if (pvVar7 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_005e372a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 3;
    extraout_ECX[0x59] = iVar4;
    if (iVar4 != 0) {
      FUN_005a5631(DAT_006cddc8,unaff_EBP + -0x14,4);
      if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
      }
      (**(code **)(*(int *)extraout_ECX[0x59] + 0x19c))(*(undefined4 *)(unaff_EBP + -0x14),4,1);
      *(undefined1 *)(extraout_ECX[0x59] + 0x16b) = 1;
      FUN_004cb21d(DAT_006f58a8,DAT_006f58ac);
      piVar5 = (int *)extraout_ECX[0x59];
      if ((char)piVar5[0x5a] != '\0') {
        *(undefined1 *)(piVar5 + 0x5a) = 0;
        (**(code **)(*piVar5 + 0x168))();
      }
      (**(code **)(*(int *)extraout_ECX[0x67] + 0x20))(extraout_ECX[0x59]);
    }
  }
  else {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x100) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x16c) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 9;
    uVar12 = FUN_0041532c(9,unaff_EBP + -0x16c,0);
    FUN_004fff98(0xe1,uVar12);
    uVar12 = FUN_0041532c(9,unaff_EBP + -0x100,0);
    cVar2 = FUN_004fff98(0x97,uVar12);
    if (cVar2 != '\0') {
      FUN_00471655(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      do {
        pvVar7 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x20) = pvVar7;
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        if (pvVar7 == (void *)0x0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_005e372a();
        }
        iVar11 = *(int *)(unaff_EBP + -0x10);
        *(undefined1 *)(unaff_EBP + -4) = 10;
        piVar5 = extraout_ECX + iVar11 + 0x55;
        *piVar5 = iVar4;
        if (iVar4 != 0) {
          FUN_005a5631(*(undefined4 *)(&DAT_006cddb8 + iVar11 * 4),unaff_EBP + -0x14,4);
          uVar12 = 0;
          if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
            uVar12 = *(undefined4 *)(unaff_EBP + -0x14);
          }
          if (*(int *)(unaff_EBP + -0x10) == 9) {
            uVar10 = 1;
            iVar4 = *(int *)extraout_ECX[0x5e];
          }
          else {
            uVar10 = 4;
            iVar4 = *(int *)*piVar5;
          }
          (**(code **)(iVar4 + 0x19c))(uVar12,uVar10,1);
          iVar4 = *(int *)(unaff_EBP + -0x10);
          *(undefined1 *)(*piVar5 + 0x16b) = 1;
          if (iVar4 == 4) {
            uVar12 = FUN_004705f2(9,0xffffffff);
            FUN_005d4956(uVar12);
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            FUN_005dd9c8(unaff_EBP + -0x50);
            *(undefined1 *)(unaff_EBP + -4) = 10;
            FUN_005b8770();
          }
          else {
            FUN_0046fc87(unaff_EBP + -0x28,0);
            *(undefined1 *)(unaff_EBP + -4) = 0xc;
            uVar12 = FUN_0046fc7a();
            FUN_005d4956(uVar12);
            *(undefined1 *)(unaff_EBP + -4) = 0xd;
            FUN_005dd9c8(unaff_EBP + -0x68);
            *(undefined1 *)(unaff_EBP + -4) = 0xc;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 10;
            FUN_0042004f();
          }
          FUN_005e4817(0,s_UI_Nhood_click_006cd914,0,0);
          if (*(int *)(unaff_EBP + -0x10) == 4) {
            FUN_004cb21d(DAT_006f58a8,DAT_006f58ac);
            (**(code **)(*(int *)extraout_ECX[0x67] + 0x20))(extraout_ECX[0x59]);
          }
          else {
            FUN_004cb21d(*(undefined4 *)(&DAT_006f5888 + *(int *)(unaff_EBP + -0x10) * 8),
                         *(undefined4 *)(&DAT_006f588c + *(int *)(unaff_EBP + -0x10) * 8));
            (**(code **)(*(int *)extraout_ECX[99] + 0x20))(*piVar5);
            if (((*(byte *)(DAT_006e486c + 0x66) & 4) == 0) && (*(int *)(unaff_EBP + -0x10) == 8)) {
              piVar5 = (int *)extraout_ECX[0x5d];
              if ((char)piVar5[0x5a] != '\0') {
                *(undefined1 *)(piVar5 + 0x5a) = 0;
                (**(code **)(*piVar5 + 0x168))();
              }
              uVar12 = FUN_004705f2(1,0xffffffff);
              FUN_005d4956(uVar12);
              *(undefined1 *)(unaff_EBP + -4) = 0xf;
              FUN_005dd9c8(unaff_EBP + -0x38);
              *(undefined1 *)(unaff_EBP + -4) = 10;
              FUN_005b8770();
            }
            if (((*(byte *)(DAT_006e486c + 0x66) & 8) == 0) && (*(int *)(unaff_EBP + -0x10) == 10))
            {
              piVar5 = (int *)extraout_ECX[0x5f];
              if ((char)piVar5[0x5a] != '\0') {
                *(undefined1 *)(piVar5 + 0x5a) = 0;
                (**(code **)(*piVar5 + 0x168))();
              }
              uVar12 = FUN_004705f2(2,0xffffffff);
              FUN_005d4956(uVar12);
              *(undefined1 *)(unaff_EBP + -4) = 0x10;
              FUN_005dd9c8(unaff_EBP + -0x44);
              *(undefined1 *)(unaff_EBP + -4) = 10;
              FUN_005b8770();
            }
            if (((*(byte *)(DAT_006e486c + 0x66) & 0x40) == 0) &&
               (*(int *)(unaff_EBP + -0x10) == 0xc)) {
              piVar5 = (int *)extraout_ECX[0x61];
              if ((char)piVar5[0x5a] != '\0') {
                *(undefined1 *)(piVar5 + 0x5a) = 0;
                (**(code **)(*piVar5 + 0x168))();
              }
              uVar12 = FUN_004705f2(4,0xffffffff);
              FUN_005d4956(uVar12);
              *(undefined1 *)(unaff_EBP + -4) = 0x11;
              FUN_005dd9c8(unaff_EBP + -0x5c);
              *(undefined1 *)(unaff_EBP + -4) = 10;
              FUN_005b8770();
            }
            if (((*(byte *)(DAT_006e486c + 0x66) & 0x80) == 0) &&
               (*(int *)(unaff_EBP + -0x10) == 0xd)) {
              piVar5 = (int *)extraout_ECX[0x62];
              if ((char)piVar5[0x5a] != '\0') {
                *(undefined1 *)(piVar5 + 0x5a) = 0;
                (**(code **)(*piVar5 + 0x168))();
              }
              uVar12 = FUN_004705f2(5,0xffffffff);
              FUN_005d4956(uVar12);
              *(undefined1 *)(unaff_EBP + -4) = 0x12;
              FUN_005dd9c8(unaff_EBP + -0x74);
              *(undefined1 *)(unaff_EBP + -4) = 10;
              FUN_005b8770();
            }
          }
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < 0xe);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_0042004f();
    }
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_00470467();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_00470467();
  }
  if (*(char *)((int)extraout_ECX + 0x121) == '\0') {
LAB_00557b77:
    FUN_0055b4e6(4);
    extraout_ECX[0x65] = 0x10;
    FUN_005a5631(0x1346,extraout_ECX + 100,4);
    FUN_0055da0a();
    FUN_0055e49a(0x10);
  }
  else {
    *(undefined4 *)(extraout_ECX[0x56] + 0xf8) = 1;
    *(undefined4 *)(extraout_ECX[0x56] + 0xf4) = 1;
    *(undefined4 *)(extraout_ECX[0x60] + 0xf8) = 1;
    *(undefined4 *)(extraout_ECX[0x60] + 0xf4) = 1;
    *(undefined4 *)(extraout_ECX[0x55] + 0xf8) = 1;
    *(undefined4 *)(extraout_ECX[0x55] + 0xf4) = 1;
    if (*(char *)((int)extraout_ECX + 0x121) == '\0') goto LAB_00557b77;
    FUN_0055b4e6(0);
  }
  if (*(char *)((int)extraout_ECX + 0x121) == '\0') {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x100) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 0x14;
    uVar12 = FUN_0041532c(9,unaff_EBP + -0x100,0);
    cVar2 = FUN_004fff98(0xd4,uVar12);
    if (cVar2 == '\0') {
      pcVar9 = s_Choose_Destination____006cd88c;
    }
    else {
      uVar12 = 0xffffffff;
      iVar4 = _rand();
      pcVar9 = (char *)FUN_004705f2(iVar4 % 3 + 1,uVar12);
    }
    FUN_005d4bbf(pcVar9);
    uVar12 = FUN_0055e308();
    *(undefined4 *)(unaff_EBP + -0x24) = uVar12;
    FUN_0055da0a();
    FUN_0055e49a(*(undefined4 *)(unaff_EBP + -0x24));
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_00470467();
    if (*(char *)((int)extraout_ECX + 0x121) != '\0') goto LAB_00557c5a;
  }
  else {
LAB_00557c5a:
    FUN_005e6125(&DAT_006c9c58,FUN_0055c263,extraout_ECX,s_Usage__load__house_num___between_006cd860
                );
    FUN_005e6125(s_move_lots_006cd7a4,FUN_0055c263,extraout_ECX,
                 s_Usage__move_lots_to_enter_lot_mo_006cd7b0);
    FUN_005e6125(s_show_zones_006cdee4,FUN_0055c263,extraout_ECX,
                 s_Usage__show_zones_on_off_to_hide_006cdef0);
    FUN_005e6125(s_show_filter_006cde54,FUN_0055c263,extraout_ECX,
                 s_Usage__show_filter_0___7__0_to_h_006cde60);
    FUN_005e6125(s_nessie_006cd7f4,FUN_0055c263,extraout_ECX,
                 s_Usage__nessie__Same_as_SimCity__006cd7fc);
    FUN_005e6125(s_stream_fps_006cd81c,FUN_0055c263,extraout_ECX,
                 s_Usage__stream_fps__max_frames_pe_006cd828);
    FUN_005e6125(s_reload_neighborhood_006cde24,FUN_0055c263,extraout_ECX,
                 s_Usage__reload_neighborhood_006cde38);
  }
  *(undefined1 *)(extraout_ECX + 0x1b) = 0;
  extraout_ECX[0x80] = *(int *)(DAT_006fe8f4 + 0x1fc);
  *(int **)(DAT_006fe8f4 + 0x1fc) = extraout_ECX;
  FUN_005dadbc(0,1);
  FUN_005db1e2();
  FUN_0055c517();
  if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
    *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 100;
  }
  FUN_0055d388();
  FUN_005dadff(extraout_ECX,1000,0);
  FUN_004fb560();
  if (*(char *)((int)extraout_ECX + 0x121) == '\0') {
    pcVar9 = s_station_unleashed_006c7ab0;
  }
  else {
    pcVar9 = s_bkground_nhood1_006cde14;
  }
  FUN_0057a7f7(pcVar9,0xffffffff);
  piVar5 = *(int **)extraout_ECX[0xe];
  if (piVar5 != (int *)extraout_ECX[0xe]) {
    do {
      (**(code **)(*(int *)piVar5[2] + 0x90))(0x400,0);
      (**(code **)(*(int *)piVar5[2] + 0x90))(2,0);
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)extraout_ECX[0xe]);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005bc3da();
  uVar3 = 1;
LAB_00557def:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

