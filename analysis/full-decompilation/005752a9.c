
void __fastcall FUN_005752a9(int param_1)

{
  int *piVar1;
  
  *(undefined1 *)(param_1 + 4) = 0;
  piVar1 = (int *)FUN_00573466(0x203);
                    /* WARNING: Could not recover jumptable at 0x005752c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x5c))();
  return;
}

