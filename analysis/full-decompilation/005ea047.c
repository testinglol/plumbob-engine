
void FUN_005ea047(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005e9e40(uVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

