
void FUN_004eb570(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = (iVar2 - *extraout_ECX) / 0x1c;
    iVar4 = 0;
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar2 * 2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      iVar4 = FUN_00401742(*(int *)(unaff_EBP + -0x14) * 0x1c);
    }
    iVar2 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x1c) = iVar4;
    *(int *)(unaff_EBP + -0x18) = iVar4;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    iVar2 = FUN_004ebae7(iVar2,*(undefined4 *)(unaff_EBP + 8),iVar4,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (iVar2 != 0) {
      FUN_004e88f3(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar1 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(int *)(unaff_EBP + -0x18) = iVar2 + 0x1c;
    uVar3 = FUN_004ebae7(*(undefined4 *)(unaff_EBP + 8),iVar1,iVar2 + 0x1c,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
    iVar1 = extraout_ECX[1];
    *(int *)(unaff_EBP + 8) = iVar1;
    if (iVar2 != iVar1) {
      do {
        FUN_004ebbaf(0);
        iVar2 = iVar2 + 0x1c;
      } while (iVar2 != *(int *)(unaff_EBP + 8));
    }
    iVar2 = (extraout_ECX[2] - *extraout_ECX) / 0x1c;
    if (iVar2 != 0) {
      FUN_0040189d(*extraout_ECX,iVar2 * 0x1c);
    }
    iVar2 = *(int *)(unaff_EBP + 0xc);
    *extraout_ECX = iVar4;
    extraout_ECX[1] = iVar2;
    extraout_ECX[2] = *(int *)(unaff_EBP + -0x14) * 0x1c + iVar4;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_004e88f3(iVar2 + -0x1c);
    }
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x1c;
    FUN_004e88f3(uVar3);
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_004eb888(*(undefined4 *)(unaff_EBP + 8),iVar2 + -0x38,iVar2 + -0x1c);
    FUN_004e89a7(unaff_EBP + -0x3c);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005a5e09();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

