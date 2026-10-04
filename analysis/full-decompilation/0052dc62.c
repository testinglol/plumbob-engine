
undefined4 * FUN_0052dc62(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x44] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_00635e55(extraout_ECX + 0x49,0xc,4,FUN_005d48d9,FUN_005b8770);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x3b] = uVar1;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x36] = 0;
  *extraout_ECX = &PTR_FUN_0066de2c;
  return extraout_ECX;
}

