
undefined4 * FUN_005634a9(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e8c4a(0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *extraout_ECX = &PTR_FUN_00670c70;
  extraout_ECX[0x35] = &PTR_LAB_00670c40;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x52] = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x4f] = 0;
  extraout_ECX[0x51] = 0;
  extraout_ECX[0x50] = 0;
  extraout_ECX[0x54] = 0;
  extraout_ECX[0x55] = DAT_006fea20;
  DAT_006fea20 = DAT_006f2a98;
  *(undefined1 *)(extraout_ECX + 0x56) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x159) = 0;
  return extraout_ECX;
}

