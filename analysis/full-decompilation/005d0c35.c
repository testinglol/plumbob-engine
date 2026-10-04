
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005d0c35(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d47c5(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c56a0();
  uVar1 = _DAT_0066745c;
  extraout_ECX[0x32] = 0;
  extraout_ECX[0x33] = 0;
  extraout_ECX[0x34] = 0;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x3b] = 0;
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = uVar1;
  extraout_ECX[0x3f] = uVar1;
  extraout_ECX[0x40] = uVar1;
  uVar1 = _DAT_00667458;
  extraout_ECX[0x41] = _DAT_00667458;
  extraout_ECX[0x42] = uVar1;
  extraout_ECX[0x43] = uVar1;
  extraout_ECX[5] = extraout_ECX[5] | 1;
  *extraout_ECX = &PTR_FUN_0067354c;
  extraout_ECX[0x31] = extraout_ECX[0x31] & 0xfffffffc | 4;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x44] = DAT_006d6360;
  return extraout_ECX;
}

