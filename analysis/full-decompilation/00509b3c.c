
void __fastcall FUN_00509b3c(undefined4 *param_1)

{
  int unaff_EBP;
  
  *(undefined4 **)(unaff_EBP + -0x10) = param_1;
  *param_1 = &PTR_FUN_0066ad44;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0050a45d();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

