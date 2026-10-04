
undefined4 * FUN_00403586(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(extraout_ECX + 7,0,0x40);
  extraout_ECX[4] = &PTR_FUN_0066651c;
  FUN_00635e55(extraout_ECX + 0x17,0xc,2,FUN_005b8680,FUN_005b8770);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = 0;
  return extraout_ECX;
}

