
void FUN_00460259(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff44;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = (iVar2 - *extraout_ECX) / 0x9c;
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x18) = iVar2 * 2;
    }
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    }
    else {
      uVar3 = FUN_00401742(*(int *)(unaff_EBP + -0x18) * 0x9c);
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
    }
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar2 = FUN_004612f1(iVar2,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x1c),
                         *(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar2 != 0) {
      FUN_004607ee(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar1 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x14) = iVar2 + 0x9c;
    uVar3 = FUN_004612f1(*(undefined4 *)(unaff_EBP + 8),iVar1,iVar2 + 0x9c,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
    iVar1 = extraout_ECX[1];
    *(int *)(unaff_EBP + 8) = iVar1;
    if (iVar2 != iVar1) {
      do {
        FUN_0045fae5();
        iVar2 = iVar2 + 0x9c;
      } while (iVar2 != *(int *)(unaff_EBP + 8));
    }
    iVar2 = (extraout_ECX[2] - *extraout_ECX) / 0x9c;
    if (iVar2 != 0) {
      FUN_0040189d(*extraout_ECX,iVar2 * 0x9c);
    }
    iVar2 = *(int *)(unaff_EBP + -0x1c);
    extraout_ECX[1] = *(int *)(unaff_EBP + 0xc);
    iVar1 = *(int *)(unaff_EBP + -0x18);
    *extraout_ECX = iVar2;
    extraout_ECX[2] = iVar1 * 0x9c + iVar2;
  }
  else {
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_004607ee(iVar2 + -0x9c);
    }
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x9c;
    FUN_004607ee(uVar3);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_00460edc(*(undefined4 *)(unaff_EBP + 8),iVar2 + -0x138,iVar2 + -0x9c);
    FUN_004608ca(unaff_EBP + -0xbc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005db425();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

