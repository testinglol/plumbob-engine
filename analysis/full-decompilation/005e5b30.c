
void __fastcall FUN_005e5b30(int param_1)

{
  if (*(int **)(param_1 + 0x104) == (int *)0x0) {
    *(undefined1 *)(param_1 + 0x11c) = 0;
  }
  else if (*(char *)(param_1 + 0x11c) == '\0') {
    *(undefined1 *)(param_1 + 0x11c) = 1;
    (**(code **)(**(int **)(param_1 + 0x104) + 0x1a0))(1);
    (**(code **)(**(int **)(param_1 + 0x104) + 0xe4))(0,0,0);
    FUN_005dadff(param_1,200,0);
  }
  else {
    FUN_005dae65(param_1);
    *(undefined1 *)(param_1 + 0x11c) = 0;
    (**(code **)(**(int **)(param_1 + 0x104) + 0xf4))(0,0,0);
  }
  return;
}

