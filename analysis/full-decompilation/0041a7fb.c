
int __thiscall FUN_0041a7fb(int param_1,int param_2)

{
  if (param_2 + 0x14 != *(int *)(param_1 + 4)) {
    FUN_0041adce(param_2 + 0x14,*(int *)(param_1 + 4),param_2);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0x14;
  FUN_0041a7c5();
  return param_2;
}

