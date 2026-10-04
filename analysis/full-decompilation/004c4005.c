
void FUN_004c4005(void)

{
  int *piVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006688d4;
  piVar1 = (int *)extraout_ECX[6];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
    if ((undefined4 *)extraout_ECX[6] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[6])(1);
    }
    extraout_ECX[6] = 0;
  }
  if ((int *)extraout_ECX[4] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[4] + 8))();
    if ((undefined4 *)extraout_ECX[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[4])(1);
    }
    extraout_ECX[4] = 0;
  }
  if ((int *)extraout_ECX[5] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[5] + 8))();
    if ((undefined4 *)extraout_ECX[5] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[5])(1);
    }
    extraout_ECX[5] = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040763c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

