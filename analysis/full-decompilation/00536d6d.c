
void FUN_00536d6d(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066ed40;
  extraout_ECX[0x35] = &PTR_LAB_0066ed30;
  *(undefined4 *)(unaff_EBP + -4) = 5;
  FUN_00522114();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e359a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

