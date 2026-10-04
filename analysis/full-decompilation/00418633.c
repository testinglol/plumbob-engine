
void FUN_00418633(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = (piVar1[1] - *piVar1) / 0x50;
  FUN_00464a5e(unaff_EBP + 8,1);
  iVar4 = piVar1[1];
  iVar2 = (iVar4 - *piVar1) / 0x50 - *(int *)(unaff_EBP + 8);
  if (iVar2 < 0) {
    uVar3 = FUN_004186fe();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    iVar4 = piVar1[1];
    iVar2 = *piVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0041882b(iVar4,*(int *)(unaff_EBP + 8) - (iVar4 - iVar2) / 0x50,
                 *(undefined4 *)(unaff_EBP + -0x10));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else if (0 < iVar2) {
    FUN_004187d3(iVar4 + iVar2 * -0x50,iVar4);
  }
  iVar4 = *piVar1;
  if (iVar4 != piVar1[1]) {
    *(int *)(unaff_EBP + -0x10) = iVar4 + 4;
    do {
      FUN_00464a5e(iVar4,1);
      FUN_00464d2c(*(undefined4 *)(unaff_EBP + -0x10));
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x50;
      iVar4 = iVar4 + 0x50;
    } while (iVar4 != piVar1[1]);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

