
void __fastcall FUN_00416f3c(undefined4 *param_1)

{
  char cVar1;
  int unaff_EBP;
  
  *(undefined4 **)(unaff_EBP + -0x10) = param_1;
  *param_1 = &PTR_FUN_00666794;
  param_1[3] = &PTR_LAB_00666824;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  cVar1 = FUN_004131c2();
  if (cVar1 != '\0') {
    FUN_004171fa();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004130c0();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004659d4();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

