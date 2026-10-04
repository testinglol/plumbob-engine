
undefined4 * FUN_0054f92a(void)

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
  extraout_ECX[0x3f] = *(undefined4 *)(unaff_EBP + 8);
  return extraout_ECX;
}

