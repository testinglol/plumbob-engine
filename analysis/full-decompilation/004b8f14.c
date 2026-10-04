
void FUN_004b8f14(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  iVar5 = extraout_ECX[1];
  if (iVar5 == extraout_ECX[2]) {
    iVar5 = iVar5 - *extraout_ECX >> 3;
    if (iVar5 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar5 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar5 = iVar5 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar5;
    }
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_00401742(iVar5 << 3);
    }
    iVar3 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x1c) = iVar5;
    *(int *)(unaff_EBP + -0x18) = iVar5;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar3 = FUN_004b911d(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar5,*(undefined4 *)(unaff_EBP + 8));
    if (iVar3 != 0) {
      FUN_004b8d72(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar2 = extraout_ECX[1];
    *(int *)(unaff_EBP + -0x18) = iVar3 + 8;
    uVar4 = FUN_004b911d(*(undefined4 *)(unaff_EBP + 8),iVar2,iVar3 + 8,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
    iVar2 = extraout_ECX[1];
    *(int *)(unaff_EBP + 8) = iVar2;
    if (iVar3 != iVar2) {
      do {
        FUN_004b9149(iVar3);
        iVar3 = iVar3 + 8;
      } while (iVar3 != *(int *)(unaff_EBP + 8));
    }
    iVar3 = extraout_ECX[2] - *extraout_ECX >> 3;
    if (iVar3 != 0) {
      FUN_0040189d(*extraout_ECX,iVar3 << 3);
    }
    iVar3 = *(int *)(unaff_EBP + 0xc);
    *extraout_ECX = iVar5;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = iVar5 + *(int *)(unaff_EBP + -0x14) * 8;
  }
  else {
    if (iVar5 != 0) {
      FUN_004b8d72(iVar5 + -8);
    }
    puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 8;
    iVar5 = puVar1[1];
    *(undefined4 *)(unaff_EBP + -0x20) = *puVar1;
    *(int *)(unaff_EBP + -0x1c) = iVar5;
    if (iVar5 != 0) {
      *(int *)(iVar5 + 0x14) = *(int *)(iVar5 + 0x14) + 1;
    }
    iVar5 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004b90ee(*(undefined4 *)(unaff_EBP + 8),iVar5 + -0x10,iVar5 + -8,
                 *(undefined4 *)(unaff_EBP + 8),0);
    FUN_004b8d99(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x1c) != 0) {
      FUN_00415317();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

