
int __thiscall FUN_004064ae(int param_1,int param_2,int param_3)

{
  if (param_2 != param_3) {
    FUN_00635190(param_2,param_3,(*(int *)(param_1 + 4) - param_3) + 1);
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_2 - param_3);
  }
  return param_2;
}

