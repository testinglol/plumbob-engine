
void FUN_00563570(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00670c70;
  extraout_ECX[0x35] = &PTR_LAB_00670c40;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_00563cf1();
  DAT_006fea20 = extraout_ECX[0x55];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e8cc5();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

