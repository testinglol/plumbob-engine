
undefined4 __fastcall FUN_00436f21(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x40) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x40) + 0x4c))(param_1);
    return uVar1;
  }
  return 0;
}

