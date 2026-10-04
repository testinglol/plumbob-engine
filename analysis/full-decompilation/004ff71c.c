
undefined4 * FUN_004ff71c(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x3e] = 0x2d;
  extraout_ECX[0x3f] = 0x2d;
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x3a] = 6;
  extraout_ECX[0x3b] = 1;
  extraout_ECX[0x43] = 0xffffffff;
  extraout_ECX[0x44] = 0xffffffff;
  extraout_ECX[0x45] = 0xffffffff;
  extraout_ECX[0x46] = 0xffffffff;
  FUN_00635e55(extraout_ECX + 0x47,0x10,4,&LAB_004ff7ee,FUN_00416e17);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00669c90;
  return extraout_ECX;
}

