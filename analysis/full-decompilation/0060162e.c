
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0060162e(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00676a00;
  uVar1 = FUN_00401742(0x18);
  extraout_ECX[1] = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(undefined4 *)(extraout_ECX[1] + 4) = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d909f();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d920a(0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00676990;
  _DAT_006fed9c = _DAT_006fed9c + 1;
  return extraout_ECX;
}

