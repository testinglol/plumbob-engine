
void FUN_00497350(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066822c;
  iVar1 = extraout_ECX[0x15];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (iVar1 != 0) {
    FUN_00485b4c();
    extraout_ECX[0x15] = 0;
  }
  if (extraout_ECX[0xf] != 0) {
    FUN_0046176c();
    extraout_ECX[0xf] = 0;
  }
  if (extraout_ECX[0x10] != 0) {
    FUN_0046176c();
    extraout_ECX[0x10] = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00667bd0;
  return;
}

