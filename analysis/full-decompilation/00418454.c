
int __thiscall FUN_00418454(int param_1,int param_2)

{
  if (param_2 + 0x50 != *(int *)(param_1 + 4)) {
    FUN_00418779(param_2 + 0x50,*(int *)(param_1 + 4),param_2);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0x50;
  return param_2;
}

