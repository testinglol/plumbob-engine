
void FUN_00468f04(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar6;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  iVar2 = extraout_ECX[1];
  if (iVar2 == extraout_ECX[2]) {
    iVar2 = (iVar2 - *extraout_ECX) / 0xc;
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
      iVar2 = FUN_00401742(iVar2 * 0xc);
    }
    iVar3 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    iVar3 = FUN_00469582(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar2,*(undefined4 *)(unaff_EBP + 8));
    *(int *)(unaff_EBP + -0x1c) = iVar3;
    *(int *)(unaff_EBP + -0x20) = iVar3;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (iVar3 != 0) {
      FUN_00462be8(*(undefined4 *)(unaff_EBP + 0xc));
    }
    iVar5 = extraout_ECX[1];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar4 = FUN_00469582(*(undefined4 *)(unaff_EBP + 8),iVar5,iVar3 + 0xc,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar3 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + 8) = uVar4;
    for (iVar5 = *extraout_ECX; iVar5 != iVar3; iVar5 = iVar5 + 0xc) {
    }
    iVar3 = (extraout_ECX[2] - *extraout_ECX) / 0xc;
    if (iVar3 != 0) {
      FUN_0040189d(*extraout_ECX,iVar3 * 0xc);
    }
    iVar3 = *(int *)(unaff_EBP + 8);
    *extraout_ECX = iVar2;
    extraout_ECX[1] = iVar3;
    iVar2 = iVar2 + *(int *)(unaff_EBP + -0x14) * 0xc;
    piVar6 = extraout_ECX;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 != 0) {
      FUN_00462be8(iVar2 + -0xc);
    }
    puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + 0xc;
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x2c) = *puVar1;
    uVar4 = puVar1[2];
    *(undefined4 *)(unaff_EBP + -0x28) = puVar1[1];
    *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
    piVar6 = *(int **)(unaff_EBP + 8);
    FUN_004693e4(piVar6,iVar2 + -0x18,iVar2 + -0xc);
    *piVar6 = *(int *)(unaff_EBP + -0x2c);
    piVar6[1] = *(int *)(unaff_EBP + -0x28);
    iVar2 = *(int *)(unaff_EBP + -0x24);
  }
  uVar4 = *(undefined4 *)(unaff_EBP + -0xc);
  piVar6[2] = iVar2;
  *unaff_FS_OFFSET = uVar4;
  return;
}

