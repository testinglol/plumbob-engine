
void FUN_00556b56(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006708c4;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_00557dfc();
  DAT_006fea20 = extraout_ECX[0x81];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0055e50a();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

