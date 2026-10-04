
void FUN_0056ce1a(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00671158;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0056cec0();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e3892();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

