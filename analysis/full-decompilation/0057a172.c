
void __fastcall FUN_0057a172(int param_1)

{
  if (*(char *)(param_1 + 0x14) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0057a17d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 4) + 4))();
    return;
  }
  return;
}

