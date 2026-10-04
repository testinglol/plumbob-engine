
undefined4 __fastcall FUN_005d972a(int param_1)

{
  if (*(int *)(param_1 + 0x170) != 0) {
    FUN_005e7490();
    if (*(undefined4 **)(param_1 + 0x170) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x170))(1);
    }
    *(undefined4 *)(param_1 + 0x170) = 0;
  }
  if (*(int **)(param_1 + 0x18c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18c) + 8))();
    *(undefined4 *)(param_1 + 0x18c) = 0;
  }
  if (*(int **)(param_1 + 0x1b8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x1b8) + 8))();
    *(undefined4 *)(param_1 + 0x1b8) = 0;
  }
  if (*(int **)(param_1 + 500) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 500) + 8))();
    *(undefined4 *)(param_1 + 500) = 0;
  }
  return 1;
}

