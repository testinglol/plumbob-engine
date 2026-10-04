
int * FUN_0057c4d2(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  iVar1 = FUN_00401742(0xc);
  *extraout_ECX = iVar1;
  *(int *)iVar1 = iVar1;
  *(int *)(*extraout_ECX + 4) = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  extraout_ECX[1] = 0;
  extraout_ECX[5] = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[6] = 0;
  return extraout_ECX;
}

