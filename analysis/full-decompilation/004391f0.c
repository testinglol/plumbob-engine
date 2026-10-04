
void FUN_004391f0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = iVar2 - *extraout_ECX >> 4;
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar2 * 2;
    }
    iVar2 = 0;
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      iVar2 = FUN_00401742(*(int *)(unaff_EBP + -0x14) << 4);
    }
    iVar3 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar3 = FUN_00439631(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar2,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x18) = iVar3;
    *(int *)(unaff_EBP + -0x20) = iVar3;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar3 != 0) {
      FUN_004393d9(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar4 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x18) = iVar3 + 0x10;
    iVar3 = FUN_00439631(*(undefined4 *)(unaff_EBP + 8),iVar4,iVar3 + 0x10,
                         *(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00439507(*extraout_ECX,extraout_ECX[1]);
    iVar4 = extraout_ECX[2] - *extraout_ECX >> 4;
    if (iVar4 != 0) {
      FUN_0040189d(*extraout_ECX,iVar4 << 4);
    }
    iVar4 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar2;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = iVar4 * 0x10 + iVar2;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_004393d9(iVar2 + -0x10);
    }
    uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x10;
    FUN_004393d9(uVar1);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_0043954f(*(undefined4 *)(unaff_EBP + 8),iVar2 + -0x20,iVar2 + -0x10,
                 *(undefined4 *)(unaff_EBP + 8),0);
    FUN_004393d9(unaff_EBP + -0x30);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

