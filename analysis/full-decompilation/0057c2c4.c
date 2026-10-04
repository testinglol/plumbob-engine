
void FUN_0057c2c4(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00580a0c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00671918;
  return;
}

