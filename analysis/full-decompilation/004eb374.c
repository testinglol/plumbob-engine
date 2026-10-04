
void FUN_004eb374(void)

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
    iVar2 = FUN_004eb94a(iVar2,*(undefined4 *)(unaff_EBP + 8),iVar4,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar2 != 0) {
      FUN_004eb760(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar1 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x18) = iVar2 + 0x44;
    uVar3 = FUN_004eb94a(*(undefined4 *)(unaff_EBP + 8),iVar1,iVar2 + 0x44,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
    iVar1 = extraout_ECX[1];
    *(int *)(unaff_EBP + 8) = iVar1;
    if (iVar2 != iVar1) {
      do {
        FUN_004ebba6(iVar2);
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
      FUN_004eb760(iVar2 + -0x44);
    }
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x44;
    FUN_004eb760(uVar3);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_004eb918(*(undefined4 *)(unaff_EBP + 8),iVar2 + -0x88,iVar2 + -0x44,
                 *(undefined4 *)(unaff_EBP + 8),0);
    FUN_004eb7af(unaff_EBP + -100);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00635f6d(unaff_EBP + -0x58,8,7,&LAB_004e8a75);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

