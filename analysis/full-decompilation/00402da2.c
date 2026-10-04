
void FUN_00402da2(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff8c;
  iVar1 = extraout_ECX[1];
  if (iVar1 == extraout_ECX[2]) {
    iVar1 = (iVar1 - *extraout_ECX) / 0x54;
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = iVar1 * 2;
    }
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    else {
      uVar3 = FUN_00401742(iVar1 * 0x54);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    }
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar2 = FUN_004031f1(iVar2,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14),
                         *(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (iVar2 != 0) {
      FUN_00403093(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar4 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar3 = FUN_004031f1(*(undefined4 *)(unaff_EBP + 8),iVar4,iVar2 + 0x54,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 8) = uVar3;
    for (iVar4 = *extraout_ECX; iVar4 != iVar2; iVar4 = iVar4 + 0x54) {
    }
    iVar2 = (extraout_ECX[2] - *extraout_ECX) / 0x54;
    if (iVar2 != 0) {
      FUN_0040189d(*extraout_ECX,iVar2 * 0x54);
    }
    iVar2 = *(int *)(unaff_EBP + -0x14);
    iVar4 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar2;
    extraout_ECX[1] = iVar4;
    extraout_ECX[2] = iVar1 * 0x54 + iVar2;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar1;
    *(int *)(unaff_EBP + -0x18) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar1 != 0) {
      FUN_00403093(iVar1 + -0x54);
    }
    iVar1 = *(int *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x54;
    FUN_004030b4(iVar1);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar1 + 0x4c);
    *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar1 + 0x50);
    iVar1 = *(int *)(unaff_EBP + 8);
    FUN_0040313a(iVar1,iVar2 + -0xa8,iVar2 + -0x54);
    FUN_0046f8e4(unaff_EBP + -0x74);
    *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(unaff_EBP + -0x24);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

