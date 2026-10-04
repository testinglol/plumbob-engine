
undefined4 * FUN_004a702c(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b3f82(0x400);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 3) = 0;
  extraout_ECX[4] = 0;
  *(undefined1 *)(extraout_ECX + 5) = 0;
  return extraout_ECX;
}

