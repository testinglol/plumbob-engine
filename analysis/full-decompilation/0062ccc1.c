
uint __fastcall FUN_0062ccc1(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(uint *)(param_1 + 0xc) =
         (uint)*(byte *)((*(uint *)(param_1 + 4) & 0xfff) + 0x10 + param_1) << 0x18;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) + 1;
    *(undefined4 *)(param_1 + 8) = 8;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  *(uint *)(param_1 + 0xc) = uVar1 * 2;
  return uVar1 >> 0x1f;
}

