
undefined4 __fastcall FUN_004c4472(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c447b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x28))();
    return uVar1;
  }
  return 0;
}

