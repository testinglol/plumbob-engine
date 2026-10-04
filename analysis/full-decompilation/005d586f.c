
undefined4 * FUN_005d586f(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_005d58d8(0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x12] = &PTR_LAB_006737d4;
  extraout_ECX[0x13] = 0;
  FUN_005d5fbc(unaff_EBP + -0xe,unaff_EBP + -0xd);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_006737bc;
  extraout_ECX[1] = &PTR_LAB_006737b0;
  extraout_ECX[2] = &PTR_FUN_00673798;
  extraout_ECX[4] = &PTR_LAB_00673790;
  extraout_ECX[0x12] = &PTR_LAB_00673768;
  return extraout_ECX;
}

