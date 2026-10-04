
void FUN_005cf3c9(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
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
    iVar2 = FUN_005cf5dc(iVar2,*(undefined4 *)(unaff_EBP + 8),iVar4,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar2 != 0) {
      FUN_005c36c0(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar1 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x18) = iVar2 + 0x44;
    uVar3 = FUN_005cf5dc(*(undefined4 *)(unaff_EBP + 8),iVar1,iVar2 + 0x44,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
    iVar1 = extraout_ECX[1];
    *(int *)(unaff_EBP + 8) = iVar1;
    if (iVar2 != iVar1) {
      do {
        FUN_005c4890();
        iVar2 = iVar2 + 0x44;
      } while (iVar2 != *(int *)(unaff_EBP + 8));
    }
    iVar2 = (extraout_ECX[2] - *extraout_ECX) / 0x44;
    if (iVar2 != 0) {
      FUN_0040189d(*extraout_ECX,iVar2 * 0x44);
    }
    iVar2 = *(int *)(unaff_EBP + 0xc);
    *extraout_ECX = iVar4;
    extraout_ECX[1] = iVar2;
    extraout_ECX[2] = *(int *)(unaff_EBP + -0x14) * 0x44 + iVar4;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_005c36c0(iVar2 + -0x44);
    }
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x44;
    FUN_005c36c0(uVar3);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar4 = *(int *)(unaff_EBP + 8);
    FUN_005cf575(iVar4,iVar2 + -0x88,iVar2 + -0x44);
    FUN_00462f2f(unaff_EBP + -100);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(unaff_EBP + -0x24);
    FUN_005c4890();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

