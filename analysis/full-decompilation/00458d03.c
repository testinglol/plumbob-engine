
void FUN_00458d03(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff9c;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = (iVar2 - *extraout_ECX) / 0x44;
    iVar4 = 0;
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar2 * 2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      iVar4 = FUN_00401742(*(int *)(unaff_EBP + -0x14) * 0x44);
    }
    iVar2 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x1c) = iVar4;
    *(int *)(unaff_EBP + -0x18) = iVar4;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar2 = FUN_00458f0c(iVar2,*(undefined4 *)(unaff_EBP + 8),iVar4,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar2 != 0) {
      FUN_0041ed89(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar1 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x18) = iVar2 + 0x44;
    uVar3 = FUN_00458f0c(*(undefined4 *)(unaff_EBP + 8),iVar1,iVar2 + 0x44,
                         *(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + 8) = uVar3;
    FUN_00458ef3(*extraout_ECX,iVar2);
    iVar2 = (extraout_ECX[2] - *extraout_ECX) / 0x44;
    if (iVar2 != 0) {
      FUN_0040189d(*extraout_ECX,iVar2 * 0x44);
    }
    iVar2 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar4;
    extraout_ECX[1] = iVar2;
    extraout_ECX[2] = *(int *)(unaff_EBP + -0x14) * 0x44 + iVar4;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_0041ed89(iVar2 + -0x44);
    }
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x44;
    FUN_0041ed89(uVar3);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_00458e90(*(undefined4 *)(unaff_EBP + 8),iVar2 + -0x88,iVar2 + -0x44);
    FUN_0041edc1(unaff_EBP + -100);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

