
undefined4 * FUN_004706f0(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046fca5();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x1b] = 0;
  extraout_ECX[0x1c] = 0;
  extraout_ECX[0x1d] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_00667870;
  FUN_00471747(0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

