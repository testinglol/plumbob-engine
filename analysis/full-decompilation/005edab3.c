
undefined4 * FUN_005edab3(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d58d8(0xffe17b80);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x12] = &PTR_LAB_00675218;
  FUN_00602e26();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_006751e8;
  extraout_ECX[1] = &PTR_LAB_006751dc;
  extraout_ECX[2] = &PTR_FUN_006751c4;
  extraout_ECX[4] = &PTR_LAB_006751bc;
  extraout_ECX[0x12] = &PTR_LAB_00675174;
  return extraout_ECX;
}

