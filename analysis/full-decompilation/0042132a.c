
void FUN_0042132a(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00470383(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),0);
  iVar1 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + 0xc) = 1;
  if (0 < iVar1) {
    do {
      FUN_0046146a();
      iVar1 = FUN_004705f2(*(undefined4 *)(unaff_EBP + 0xc),0xffffffff);
      if (iVar1 != 0) {
        FUN_00461575(iVar1);
      }
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
    } while (*(int *)(unaff_EBP + 0xc) <= *(int *)(extraout_ECX + 4));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

