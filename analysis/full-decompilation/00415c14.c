
void FUN_00415c14(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00666714;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00415e60();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040763c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

