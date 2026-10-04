
void FUN_00596b92(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar1 = *(int *)(extraout_ECX + 0x30);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    FUN_005946cf();
  }
  *(undefined4 *)(extraout_ECX + 0x30) = 0;
  if (*(int *)(extraout_ECX + 0x2c) != 0) {
    FUN_005942ab();
  }
  *(undefined4 *)(extraout_ECX + 0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

