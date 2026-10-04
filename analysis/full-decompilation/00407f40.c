
void FUN_00407f40(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = (piVar1[1] - *piVar1) / 0x14;
  FUN_00464a5e(unaff_EBP + -0x10,1);
  iVar3 = piVar1[1];
  iVar2 = (iVar3 - *piVar1) / 0x14 - *(int *)(unaff_EBP + -0x10);
  if (iVar2 < 0) {
    FUN_0055e4e2(unaff_EBP + 0xb);
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    iVar3 = piVar1[1];
    iVar2 = *piVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004084db(iVar3,*(int *)(unaff_EBP + -0x10) - (iVar3 - iVar2) / 0x14,unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00407c07();
  }
  else if (0 < iVar2) {
    FUN_00408182(iVar3 + iVar2 * -0x14,iVar3);
  }
  for (iVar3 = *piVar1; iVar3 != piVar1[1]; iVar3 = iVar3 + 0x14) {
    FUN_00407b00(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

