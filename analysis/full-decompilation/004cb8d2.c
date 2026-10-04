
undefined4 * FUN_004cb8d2(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d4956(&DAT_006de560);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d4956(&DAT_006de560);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[7] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  FUN_005c1719();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00635e55(extraout_ECX + 0xc,4,2,FUN_005c1719,FUN_005a5e09);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  extraout_ECX[0xf] = 0;
  extraout_ECX[0x10] = 1;
  FUN_005c1719();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x14] = 0;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x16] = 0;
  extraout_ECX[0x17] = 0;
  *extraout_ECX = &PTR_FUN_00668b68;
  *(undefined1 *)(extraout_ECX + 0x13) = 0;
  return extraout_ECX;
}

