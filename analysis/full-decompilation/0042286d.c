
void FUN_0042286d(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00666c20;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00422909();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004323e0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

