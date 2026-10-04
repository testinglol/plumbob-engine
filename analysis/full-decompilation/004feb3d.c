
void FUN_004feb3d(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  iVar3 = extraout_ECX[1];
  if (iVar3 == extraout_ECX[2]) {
    iVar3 = (iVar3 - *extraout_ECX) / 0xc;
    if (iVar3 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
      iVar3 = *(int *)(unaff_EBP + -0x18);
    }
    else {
      iVar3 = iVar3 * 2;
      *(int *)(unaff_EBP + -0x18) = iVar3;
    }
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00401742(iVar3 * 0xc);
    }
    iVar4 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x1c) = iVar3;
    *(int *)(unaff_EBP + -0x14) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar4 = FUN_004d62c5(iVar4,*(undefined4 *)(unaff_EBP + 8),iVar3,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x14) = iVar4;
    *(int *)(unaff_EBP + -0x20) = iVar4;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar4 != 0) {
      FUN_005b8680();
    }
    iVar1 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x14) = iVar4 + 0xc;
    uVar2 = FUN_004d62c5(*(undefined4 *)(unaff_EBP + 8),iVar1,iVar4 + 0xc,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar4 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
    iVar1 = extraout_ECX[1];
    *(int *)(unaff_EBP + 8) = iVar1;
    if (iVar4 != iVar1) {
      do {
        FUN_005b8770();
        iVar4 = iVar4 + 0xc;
      } while (iVar4 != *(int *)(unaff_EBP + 8));
    }
    iVar4 = (extraout_ECX[2] - *extraout_ECX) / 0xc;
    if (iVar4 != 0) {
      FUN_0040189d(*extraout_ECX,iVar4 * 0xc);
    }
    iVar4 = *(int *)(unaff_EBP + -0x20);
    *extraout_ECX = iVar3;
    extraout_ECX[1] = iVar4;
    extraout_ECX[2] = iVar3 + *(int *)(unaff_EBP + -0x18) * 0xc;
  }
  else {
    *(int *)(unaff_EBP + -0x20) = iVar3;
    *(int *)(unaff_EBP + -0x1c) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar3 != 0) {
      FUN_005b86bd(iVar3 + -0xc);
    }
    extraout_ECX[1] = extraout_ECX[1] + 0xc;
    iVar3 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00405f0d(*(undefined4 *)(unaff_EBP + 8),iVar3 + -0x18,iVar3 + -0xc);
    uVar2 = FUN_005b8680();
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005d499c(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

