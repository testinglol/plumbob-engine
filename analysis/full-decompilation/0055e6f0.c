
undefined4 * FUN_0055e6f0(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x56] = 0;
  extraout_ECX[0x57] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x5b] = 0;
  extraout_ECX[0x5c] = 0;
  extraout_ECX[0x5d] = 0;
  extraout_ECX[0x3b] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_00667060;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x3c] = 0;
  _memset(extraout_ECX + 0x3d,0,0x28);
  _memset(extraout_ECX + 0x47,0,0x38);
  if (DAT_006f5b18 == 0) {
    FUN_00561da7();
  }
  extraout_ECX[99] = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[100] = 0;
  extraout_ECX[0x65] = 0;
  extraout_ECX[0x66] = 0;
  extraout_ECX[0x67] = 0x40a00000;
  extraout_ECX[0x68] = 0;
  extraout_ECX[0x6a] = DAT_006fea20;
  DAT_006fea20 = DAT_006f2a98;
  extraout_ECX[0x5e] = 0xffffffff;
  *(undefined1 *)(extraout_ECX + 0x59) = 0;
  extraout_ECX[0x5a] = 0;
  *(undefined1 *)(extraout_ECX + 0x6b) = 0;
  return extraout_ECX;
}

