
void FUN_006041f7(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    FUN_006321f0(iVar1);
    *extraout_ECX = 0;
  }
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

