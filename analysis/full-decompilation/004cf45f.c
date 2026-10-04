
void __thiscall FUN_004cf45f(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x6c + *(int *)(param_1 + 0x68) * 4) = param_2;
  FUN_004cf268(*(undefined4 *)(param_1 + 0x68));
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x20;
  return;
}

