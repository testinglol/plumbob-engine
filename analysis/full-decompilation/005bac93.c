
int FUN_005bac93(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_005bbd01(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1 + 0xc;
}

