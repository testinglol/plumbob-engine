
void FUN_005801ed(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00671c84;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (*(code *)PTR_FUN_00671cbc)();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00671918;
  return;
}

