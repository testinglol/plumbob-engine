
void FUN_0041342c(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffe84;
  iVar1 = extraout_ECX[1];
  if (iVar1 == extraout_ECX[2]) {
    iVar1 = (iVar1 - *extraout_ECX) / 0x15c;
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar1 * 2;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      uVar2 = FUN_00401742(*(int *)(unaff_EBP + -0x14) * 0x15c);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar1 = FUN_00413a4a(iVar1,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),
                         *(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar1;
    *(int *)(unaff_EBP + -0x20) = iVar1;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (iVar1 != 0) {
      FUN_00413743(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar4 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar3 = FUN_00413a4a(*(undefined4 *)(unaff_EBP + 8),iVar4,iVar1 + 0x15c,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar1 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    for (iVar4 = *extraout_ECX; iVar4 != iVar1; iVar4 = iVar4 + 0x15c) {
    }
    iVar1 = (extraout_ECX[2] - *extraout_ECX) / 0x15c;
    if (iVar1 != 0) {
      FUN_0040189d(*extraout_ECX,iVar1 * 0x15c);
    }
    iVar1 = *(int *)(unaff_EBP + -0x14);
    iVar4 = *(int *)(unaff_EBP + -0x18);
    *extraout_ECX = iVar4;
    extraout_ECX[1] = iVar3;
    extraout_ECX[2] = iVar1 * 0x15c + iVar4;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar1;
    *(int *)(unaff_EBP + -0x18) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar1 != 0) {
      FUN_00413743(iVar1 + -0x15c);
    }
    uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x15c;
    FUN_00413743(uVar2);
    FUN_004139a9(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1] + -0x2b8,extraout_ECX[1] + -0x15c);
    FUN_0041376e(unaff_EBP + -0x17c);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

