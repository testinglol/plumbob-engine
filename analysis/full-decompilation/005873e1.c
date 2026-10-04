
int __thiscall FUN_005873e1(int param_1,int param_2)

{
  if (param_2 + 0x110 != *(int *)(param_1 + 4)) {
    FUN_0058753e(param_2 + 0x110,*(int *)(param_1 + 4),param_2);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0x110;
  return param_2;
}

