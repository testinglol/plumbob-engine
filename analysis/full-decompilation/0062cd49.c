
void __thiscall FUN_0062cd49(int param_1,int param_2)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
  if (*(int *)(param_1 + 8) != 0) {
    *(uint *)(param_1 + 0xc) =
         (uint)*(byte *)((*(int *)(param_1 + 4) - 1U & 0xfff) + 0x10 + param_1) <<
         (0x20U - (char)*(int *)(param_1 + 8) & 0x1f);
  }
  return;
}

