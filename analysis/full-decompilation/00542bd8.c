
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00542bd8(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e372a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x6e] = 0;
  extraout_ECX[0x6f] = 0;
  extraout_ECX[0x70] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00429c21();
  *extraout_ECX = &PTR_FUN_0066f3fc;
  _DAT_006f4f70 = _DAT_006f4f70 + 1;
  _memset(extraout_ECX + 0x65,0,0x20);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x6d] = 0xffffffff;
  extraout_ECX[0x79] = 0;
  extraout_ECX[0x7a] = 0;
  extraout_ECX[0x7b] = 0;
  extraout_ECX[0x7c] = 0;
  extraout_ECX[0x78] = 0;
  *(undefined1 *)(extraout_ECX + 0x7d) = 0;
  return extraout_ECX;
}

