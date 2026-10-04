
void FUN_005edb43(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[-2] = &PTR_LAB_006751e8;
  extraout_ECX[-1] = &PTR_LAB_006751dc;
  *extraout_ECX = &PTR_FUN_006751c4;
  extraout_ECX[2] = &PTR_LAB_006751bc;
  extraout_ECX[0x10] = &PTR_LAB_00675174;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00602e69();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005d5951();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

