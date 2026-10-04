
undefined4 * FUN_00455e7f(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046fca5();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_0066728c;
  FUN_0047034e(0,0,0,0,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

