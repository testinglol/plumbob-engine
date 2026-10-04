
void FUN_004a191c(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffec4;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = (iVar2 - *extraout_ECX) / 0x11c;
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x18) = iVar2 * 2;
    }
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    else {
      uVar3 = FUN_00401742(*(int *)(unaff_EBP + -0x18) * 0x11c);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    }
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar2 = FUN_004a2c9e(iVar2,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14),
                         *(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar2 != 0) {
      FUN_004a2108(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar4 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x1c) = iVar2 + 0x11c;
    iVar2 = FUN_004a2c9e(*(undefined4 *)(unaff_EBP + 8),iVar4,iVar2 + 0x11c,
                         *(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004a26fb(*extraout_ECX,extraout_ECX[1]);
    iVar4 = (extraout_ECX[2] - *extraout_ECX) / 0x11c;
    if (iVar4 != 0) {
      FUN_0040189d(*extraout_ECX,iVar4 * 0x11c);
    }
    iVar4 = *(int *)(unaff_EBP + -0x18);
    iVar1 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar1;
    extraout_ECX[1] = iVar2;
    extraout_ECX[2] = iVar4 * 0x11c + iVar1;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_004a2108(iVar2 + -0x11c);
    }
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x11c;
    FUN_004a2108(uVar3);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_004a2914(*(undefined4 *)(unaff_EBP + 8),iVar2 + -0x238,iVar2 + -0x11c,
                 *(undefined4 *)(unaff_EBP + 8),0);
    FUN_004a2139(unaff_EBP + -0x13c);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004a216a();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

