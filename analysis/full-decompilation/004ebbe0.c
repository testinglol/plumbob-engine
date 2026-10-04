
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004ebbe0(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e372a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x68] = 0;
  extraout_ECX[0x69] = 0;
  extraout_ECX[0x6a] = 0;
  extraout_ECX[0x6c] = 0;
  extraout_ECX[0x6d] = 0;
  extraout_ECX[0x6e] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00635e55(extraout_ECX + 0x70,0x6c,4,FUN_00403288,thunk_FUN_00470467);
  *extraout_ECX = &PTR_FUN_0066942c;
  _DAT_006f26ac = _DAT_006f26ac + 1;
  _memset(extraout_ECX + 0x65,0,0xc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x6f] = 0;
  extraout_ECX[0x6b] = 0;
  return extraout_ECX;
}

