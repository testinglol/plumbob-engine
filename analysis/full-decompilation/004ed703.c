
undefined4 * FUN_004ed703(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(extraout_ECX + 10,0,0x104);
  extraout_ECX[7] = &PTR_FUN_006664e8;
  FUN_0046f824(extraout_ECX + 0x4e,0,0x104);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x4b] = &PTR_FUN_006664e8;
  extraout_ECX[5] = uVar1;
  *extraout_ECX = &PTR_FUN_0066979c;
  extraout_ECX[4] = 0;
  extraout_ECX[6] = 0;
  extraout_ECX[0x8f] = 0;
  return extraout_ECX;
}

