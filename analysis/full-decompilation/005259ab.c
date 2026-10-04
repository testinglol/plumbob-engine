
undefined4 __fastcall FUN_005259ab(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xd8) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0xd8) + 0x110);
  }
                    /* WARNING: Could not recover jumptable at 0x005259c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(DAT_006e486c + 4) + 0x38))();
  return uVar1;
}

