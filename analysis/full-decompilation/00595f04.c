
void __thiscall FUN_00595f04(int param_1,int *param_2)

{
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_005942ab();
  }
  if (param_2 != (int *)0x0) {
    *param_2 = *param_2 + 1;
  }
  *(int *)(param_1 + 0x130) = *(int *)(param_1 + 0x130) + 1;
  *(int **)(param_1 + 0x2c) = param_2;
  return;
}

