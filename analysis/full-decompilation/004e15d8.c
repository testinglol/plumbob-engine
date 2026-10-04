
void FUN_004e15d8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc0;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = iVar2 - *extraout_ECX >> 5;
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar2 * 2;
    }
    iVar2 = 0;
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      iVar2 = FUN_00401742(*(int *)(unaff_EBP + -0x14) << 5);
    }
    iVar3 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    iVar3 = FUN_004e188c(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar2,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x18) = iVar3;
    *(int *)(unaff_EBP + -0x20) = iVar3;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (iVar3 != 0) {
      FUN_004e17ba(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar1 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(int *)(unaff_EBP + -0x18) = iVar3 + 0x20;
    uVar4 = FUN_004e188c(*(undefined4 *)(unaff_EBP + 8),iVar1,iVar3 + 0x20,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
    iVar1 = extraout_ECX[1];
    *(int *)(unaff_EBP + 8) = iVar1;
    if (iVar3 != iVar1) {
      do {
        FUN_004e1900(iVar3);
        iVar3 = iVar3 + 0x20;
      } while (iVar3 != *(int *)(unaff_EBP + 8));
    }
    iVar3 = extraout_ECX[2] - *extraout_ECX >> 5;
    if (iVar3 != 0) {
      FUN_0040189d(*extraout_ECX,iVar3 << 5);
    }
    iVar3 = *(int *)(unaff_EBP + 0xc);
    *extraout_ECX = iVar2;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = *(int *)(unaff_EBP + -0x14) * 0x20 + iVar2;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_004e17ba(iVar2 + -0x20);
    }
    uVar4 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x20;
    FUN_004e17ba(uVar4);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_004e185d(*(undefined4 *)(unaff_EBP + 8),iVar2 + -0x40,iVar2 + -0x20,
                 *(undefined4 *)(unaff_EBP + 8),0);
    FUN_004e1803(unaff_EBP + -0x40);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

