
void FUN_0053d8b1(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066f3d0;
  iVar1 = extraout_ECX[9];
  *(undefined4 *)(unaff_EBP + -4) = 6;
  if (iVar1 != 0) {
    FUN_0053d900();
  }
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_0053ff1c();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_0053ff1c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

