
undefined4 * FUN_005cdf87(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[0x18] = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x1e] = 0;
  extraout_ECX[0x1f] = 0;
  extraout_ECX[0x20] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x21] = 0;
  extraout_ECX[0x22] = 0;
  extraout_ECX[0x23] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0049b1e4();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c35b0();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c35b0();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005c35b0();
  extraout_ECX[0x6f] = 0;
  extraout_ECX[0x70] = 0;
  extraout_ECX[0x71] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_004a702c();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_004a702c();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_004a702c();
  extraout_ECX[0x87] = &PTR_FUN_00673470;
  extraout_ECX[0x88] = 0;
  extraout_ECX[0x89] = &PTR_FUN_00673470;
  extraout_ECX[0x8a] = 0;
  *extraout_ECX = &PTR_FUN_006734a0;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x6d] = 0;
  extraout_ECX[0x6e] = 0;
  extraout_ECX[0x8b] = 0;
  extraout_ECX[0x25] = 0;
  *(undefined1 *)(extraout_ECX + 0x19) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x65) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x66) = 1;
  extraout_ECX[0x17] = 0;
  extraout_ECX[0x24] = 0;
  extraout_ECX[0x72] = 0;
  extraout_ECX[0x73] = 0;
  extraout_ECX[0x74] = 0;
  SetRect((LPRECT)(extraout_ECX + 0x26),0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x100] = 0;
  extraout_ECX[0x101] = 0;
  return extraout_ECX;
}

