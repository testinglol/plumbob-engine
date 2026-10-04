
void FUN_005e526c(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006741a4;
  extraout_ECX[0x35] = &PTR_LAB_00674194;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005e5785();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e359a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

