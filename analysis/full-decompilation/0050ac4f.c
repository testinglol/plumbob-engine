
void __fastcall FUN_0050ac4f(int param_1)

{
  FUN_005de633();
  if (*(int **)(param_1 + 0xe0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xe0) + 0x98))();
  }
  if (*(int **)(param_1 + 0xe4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xe4) + 0x98))();
  }
  if (*(int **)(param_1 + 0xec) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xec) + 0x98))();
  }
  if (*(int **)(param_1 + 0xe8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xe8) + 0x98))();
  }
  if (*(int **)(param_1 + 0xf0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xf0) + 0x98))();
  }
  if (*(int **)(param_1 + 0xf4) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0050acbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0xf4) + 0x98))();
    return;
  }
  return;
}

