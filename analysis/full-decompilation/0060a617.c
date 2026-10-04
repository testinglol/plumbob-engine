
void FUN_0060a617(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006770f4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0060a6d3();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00677068;
  return;
}

