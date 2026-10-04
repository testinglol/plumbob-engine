
int FUN_005c14ef(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c1719();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d499c(iVar1);
  FUN_005d499c(iVar1 + 0xc);
  FUN_005c178a(iVar1 + 0x18);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
  return extraout_ECX;
}

