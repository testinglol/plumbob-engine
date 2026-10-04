
void FUN_0050d6ac(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 0xc);
  if (*(int *)(unaff_EBP + 8) == 1) {
    if (iVar1 == extraout_ECX[0x39]) {
      FUN_005b870f(*(undefined4 *)(extraout_ECX[0x36] + 0xe4));
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004e9b56(extraout_ECX[0x35],unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    else if (iVar1 != extraout_ECX[0x3a]) goto LAB_0050d720;
    FUN_005dac30(0x10,extraout_ECX,0);
  }
  else if (*(int *)(unaff_EBP + 8) == 0x18) {
    (**(code **)(*extraout_ECX + 300))(1,extraout_ECX[0x3a]);
    goto LAB_0050d720;
  }
  FUN_005dd97f(*(undefined4 *)(unaff_EBP + 8),iVar1);
LAB_0050d720:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

