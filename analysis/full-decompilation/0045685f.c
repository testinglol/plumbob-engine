
void FUN_0045685f(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006672b0;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_004569a5();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004569dc();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00456b0c();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00456cc5();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

