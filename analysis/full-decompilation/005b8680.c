
undefined4 * FUN_005b8680(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  FUN_00401aae(8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00401a79();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

