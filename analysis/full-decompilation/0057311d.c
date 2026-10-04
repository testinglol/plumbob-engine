
void __fastcall FUN_0057311d(int param_1)

{
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00573126. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x18))();
    return;
  }
  return;
}

