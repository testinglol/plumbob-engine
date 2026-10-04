
void FUN_0050b039(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066af1c;
  extraout_ECX[0x35] = &PTR_LAB_0066aeec;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0050b87b();
  DAT_006f3600 = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0050bdab();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e8cc5();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

