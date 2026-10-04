
undefined4 __fastcall FUN_00435294(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (((*(byte *)(param_1 + 0x634) & 1) != 1) && ((*(byte *)(param_1 + 0x614) & 1) != 1)) {
    uVar1 = 0;
  }
  return uVar1;
}

