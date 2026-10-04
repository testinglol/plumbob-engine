
void FUN_0054113b(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  iVar4 = extraout_ECX[1];
  if (iVar4 == extraout_ECX[2]) {
    iVar4 = iVar4 - *extraout_ECX >> 2;
    if (iVar4 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
      iVar4 = *(int *)(unaff_EBP + -0x18);
    }
    else {
      iVar4 = iVar4 * 2;
      *(int *)(unaff_EBP + -0x18) = iVar4;
    }
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00401742(iVar4 << 2);
    }
    iVar5 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x1c) = iVar4;
    *(int *)(unaff_EBP + -0x14) = iVar4;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar5 = FUN_00541a8c(iVar5,*(undefined4 *)(unaff_EBP + 8),iVar4,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x14) = iVar5;
    *(int *)(unaff_EBP + -0x20) = iVar5;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (iVar5 != 0) {
      FUN_005412dc(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar3 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(int *)(unaff_EBP + -0x14) = iVar5 + 4;
    uVar6 = FUN_00541a8c(*(undefined4 *)(unaff_EBP + 8),iVar3,iVar5 + 4,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar5 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar6;
    iVar3 = extraout_ECX[1];
    *(int *)(unaff_EBP + 8) = iVar3;
    if (iVar5 != iVar3) {
      do {
        FUN_005421a6(iVar5);
        iVar5 = iVar5 + 4;
      } while (iVar5 != *(int *)(unaff_EBP + 8));
    }
    iVar5 = extraout_ECX[2] - *extraout_ECX >> 2;
    if (iVar5 != 0) {
      FUN_0040189d(*extraout_ECX,iVar5 << 2);
    }
    iVar5 = *(int *)(unaff_EBP + 0xc);
    *extraout_ECX = iVar4;
    extraout_ECX[1] = iVar5;
    extraout_ECX[2] = iVar4 + *(int *)(unaff_EBP + -0x18) * 4;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar4;
    *(int *)(unaff_EBP + -0x14) = iVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar4 != 0) {
      FUN_005412dc(iVar4 + -4);
    }
    piVar2 = *(int **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 4;
    iVar4 = *piVar2;
    if (iVar4 != 0) {
      piVar1 = (int *)(iVar4 + 0x20);
      *piVar1 = *piVar1 + 1;
    }
    *(int *)(unaff_EBP + -0x18) = *piVar2;
    iVar4 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_0054195a(*(undefined4 *)(unaff_EBP + 8),iVar4 + -8,iVar4 + -4,*(undefined4 *)(unaff_EBP + 8)
                 ,0);
    FUN_005412f4(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      FUN_0053d900();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

