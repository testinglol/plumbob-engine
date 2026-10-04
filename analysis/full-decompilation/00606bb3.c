
void FUN_00606bb3(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00676d68;
  extraout_ECX[0x35] = &PTR_LAB_00676d38;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00606e38();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e8cc5();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

