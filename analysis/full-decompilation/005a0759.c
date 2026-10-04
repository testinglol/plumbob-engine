
void FUN_005a0759(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar1 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (iVar1 != 0) {
    FUN_00598d92();
  }
  if (*(int **)(extraout_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(extraout_ECX + 0xc) + 8))();
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

