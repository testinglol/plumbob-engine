
void __thiscall FUN_004480d7(int param_1,int param_2)

{
  int *local_50;
  int *local_24;
  
  if ((param_2 != 0) && (*(char *)(param_1 + 0x11) != '\0')) {
    if (*(int *)(param_1 + 200) == param_2) {
      *(undefined4 *)(param_1 + 200) = 0;
    }
    if (*(int *)(param_1 + 0xcc) == param_2) {
      *(undefined4 *)(param_1 + 0xcc) = 0;
    }
    for (local_24 = *(int **)(param_1 + 0xd0);
        (local_24 != *(int **)(param_1 + 0xd4) && (*local_24 != param_2)); local_24 = local_24 + 1)
    {
    }
    if (local_24 != *(int **)(param_1 + 0xd4)) {
      FUN_004486a3(local_24);
    }
    for (local_50 = *(int **)(param_1 + 0xdc);
        (local_50 != *(int **)(param_1 + 0xe0) && (*local_50 != param_2)); local_50 = local_50 + 1)
    {
    }
    if (local_50 != *(int **)(param_1 + 0xe0)) {
      FUN_004486a3(local_50);
    }
  }
  return;
}

