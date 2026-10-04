
void FUN_0057ce80(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_006029b3();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006029b3();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

