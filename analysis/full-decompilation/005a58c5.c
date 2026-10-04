
void FUN_005a58c5(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005a5ae3(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005a5a3b();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

