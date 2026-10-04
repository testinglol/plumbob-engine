
void __fastcall FUN_004cfc14(int param_1)

{
  if (*(int **)(param_1 + 0x4c) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004cfc1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x4c) + 0x5c))();
    return;
  }
  return;
}

