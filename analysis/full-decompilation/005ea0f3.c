
undefined4 * FUN_005ea0f3(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  extraout_ECX[0x35] = 0xffffffff;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  *(undefined1 *)(extraout_ECX + 0x3a) = 0;
  extraout_ECX[0x3b] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0x3c) = 0;
  FUN_005d48d9();
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x59] = 0;
  *(undefined1 *)(extraout_ECX + 0x42) = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x5c] = 1;
  extraout_ECX[0x5f] = 1;
  extraout_ECX[0x60] = 1;
  extraout_ECX[0x5a] = 0;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x46] = 0;
  extraout_ECX[0x47] = 0;
  extraout_ECX[0x48] = 0;
  extraout_ECX[0x49] = 0;
  extraout_ECX[0x4a] = 0;
  extraout_ECX[0x4b] = 0;
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x4d] = 0;
  extraout_ECX[0x4e] = 0;
  extraout_ECX[0x4f] = 0;
  extraout_ECX[0x50] = 0;
  extraout_ECX[0x51] = 0;
  extraout_ECX[0x52] = 0;
  *(undefined1 *)(extraout_ECX + 0x53) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x14d) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x14e) = 0;
  extraout_ECX[0x54] = 0;
  extraout_ECX[0x56] = 0;
  extraout_ECX[0x57] = 0;
  extraout_ECX[0x58] = 0;
  extraout_ECX[0x5b] = 8;
  extraout_ECX[0x5d] = 0;
  extraout_ECX[0x5e] = 0;
  *(undefined1 *)(extraout_ECX + 99) = 0;
  extraout_ECX[100] = 0;
  extraout_ECX[0x65] = 0;
  extraout_ECX[0x66] = 0;
  *extraout_ECX = &PTR_FUN_00674b54;
  extraout_ECX[0x61] = 0x28;
  extraout_ECX[0x62] = 0x14;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = FUN_005e749a(0);
  FUN_005dde6d(uVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

