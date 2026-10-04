
undefined4 __fastcall FUN_0057da7d(int param_1)

{
  if (*(char *)(param_1 + 0x1c) != '\0') {
    *(undefined1 *)(param_1 + 0x1c) = 0;
  }
  *(undefined1 *)(param_1 + 0xcc) = 0;
  FUN_0058059c();
  if (*(int **)(param_1 + 0x1d0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x1d0) + 0xc))();
    if (*(undefined4 **)(param_1 + 0x1d0) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x1d0))(1);
    }
    *(undefined4 *)(param_1 + 0x1d0) = 0;
  }
  return 1;
}

