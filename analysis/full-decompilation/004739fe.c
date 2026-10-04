
void FUN_004739fe(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = extraout_ECX[1];
  for (iVar2 = *extraout_ECX; iVar2 != iVar1; iVar2 = iVar2 + 0x30) {
    FUN_00473f56(0);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00473a95();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

