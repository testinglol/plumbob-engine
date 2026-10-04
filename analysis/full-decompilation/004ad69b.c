
void __fastcall FUN_004ad69b(int param_1)

{
  if (*(char *)(param_1 + 0x1e) != '\0') {
    if (*(int **)(param_1 + 0x18) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x18) + 0xc))();
    }
    if (*(int **)(param_1 + 0x10) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x10) + 0xc))();
    }
    *(undefined1 *)(param_1 + 0x1e) = 0;
  }
  return;
}

