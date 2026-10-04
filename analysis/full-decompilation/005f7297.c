
void FUN_005f7297(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00675ccc;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (*(code *)PTR_FUN_00675d94)();
  FUN_005e38e0();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e3892();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

