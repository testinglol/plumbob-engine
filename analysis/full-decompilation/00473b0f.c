
void FUN_00473b0f(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  int iVar3;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = (piVar1[1] - *piVar1) / 0x30;
  FUN_00464a5e(unaff_EBP + 8,1);
  iVar3 = piVar1[1];
  iVar2 = (iVar3 - *piVar1) / 0x30 - *(int *)(unaff_EBP + 8);
  if (iVar2 < 0) {
    FUN_005b8680();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005b8680();
    iVar3 = *piVar1;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_00473d19(piVar1[1],*(int *)(unaff_EBP + 8) - (piVar1[1] - iVar3) / 0x30,unaff_EBP + -0x3c);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else if (0 < iVar2) {
    FUN_00473a46(iVar3 + iVar2 * -0x30,iVar3);
  }
  for (iVar3 = *piVar1; iVar3 != piVar1[1]; iVar3 = iVar3 + 0x30) {
    FUN_00473984(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

