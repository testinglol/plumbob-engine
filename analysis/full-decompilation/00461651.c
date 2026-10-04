
undefined4 * FUN_00461651(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004620e1(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[9] = 0;
  *extraout_ECX = &PTR_FUN_00667438;
  FUN_00461b8d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

