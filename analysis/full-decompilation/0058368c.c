
undefined4 * FUN_0058368c(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  FUN_005b86bd(iVar1 + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(iVar1 + 0x10);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

