
undefined4 * FUN_0040b75a(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  extraout_ECX[6] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  extraout_ECX[7] = 0;
  FUN_0046f824(extraout_ECX + 0xb,0,0x100);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[8] = &PTR_FUN_00666524;
  return extraout_ECX;
}

