
int __thiscall FUN_005bd7f0(int param_1,int param_2,int param_3)

{
  if (param_2 != param_3) {
    FUN_00635190(param_2,param_3,(*(int *)(param_1 + 4) - param_3 >> 1) * 2 + 2);
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - param_2 >> 1) * -2;
  }
  return param_2;
}

