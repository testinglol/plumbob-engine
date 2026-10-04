
void FUN_005f8c5d(void)

{
  undefined4 uVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  (**(code **)(*extraout_ECX + 0x50))();
  uVar1 = FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d499c(uVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  (**(code **)(*extraout_ECX + 0x30))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

