
void FUN_00465bdf(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006675a0;
  iVar1 = extraout_ECX[3];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (iVar1 != 0) {
    FUN_005c2ee6();
    FUN_006321f0(iVar1);
  }
  extraout_ECX[3] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00401634();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004659d4();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

