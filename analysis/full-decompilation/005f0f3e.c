
void __fastcall FUN_005f0f3e(int *param_1)

{
  (**(code **)(*param_1 + 0x98))();
  if (DAT_006fecac != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005f0f52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_006fecac + 0x98))();
    return;
  }
  return;
}

