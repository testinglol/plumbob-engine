
void FUN_0040f9f9(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff50;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = (iVar2 - *extraout_ECX) / 0x90;
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
      iVar2 = *(int *)(unaff_EBP + -0x18);
    }
    else {
      iVar2 = iVar2 * 2;
      *(int *)(unaff_EBP + -0x18) = iVar2;
    }
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    else {
      uVar3 = FUN_00401742(iVar2 * 0x90);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    }
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar2 = FUN_0041006d(iVar2,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14),
                         *(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar2 != 0) {
      FUN_0040fcc1(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar4 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar4 = FUN_0041006d(*(undefined4 *)(unaff_EBP + 8),iVar4,iVar2 + 0x90,
                         *(undefined4 *)(unaff_EBP + 8));
    for (iVar2 = *extraout_ECX; iVar2 != extraout_ECX[1]; iVar2 = iVar2 + 0x90) {
    }
    iVar2 = (extraout_ECX[2] - *extraout_ECX) / 0x90;
    if (iVar2 != 0) {
      FUN_0040189d(*extraout_ECX,iVar2 * 0x90);
    }
    iVar2 = *(int *)(unaff_EBP + -0x18);
    iVar1 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar1;
    extraout_ECX[1] = iVar4;
    extraout_ECX[2] = iVar2 * 0x90 + iVar1;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_0040fcc1(iVar2 + -0x90);
    }
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x90;
    FUN_0040fcc1(uVar3);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_0040fe4c(*(undefined4 *)(unaff_EBP + 8),iVar2 + -0x120,iVar2 + -0x90);
    FUN_0040fd2d(unaff_EBP + -0xb0);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

