
void FUN_005cb675(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffcf0;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = (iVar2 - *extraout_ECX) / 0x2f0;
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar2 * 2;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      uVar3 = FUN_00401742(*(int *)(unaff_EBP + -0x14) * 0x2f0);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
    }
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar2 = FUN_005cbd7d(iVar2,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                         *(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (iVar2 != 0) {
      FUN_005cb7ff(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar4 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar4 = FUN_005cbd7d(*(undefined4 *)(unaff_EBP + 8),iVar4,iVar2 + 0x2f0,
                         *(undefined4 *)(unaff_EBP + 8));
    for (iVar2 = *extraout_ECX; iVar2 != extraout_ECX[1]; iVar2 = iVar2 + 0x2f0) {
    }
    iVar2 = (extraout_ECX[2] - *extraout_ECX) / 0x2f0;
    if (iVar2 != 0) {
      FUN_0040189d(*extraout_ECX,iVar2 * 0x2f0);
    }
    iVar2 = *(int *)(unaff_EBP + -0x14);
    iVar1 = *(int *)(unaff_EBP + -0x18);
    *extraout_ECX = iVar1;
    extraout_ECX[1] = iVar4;
    extraout_ECX[2] = iVar2 * 0x2f0 + iVar1;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_005cb7ff(iVar2 + -0x2f0);
    }
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x2f0;
    FUN_005cb7ff(uVar3);
    FUN_005cbbcb(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1] + -0x5e0,extraout_ECX[1] + -0x2f0);
    FUN_005ca85e(unaff_EBP + -0x310);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

