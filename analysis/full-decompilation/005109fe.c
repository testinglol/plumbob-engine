
undefined4 FUN_005109fe(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  void *pvVar8;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar9;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 != '\0') {
    uVar5 = FUN_005dbf32();
    goto LAB_0051133d;
  }
  FUN_005dbf32();
  if (*(char *)((int)extraout_ECX + 0x446) == '\0') {
    if ((*(short *)(extraout_ECX[0x42] + 0x600) == 0) ||
       (DAT_006f38b0 = 0, 0x11 < *(short *)(extraout_ECX[0x42] + 0x600))) {
      DAT_006f38b0 = 1;
    }
  }
  else {
    DAT_006f38b0 = 2;
  }
  FUN_005a5631(0x5d,extraout_ECX + 0x4a,4);
  FUN_005a5631(0x5b,extraout_ECX + 0x4b,4);
  FUN_005a5631(0x5c,extraout_ECX + 0x4c,4);
  FUN_005a5631(0x5a,extraout_ECX + 0x4d,4);
  FUN_005a5631(0x5e,extraout_ECX + 0x4e,4);
  FUN_005a5631(0xbc0,extraout_ECX + 0x47,4);
  FUN_005a5631(0x52,extraout_ECX + 0x48,4);
  if (extraout_ECX[0x42] == 0) {
    uVar5 = 0;
    goto LAB_0051133d;
  }
  FUN_004fff98(1,s_magic_iff_006cc97c,extraout_ECX + 0x54,0);
  FUN_004fff98(0xd,s_magic_iff_006cc97c,extraout_ECX + 0xdb,0);
  FUN_004fff98(9,s_magic_iff_006cc97c,extraout_ECX + 0x8a,0);
  FUN_004fff98(0xe,s_magic_iff_006cc97c,extraout_ECX + 0xf6,0);
  FUN_004fff98(10,s_magic_iff_006cc97c,extraout_ECX + 0xa5,0);
  FUN_004fff98(0xc,s_magic_iff_006cc97c,extraout_ECX + 0xc0,0);
  FUN_004fff98(8,s_magic_iff_006cc97c,extraout_ECX + 0x6f,0);
  FUN_005ddfdc(1);
  (**(code **)(*extraout_ECX + 0x60))(0,0,DAT_006f38a0,DAT_006f38a4);
  FUN_004cb21d(DAT_006f38a8,DAT_006f38ac);
  FUN_004cb1a2(600,0x17e);
  iVar3 = FUN_004b46a0();
  *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(iVar3 + 0x7c);
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar3 + 0x80);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar3 + 0x84);
  iVar3 = *(int *)(iVar3 + 0x88);
  *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + -100;
  *(int *)(unaff_EBP + -0x2c) = iVar3 + -100;
  (**(code **)(*extraout_ECX + 100))(unaff_EBP + -0x38);
  piVar4 = (int *)FUN_005e7743();
  iVar3 = *piVar4;
  *(int **)(unaff_EBP + -0x28) = piVar4;
  uVar5 = FUN_005e50fa(1);
  piVar4 = (int *)(**(code **)(iVar3 + 0x24))(1,uVar5);
  extraout_ECX[0x45] = (int)piVar4;
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x90))(0x2000,1);
    iVar3 = extraout_ECX[0x45];
    FUN_004cb21d(((extraout_ECX[0x21] - *(int *)(iVar3 + 0x84)) - extraout_ECX[0x1f]) + -0x14 +
                 *(int *)(iVar3 + 0x7c),
                 (((*(int *)(iVar3 + 0x80) - *(int *)(iVar3 + 0x88)) * 3) / 2 - extraout_ECX[0x20])
                 + extraout_ECX[0x22]);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x45]);
  }
  uVar5 = FUN_004705f2(4,0xffffffff);
  FUN_005d4956(uVar5);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piVar4 = (int *)FUN_005e7743();
  iVar3 = (**(code **)(*piVar4 + 0x24))(1,unaff_EBP + -0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x114] = iVar3;
  FUN_005b8770();
  if ((int *)extraout_ECX[0x114] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0x114] + 0x90))(0x2000,1);
    iVar3 = extraout_ECX[0x114];
    FUN_004cb21d((*(int *)(iVar3 + 0x84) - *(int *)(iVar3 + 0x7c)) * 3,
                 (((*(int *)(iVar3 + 0x80) - *(int *)(iVar3 + 0x88)) * 3) / 2 - extraout_ECX[0x20])
                 + extraout_ECX[0x22]);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x114]);
  }
  uVar5 = FUN_004705f2(3,0xffffffff);
  FUN_005d4956(uVar5);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  piVar4 = (int *)FUN_005e7743();
  iVar3 = (**(code **)(*piVar4 + 0x24))(1,unaff_EBP + -0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x113] = iVar3;
  FUN_005b8770();
  if ((int *)extraout_ECX[0x113] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0x113] + 0x90))(0x2000,1);
    FUN_004cb21d(0x31,(((*(int *)(extraout_ECX[0x113] + 0x80) - *(int *)(extraout_ECX[0x113] + 0x88)
                        ) * 3) / 2 - extraout_ECX[0x20]) + extraout_ECX[0x22]);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x113]);
  }
  FUN_005d4956(&DAT_006de560);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  piVar4 = (int *)FUN_005e7743();
  iVar3 = (**(code **)(*piVar4 + 0x28))(0,unaff_EBP + -0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x115] = iVar3;
  FUN_005b8770();
  if (extraout_ECX[0x115] != 0) {
    FUN_004ec186(*(int *)(extraout_ECX[0x114] + 0x84) - *(int *)(extraout_ECX[0x114] + 0x7c));
    FUN_004cb21d((*(int *)(extraout_ECX[0x114] + 0x84) - *(int *)(extraout_ECX[0x114] + 0x7c)) * 2,
                 (((*(int *)(extraout_ECX[0x113] + 0x80) - *(int *)(extraout_ECX[0x113] + 0x88)) * 3
                  ) / 2 - extraout_ECX[0x20]) + extraout_ECX[0x22]);
    uVar5 = (**(code **)(*DAT_006f2aa4 + 0x58))();
    FUN_004ec1a7(uVar5);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x115]);
  }
  iVar3 = *(int *)(*DAT_006e486c + 0x10);
  extraout_ECX[0x119] = *(int *)(iVar3 + 0x10c);
  FUN_0046f824(unaff_EBP + -0x144,0,0x100);
  *(undefined ***)(unaff_EBP + -0x150) = &PTR_FUN_00666524;
  FUN_0046f847(&DAT_006de560,0xffffffff);
  if (iVar3 != 0) {
    FUN_004102d4(unaff_EBP + -0x150);
  }
  if (DAT_006f38b0 == 0) {
    extraout_ECX[0x112] = 9;
LAB_00510f02:
    uVar5 = *(undefined4 *)(unaff_EBP + -0x14c);
    uVar6 = FUN_004705f2(1,0xffffffff);
    FUN_00635858(unaff_EBP + -0x550,uVar6,uVar5);
  }
  else {
    if (DAT_006f38b0 == 1) {
      extraout_ECX[0x112] = 0x16;
      goto LAB_00510f02;
    }
    if (DAT_006f38b0 == 2) {
      uVar5 = *(undefined4 *)(unaff_EBP + -0x14c);
      uVar6 = FUN_004705f2(2,0xffffffff);
      FUN_00635858(unaff_EBP + -0x550,uVar6,uVar5);
      extraout_ECX[0x112] = 9;
    }
  }
  FUN_005d4956(unaff_EBP + -0x550);
  *(undefined4 *)(unaff_EBP + -4) = 3;
  piVar4 = (int *)FUN_005e7743();
  iVar3 = (**(code **)(*piVar4 + 0x28))(0,unaff_EBP + -0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x46] = iVar3;
  FUN_005b8770();
  if (extraout_ECX[0x46] != 0) {
    (**(code **)(*(int *)(extraout_ECX[0x46] + 0xd4) + 0xc))(2,1);
    (*(code *)**(undefined4 **)(extraout_ECX[0x46] + 0xd4))();
    (**(code **)(*(int *)(extraout_ECX[0x46] + 0xd4) + 0x1c))(0);
    iVar3 = *(int *)extraout_ECX[0x46];
    iVar7 = (**(code **)(*DAT_006f2aa4 + 0x58))();
    (**(code **)(iVar3 + 0x60))(0,0,DAT_006f3890,iVar7 << 1);
    FUN_004cb21d(DAT_006f3878,DAT_006f387c);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x46]);
  }
  extraout_ECX[0x116] = 0;
  extraout_ECX[0x117] = 0;
  cVar2 = FUN_005117ea(5,3);
  *(char *)(unaff_EBP + -0xe) = '\x01' - (cVar2 != '\0');
  cVar2 = FUN_005117ea(4,4);
  *(char *)(unaff_EBP + -0xd) = '\x01' - (cVar2 != '\0');
  pvVar8 = operator_new(0x1f8);
  *(void **)(unaff_EBP + -0x14) = pvVar8;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if (pvVar8 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_004ec63d(extraout_ECX[0x112]);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x118] = iVar3;
  if (iVar3 != 0) {
    *(undefined1 *)(iVar3 + 0xec) = *(undefined1 *)(unaff_EBP + -0xe);
    *(undefined1 *)(extraout_ECX[0x118] + 0xed) = *(undefined1 *)(unaff_EBP + -0xd);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x118]);
    FUN_004cb21d(DAT_006f3898,DAT_006f389c);
    iVar3 = extraout_ECX[0x118];
    *(int *)(iVar3 + 0xfc) = extraout_ECX[0x48];
    *(int *)(iVar3 + 0x100) = extraout_ECX[0x116];
    *(int *)(iVar3 + 0x104) = extraout_ECX[0x117];
    iVar1 = DAT_006f3894;
    iVar7 = DAT_006f3890;
    iVar3 = *(int *)extraout_ECX[0x118];
    *(int **)(unaff_EBP + -0x14) = (int *)extraout_ECX[0x118];
    (**(code **)(iVar3 + 0x60))(DAT_006f3898,DAT_006f389c,iVar7 + DAT_006f3898,iVar1 + DAT_006f389c)
    ;
    uVar5 = FUN_005dd5e1(0x79,0x70,0x6e);
    *(undefined4 *)(extraout_ECX[0x118] + 100) = uVar5;
  }
  uVar5 = FUN_00511851(unaff_EBP + -0x20,0);
  *(undefined4 *)(unaff_EBP + -4) = 5;
  piVar4 = (int *)FUN_005e7743();
  iVar3 = (**(code **)(*piVar4 + 0x28))(0,uVar5);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x44] = iVar3;
  FUN_005b8770();
  if ((int *)extraout_ECX[0x44] != (int *)0x0) {
    iVar3 = *(int *)extraout_ECX[0x44];
    uVar5 = (**(code **)(*DAT_006f2aa4 + 0x58))();
    (**(code **)(iVar3 + 0x60))(0,0,DAT_006f3890,uVar5);
    FUN_004cb21d(DAT_006f3888,DAT_006f388c);
    FUN_004ec186(DAT_006f3890);
    uVar5 = (**(code **)(*DAT_006f2aa4 + 0x58))();
    FUN_004ec1a7(uVar5);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x44]);
  }
  pvVar8 = operator_new(0x1b8);
  *(void **)(unaff_EBP + -0x14) = pvVar8;
  *(undefined4 *)(unaff_EBP + -4) = 6;
  if (pvVar8 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005f179a();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x43] = iVar3;
  if (iVar3 != 0) {
    cVar2 = FUN_004cff80();
    FUN_005f42c3((&DAT_006f2a74)[(-(uint)(cVar2 != '\0') & 2) + 8]);
    FUN_005f42b6(0xffffffff);
    iVar1 = DAT_006f3884;
    iVar7 = DAT_006f3880;
    *(int *)(unaff_EBP + -0x1c) = DAT_006f3890 + DAT_006f3880;
    iVar3 = DAT_006f3894 + -0x5a;
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)extraout_ECX[0x43];
    (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x60))
              (iVar7,iVar1,*(undefined4 *)(unaff_EBP + -0x1c),iVar3 + iVar1);
    FUN_005f489f(1);
    FUN_005f427f(2);
    *(int *)(extraout_ECX[0x43] + 8) = extraout_ECX[0x43];
    FUN_005f4294(0);
    (**(code **)(*(int *)extraout_ECX[0x43] + 0x90))(0x2000,0);
    FUN_005f42a1(0);
    FUN_005f435f(0x3fc);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x43]);
    FUN_0051193f(unaff_EBP + -0x44,0);
    uVar9 = 1;
    uVar6 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 7;
    uVar5 = FUN_004096c2(0,1);
    FUN_005f436c(uVar5,uVar6,uVar9);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  (**(code **)(*extraout_ECX + 0x90))(0x2000,1);
  (**(code **)(*extraout_ECX + 0x90))(4,0);
  FUN_004ecfac();
  FUN_00511d39();
  uVar5 = 1;
LAB_0051133d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

