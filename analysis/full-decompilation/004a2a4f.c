
void FUN_004a2a4f(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = (piVar1[1] - *piVar1) / 0x11c;
  FUN_00464a5e(unaff_EBP + -0x10,1);
  iVar4 = piVar1[1];
  iVar2 = (iVar4 - *piVar1) / 0x11c - *(int *)(unaff_EBP + -0x10);
  if (iVar2 < 0) {
    uVar3 = FUN_004a223c();
    *(undefined4 *)(unaff_EBP + 8) = uVar3;
    iVar4 = piVar1[1];
    iVar2 = *piVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004a2d52(iVar4,*(int *)(unaff_EBP + -0x10) - (iVar4 - iVar2) / 0x11c,
                 *(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004a216a();
  }
  else if (0 < iVar2) {
    FUN_004a17d3(iVar4 + iVar2 * -0x11c,iVar4);
  }
  iVar4 = *piVar1;
  if (iVar4 != piVar1[1]) {
    *(int *)(unaff_EBP + 8) = iVar4 + 0x110;
    do {
      FUN_00464d2c(*(int *)(unaff_EBP + 8) + -0x10c);
      FUN_004a3192(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                   *(undefined4 *)(unaff_EBP + 0x10));
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0x11c;
      iVar4 = iVar4 + 0x11c;
    } while (iVar4 != piVar1[1]);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

