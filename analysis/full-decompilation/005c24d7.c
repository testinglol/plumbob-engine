
void FUN_005c24d7(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046664c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0042004f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

