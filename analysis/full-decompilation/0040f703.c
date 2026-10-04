
void FUN_0040f703(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff48;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = (iVar2 - *extraout_ECX) / 0x98;
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
      uVar3 = FUN_00401742(*(int *)(unaff_EBP + -0x14) * 0x98);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
    }
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar2 = FUN_0040ffac(iVar2,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                         *(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (iVar2 != 0) {
      FUN_00472f33(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar4 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar4 = FUN_0040ffac(*(undefined4 *)(unaff_EBP + 8),iVar4,iVar2 + 0x98,
                         *(undefined4 *)(unaff_EBP + 8));
    for (iVar2 = *extraout_ECX; iVar2 != extraout_ECX[1]; iVar2 = iVar2 + 0x98) {
    }
    iVar2 = (extraout_ECX[2] - *extraout_ECX) / 0x98;
    if (iVar2 != 0) {
      FUN_0040189d(*extraout_ECX,iVar2 * 0x98);
    }
    iVar2 = *(int *)(unaff_EBP + -0x14);
    iVar1 = *(int *)(unaff_EBP + -0x18);
    *extraout_ECX = iVar1;
    extraout_ECX[1] = iVar4;
    extraout_ECX[2] = iVar2 * 0x98 + iVar1;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_00472f33(iVar2 + -0x98);
    }
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x98;
    FUN_00472f33(uVar3);
    FUN_0040fe0e(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1] + -0x130,extraout_ECX[1] + -0x98);
    FUN_00473077(unaff_EBP + -0xb8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

