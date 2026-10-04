
void FUN_00412b5c(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffed0;
  iVar1 = extraout_ECX[1];
  if (iVar1 == extraout_ECX[2]) {
    iVar1 = (iVar1 - *extraout_ECX) / 0x110;
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar1 * 2;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      uVar2 = FUN_00401742(*(int *)(unaff_EBP + -0x14) * 0x110);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar1 = FUN_00412f3d(iVar1,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                         *(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar1;
    *(int *)(unaff_EBP + -0x20) = iVar1;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (iVar1 != 0) {
      FUN_00405584(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar4 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar3 = FUN_00412f3d(*(undefined4 *)(unaff_EBP + 8),iVar4,iVar1 + 0x110,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar1 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    for (iVar4 = *extraout_ECX; iVar4 != iVar1; iVar4 = iVar4 + 0x110) {
    }
    iVar1 = (extraout_ECX[2] - *extraout_ECX) / 0x110;
    if (iVar1 != 0) {
      FUN_0040189d(*extraout_ECX,iVar1 * 0x110);
    }
    iVar1 = *(int *)(unaff_EBP + -0x14);
    iVar4 = *(int *)(unaff_EBP + -0x18);
    *extraout_ECX = iVar4;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = iVar1 * 0x110 + iVar4;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar1;
    *(int *)(unaff_EBP + -0x18) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar1 != 0) {
      FUN_00405584(iVar1 + -0x110);
    }
    uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x110;
    FUN_00405584(uVar2);
    FUN_00412f07(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1] + -0x220,extraout_ECX[1] + -0x110,
                 *(undefined4 *)(unaff_EBP + 8),0);
    FUN_0046f8e4(unaff_EBP + -0x130);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

