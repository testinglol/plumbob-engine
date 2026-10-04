
void FUN_0041905d(void)

{
  char cVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066682c;
  extraout_ECX[3] = &PTR_LAB_006668bc;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  cVar1 = FUN_004131c2();
  if (cVar1 != '\0') {
    FUN_004195ba();
  }
  if (extraout_ECX[10] != 0) {
    FUN_006321f0(extraout_ECX[10]);
  }
  extraout_ECX[10] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004130c0();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004659d4();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

