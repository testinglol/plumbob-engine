
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0055e843(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined1 uVar5;
  int *piVar6;
  void *pvVar7;
  int *piVar8;
  int *extraout_ECX;
  uint uVar9;
  int iVar10;
  int unaff_EBP;
  undefined4 uVar11;
  undefined4 uVar12;
  char *pcVar13;
  
  FUN_00634c24();
  FUN_00636080();
  cVar4 = (**(code **)(*extraout_ECX + 200))();
  if (cVar4 != '\0') {
    uVar5 = FUN_005dbf32();
    goto LAB_0055f65d;
  }
  cVar4 = FUN_005dbf32();
  uVar5 = 0;
  if (cVar4 == '\0') goto LAB_0055f65d;
  FUN_0046f824(unaff_EBP + -0x204,0,0x104);
  *(undefined ***)(unaff_EBP + -0x210) = &PTR_FUN_006664e8;
  FUN_00425531(unaff_EBP + -0x210);
  FUN_006358b0(unaff_EBP + -0xb44,*(undefined4 *)(unaff_EBP + -0x20c));
  FUN_006358c0(unaff_EBP + -0xb44,s_Houses_House00_iff_006ce15c);
  FUN_005d4956(unaff_EBP + -0xb44);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar4 = FUN_005ed4a5(unaff_EBP + -0x30);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  if (cVar4 == '\0') {
    iVar10 = 0;
    do {
      FUN_006358b0(unaff_EBP + -0xb44,*(undefined4 *)(unaff_EBP + -0x20c));
      if (iVar10 < 10) {
        pcVar13 = s____TemplateUserData_Houses_House_006ce134;
      }
      else {
        pcVar13 = s____TemplateUserData_Houses_House_006ce10c;
      }
      FUN_00635858(unaff_EBP + -0x344,pcVar13,iVar10);
      FUN_006358c0(unaff_EBP + -0xb44,unaff_EBP + -0x344);
      FUN_006358b0(unaff_EBP + -0x1344,*(undefined4 *)(unaff_EBP + -0x20c));
      if (iVar10 < 10) {
        pcVar13 = s_Houses_House0_d_iff_006ce0f8;
      }
      else {
        pcVar13 = s_Houses_House_d_iff_006ce0e4;
      }
      FUN_00635858(unaff_EBP + -0x344,pcVar13,iVar10);
      FUN_006358c0(unaff_EBP + -0x1344,unaff_EBP + -0x344);
      FUN_005d4956(unaff_EBP + -0x1344);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005d4956(unaff_EBP + -0xb44);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005ed4f0(unaff_EBP + -0x30,unaff_EBP + -0x1c,1);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar10 = iVar10 + 1;
    } while (iVar10 < 0xc);
    FUN_006358b0(unaff_EBP + -0xb44,*(undefined4 *)(unaff_EBP + -0x20c));
    FUN_006358c0(unaff_EBP + -0xb44,s____TemplateUserData_Neighborhood_006ce0bc);
    FUN_006358b0(unaff_EBP + -0x1344,*(undefined4 *)(unaff_EBP + -0x20c));
    FUN_006358c0(unaff_EBP + -0x1344,s_Neighborhood_iff_006c1db0);
    FUN_005d4956(unaff_EBP + -0x1344);
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_005d4956(unaff_EBP + -0xb44);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005ed4f0(unaff_EBP + -0x30,unaff_EBP + -0x1c,1);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  FUN_005e47ab(0,s_UI_Nhood_click_006cd914,0,0);
  piVar8 = extraout_ECX + 0x36;
  if ((undefined4 *)extraout_ECX[0x36] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[0x36])(1);
    *piVar8 = 0;
  }
  if (*piVar8 == 0) {
    FUN_0046f824(unaff_EBP + -0x204,0,0x104);
    *(undefined ***)(unaff_EBP + -0x210) = &PTR_FUN_006664e8;
    FUN_00425531(unaff_EBP + -0x210);
    FUN_006358b0(unaff_EBP + -0xb44,*(undefined4 *)(unaff_EBP + -0x20c));
    FUN_006358c0(unaff_EBP + -0xb44,s_neighborhood_jpg_006ce0a8);
    iVar10 = FUN_004b845d(unaff_EBP + -0xb44);
    *piVar8 = iVar10;
    if (iVar10 != 0) {
      FUN_006358b0(unaff_EBP + -0xb44,*(undefined4 *)(unaff_EBP + -0x20c));
      FUN_006358c0(unaff_EBP + -0xb44,s_neighborhood0_jpg_006ce094);
      iVar10 = FUN_004b845d(unaff_EBP + -0xb44);
      uVar12 = *(undefined4 *)(unaff_EBP + -0x20c);
      extraout_ECX[100] = iVar10;
      FUN_006358b0(unaff_EBP + -0xb44,uVar12);
      FUN_006358c0(unaff_EBP + -0xb44,s_neighborhood1_jpg_006ce080);
      iVar10 = FUN_004b845d(unaff_EBP + -0xb44);
      uVar12 = *(undefined4 *)(unaff_EBP + -0x20c);
      extraout_ECX[0x65] = iVar10;
      FUN_006358b0(unaff_EBP + -0xb44,uVar12);
      FUN_006358c0(unaff_EBP + -0xb44,s_neighborhood2_jpg_006ce06c);
      iVar10 = FUN_004b845d(unaff_EBP + -0xb44);
      extraout_ECX[0x66] = iVar10;
    }
    if (*piVar8 == 0) {
      if (*(char *)(DAT_006e486c + 100) == '\x01') {
        uVar12 = 5000;
      }
      else {
        uVar12 = 0x14bc;
      }
      FUN_005a5631(uVar12,piVar8,4);
      if (*(char *)(DAT_006e486c + 100) == '\x01') {
        FUN_005a5631(0x14b6,extraout_ECX + 100,4);
        FUN_005a5631(0x14b7,extraout_ECX + 0x65,4);
        uVar12 = 0x14b8;
      }
      else {
        FUN_005a5631(0x14bd,extraout_ECX + 100,4);
        FUN_005a5631(0x14be,extraout_ECX + 0x65,4);
        uVar12 = 0x14bf;
      }
      FUN_005a5631(uVar12,extraout_ECX + 0x66,4);
    }
  }
  cVar4 = *(char *)(DAT_006e486c + 100);
  if (cVar4 != '\x01') {
    if (cVar4 == '\x03') {
      _DAT_006ce044 = 0x14c0;
    }
    else if (cVar4 == '\x04') {
      _DAT_006ce044 = 0x14c1;
    }
    else if (cVar4 == '\x06') {
      _DAT_006ce044 = 0x14c2;
    }
    else if (cVar4 == '\x0f') {
      _DAT_006ce044 = 0x14c4;
    }
    else {
      _DAT_006ce044 = 0x14c3;
    }
  }
  if (extraout_ECX[0x38] == 0) {
    FUN_005a5631(0x152c,extraout_ECX + 0x38,4);
  }
  if ((extraout_ECX[0x37] == 0) && (800 < extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    FUN_005a5631(0x1389,extraout_ECX + 0x37,4);
  }
  piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
  piVar6 = (int *)(**(code **)(*piVar6 + 0x10))(1,0xc,0,0);
  extraout_ECX[0x3a] = (int)piVar6;
  if (piVar6 != (int *)0x0) {
    iVar10 = *piVar6;
    uVar12 = FUN_005dd5e1(0xff,0xff,0xff);
    (**(code **)(iVar10 + 0x20))(uVar12);
  }
  uVar9 = *(uint *)(*piVar8 + 0x1c);
  uVar1 = *(uint *)(*piVar8 + 0x20);
  if (uVar9 < (uint)(extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    uVar9 = (extraout_ECX[0x21] - extraout_ECX[0x1f]) - uVar9 >> 1;
  }
  else {
    uVar9 = 0;
  }
  extraout_ECX[0x3b] = uVar9;
  if (uVar1 < (uint)(extraout_ECX[0x22] - extraout_ECX[0x20])) {
    uVar9 = (extraout_ECX[0x22] - extraout_ECX[0x20]) - uVar1 >> 1;
  }
  else {
    uVar9 = 0;
  }
  extraout_ECX[0x3c] = uVar9;
  if (extraout_ECX[0x39] == 0) {
    FUN_005a5631(0x1456,extraout_ECX + 0x39,4);
    iVar10 = extraout_ECX[0x39];
    DAT_006f5a98 = DAT_006ce030 + extraout_ECX[0x3b];
    _DAT_006f5aa0 = extraout_ECX[0x3b] + *(int *)(iVar10 + 0x1c) + DAT_006ce030;
    _DAT_006f5aa4 = *(int *)(iVar10 + 0x20) + 3 + extraout_ECX[0x3c];
    DAT_006f5a9c = extraout_ECX[0x3c] + 3;
  }
  *(undefined1 *)(extraout_ECX + 0x62) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x189) = 1;
  FUN_005dadff(extraout_ECX,1000,0);
  iVar10 = extraout_ECX[0x3b];
  iVar2 = extraout_ECX[0x3c];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x20) = iVar10;
  piVar8 = extraout_ECX + 0x3d;
  do {
    pvVar7 = operator_new(0x26c);
    *(void **)(unaff_EBP + -0x24) = pvVar7;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    if (pvVar7 == (void *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)FUN_0054dfdb(extraout_ECX,0,1);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *piVar8 = (int)piVar6;
    cVar4 = (**(code **)(*piVar6 + 0xc))();
    if (cVar4 != '\0') {
      FUN_0054e5e9(*(int *)(unaff_EBP + -0x10) + 1);
      iVar10 = *piVar8;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (iVar10 != -0x194) {
        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar10 + 0x208);
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar10 + 0x20c);
        if (*(int *)(iVar10 + 0x1ec) < 0) {
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + *(int *)(iVar10 + 0x1ec);
        }
        if (*(int *)(iVar10 + 0x1f0) < 0) {
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + *(int *)(iVar10 + 0x1f0);
        }
      }
      Sleep(0x32);
      iVar10 = extraout_ECX[0x3b];
      *(int *)(unaff_EBP + -0x34) = extraout_ECX[0x3c] + *(int *)(unaff_EBP + -0x14);
      *(int *)(unaff_EBP + -0x38) = iVar10 + *(int *)(unaff_EBP + -0x18);
      FUN_0054ec7a(unaff_EBP + -0x38);
      iVar10 = *piVar8;
      iVar3 = *(int *)(unaff_EBP + -0x20);
      *(int *)(iVar10 + 0x230) = iVar3;
      *(int *)(iVar10 + 0x238) = iVar3 + 800;
      *(int *)(iVar10 + 0x234) = iVar2;
      *(int *)(iVar10 + 0x23c) = iVar2 + 600;
      (**(code **)(*(int *)*piVar8 + 0x90))(0x10,0);
      (**(code **)(*extraout_ECX + 0x20))(*piVar8);
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    piVar8 = piVar8 + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 10);
  cVar4 = *(char *)(DAT_006e486c + 100);
  if (cVar4 != '\x01') {
    if (cVar4 == '\x03') {
      _DAT_006ce044 = 0x14c0;
      _DAT_006ce058 = 0x1534;
    }
    else if (cVar4 == '\x04') {
      _DAT_006ce044 = 0x14c1;
      _DAT_006ce058 = 0x1535;
    }
    else if (cVar4 == '\x06') {
      _DAT_006ce044 = 0x14c2;
      _DAT_006ce058 = 0x1533;
    }
    else {
      if (cVar4 == '\x0f') {
        _DAT_006ce044 = 0x14c4;
        _DAT_006ce058 = 0x1536;
        DAT_006f5ac8 = 0x13;
        DAT_006f5acc = 0x20c;
        goto LAB_0055efff;
      }
      _DAT_006ce044 = 0x14c3;
      _DAT_006ce058 = 0x152d;
    }
    DAT_006f5acc = 0x21f;
    DAT_006f5ac8 = 0x29;
  }
LAB_0055efff:
  pvVar7 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x24) = pvVar7;
  *(undefined4 *)(unaff_EBP + -4) = 6;
  if (pvVar7 == (void *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x55] = (int)piVar8;
  (**(code **)(*piVar8 + 0x19c))(extraout_ECX[0x38],1,1);
  FUN_004cb21d(extraout_ECX[0x3b],extraout_ECX[0x3c]);
  *(undefined1 *)(extraout_ECX[0x55] + 0x16b) = 0;
  FUN_005e4817(0,0,0,0);
  piVar8 = (int *)extraout_ECX[0x55];
  if ((char)piVar8[0x5a] != '\0') {
    *(undefined1 *)(piVar8 + 0x5a) = 0;
    (**(code **)(*piVar8 + 0x168))();
  }
  (**(code **)(*(int *)extraout_ECX[0x55] + 0x90))(0x400,0);
  (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x55]);
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x27c) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 7;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x100) = &PTR_FUN_0066643c;
  iVar10 = extraout_ECX[0x55];
  *(undefined1 *)(unaff_EBP + -4) = 8;
  uVar12 = *(undefined4 *)(iVar10 + 0x7c);
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar10 + 0x80);
  *(undefined4 *)(unaff_EBP + -0x24) = uVar12;
  uVar12 = FUN_0041532c(9,unaff_EBP + -0x100,0);
  FUN_004fff98(0xe1,uVar12);
  uVar12 = FUN_0041532c(9,unaff_EBP + -0x27c,0);
  cVar4 = FUN_004fff98(0x97,uVar12);
  if (cVar4 != '\0') {
    FUN_00471655(unaff_EBP + -0x40);
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 9;
    do {
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x14) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 10;
      if (pvVar7 == (void *)0x0) {
        iVar10 = 0;
      }
      else {
        iVar10 = FUN_005e372a();
      }
      iVar2 = *(int *)(unaff_EBP + -0x10);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      piVar8 = extraout_ECX + iVar2 + 0x47;
      *piVar8 = iVar10;
      if (iVar10 != 0) {
        FUN_005a5631(*(undefined4 *)(&DAT_006ce034 + iVar2 * 4),unaff_EBP + -0x20,4);
        uVar12 = 0;
        if (*(int **)(unaff_EBP + -0x20) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x68))(DAT_006f2a64);
          uVar12 = *(undefined4 *)(unaff_EBP + -0x20);
        }
        if (*(int *)(unaff_EBP + -0x10) == 9) {
          uVar11 = 1;
          iVar10 = *(int *)extraout_ECX[0x50];
        }
        else {
          uVar11 = 4;
          iVar10 = *(int *)*piVar8;
        }
        (**(code **)(iVar10 + 0x19c))(uVar12,uVar11,1);
        iVar10 = *(int *)(unaff_EBP + -0x10);
        *(undefined1 *)(*piVar8 + 0x16b) = 1;
        if (iVar10 == 4) {
          uVar12 = FUN_004705f2(9,0xffffffff);
          FUN_005d4956(uVar12);
          *(undefined1 *)(unaff_EBP + -4) = 0xd;
          FUN_005dd9c8(unaff_EBP + -0x94);
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_005b8770();
        }
        else {
          FUN_0046fc87(unaff_EBP + -0x2c,0);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          uVar12 = FUN_0046fc7a();
          FUN_005d4956(uVar12);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          FUN_005dd9c8(unaff_EBP + -0x70);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_0042004f();
        }
        FUN_005e4817(0,s_UI_Nhood_click_006cd914,0,0);
        if (*(int *)(unaff_EBP + -0x10) == 4) {
          FUN_004cb21d(*(int *)(unaff_EBP + -0x24) + DAT_006f5ac8,
                       DAT_006f5acc + *(int *)(unaff_EBP + -0x34));
          (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x4b]);
        }
        else {
          FUN_004cb21d(*(undefined4 *)(&DAT_006f5aa8 + *(int *)(unaff_EBP + -0x10) * 8),
                       *(undefined4 *)(&DAT_006f5aac + *(int *)(unaff_EBP + -0x10) * 8));
          (**(code **)(*(int *)extraout_ECX[0x55] + 0x20))(*piVar8);
          if (((*(byte *)(DAT_006e486c + 0x66) & 4) == 0) && (*(int *)(unaff_EBP + -0x10) == 8)) {
            piVar8 = (int *)extraout_ECX[0x4f];
            if ((char)piVar8[0x5a] != '\0') {
              *(undefined1 *)(piVar8 + 0x5a) = 0;
              (**(code **)(*piVar8 + 0x168))();
            }
            uVar12 = FUN_004705f2(1,0xffffffff);
            FUN_005d4956(uVar12);
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            FUN_005dd9c8(unaff_EBP + -0x4c);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_005b8770();
          }
          if (((*(byte *)(DAT_006e486c + 0x66) & 8) == 0) && (*(int *)(unaff_EBP + -0x10) == 10)) {
            piVar8 = (int *)extraout_ECX[0x51];
            if ((char)piVar8[0x5a] != '\0') {
              *(undefined1 *)(piVar8 + 0x5a) = 0;
              (**(code **)(*piVar8 + 0x168))();
            }
            uVar12 = FUN_004705f2(2,0xffffffff);
            FUN_005d4956(uVar12);
            *(undefined1 *)(unaff_EBP + -4) = 0xf;
            FUN_005dd9c8(unaff_EBP + -0x88);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_005b8770();
          }
          if (((*(byte *)(DAT_006e486c + 0x66) & 0x20) == 0) && (*(int *)(unaff_EBP + -0x10) == 0xb)
             ) {
            piVar8 = (int *)extraout_ECX[0x52];
            if ((char)piVar8[0x5a] != '\0') {
              *(undefined1 *)(piVar8 + 0x5a) = 0;
              (**(code **)(*piVar8 + 0x168))();
            }
            uVar12 = FUN_004705f2(3,0xffffffff);
            FUN_005d4956(uVar12);
            *(undefined1 *)(unaff_EBP + -4) = 0x10;
            FUN_005dd9c8(unaff_EBP + -100);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_005b8770();
          }
          if (((*(byte *)(DAT_006e486c + 0x66) & 0x40) == 0) && (*(int *)(unaff_EBP + -0x10) == 0xc)
             ) {
            piVar8 = (int *)extraout_ECX[0x53];
            if ((char)piVar8[0x5a] != '\0') {
              *(undefined1 *)(piVar8 + 0x5a) = 0;
              (**(code **)(*piVar8 + 0x168))();
            }
            uVar12 = FUN_004705f2(4,0xffffffff);
            FUN_005d4956(uVar12);
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
            FUN_005dd9c8(unaff_EBP + -0x7c);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_005b8770();
          }
          if (((*(byte *)(DAT_006e486c + 0x66) & 0x80) == 0) && (*(int *)(unaff_EBP + -0x10) == 0xd)
             ) {
            piVar8 = (int *)extraout_ECX[0x54];
            if ((char)piVar8[0x5a] != '\0') {
              *(undefined1 *)(piVar8 + 0x5a) = 0;
              (**(code **)(*piVar8 + 0x168))();
            }
            uVar12 = FUN_004705f2(5,0xffffffff);
            FUN_005d4956(uVar12);
            *(undefined1 *)(unaff_EBP + -4) = 0x12;
            FUN_005dd9c8(unaff_EBP + -0x58);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_005b8770();
          }
        }
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < 0xe);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_0042004f();
  }
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_00470467();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  *(undefined4 *)(extraout_ECX[0x48] + 0xf8) = 1;
  *(undefined4 *)(extraout_ECX[0x48] + 0xf4) = 1;
  *(undefined4 *)(extraout_ECX[0x47] + 0xf8) = 1;
  *(undefined4 *)(extraout_ECX[0x47] + 0xf4) = 1;
  FUN_00561954(0);
  FUN_005e6125(&DAT_006c9c58,FUN_005620f6,extraout_ECX,s_Usage__load__house_num___between_006cd860);
  FUN_005e6125(s_stream_fps_006cd81c,FUN_005620f6,extraout_ECX,
               s_Usage__stream_fps__max_frames_pe_006cd828);
  *(undefined1 *)(extraout_ECX + 0x1b) = 1;
  extraout_ECX[0x69] = *(int *)(DAT_006fe8f4 + 0x1fc);
  *(int **)(DAT_006fe8f4 + 0x1fc) = extraout_ECX;
  FUN_005dadbc(0,1);
  FUN_005db1e2();
  FUN_005621bb();
  if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
    *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 100;
  }
  FUN_004fb560();
  FUN_0057a7f7(s_bkground_nhood1_006cde14,0xffffffff);
  piVar8 = *(int **)extraout_ECX[0xe];
  if (piVar8 != (int *)extraout_ECX[0xe]) {
    do {
      (**(code **)(*(int *)piVar8[2] + 0x90))(0x400,0);
      (**(code **)(*(int *)piVar8[2] + 0x90))(2,0);
      piVar8 = (int *)*piVar8;
    } while (piVar8 != (int *)extraout_ECX[0xe]);
  }
  uVar5 = 1;
LAB_0055f65d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

