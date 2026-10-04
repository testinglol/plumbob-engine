
void FUN_0046058f(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar4 = piVar1[1];
  *(int *)(unaff_EBP + 8) = (iVar4 - *piVar1) / 0x9c;
  FUN_00464a5e(unaff_EBP + 8,1);
  iVar2 = (iVar4 - *piVar1) / 0x9c - *(int *)(unaff_EBP + 8);
  if (iVar2 < 0) {
    uVar3 = FUN_0048174b();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    iVar2 = *piVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00460c91(iVar4,*(int *)(unaff_EBP + 8) - (iVar4 - iVar2) / 0x9c,
                 *(undefined4 *)(unaff_EBP + -0x10));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005db425();
  }
  else if (0 < iVar2) {
    FUN_0045fc43(iVar4 + iVar2 * -0x9c,iVar4);
  }
  iVar2 = piVar1[1];
  for (iVar4 = *piVar1; iVar4 != iVar2; iVar4 = iVar4 + 0x9c) {
    FUN_005fe275(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

