
void FUN_00416f31(void)

{
  char cVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00666794;
  extraout_ECX[3] = &PTR_LAB_00666824;
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

