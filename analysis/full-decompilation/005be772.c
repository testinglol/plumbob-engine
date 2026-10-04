
undefined4 * FUN_005be772(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00672c24;
  FUN_005bdd58(uVar1);
  extraout_ECX[7] = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 6) = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0x20000000;
  FUN_004dc9d9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x14] = 0;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x17] = 0;
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x1b] = 0;
  extraout_ECX[0x1c] = 0;
  extraout_ECX[0x1d] = 0;
  extraout_ECX[0x1e] = 0;
  extraout_ECX[0x1f] = 0;
  *extraout_ECX = &PTR_LAB_00672b9c;
  return extraout_ECX;
}

