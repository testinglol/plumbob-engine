
void FUN_0050ea47(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066b928;
  extraout_ECX[0x35] = &PTR_LAB_0066b8f8;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0050ef7f();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00470467();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e8cc5();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

