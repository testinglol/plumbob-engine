
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00564927(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined1 uVar5;
  int *piVar6;
  void *pvVar7;
  int *piVar8;
  char *pcVar9;
  int *extraout_ECX;
  uint uVar10;
  int unaff_EBP;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  FUN_00634c24();
  FUN_00636080();
  cVar4 = (**(code **)(*extraout_ECX + 200))();
  if (cVar4 != '\0') {
    uVar5 = FUN_005dbf32();
    goto LAB_00565333;
  }
  cVar4 = FUN_005dbf32();
  uVar5 = 0;
  if (cVar4 == '\0') goto LAB_00565333;
  FUN_0046f824(unaff_EBP + -0x278,0,0x104);
  *(undefined ***)(unaff_EBP + -0x284) = &PTR_FUN_006664e8;
  FUN_00425531(unaff_EBP + -0x284);
  FUN_006358b0(unaff_EBP + -0xa84,*(undefined4 *)(unaff_EBP + -0x280));
  FUN_006358c0(unaff_EBP + -0xa84,s__Houses_House81_iff_006ce2b0);
  FUN_005d4956(unaff_EBP + -0xa84);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar4 = FUN_005ed4a5(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(char *)(unaff_EBP + -0x11) = '\x01' - (cVar4 != '\0');
  FUN_005b8770();
  if (*(char *)(unaff_EBP + -0x11) != '\0') {
    iVar11 = 0x51;
    do {
      FUN_006358b0(unaff_EBP + -0xa84,*(undefined4 *)(unaff_EBP + -0x280));
      FUN_00635858(unaff_EBP + -0x174,s_____TemplateStudiotown_House_d_i_006ce28c,iVar11);
      FUN_006358c0(unaff_EBP + -0xa84,unaff_EBP + -0x174);
      FUN_006358b0(unaff_EBP + -0x1284,*(undefined4 *)(unaff_EBP + -0x280));
      FUN_00635858(unaff_EBP + -0x174,s__Houses_House_d_iff_006cd980,iVar11);
      FUN_006358c0(unaff_EBP + -0x1284,unaff_EBP + -0x174);
      FUN_005d4956(unaff_EBP + -0x1284);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005d4956(unaff_EBP + -0xa84);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005ed4f0(unaff_EBP + -0x24,unaff_EBP + -0x30,1);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar11 = iVar11 + 1;
    } while (iVar11 < 0x5a);
    FUN_006358b0(unaff_EBP + -0xa84,*(undefined4 *)(unaff_EBP + -0x280));
    FUN_006358c0(unaff_EBP + -0xa84,s_____TemplateStudiotown_STDesc_if_006ce268);
    FUN_006358b0(unaff_EBP + -0x1284,*(undefined4 *)(unaff_EBP + -0x280));
    FUN_006358c0(unaff_EBP + -0x1284,s__Houses_STDesc_iff_006ce254);
    FUN_005d4956(unaff_EBP + -0x1284);
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_005d4956(unaff_EBP + -0xa84);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005ed4f0(unaff_EBP + -0x24,unaff_EBP + -0x30,1);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  FUN_0057a7f7(s_music_superstar_transition_006ce238,0xffffffff);
  iVar11 = _strcmp(DAT_006f5e58,&DAT_006de560);
  if (iVar11 == 0) {
    FUN_00566973();
  }
  if ((char)extraout_ECX[0xed] == '\0') {
    (**(code **)(*extraout_ECX + 0x90))(0x20,1);
  }
  FUN_005e47ab(0,s_UI_Nhood_click_006cd914,0,0);
  piVar6 = extraout_ECX + 0xee;
  if ((undefined4 *)extraout_ECX[0xee] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[0xee])(1);
    *piVar6 = 0;
  }
  if (*piVar6 == 0) {
    FUN_005a5631(0x14c9,piVar6,4);
  }
  iVar11 = 0;
  *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0xdb;
  do {
    FUN_005a5631(iVar11 + 0x161c,*(undefined4 *)(unaff_EBP + -0x10),4);
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
    iVar11 = iVar11 + 1;
  } while (iVar11 < 0x12);
  if (extraout_ECX[0xf0] == 0) {
    if ((char)extraout_ECX[0xed] == '\0') {
      uVar13 = 0x13b6;
    }
    else {
      uVar13 = 0x152e;
    }
    FUN_005a5631(uVar13,extraout_ECX + 0xf0,4);
    piVar6 = (int *)extraout_ECX[0xf0];
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x68))(DAT_006f2a64);
    }
  }
  if ((extraout_ECX[0xf2] == 0) && ((char)extraout_ECX[0xed] == '\0')) {
    FUN_005a5631(0x1538,extraout_ECX + 0xf2,4);
    piVar6 = (int *)extraout_ECX[0xf2];
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x68))(DAT_006f2a64);
    }
  }
  if ((extraout_ECX[0xef] == 0) && (800 < extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    FUN_005a5631(0x138a,extraout_ECX + 0xef,4);
  }
  cVar4 = *(char *)(DAT_006e486c + 100);
  if (cVar4 != '\x01') {
    if (cVar4 == '\x03') {
      _DAT_006ce1e0 = 0x1534;
    }
    else if (cVar4 == '\x04') {
      _DAT_006ce1e0 = 0x1535;
    }
    else if (cVar4 == '\x06') {
      _DAT_006ce1e0 = 0x1533;
    }
    else if (cVar4 == '\x0f') {
      _DAT_006ce1e0 = 0x1536;
    }
    else {
      _DAT_006ce1e0 = 0x152d;
    }
  }
  piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
  piVar6 = (int *)(**(code **)(*piVar6 + 0x10))(1,0xc,0,0);
  extraout_ECX[0xf3] = (int)piVar6;
  if (piVar6 != (int *)0x0) {
    iVar11 = *piVar6;
    uVar13 = FUN_005dd5e1(0xff,0xff,0xff);
    (**(code **)(iVar11 + 0x20))(uVar13);
  }
  iVar11 = extraout_ECX[0x22];
  uVar13 = *(undefined4 *)(extraout_ECX[0xee] + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(extraout_ECX[0xee] + 0x20);
  iVar2 = extraout_ECX[0x20];
  *(undefined4 *)(unaff_EBP + -0x10) = uVar13;
  if (*(uint *)(unaff_EBP + -0x10) < (uint)(extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    uVar10 = (uint)((extraout_ECX[0x21] - extraout_ECX[0x1f]) - *(int *)(unaff_EBP + -0x10)) >> 1;
  }
  else {
    uVar10 = 0;
  }
  uVar1 = *(uint *)(unaff_EBP + -0x18);
  extraout_ECX[0xf4] = uVar10;
  if (uVar1 < (uint)(iVar11 - iVar2)) {
    uVar10 = (uint)((iVar11 - iVar2) - *(int *)(unaff_EBP + -0x18)) >> 1;
  }
  else {
    uVar10 = 0;
  }
  extraout_ECX[0xf5] = uVar10;
  *(undefined1 *)(extraout_ECX + 0x113) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x44d) = 1;
  FUN_005dadff(extraout_ECX,1000,0);
  pvVar7 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x28) = pvVar7;
  *(undefined4 *)(unaff_EBP + -4) = 5;
  if (pvVar7 == (void *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x105] = (int)piVar6;
  (**(code **)(*piVar6 + 0x19c))(extraout_ECX[0xee],1,1);
  FUN_004cb21d(extraout_ECX[0xf4],extraout_ECX[0xf5]);
  *(undefined1 *)(extraout_ECX[0x105] + 0x16b) = 0;
  FUN_005e4817(0,0,0,0);
  piVar6 = (int *)extraout_ECX[0x105];
  if ((char)piVar6[0x5a] != '\0') {
    *(undefined1 *)(piVar6 + 0x5a) = 0;
    (**(code **)(*piVar6 + 0x168))();
  }
  (**(code **)(*(int *)extraout_ECX[0x105] + 0x90))(0x400,0);
  (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x105]);
  iVar11 = extraout_ECX[0xf5];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x28) = iVar11;
  *(int *)(unaff_EBP + -0x18) = extraout_ECX[0xf4];
  piVar6 = extraout_ECX + 0xf6;
  do {
    pvVar7 = operator_new(0x26c);
    *(void **)(unaff_EBP + -0x34) = pvVar7;
    *(undefined4 *)(unaff_EBP + -4) = 6;
    if (pvVar7 == (void *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)FUN_0054e123(extraout_ECX);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *piVar6 = (int)piVar8;
    cVar4 = (**(code **)(*piVar8 + 0xc))();
    if (cVar4 != '\0') {
      FUN_0054e5e9(*(int *)(unaff_EBP + -0x10) + 0x51);
      iVar11 = *piVar6;
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      if (iVar11 != -0x194) {
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar11 + 0x208);
        *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar11 + 0x20c);
        if (*(int *)(iVar11 + 0x1ec) < 0) {
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + *(int *)(iVar11 + 0x1ec);
        }
        if (*(int *)(iVar11 + 0x1f0) < 0) {
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *(int *)(iVar11 + 0x1f0);
        }
      }
      Sleep(0x32);
      FUN_0054ec7a(unaff_EBP + -0x20);
      iVar11 = *piVar6;
      iVar2 = *(int *)(unaff_EBP + -0x18);
      iVar3 = *(int *)(unaff_EBP + -0x28);
      *(int *)(iVar11 + 0x230) = iVar2;
      *(int *)(iVar11 + 0x234) = iVar3;
      *(int *)(iVar11 + 0x238) = iVar2 + 800;
      *(int *)(iVar11 + 0x23c) = iVar3 + 600;
      (**(code **)(*(int *)*piVar6 + 0x90))(0x10,0);
      (**(code **)(*(int *)extraout_ECX[0x105] + 0x20))(*piVar6);
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    piVar6 = piVar6 + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 9);
  _DAT_006f5f1c = 0;
  _DAT_006f5f18 = 5;
  pvVar7 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x34) = pvVar7;
  *(undefined4 *)(unaff_EBP + -4) = 7;
  if (pvVar7 == (void *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x104] = (int)piVar6;
  (**(code **)(*piVar6 + 0x19c))(extraout_ECX[0xf0],1,1);
  (**(code **)(*(int *)extraout_ECX[0x104] + 0x90))(0x400,0);
  *(undefined1 *)(extraout_ECX[0x104] + 0x16b) = 0;
  FUN_005e4817(0,0,0,0);
  piVar6 = (int *)extraout_ECX[0x104];
  if ((char)piVar6[0x5a] != '\0') {
    *(undefined1 *)(piVar6 + 0x5a) = 0;
    (**(code **)(*piVar6 + 0x168))();
  }
  (**(code **)(*(int *)extraout_ECX[0x105] + 0x20))(extraout_ECX[0x104]);
  if ((char)extraout_ECX[0xed] == '\0') {
LAB_005651be:
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xac) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0xd;
    uVar13 = FUN_0041532c(9,unaff_EBP + -0xac,0);
    cVar4 = FUN_004fff98(0xd4,uVar13);
    if (cVar4 == '\0') {
      pcVar9 = s_Choose_Destination____006cd88c;
    }
    else {
      uVar13 = 0xffffffff;
      iVar11 = _rand();
      pcVar9 = (char *)FUN_004705f2(iVar11 % 3 + 1,uVar13);
    }
    FUN_005d4bbf(pcVar9);
    uVar13 = FUN_005684cb();
    FUN_00567366();
    FUN_0056865f(uVar13);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  else {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x118) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 8;
    uVar13 = FUN_0041532c(9,unaff_EBP + -0x118,0);
    cVar4 = FUN_004fff98(0xad,uVar13);
    if (cVar4 != '\0') {
      FUN_00471655(unaff_EBP + -0x20);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      do {
        pvVar7 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x34) = pvVar7;
        *(undefined1 *)(unaff_EBP + -4) = 10;
        if (pvVar7 == (void *)0x0) {
          iVar11 = 0;
        }
        else {
          iVar11 = FUN_005e372a();
        }
        iVar2 = *(int *)(unaff_EBP + -0x10);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        piVar6 = extraout_ECX + iVar2 + 0xff;
        *piVar6 = iVar11;
        if (iVar11 != 0) {
          FUN_005a5631(*(undefined4 *)(&DAT_006ce1d8 + iVar2 * 4),unaff_EBP + -0x18,4);
          uVar13 = 0;
          if (*(int **)(unaff_EBP + -0x18) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x68))(DAT_006f2a64);
            uVar13 = *(undefined4 *)(unaff_EBP + -0x18);
          }
          if (*(int *)(unaff_EBP + -0x10) == 2) {
            uVar12 = 1;
            iVar11 = *(int *)extraout_ECX[0x101];
          }
          else {
            uVar12 = 4;
            iVar11 = *(int *)*piVar6;
          }
          (**(code **)(iVar11 + 0x19c))(uVar13,uVar12,1);
          FUN_004cb21d(*(undefined4 *)(&DAT_006f5f08 + *(int *)(unaff_EBP + -0x10) * 8),
                       *(undefined4 *)(&DAT_006f5f0c + *(int *)(unaff_EBP + -0x10) * 8));
          *(undefined1 *)(*piVar6 + 0x16b) = 1;
          FUN_0046fc87(unaff_EBP + -0x2c,0);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          uVar13 = FUN_0046fc7a();
          FUN_005d4956(uVar13);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          FUN_005dd9c8(unaff_EBP + -0x40);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_0042004f();
          FUN_005e4817(0,s_UI_Nhood_click_006cd914,0,0);
          (**(code **)(*(int *)extraout_ECX[0x104] + 0x20))(*piVar6);
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < 5);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_0042004f();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
    if ((char)extraout_ECX[0xed] == '\0') goto LAB_005651be;
  }
  FUN_005666ee(0);
  FUN_005e6125(&DAT_006c9c58,FUN_00566c2a,extraout_ECX,s_Usage__load__house_num___between_006cd860);
  FUN_005e6125(s_stream_fps_006cd81c,FUN_00566c2a,extraout_ECX,
               s_Usage__stream_fps__max_frames_pe_006cd828);
  FUN_005e6125(&DAT_006ce210,FUN_00566c2a,extraout_ECX,s_Usage__cars__speed___numcars__006ce218);
  FUN_005e6125(s_move_lots_006cd7a4,FUN_00566c2a,extraout_ECX,
               s_Usage__move_lots_to_enter_lot_mo_006cd7b0);
  *(undefined1 *)(extraout_ECX + 0x1b) = 1;
  extraout_ECX[0x117] = *(int *)(DAT_006fe8f4 + 0x1fc);
  *(int **)(DAT_006fe8f4 + 0x1fc) = extraout_ECX;
  FUN_005dadbc(0,1);
  FUN_005db1e2();
  FUN_00566d9f();
  if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
    *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 100;
  }
  FUN_00567c7e();
  FUN_004733da(0xa6);
  uVar5 = 1;
LAB_00565333:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

