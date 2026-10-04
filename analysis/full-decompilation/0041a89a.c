
void FUN_0041a89a(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff84;
  iVar1 = extraout_ECX[1];
  if (iVar1 == extraout_ECX[2]) {
    iVar1 = (iVar1 - *extraout_ECX) / 0x5c;
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = iVar1 * 2;
    }
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    else {
      uVar3 = FUN_00401742(iVar1 * 0x5c);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    }
    iVar2 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar2 = FUN_0041b618(iVar2,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14),
                         *(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (iVar2 != 0) {
      FUN_0041ae1b(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar4 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar3 = FUN_0041b618(*(undefined4 *)(unaff_EBP + 8),iVar4,iVar2 + 0x5c,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + 8) = uVar3;
    for (iVar4 = *extraout_ECX; iVar4 != iVar2; iVar4 = iVar4 + 0x5c) {
    }
    iVar2 = (extraout_ECX[2] - *extraout_ECX) / 0x5c;
    if (iVar2 != 0) {
      FUN_0040189d(*extraout_ECX,iVar2 * 0x5c);
    }
    iVar2 = *(int *)(unaff_EBP + -0x14);
    iVar4 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar2;
    extraout_ECX[1] = iVar4;
    extraout_ECX[2] = iVar1 * 0x5c + iVar2;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar1;
    *(int *)(unaff_EBP + -0x18) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar1 != 0) {
      FUN_0041ae1b(iVar1 + -0x5c);
    }
    uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = extraout_ECX[1] + 0x5c;
    FUN_0041ae1b(uVar3);
    FUN_0041b584(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1] + -0xb8,extraout_ECX[1] + -0x5c,
                 *(undefined4 *)(unaff_EBP + 8),0);
    FUN_0041ae54(unaff_EBP + -0x7c);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

