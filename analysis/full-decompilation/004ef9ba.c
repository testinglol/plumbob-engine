
undefined4 __fastcall FUN_004ef9ba(int param_1)

{
  if (*(int **)(param_1 + 200) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 200) + 0x94))();
    (**(code **)(**(int **)(param_1 + 200) + 0x168))();
    *(undefined1 *)(*(int *)(param_1 + 200) + 0x1b0) = 0;
  }
  FUN_004fb0d6();
  FUN_004fb49a();
  return 1;
}

