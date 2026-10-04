
void FUN_00405cc9(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = (piVar1[1] - *piVar1) / 0x3c0;
  FUN_00464a5e(unaff_EBP + 8,1);
  iVar4 = piVar1[1];
  iVar2 = (iVar4 - *piVar1) / 0x3c0 - *(int *)(unaff_EBP + 8);
  if (iVar2 < 0) {
    uVar3 = FUN_004032ba();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    iVar4 = piVar1[1];
    iVar2 = *piVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00405851(iVar4,*(int *)(unaff_EBP + 8) - (iVar4 - iVar2) / 0x3c0,
                 *(undefined4 *)(unaff_EBP + -0x10));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else if (0 < iVar2) {
    FUN_0040564f(iVar4 + iVar2 * -0x3c0,iVar4);
  }
  for (iVar4 = *piVar1; iVar4 != piVar1[1]; iVar4 = iVar4 + 0x3c0) {
    FUN_0040344b(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

