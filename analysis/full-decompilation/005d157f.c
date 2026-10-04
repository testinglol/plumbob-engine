
void FUN_005d157f(void)

{
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d1646(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004d4185();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

