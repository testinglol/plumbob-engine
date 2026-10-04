
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0050913d(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  void *pvVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar3 = (**(code **)(*extraout_ECX + 200))();
  if (cVar3 != '\0') {
    uVar4 = FUN_005dbf32();
    goto LAB_005098a5;
  }
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x94) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar5 = FUN_0041532c(9,unaff_EBP + -0x94,0);
  cVar3 = FUN_004fff98(0xdc,uVar5);
  if (cVar3 == '\0') {
    uVar4 = 0;
  }
  else {
    FUN_00471655(unaff_EBP + -0x14);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar5 = FUN_0046fc7a();
    FUN_005d4bbf(uVar5);
    FUN_005c11ce();
    uVar5 = FUN_0046fc7a();
    FUN_005d4bbf(uVar5);
    FUN_005c11ce();
    uVar5 = FUN_0046fc7a();
    FUN_005d4bbf(uVar5);
    FUN_005c11ce();
    uVar5 = FUN_0046fc7a();
    FUN_005d4bbf(uVar5);
    FUN_005c11ce();
    uVar5 = FUN_0046fc7a();
    FUN_005d4bbf(uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042004f();
    pvVar6 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x10) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar6 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_005e9913();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    extraout_ECX[0x38] = iVar7;
    if (iVar7 != 0) {
      iVar7 = extraout_ECX[0x49];
      (**(code **)(*DAT_006f2ab4 + 0x50))(unaff_EBP + -0x24,iVar7,extraout_ECX[0x4a] - iVar7);
      (**(code **)(*(int *)extraout_ECX[0x38] + 0x60))
                (*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),
                 *(int *)(unaff_EBP + -0x1c) + 5,*(undefined4 *)(unaff_EBP + -0x18));
      (**(code **)(*(int *)(extraout_ECX[0x38] + 0xd4) + 0x18))(DAT_006f2ab4);
      (**(code **)(*(int *)extraout_ECX[0x38] + 0x9c))(extraout_ECX + 0x49);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x38]);
      (**(code **)(*(int *)(extraout_ECX[0x38] + 0xd4) + 0x1c))(2);
      (**(code **)(*(int *)(extraout_ECX[0x38] + 0xd4) + 0x14))(0);
    }
    piVar8 = (int *)FUN_005e7743();
    iVar7 = *piVar8;
    uVar5 = FUN_005e50fa(3);
    iVar7 = (**(code **)(iVar7 + 0x24))(0,uVar5);
    extraout_ECX[0x3b] = iVar7;
    if (iVar7 != 0) {
      FUN_005e4b90(1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3b]);
    }
    piVar8 = (int *)FUN_005e7743();
    iVar7 = (**(code **)(*piVar8 + 0x24))(1,extraout_ECX + 0x46);
    extraout_ECX[0x3c] = iVar7;
    if (iVar7 != 0) {
      FUN_005e4b90(1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3c]);
    }
    iVar7 = extraout_ECX[0x38];
    iVar9 = extraout_ECX[0x21] - extraout_ECX[0x1f];
    if (iVar9 < *(int *)(iVar7 + 0x84) - *(int *)(iVar7 + 0x7c)) {
      iVar9 = *(int *)(iVar7 + 0x84) - *(int *)(iVar7 + 0x7c);
    }
    iVar7 = extraout_ECX[0x3c];
    iVar11 = extraout_ECX[0x3b];
    if (iVar9 < (((*(int *)(iVar7 + 0x84) + *(int *)(iVar11 + 0x84)) - *(int *)(iVar7 + 0x7c)) -
                *(int *)(iVar11 + 0x7c)) + 0xf) {
      iVar9 = (((*(int *)(iVar7 + 0x84) + *(int *)(iVar11 + 0x84)) - *(int *)(iVar7 + 0x7c)) -
              *(int *)(iVar11 + 0x7c)) + 0xf;
    }
    if (extraout_ECX[0x21] - extraout_ECX[0x1f] < iVar9) {
      iVar7 = extraout_ECX[0x22];
      iVar11 = extraout_ECX[0x20];
      *(int *)(unaff_EBP + -0x1c) = iVar9 + 10;
      iVar10 = FUN_004b46a0();
      iVar1 = *(int *)(iVar10 + 0x88);
      iVar2 = *(int *)(iVar10 + 0x80);
      iVar10 = ((*(int *)(iVar10 + 0x84) - *(int *)(iVar10 + 0x7c)) - (iVar9 + 10)) / 2;
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + iVar10;
      iVar9 = ((iVar1 - iVar2) - (iVar7 - iVar11)) / 2;
      (**(code **)(*extraout_ECX + 0x60))
                (iVar10,iVar9,*(undefined4 *)(unaff_EBP + -0x1c),(iVar7 - iVar11) + iVar9);
    }
    iVar7 = extraout_ECX[0x38];
    if (iVar7 != 0) {
      iVar9 = extraout_ECX[0x4c];
      if (iVar9 == 0) {
        iVar11 = 0;
        iVar9 = 0;
      }
      else {
        iVar11 = *(int *)(iVar9 + 0x20) / 3;
        iVar9 = *(int *)(iVar9 + 0x1c) / 3;
      }
      FUN_004cb21d(iVar9 + (((extraout_ECX[0x21] - *(int *)(iVar7 + 0x84)) - extraout_ECX[0x1f]) +
                           *(int *)(iVar7 + 0x7c)) / 2,iVar11 + 9);
    }
    iVar7 = extraout_ECX[0x4c];
    if (iVar7 == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)(iVar7 + 0x20) / 3;
    }
    iVar11 = extraout_ECX[0x3b];
    *(int *)(unaff_EBP + -0x10) =
         ((extraout_ECX[0x22] - extraout_ECX[0x20]) - *(int *)(iVar11 + 0x88)) +
         *(int *)(iVar11 + 0x80) + -9 + iVar9;
    if ((iVar11 != 0) && (iVar9 = extraout_ECX[0x3c], iVar9 != 0)) {
      iVar9 = ((extraout_ECX[0x21] - extraout_ECX[0x1f]) -
              (((*(int *)(iVar9 + 0x84) + *(int *)(iVar11 + 0x84)) - *(int *)(iVar11 + 0x7c)) -
              *(int *)(iVar9 + 0x7c))) / 3;
      if (iVar7 == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(iVar7 + 0x1c) / 3;
      }
      FUN_004cb21d(iVar7 + iVar9,*(undefined4 *)(unaff_EBP + -0x10));
      if (extraout_ECX[0x4c] == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(extraout_ECX[0x4c] + 0x1c) / 3;
      }
      FUN_004cb21d(((*(int *)(extraout_ECX[0x3b] + 0x84) + iVar9 * 2) -
                   *(int *)(extraout_ECX[0x3b] + 0x7c)) + iVar7,*(undefined4 *)(unaff_EBP + -0x10));
    }
    iVar7 = extraout_ECX[0x4c];
    if (iVar7 == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)(iVar7 + 0x1c) / 3;
    }
    *(int *)(unaff_EBP + -0x24) = iVar9 + 9;
    if (iVar7 == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)(iVar7 + 0x1c) / 3;
    }
    *(int *)(unaff_EBP + -0x1c) = (extraout_ECX[0x21] - extraout_ECX[0x1f]) + -9 + iVar9;
    if (iVar7 == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)(iVar7 + 0x20) / 3;
    }
    *(int *)(unaff_EBP + -0x20) =
         (*(int *)(extraout_ECX[0x38] + 0x88) - *(int *)(extraout_ECX[0x38] + 0x80)) + 0x12 + iVar9;
    if (iVar7 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(iVar7 + 0x20) / 3;
    }
    *(int *)(unaff_EBP + -0x18) =
         ((extraout_ECX[0x22] - extraout_ECX[0x20]) - *(int *)(extraout_ECX[0x3b] + 0x88)) +
         *(int *)(extraout_ECX[0x3b] + 0x80) + -0x12 + iVar7;
    FUN_005a5631(300,unaff_EBP + -0x28,4);
    if (*(int **)(unaff_EBP + -0x28) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EBP + -0x28) + 0x68))(DAT_006f2a64);
    }
    pvVar6 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x10) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (pvVar6 == (void *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)FUN_005e372a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    extraout_ECX[0x39] = (int)piVar8;
    (**(code **)(*piVar8 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x28),4,1);
    *(undefined1 *)(extraout_ECX[0x39] + 0x16b) = 1;
    *(undefined4 *)(extraout_ECX[0x39] + 0xf4) = 1;
    FUN_005dd9c8(extraout_ECX + 0x40);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x39]);
    FUN_005a5631(0x12d,unaff_EBP + -0x28,4);
    if (*(int **)(unaff_EBP + -0x28) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EBP + -0x28) + 0x68))(DAT_006f2a64);
    }
    pvVar6 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x10) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (pvVar6 == (void *)0x0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)FUN_005e372a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    extraout_ECX[0x3a] = (int)piVar8;
    (**(code **)(*piVar8 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x28),4,1);
    *(undefined1 *)(extraout_ECX[0x3a] + 0x16b) = 1;
    *(undefined4 *)(extraout_ECX[0x3a] + 0xf4) = 1;
    FUN_005dd9c8(extraout_ECX + 0x3d);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3a]);
    iVar7 = extraout_ECX[0x39];
    iVar11 = ((*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x24)) + -200) / 2;
    iVar9 = (((*(int *)(iVar7 + 0x80) - *(int *)(iVar7 + 0x88)) - *(int *)(unaff_EBP + -0x20)) +
            *(int *)(unaff_EBP + -0x18)) / 2 + *(int *)(unaff_EBP + -0x20);
    *(int *)(unaff_EBP + -0x10) = iVar9;
    FUN_004cb21d((*(int *)(iVar7 + 0x7c) - *(int *)(iVar7 + 0x84)) + iVar11 + -9 +
                 *(int *)(unaff_EBP + -0x24),iVar9);
    FUN_004cb21d((*(int *)(unaff_EBP + -0x1c) - iVar11) + 9,*(undefined4 *)(unaff_EBP + -0x10));
    pvVar6 = operator_new(0x20a8);
    *(void **)(unaff_EBP + -0x10) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    if (pvVar6 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_0056d18e(_DAT_0066ad3c);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    extraout_ECX[0x4d] = iVar7;
    FUN_004cb1a2(200,300);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x4d]);
    iVar7 = extraout_ECX[0x4d];
    FUN_004cb21d((((*(int *)(iVar7 + 0x7c) - *(int *)(iVar7 + 0x84)) - *(int *)(unaff_EBP + -0x24))
                 + *(int *)(unaff_EBP + -0x1c)) / 2 + *(int *)(unaff_EBP + -0x24),
                 (((*(int *)(iVar7 + 0x80) - *(int *)(iVar7 + 0x88)) - *(int *)(unaff_EBP + -0x20))
                 + *(int *)(unaff_EBP + -0x18)) / 2 + *(int *)(unaff_EBP + -0x20));
    iVar7 = extraout_ECX[0x36];
    if (iVar7 == 0) {
LAB_00509863:
      uVar5 = 0;
    }
    else if (iVar7 == 1) {
      uVar5 = 4;
    }
    else if (iVar7 == 2) {
      uVar5 = 2;
    }
    else if (iVar7 == 3) {
      uVar5 = 5;
    }
    else if (iVar7 == 4) {
      uVar5 = 0x11;
    }
    else {
      if (iVar7 != 5) goto LAB_00509863;
      uVar5 = 0x12;
    }
    FUN_0056d52d(extraout_ECX[0x37],uVar5);
    piVar8 = (int *)FUN_005e7743();
    iVar7 = (**(code **)(*piVar8 + 0x10))(5);
    extraout_ECX[0x4c] = iVar7;
    uVar4 = FUN_005dbf32();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
LAB_005098a5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

