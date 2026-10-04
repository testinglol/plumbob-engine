
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00551704(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined1 uVar5;
  void *pvVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  undefined4 uVar10;
  char *pcVar11;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar12;
  undefined4 uVar13;
  int iStack_2c;
  
  FUN_00634c24();
  FUN_00636080();
  cVar4 = (**(code **)(*extraout_ECX + 200))();
  if (cVar4 != '\0') {
    uVar5 = FUN_005dbf32();
    goto LAB_005522ed;
  }
  cVar4 = FUN_005dbf32();
  uVar5 = 0;
  if (cVar4 == '\0') goto LAB_005522ed;
  uVar5 = 0;
  FUN_0046f824();
  *(undefined ***)(unaff_EBP + -0x308) = &PTR_FUN_006664e8;
  FUN_00425531();
  FUN_006358b0();
  FUN_006358c0();
  FUN_005d4956();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar4 = FUN_005ed4a5();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(char *)(unaff_EBP + -0x11) = '\x01' - (cVar4 != '\0');
  FUN_005b8770();
  if (*(char *)(unaff_EBP + -0x11) != '\0') {
    iVar12 = 0x5a;
    do {
      FUN_006358b0();
      FUN_00635858();
      FUN_006358c0();
      iStack_2c = 0x551828;
      FUN_006358b0();
      FUN_00635858();
      FUN_006358c0();
      FUN_005d4956();
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005d4956();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005ed4f0();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar12 = iVar12 + 1;
    } while (iVar12 < 99);
    FUN_006358b0();
    FUN_006358c0();
    FUN_006358b0();
    iStack_2c = unaff_EBP + -0x1308;
    FUN_006358c0();
    FUN_005d4956();
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_005d4956();
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005ed4f0();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  FUN_0057a7f7();
  iVar12 = _strcmp(DAT_006f5620,&DAT_006de560);
  if (iVar12 == 0) {
    FUN_00554b28();
  }
  if (*(char *)((int)extraout_ECX + 0x12a) == '\0') {
    (**(code **)(*extraout_ECX + 0x90))();
  }
  FUN_005e47ab();
  if ((undefined4 *)extraout_ECX[0x4b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[0x4b])();
    extraout_ECX[0x4b] = 0;
  }
  if (extraout_ECX[0x4b] == 0) {
    FUN_005a5631();
  }
  pvVar6 = operator_new(0x3b0);
  *(void **)(unaff_EBP + -0x28) = pvVar6;
  *(undefined4 *)(unaff_EBP + -4) = 5;
  if (pvVar6 == (void *)0x0) {
    iVar12 = 0;
  }
  else {
    iVar12 = FUN_0054231a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x7b] = iVar12;
  FUN_005423c5();
  FUN_005423ea();
  FUN_00542439();
  iVar12 = extraout_ECX[0x22];
  iVar2 = extraout_ECX[0x20];
  iVar3 = extraout_ECX[0x7b];
  *(int *)(iVar3 + 0x39c) = extraout_ECX[0x21] - extraout_ECX[0x1f];
  *(int *)(iVar3 + 0x3a0) = iVar12 - iVar2;
  FUN_004e609e();
  iVar12 = FUN_004e6141();
  if (iVar12 == 0) {
    *(undefined4 *)(extraout_ECX[0x7b] + 0x38c) = 0;
  }
  else if (iVar12 == 1) {
    *(undefined4 *)(extraout_ECX[0x7b] + 0x38c) = 1;
  }
  else if (iVar12 == 2) {
    *(undefined4 *)(extraout_ECX[0x7b] + 0x38c) = 2;
  }
  if (extraout_ECX[0x4d] == 0) {
    FUN_005a5631();
    if ((int *)extraout_ECX[0x4d] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x4d] + 0x68))();
    }
  }
  if ((extraout_ECX[0x4f] == 0) && (*(char *)((int)extraout_ECX + 0x12a) == '\0')) {
    FUN_005a5631();
    if ((int *)extraout_ECX[0x4f] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x4f] + 0x68))();
    }
  }
  if ((extraout_ECX[0x4c] == 0) && (800 < extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    FUN_005a5631();
  }
  cVar4 = *(char *)(DAT_006e486c + 100);
  if (cVar4 != '\x01') {
    if (cVar4 == '\x03') {
      _DAT_006cdc7c = 0x1534;
    }
    else if (cVar4 == '\x04') {
      _DAT_006cdc7c = 0x1535;
    }
    else if (cVar4 == '\x06') {
      _DAT_006cdc7c = 0x1533;
    }
    else if (cVar4 == '\x0f') {
      _DAT_006cdc7c = 0x1536;
    }
    else {
      _DAT_006cdc7c = 0x152d;
    }
  }
  piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
  piVar7 = (int *)(**(code **)(*piVar7 + 0x10))();
  extraout_ECX[0x50] = (int)piVar7;
  if (piVar7 != (int *)0x0) {
    iVar12 = *piVar7;
    iStack_2c = 0xff;
    FUN_005dd5e1(0xff);
    iStack_2c = 0x551bbc;
    (**(code **)(iVar12 + 0x20))();
  }
  iVar12 = extraout_ECX[0x22];
  uVar8 = *(uint *)(extraout_ECX[0x4b] + 0x1c);
  iVar2 = extraout_ECX[0x20];
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(extraout_ECX[0x4b] + 0x20);
  if (uVar8 < (uint)(extraout_ECX[0x21] - extraout_ECX[0x1f])) {
    uVar8 = (extraout_ECX[0x21] - extraout_ECX[0x1f]) - uVar8 >> 1;
  }
  else {
    uVar8 = 0;
  }
  uVar1 = *(uint *)(unaff_EBP + -0x10);
  extraout_ECX[0x51] = uVar8;
  if (uVar1 < (uint)(iVar12 - iVar2)) {
    uVar8 = (uint)((iVar12 - iVar2) - *(int *)(unaff_EBP + -0x10)) >> 1;
  }
  else {
    uVar8 = 0;
  }
  extraout_ECX[0x52] = uVar8;
  iStack_2c = extraout_ECX[0x51];
  *(int **)(unaff_EBP + -0x28) = &iStack_2c;
  FUN_005522fc();
  *(undefined1 *)(extraout_ECX + 0x70) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1c1) = 1;
  iStack_2c = 1000;
  FUN_005dadff(extraout_ECX);
  iStack_2c = 0x551c58;
  pvVar6 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x28) = pvVar6;
  *(undefined4 *)(unaff_EBP + -4) = 6;
  if (pvVar6 == (void *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)FUN_005e372a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_2c = 1;
  extraout_ECX[99] = (int)piVar7;
  (**(code **)(*piVar7 + 0x19c))(extraout_ECX[0x4b]);
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
  iVar12 = extraout_ECX[0x52];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x28) = iVar12;
  *(int *)(unaff_EBP + -0x24) = extraout_ECX[0x51];
  piVar7 = extraout_ECX + 0x53;
  do {
    pvVar6 = operator_new(0x26c);
    *(void **)(unaff_EBP + -0x34) = pvVar6;
    *(undefined4 *)(unaff_EBP + -4) = 7;
    if (pvVar6 == (void *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = (int *)FUN_0054e1b8(extraout_ECX);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *piVar7 = (int)piVar9;
    cVar4 = (**(code **)(*piVar9 + 0xc))();
    if (cVar4 != '\0') {
      FUN_0054e5e9(*(int *)(unaff_EBP + -0x10) + 0x5a);
      iVar12 = *piVar7;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      if (iVar12 != -0x194) {
        *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar12 + 0x208);
        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar12 + 0x20c);
        if (*(int *)(iVar12 + 0x1ec) < 0) {
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *(int *)(iVar12 + 0x1ec);
        }
        if (*(int *)(iVar12 + 0x1f0) < 0) {
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + *(int *)(iVar12 + 0x1f0);
        }
      }
      Sleep(100);
      FUN_0054ec7a(unaff_EBP + -0x1c);
      iVar12 = *piVar7;
      iVar2 = *(int *)(unaff_EBP + -0x24);
      iVar3 = *(int *)(unaff_EBP + -0x28);
      *(int *)(iVar12 + 0x230) = iVar2;
      *(int *)(iVar12 + 0x234) = iVar3;
      *(int *)(iVar12 + 0x238) = iVar2 + 800;
      *(int *)(iVar12 + 0x23c) = iVar3 + 600;
      (**(code **)(*(int *)*piVar7 + 0x90))(0x10,0);
      (**(code **)(*(int *)extraout_ECX[99] + 0x20))(*piVar7);
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    piVar7 = piVar7 + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 9);
  _DAT_006f5714 = 0;
  _DAT_006f5710 = 5;
  pvVar6 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x34) = pvVar6;
  *(undefined4 *)(unaff_EBP + -4) = 8;
  if (pvVar6 == (void *)0x0) {
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
  if (*(char *)((int)extraout_ECX + 0x12a) == '\0') {
LAB_00552049:
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x130) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0xe;
    uVar10 = FUN_0041532c(9,unaff_EBP + -0x130,0);
    cVar4 = FUN_004fff98(0xd4,uVar10);
    if (cVar4 == '\0') {
      pcVar11 = s_Choose_Destination____006cd88c;
    }
    else {
      uVar10 = 0xffffffff;
      iVar12 = _rand();
      pcVar11 = (char *)FUN_004705f2(iVar12 % 3 + 1,uVar10);
    }
    FUN_005d4bbf(pcVar11);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
    if (*(char *)((int)extraout_ECX + 0x12a) != '\0') goto LAB_005520cb;
LAB_00552111:
    FUN_005547b8(4);
    uVar10 = FUN_00555f99();
    FUN_005555bb();
    FUN_0055612d(uVar10);
  }
  else {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x19c) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 9;
    uVar10 = FUN_0041532c(9,unaff_EBP + -0x19c,0);
    cVar4 = FUN_004fff98(0xae,uVar10);
    if (cVar4 != '\0') {
      FUN_00471655(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      do {
        pvVar6 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x34) = pvVar6;
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        if (pvVar6 == (void *)0x0) {
          iVar12 = 0;
        }
        else {
          iVar12 = FUN_005e372a();
        }
        iVar2 = *(int *)(unaff_EBP + -0x10);
        *(undefined1 *)(unaff_EBP + -4) = 10;
        piVar7 = extraout_ECX + iVar2 + 0x5c;
        *piVar7 = iVar12;
        if (iVar12 != 0) {
          FUN_005a5631(*(undefined4 *)(&DAT_006cdc74 + iVar2 * 4),unaff_EBP + -0x24,4);
          uVar10 = 0;
          if (*(int **)(unaff_EBP + -0x24) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x68))(DAT_006f2a64);
            uVar10 = *(undefined4 *)(unaff_EBP + -0x24);
          }
          if (*(int *)(unaff_EBP + -0x10) == 2) {
            uVar13 = 1;
            iVar12 = *(int *)extraout_ECX[0x5e];
          }
          else {
            uVar13 = 4;
            iVar12 = *(int *)*piVar7;
          }
          (**(code **)(iVar12 + 0x19c))(uVar10,uVar13,1);
          FUN_004cb21d(*(undefined4 *)(&DAT_006f5700 + *(int *)(unaff_EBP + -0x10) * 8),
                       *(undefined4 *)(&DAT_006f5704 + *(int *)(unaff_EBP + -0x10) * 8));
          *(undefined1 *)(*piVar7 + 0x16b) = 1;
          FUN_0046fc87(unaff_EBP + -0x2c,0);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          uVar10 = FUN_0046fc7a();
          FUN_005d4956(uVar10);
          *(undefined1 *)(unaff_EBP + -4) = 0xd;
          FUN_005dd9c8(unaff_EBP + -0x58);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_0042004f();
          FUN_005e4817(0,s_UI_Nhood_click_006cd914,0,0);
          (**(code **)(*(int *)extraout_ECX[0x62] + 0x20))(*piVar7);
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < 6);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_0042004f();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
    if (*(char *)((int)extraout_ECX + 0x12a) == '\0') goto LAB_00552049;
LAB_005520cb:
    *(undefined4 *)(extraout_ECX[0x60] + 0xf8) = 1;
    *(undefined4 *)(extraout_ECX[0x60] + 0xf4) = 1;
    *(undefined4 *)(extraout_ECX[0x61] + 0xf8) = 1;
    *(undefined4 *)(extraout_ECX[0x61] + 0xf4) = 1;
    if (*(char *)((int)extraout_ECX + 0x12a) == '\0') goto LAB_00552111;
    FUN_005547b8(0);
  }
  FUN_005e6125(&DAT_006c9c58,FUN_00554e69,extraout_ECX,s_Usage__load__house_num___between_006cd860);
  FUN_005e6125(s_stream_fps_006cd81c,FUN_00554e69,extraout_ECX,
               s_Usage__stream_fps__max_frames_pe_006cd828);
  FUN_005e6125(s_move_lots_006cd7a4,FUN_00554e69,extraout_ECX,
               s_Usage__move_lots_to_enter_lot_mo_006cd7b0);
  *(undefined1 *)(extraout_ECX + 0x1b) = 1;
  extraout_ECX[0x74] = *(int *)(DAT_006fe8f4 + 0x1fc);
  *(int **)(DAT_006fe8f4 + 0x1fc) = extraout_ECX;
  FUN_005dadbc(0,1);
  FUN_005db1e2();
  FUN_00554f58();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xc4) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0xf;
  uVar10 = FUN_0041532c(9,unaff_EBP + -0xc4,0);
  cVar4 = FUN_004fff98(0x86,uVar10);
  if (cVar4 != '\0') {
    uVar10 = FUN_004705f2(0x21,0xffffffff);
    FUN_005d4956(uVar10);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    uVar10 = FUN_004705f2(0x22,0xffffffff);
    FUN_005d4956(uVar10);
    *(undefined1 *)(unaff_EBP + -4) = 0x11;
    uVar10 = FUN_004096c2();
    iVar12 = FUN_00635f62(uVar10);
    extraout_ECX[0x3c] = iVar12;
    uVar10 = FUN_004096c2();
    iVar12 = FUN_00635f62(uVar10);
    extraout_ECX[0x3d] = iVar12;
    if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
      *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 100;
    }
    FUN_005424c1();
    FUN_005424ee();
    *(int *)(extraout_ECX[0x7b] + 0x390) = extraout_ECX[0x17];
    FUN_004733da(0xa6);
    (**(code **)(*extraout_ECX + 0xd4))(extraout_ECX + 3,1);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    FUN_005b8770();
    uVar5 = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
LAB_005522ed:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

