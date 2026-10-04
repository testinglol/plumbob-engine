
void __thiscall FUN_005db297(int param_1,int *param_2)

{
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))();
  }
  if (*(int **)(param_1 + 500) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 500) + 8))();
  }
  *(int **)(param_1 + 500) = param_2;
  return;
}

