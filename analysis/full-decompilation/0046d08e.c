
void FUN_0046d08e(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00667714;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0046de06();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040763c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

