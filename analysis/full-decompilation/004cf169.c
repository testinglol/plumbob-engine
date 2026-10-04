
void __thiscall FUN_004cf169(int param_1,int *param_2,undefined4 param_3)

{
  if (*(int **)(param_1 + 0x4c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x4c) + 0x60))();
  }
  *(int **)(param_1 + 0x4c) = param_2;
  *(undefined4 *)(param_1 + 0x50) = param_3;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 0x30))(param_3);
  }
  return;
}

