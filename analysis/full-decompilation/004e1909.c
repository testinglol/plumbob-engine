
void FUN_004e1909(void)

{
  undefined4 *puVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  puVar1 = (undefined4 *)*extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
    *extraout_ECX = 0;
  }
  if ((undefined4 *)extraout_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[1])(1);
    extraout_ECX[1] = 0;
  }
  if ((undefined4 *)extraout_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[2])(1);
    extraout_ECX[2] = 0;
  }
  if ((undefined4 *)extraout_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[3])(1);
    extraout_ECX[3] = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

