
void FUN_00583459(int param_1,undefined4 param_2,int param_3)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_3;
  if (*(int *)(param_1 + 8) < *(int *)(param_1 + 4)) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 4);
  }
  FUN_005b8f0f(param_2,param_3);
  return;
}

