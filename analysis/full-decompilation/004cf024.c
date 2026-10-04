
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004cf024(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x40;
  *(undefined4 *)(param_1 + 0x44) = param_2;
  __ftol();
  uVar1 = __ftol();
  FUN_004733da(uVar1);
  uVar1 = __ftol();
  FUN_004733da(uVar1);
  return;
}

