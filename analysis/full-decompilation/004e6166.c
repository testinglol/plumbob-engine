
void FUN_004e6166(int param_1)

{
  if (*(int *)(DAT_006e486c + 0x20) != 0) {
    if (param_1 == 0) {
      FUN_004c442d();
    }
    else if (param_1 == 1) {
      FUN_004c4444();
    }
    else if (param_1 == 2) {
      FUN_004c445b();
    }
    if (*(int **)(DAT_006e486c + 4) != (int *)0x0) {
      (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
    }
  }
  return;
}

