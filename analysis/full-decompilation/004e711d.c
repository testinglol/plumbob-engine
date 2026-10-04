
void __fastcall FUN_004e711d(int param_1)

{
  FUN_004e60c8(1);
  DAT_006f0138 = 1;
  if (*(int **)(DAT_006e486c + 4) != (int *)0x0) {
    (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
  }
  DAT_006f013a = 1;
  if (*(int **)(DAT_006e486c + 4) != (int *)0x0) {
    (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
  }
  *(undefined1 *)(param_1 + 1) = 1;
  FUN_004e6166(1);
  FUN_004e61c6(0);
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}

