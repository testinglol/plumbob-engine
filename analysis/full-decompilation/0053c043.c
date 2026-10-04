
void __thiscall FUN_0053c043(int param_1,undefined2 param_2,int param_3)

{
  if ((param_3 == 2) || (param_3 == 1)) {
    *(undefined2 *)(param_1 + 8) = param_2;
  }
  else {
    *(undefined2 *)(param_1 + 0x14) = param_2;
  }
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x10;
  return;
}

