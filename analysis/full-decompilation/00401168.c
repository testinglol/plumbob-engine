
undefined4 * FUN_00401168(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  *(undefined2 *)(extraout_ECX + 1) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[2] = 0;
  FUN_004011a0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[3] = 0;
  return extraout_ECX;
}

