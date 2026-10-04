
void FUN_005c7c9d(void)

{
  int *piVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00673464;
  piVar1 = (int *)extraout_ECX[2];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    extraout_ECX[2] = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005cb5d7();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

