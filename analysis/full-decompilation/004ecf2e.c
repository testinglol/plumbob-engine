
undefined4 __fastcall FUN_004ecf2e(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x11c);
  if ((uVar1 != 0xffffffff) &&
     ((-1 < (int)uVar1 || (uVar1 < (uint)(*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2))
      ))) {
    return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xf0) + uVar1 * 4) + 0x1bc);
  }
  return 1;
}

