
void __thiscall FUN_005d46b0(int param_1,int *param_2)

{
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))();
  }
  if (*(int **)(param_1 + 0x8c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x8c) + 8))();
    *(undefined4 *)(param_1 + 0x8c) = 0;
  }
  *(undefined4 *)(param_1 + 0x8c) = param_2;
  if (param_2 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  else {
    *(int *)(param_1 + 0x4c) = param_2[3];
  }
  (**(code **)(**(int **)(param_1 + 0x58) + 0xc))(*(int **)(param_1 + 0x58),param_1 + 4);
  return;
}

