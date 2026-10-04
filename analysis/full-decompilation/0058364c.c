
undefined4 * FUN_0058364c(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  FUN_005b870f(&DAT_006de560);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b870f(&DAT_006de560);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

