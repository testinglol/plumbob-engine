
void FUN_0045f9bf(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = extraout_ECX[1];
  for (iVar2 = *extraout_ECX; iVar2 != iVar1; iVar2 = iVar2 + 0x9c) {
    FUN_0045fae5();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0045fc98();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

