
undefined4 __fastcall FUN_00603fa8(int param_1)

{
  if (*(int **)(param_1 + 0x5c) == (int *)0x0) {
    return 0;
  }
  (**(code **)(**(int **)(param_1 + 0x5c) + 4))();
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return 1;
}

