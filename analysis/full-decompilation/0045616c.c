
undefined4 * FUN_0045616c(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00456418(0x20);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

