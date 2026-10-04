
void FUN_005d5a0d(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[-2] = &PTR_LAB_006737bc;
  extraout_ECX[-1] = &PTR_LAB_006737b0;
  *extraout_ECX = &PTR_FUN_00673798;
  extraout_ECX[2] = &PTR_LAB_00673790;
  extraout_ECX[0x10] = &PTR_LAB_00673768;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d5f86();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005d5951();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

