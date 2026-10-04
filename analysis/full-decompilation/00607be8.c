
void FUN_00607be8(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00676f80;
  extraout_ECX[1] = &PTR_LAB_00676f68;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_00607d39();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_006082b4();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006029b3();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

