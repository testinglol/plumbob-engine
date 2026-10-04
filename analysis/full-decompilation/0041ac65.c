
void FUN_0041ac65(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = (piVar1[1] - *piVar1) / 0x14;
  FUN_00464a5e(unaff_EBP + -0x10,1);
  iVar4 = piVar1[1];
  iVar3 = (iVar4 - *piVar1) / 0x14 - *(int *)(unaff_EBP + -0x10);
  if (iVar3 < 0) {
    FUN_0055e4e2(unaff_EBP + 0xb);
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    iVar4 = piVar1[1];
    iVar3 = *piVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0041b24e(iVar4,*(int *)(unaff_EBP + -0x10) - (iVar4 - iVar3) / 0x14,unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0041a82b();
  }
  else if (0 < iVar3) {
    FUN_0041a84b(iVar4 + iVar3 * -0x14,iVar4);
  }
  for (iVar4 = *piVar1; iVar4 != piVar1[1]; iVar4 = iVar4 + 0x14) {
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar4 + 0xc);
    FUN_00464a5e(unaff_EBP + -0x14,1);
    uVar2 = *(undefined4 *)(unaff_EBP + 0x10);
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(unaff_EBP + -0x14);
    FUN_0041aa06(iVar4,*(undefined4 *)(unaff_EBP + 0xc),uVar2);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

