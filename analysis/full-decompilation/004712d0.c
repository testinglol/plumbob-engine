
void FUN_004712d0(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00667870;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0047123b();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00471701();
  *extraout_ECX = &PTR_FUN_00667868;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0047031c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0047c52f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

