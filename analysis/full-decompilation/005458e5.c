
undefined4 * FUN_005458e5(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e8c4a(0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x58] = 0;
  extraout_ECX[0x59] = 0;
  extraout_ECX[0x5a] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d48d9();
  *extraout_ECX = &PTR_FUN_0066fb24;
  extraout_ECX[0x35] = &PTR_LAB_0066faf4;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x46] = 0;
  _memset(extraout_ECX + 0x4b,0,0x34);
  extraout_ECX[0x47] = 0xffffffff;
  *(undefined1 *)(extraout_ECX + 0x48) = 1;
  extraout_ECX[0x5b] = 0;
  extraout_ECX[0x49] = 0x19;
  *(undefined1 *)(extraout_ECX + 0x4a) = 0;
  extraout_ECX[0x61] = 0;
  _memset(extraout_ECX + 0x7a,0,0x20);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x5e] = 0;
  extraout_ECX[0x5f] = 0;
  extraout_ECX[0x60] = 1;
  extraout_ECX[0x62] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x121) = 0;
  extraout_ECX[0x6a] = 0;
  extraout_ECX[0x6b] = 0;
  extraout_ECX[0x6c] = 0;
  extraout_ECX[0x77] = 0;
  extraout_ECX[0x78] = 0;
  extraout_ECX[0x76] = DAT_006fea20;
  DAT_006fea20 = DAT_006f2a98;
  *(undefined1 *)(extraout_ECX + 0x79) = 1;
  return extraout_ECX;
}

