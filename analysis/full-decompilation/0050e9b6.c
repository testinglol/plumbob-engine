
undefined4 * FUN_0050e9b6(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e8c4a(0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046fca5();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x47] = &PTR_FUN_0066643c;
  extraout_ECX[0x45] = uVar1;
  *extraout_ECX = &PTR_FUN_0066b928;
  extraout_ECX[0x35] = &PTR_LAB_0066b8f8;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x46] = 0;
  return extraout_ECX;
}

