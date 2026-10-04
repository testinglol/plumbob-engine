
void FUN_00599bbd(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00599ca3();
  if (*(int **)(extraout_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(extraout_ECX + 0xc) + 8))();
    *(undefined4 *)(extraout_ECX + 0xc) = 0;
  }
  uVar1 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

