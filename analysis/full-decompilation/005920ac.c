
void __fastcall FUN_005920ac(int param_1)

{
  uint uVar1;
  
  uVar1 = __ftol();
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + (7 - uVar1 & 0xfffffff8);
  }
  if (7 < (int)uVar1) {
    uVar1 = uVar1 + (uVar1 >> 3) * -8;
  }
  *(short *)(*(int *)(param_1 + 0x138) + 0x4c) = (short)uVar1;
  return;
}

