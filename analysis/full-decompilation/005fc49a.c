
void FUN_005fc49a(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00676694;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005fc67e();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005f822d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

