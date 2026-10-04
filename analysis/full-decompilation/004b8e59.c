
void FUN_004b8e59(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = extraout_ECX[1];
  for (iVar2 = *extraout_ECX; iVar2 != iVar1; iVar2 = iVar2 + 8) {
    FUN_004b9149(iVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00542b02();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

