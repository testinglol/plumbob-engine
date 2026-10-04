
undefined4 * FUN_005edbcb(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00635e55(extraout_ECX + 0x3e,0xc,4,FUN_005d48d9,FUN_005b8770);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0047343b(0,0);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0047343b(0,0);
  extraout_ECX[0x69] = 0;
  extraout_ECX[0x6a] = 0;
  extraout_ECX[0x6b] = 0;
  *extraout_ECX = &PTR_FUN_00675260;
  extraout_ECX[0x35] = 0;
  _memset(extraout_ECX + 0x36,0,0x10);
  _memset(extraout_ECX + 0x3a,0,0x10);
  extraout_ECX[0x4a] = 0;
  *(undefined1 *)(extraout_ECX + 0x5c) = 1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x5d] = 0;
  extraout_ECX[0x5e] = 0;
  extraout_ECX[0x5f] = 0;
  extraout_ECX[0x60] = 0;
  extraout_ECX[0x61] = 0;
  extraout_ECX[0x62] = 0;
  extraout_ECX[99] = 0;
  extraout_ECX[100] = 0;
  extraout_ECX[0x65] = 0;
  extraout_ECX[0x66] = 0;
  extraout_ECX[0x67] = 0;
  extraout_ECX[0x68] = 0;
  *(undefined1 *)(extraout_ECX + 0x6c) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1b1) = 0;
  extraout_ECX[0x6d] = 0;
  extraout_ECX[0x6e] = 0;
  return extraout_ECX;
}

