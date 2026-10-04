
void FUN_0054e2e5(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00670204;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0054e54a();
  if ((int *)extraout_ECX[0x99] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0x99] + 0x10))();
    if ((undefined4 *)extraout_ECX[0x99] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[0x99])(1);
    }
    extraout_ECX[0x99] = 0;
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004e1909();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e3892();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

