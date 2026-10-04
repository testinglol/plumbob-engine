
void FUN_00477a2c(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00667a88;
  puVar1 = (undefined4 *)extraout_ECX[0x15];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  FUN_004782a0();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040763c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

