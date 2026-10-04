
undefined4 * FUN_00457882(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(extraout_ECX + 6,0,0x40);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[3] = &PTR_FUN_0066651c;
  return extraout_ECX;
}

