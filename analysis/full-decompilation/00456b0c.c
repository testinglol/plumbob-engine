
void FUN_00456b0c(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  int iVar1;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  for (iVar1 = *extraout_ECX; iVar1 != extraout_ECX[1]; iVar1 = iVar1 + 0xc) {
    if (*(undefined4 **)(iVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(iVar1 + 4))(1);
    }
  }
  FUN_0041fb0c(*extraout_ECX,extraout_ECX[1]);
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x10) = iVar1;
  FUN_004d6053();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

