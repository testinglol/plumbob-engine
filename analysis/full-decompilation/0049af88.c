
void __fastcall FUN_0049af88(int param_1)

{
  if (*(int *)(DAT_006e486c + 0x30) != 0) {
    if (*(int **)(param_1 + 0x10) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x10) + 8))();
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    if (*(int *)(param_1 + 4) != 0) {
      FUN_005cfd0a(*(int *)(param_1 + 4));
    }
    *(undefined4 *)(param_1 + 4) = 0;
    DAT_006ede68 = 0;
  }
  return;
}

