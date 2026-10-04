
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005d3b23(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005cf650();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x17] = 0;
  extraout_ECX[0x18] = 0;
  extraout_ECX[0x19] = 0;
  uVar2 = _DAT_0066745c;
  extraout_ECX[0x1a] = _DAT_0066745c;
  extraout_ECX[0x1b] = uVar2;
  extraout_ECX[0x1c] = uVar2;
  uVar2 = _DAT_00667458;
  extraout_ECX[0x1d] = _DAT_00667458;
  extraout_ECX[0x1e] = uVar2;
  extraout_ECX[0x1f] = uVar2;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_0067360c;
  if (iVar1 != 0) {
    FUN_005d3e0b(*(undefined4 *)(unaff_EBP + 8));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

