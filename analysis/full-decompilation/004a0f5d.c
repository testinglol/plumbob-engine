
void FUN_004a0f5d(void)

{
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00470636(unaff_EBP + -0x78);
  FUN_00470636(unaff_EBP + -0x78);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

