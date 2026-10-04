
void __fastcall FUN_00526e73(int *param_1)

{
  param_1[0x36] = param_1[0x36] + 1;
                    /* WARNING: Could not recover jumptable at 0x00526e7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x168))();
  return;
}

