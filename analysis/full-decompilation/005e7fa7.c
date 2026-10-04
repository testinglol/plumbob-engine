
void FUN_005e7fa7(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005e80fd();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040189d(*extraout_ECX,0x18);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

