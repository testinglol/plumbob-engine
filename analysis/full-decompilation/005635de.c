
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_005635de(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  int iVar7;
  void *pvVar8;
  int iVar9;
  int *extraout_ECX;
  uint uVar10;
  int unaff_EBP;
  int *piVar11;
  
  FUN_00634c24();
  cVar4 = (**(code **)(*extraout_ECX + 200))();
  if (cVar4 != '\0') {
    uVar5 = FUN_005e8d11();
    goto LAB_00563ce4;
  }
  extraout_ECX[0x41] = 3;
  extraout_ECX[0x19] = DAT_006f2a68;
  FUN_005a5631(0x14b5,extraout_ECX + 0x50,4);
  piVar11 = (int *)extraout_ECX[0x50];
  if (piVar11 != (int *)0x0) {
    (**(code **)(*piVar11 + 0x68))(DAT_006f2a64);
  }
  piVar11 = extraout_ECX + 0x4f;
  FUN_005a5631((-(uint)(*(char *)((int)extraout_ECX + 0x159) != '\0') & 2) + 0x13b1,piVar11,4);
  iVar7 = *piVar11;
  if (iVar7 == 0) {
    extraout_ECX[0x4d] = 0;
    extraout_ECX[0x4e] = 0;
  }
  else {
    uVar10 = *(uint *)(iVar7 + 0x1c);
    iVar9 = extraout_ECX[0x21];
    iVar2 = extraout_ECX[0x22];
    iVar3 = extraout_ECX[0x1f];
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar7 + 0x20);
    if (uVar10 < (uint)(iVar9 - iVar3)) {
      uVar10 = (iVar9 - iVar3) - uVar10 >> 1;
    }
    else {
      uVar10 = 0;
    }
    uVar1 = *(uint *)(unaff_EBP + -0x10);
    extraout_ECX[0x4d] = uVar10;
    if (uVar1 < (uint)(iVar2 - extraout_ECX[0x20])) {
      uVar10 = (uint)((iVar2 - extraout_ECX[0x20]) - *(int *)(unaff_EBP + -0x10)) >> 1;
    }
    else {
      uVar10 = 0;
    }
    extraout_ECX[0x4e] = uVar10;
  }
  FUN_005e8d11();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x90) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar6 = FUN_0041532c(9,unaff_EBP + -0x90,0);
  cVar4 = FUN_004fff98(0x80,uVar6);
  if (cVar4 == '\0') {
LAB_0056370c:
    uVar5 = 0;
  }
  else {
    iVar7 = FUN_0047168f();
    if (iVar7 < 8) goto LAB_0056370c;
    pvVar8 = operator_new(0x124);
    *(void **)(unaff_EBP + -0x10) = pvVar8;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar8 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_00543ad2();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    extraout_ECX[0x4c] = iVar7;
    if (iVar7 != 0) {
      *(undefined1 *)(iVar7 + 0xd4) = *(undefined1 *)((int)extraout_ECX + 0x159);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x4c]);
      FUN_004cb21d(DAT_006f5be8 + extraout_ECX[0x4d],extraout_ECX[0x4e] + _DAT_006f5bec);
      iVar7 = extraout_ECX[0x4c];
      *(int *)(iVar7 + 0xec) = *piVar11;
      *(int *)(iVar7 + 0xf0) = extraout_ECX[0x4d];
      *(int *)(iVar7 + 0xf4) = extraout_ECX[0x4e];
      uVar6 = FUN_004705f2(0x11,0xffffffff);
      uVar6 = FUN_005d4956(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005dd9c8(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
    }
    pvVar8 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x10) = pvVar8;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (pvVar8 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_005e9913();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    extraout_ECX[0x54] = iVar7;
    if (iVar7 != 0) {
      (**(code **)(*(int *)(iVar7 + 0xd4) + 0x18))(DAT_006f2ab4);
      iVar7 = extraout_ECX[0x54];
      *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x21] - extraout_ECX[0x1f];
      iVar7 = (**(code **)(**(int **)(iVar7 + 0xd8) + 0x58))();
      (**(code **)(*(int *)extraout_ECX[0x54] + 0x60))
                (0,extraout_ECX[0x4e] + 6,*(undefined4 *)(unaff_EBP + -0x14),
                 iVar7 + 6 + extraout_ECX[0x4e]);
      iVar7 = *(int *)extraout_ECX[0x54];
      uVar6 = FUN_004705f2(9,0xffffffff);
      (**(code **)(iVar7 + 0x1a0))(uVar6);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x54]);
      (**(code **)(*(int *)(extraout_ECX[0x54] + 0xd4) + 0x1c))(2);
      (**(code **)(*(int *)(extraout_ECX[0x54] + 0xd4) + 0x14))(0);
    }
    FUN_00471655(unaff_EBP + -0x24);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005c11ce();
    FUN_005c11ce();
    iVar7 = 0;
    piVar11 = extraout_ECX + 0x42;
    do {
      FUN_0046fc87(unaff_EBP + -0x14,0);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      uVar6 = FUN_0046fc7a();
      iVar9 = FUN_00563e55(iVar7,uVar6);
      *piVar11 = iVar9;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_0042004f();
      if (*piVar11 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(*piVar11);
      }
      iVar7 = iVar7 + 1;
      piVar11 = piVar11 + 1;
    } while (iVar7 < 4);
    FUN_0046fc87(unaff_EBP + -0x14,0);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    uVar6 = FUN_0046fc7a();
    FUN_005d4bbf(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x14,0);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    uVar6 = FUN_0046fc7a();
    FUN_005d4bbf(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0042004f();
    pvVar8 = operator_new(0xd4);
    *(void **)(unaff_EBP + -0x10) = pvVar8;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    if (pvVar8 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_005dbd68();
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (iVar7 != 0) {
      (**(code **)(*extraout_ECX + 0x20))(iVar7);
      FUN_004cb21d((-(uint)(*(char *)((int)extraout_ECX + 0x159) != '\0') & 0xffffffe9) + 0x24a +
                   extraout_ECX[0x4d],extraout_ECX[0x4e] + 0x2a);
      FUN_004cb1a2(0x1a,0x17);
      uVar6 = FUN_004705f2(0xb,0xffffffff);
      FUN_005d4956(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
    }
    pvVar8 = operator_new(0xd4);
    *(void **)(unaff_EBP + -0x10) = pvVar8;
    *(undefined1 *)(unaff_EBP + -4) = 10;
    if (pvVar8 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_005dbd68();
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (iVar7 != 0) {
      (**(code **)(*extraout_ECX + 0x20))(iVar7);
      FUN_004cb21d(extraout_ECX[0x4d] +
                   (-(uint)(*(char *)((int)extraout_ECX + 0x159) != '\0') & 0xffffffe7) + 0x296,
                   extraout_ECX[0x4e] + 0x2a);
      FUN_004cb1a2(0x1a,0x17);
      uVar6 = FUN_004705f2(0xc,0xffffffff);
      FUN_005d4956(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
    }
    if (*(char *)((int)extraout_ECX + 0x159) != '\0') {
      pvVar8 = operator_new(0xd4);
      *(void **)(unaff_EBP + -0x10) = pvVar8;
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      if (pvVar8 == (void *)0x0) {
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_005dbd68();
      }
      *(undefined1 *)(unaff_EBP + -4) = 4;
      if (iVar7 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(iVar7);
        FUN_004cb21d(extraout_ECX[0x4d] + 0x2b2,extraout_ECX[0x4e] + 0x2a);
        FUN_004cb1a2(0x1a,0x17);
        uVar6 = FUN_004705f2(0x12,0xffffffff);
        FUN_005d4956(uVar6);
        *(undefined1 *)(unaff_EBP + -4) = 0xd;
        FUN_005dd9c8(unaff_EBP + -0x18);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8770();
      }
    }
    piVar11 = (int *)extraout_ECX[0x43];
    if ((char)piVar11[0x5a] != '\0') {
      *(undefined1 *)(piVar11 + 0x5a) = 0;
      (**(code **)(*piVar11 + 0x168))();
    }
    FUN_005e4b90(1);
    piVar11 = (int *)extraout_ECX[0x44];
    if ((char)piVar11[0x5a] != '\0') {
      *(undefined1 *)(piVar11 + 0x5a) = 0;
      (**(code **)(*piVar11 + 0x168))();
    }
    uVar6 = FUN_004705f2(0x10,0xffffffff);
    FUN_005d4956(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    FUN_005dd9c8(unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005b8770();
    FUN_005e4b90(1);
    if (extraout_ECX[0x52] != -1) {
      FUN_00544423(extraout_ECX[0x52]);
    }
    extraout_ECX[0x53] = *(int *)(DAT_006fe8f4 + 0x1fc);
    *(int **)(DAT_006fe8f4 + 0x1fc) = extraout_ECX;
    if ((DAT_006f5c00 == 0) && (*(char *)((int)extraout_ECX + 0x159) == '\0')) {
      DAT_006f5c00 = 1;
      FUN_004e609e();
      uVar10 = FUN_00401f6f();
      if (uVar10 < 2) {
        FUN_005dadff(extraout_ECX,500,0);
      }
    }
    if ((DAT_006f5c04 == 0) && (*(char *)((int)extraout_ECX + 0x159) != '\0')) {
      DAT_006f5c04 = 1;
      FUN_004e609e();
      uVar10 = FUN_004ed868();
      if (uVar10 < 6) {
        FUN_005dadff(extraout_ECX,500,0);
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042004f();
    uVar5 = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
LAB_00563ce4:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

