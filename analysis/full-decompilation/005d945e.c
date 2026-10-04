
undefined4 * FUN_005d945e(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xf] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x10] = 0;
  uVar1 = FUN_00401742(0xc);
  extraout_ECX[0x11] = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(undefined4 *)(extraout_ECX[0x11] + 4) = extraout_ECX[0x11];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00604b69();
  extraout_ECX[0x55] = 0;
  extraout_ECX[0x56] = 0;
  extraout_ECX[0x57] = 0;
  extraout_ECX[0x58] = 0;
  extraout_ECX[0x59] = 0;
  extraout_ECX[0x5a] = 0;
  extraout_ECX[0x5c] = 0;
  extraout_ECX[0x5d] = 0;
  extraout_ECX[0x73] = 0;
  extraout_ECX[0x74] = 0;
  extraout_ECX[0x75] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d48d9();
  *extraout_ECX = &PTR_FUN_00673b38;
  DAT_006fe8f4 = extraout_ECX;
  DAT_006fe8f8 = extraout_ECX + 0x13;
  extraout_ECX[0x76] = 0xffffffff;
  extraout_ECX[0x77] = 0xffffffff;
  extraout_ECX[0x5e] = 1;
  extraout_ECX[0x5f] = 0;
  extraout_ECX[99] = 0;
  extraout_ECX[0x60] = 0;
  extraout_ECX[0x6e] = 0;
  *(undefined1 *)(extraout_ECX + 0x6d) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1a1) = 0;
  *(undefined1 *)(extraout_ECX + 0x68) = 0;
  *(undefined1 *)(extraout_ECX + 0x6f) = 0;
  extraout_ECX[0x70] = 0;
  extraout_ECX[0x71] = 0;
  *(undefined1 *)(extraout_ECX + 0x72) = 0;
  *(undefined1 *)(extraout_ECX + 0x78) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1e1) = 0;
  *(undefined1 *)(extraout_ECX + 0x7c) = 0;
  extraout_ECX[0x7d] = 0;
  *(undefined1 *)(extraout_ECX + 0x7e) = 0;
  extraout_ECX[0x7f] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(extraout_ECX + 0x80));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

