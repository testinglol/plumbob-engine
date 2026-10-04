
void FUN_004c7205(void)

{
  undefined4 *puVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_004c7318();
  puVar1 = (undefined4 *)*extraout_ECX;
  if (((puVar1 != (undefined4 *)0x0) && ((char)extraout_ECX[6] == '\0')) &&
     (puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  thunk_FUN_004b8e59();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004c951b();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

