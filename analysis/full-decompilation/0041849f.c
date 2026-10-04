
void FUN_0041849f(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff90;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = (iVar2 - *extraout_ECX) / 0x50;
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar2 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar2 = iVar2 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar2;
    }
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00401742(iVar2 * 0x50);
    }
    iVar3 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar3 = FUN_00418ab9(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar2,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar3;
    *(int *)(unaff_EBP + -0x20) = iVar3;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar3 != 0) {
      FUN_004187b6(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar5 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar4 = FUN_00418ab9(*(undefined4 *)(unaff_EBP + 8),iVar5,iVar3 + 0x50,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar3 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 8) = uVar4;
    for (iVar5 = *extraout_ECX; iVar5 != iVar3; iVar5 = iVar5 + 0x50) {
    }
    iVar3 = (extraout_ECX[2] - *extraout_ECX) / 0x50;
    if (iVar3 != 0) {
      FUN_0040189d(*extraout_ECX,iVar3 * 0x50);
    }
    iVar3 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar2;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = *(int *)(unaff_EBP + -0x14) * 0x50 + iVar2;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_004187b6(iVar2 + -0x50);
    }
    puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 0x50;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x70) = *puVar1;
    FUN_004030b4(puVar1 + 1);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    puVar1 = *(undefined4 **)(unaff_EBP + 8);
    FUN_00418a68(puVar1,iVar2 + -0xa0,iVar2 + -0x50,*(undefined4 *)(unaff_EBP + 8),0);
    *puVar1 = *(undefined4 *)(unaff_EBP + -0x70);
    FUN_0046f8e4(unaff_EBP + -0x6c);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

