
undefined4 * FUN_004c71c6(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004c94d1();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046ea4d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(extraout_ECX + 6) = 1;
  return extraout_ECX;
}

