
void FUN_0048afbb(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00667e78;
  iVar1 = extraout_ECX[0x17];
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (iVar1 != 0) {
    FUN_00485b4c();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00667bd0;
  return;
}

