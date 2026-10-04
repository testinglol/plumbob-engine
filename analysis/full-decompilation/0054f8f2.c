
undefined4 * FUN_0054f8f2(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_006703c4;
  FUN_0054f7ed();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

