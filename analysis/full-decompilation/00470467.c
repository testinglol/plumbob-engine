
void FUN_00470467(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00667868;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047031c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0047c52f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

