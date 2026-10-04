
int __thiscall FUN_005db35d(int param_1,int param_2)

{
  if (param_2 + 0x14 != *(int *)(param_1 + 4)) {
    FUN_005db86a(param_2 + 0x14,*(int *)(param_1 + 4),param_2);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0x14;
  return param_2;
}

