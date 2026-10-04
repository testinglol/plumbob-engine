
void FUN_005e359a(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066ab80;
  extraout_ECX[0x35] = &PTR_LAB_0066ad20;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005dbf4d();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

