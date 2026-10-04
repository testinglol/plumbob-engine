
undefined4 * FUN_004425e8(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x5b] = 0;
  extraout_ECX[0x5c] = 0;
  extraout_ECX[0x5d] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_00667060;
  FUN_0055e6f0();
  FUN_0055e7ee();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

