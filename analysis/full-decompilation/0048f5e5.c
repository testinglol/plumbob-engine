
void FUN_0048f5e5(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00668020;
  iVar1 = extraout_ECX[9];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    FUN_0046176c();
    extraout_ECX[9] = 0;
  }
  if (extraout_ECX[10] != 0) {
    FUN_0046176c();
    extraout_ECX[10] = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00492fa7();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

