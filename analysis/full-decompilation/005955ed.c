
void FUN_005955ed(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00595714();
  uVar1 = *(undefined4 *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
  FUN_004d6053();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

