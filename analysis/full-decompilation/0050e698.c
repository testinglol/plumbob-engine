
void FUN_0050e698(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066b73c;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_005e38e0();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e3892();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

