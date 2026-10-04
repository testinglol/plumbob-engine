
void __fastcall FUN_004d375b(int param_1)

{
  *(undefined1 *)(param_1 + 0x188) = 0;
  if (*(int **)(param_1 + 0x184) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x184) + 0x98))();
  }
  FUN_005dae65(param_1);
  *(undefined1 *)(param_1 + 0x189) = 0;
  return;
}

