
void __thiscall FUN_0062cd10(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 + *(int *)(param_1 + 8);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - (uVar1 >> 3);
  uVar1 = uVar1 & 7;
  *(uint *)(param_1 + 8) = uVar1;
  if (uVar1 != 0) {
    *(uint *)(param_1 + 0xc) =
         (uint)*(byte *)((*(int *)(param_1 + 4) - 1U & 0xfff) + 0x10 + param_1) <<
         (0x20U - (char)uVar1 & 0x1f);
  }
  return;
}

