
undefined4 * FUN_005e372a(void)

{
  char *_Str1;
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *extraout_ECX = &PTR_FUN_00673e38;
  *(undefined1 *)(extraout_ECX + 0x5a) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x169) = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x4b] = 0;
  extraout_ECX[0x51] = 0;
  extraout_ECX[0x36] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x16a) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x16b) = 0;
  extraout_ECX[0x54] = 9;
  extraout_ECX[0x55] = 0;
  *(undefined1 *)(extraout_ECX + 0x5b) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x16e) = 0;
  extraout_ECX[0x53] = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x3b] = 0;
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x58] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x16d) = 0;
  extraout_ECX[0x52] = 0;
  extraout_ECX[0x59] = 1;
  *(undefined1 *)((int)extraout_ECX + 0x16f) = 0;
  *(undefined1 *)(extraout_ECX + 0x5c) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x171) = 0;
  extraout_ECX[0x5e] = 0;
  extraout_ECX[0x5f] = 0;
  extraout_ECX[0x60] = 0;
  extraout_ECX[0x61] = 0;
  extraout_ECX[0x62] = 0;
  extraout_ECX[99] = 0;
  _Str1 = DAT_006fe948;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = _strcmp(_Str1,s_uninited_006d74f4);
  if (iVar1 == 0) {
    FUN_005e47ab(0,0,0,0);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)((int)extraout_ECX + 0x172) = 0;
  extraout_ECX[100] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x173) = 1;
  *(undefined1 *)(extraout_ECX + 0x5d) = 0;
  return extraout_ECX;
}

