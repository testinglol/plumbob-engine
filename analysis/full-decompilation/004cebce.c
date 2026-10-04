
undefined4 __fastcall FUN_004cebce(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 8) == 0) &&
     ((*(int *)(param_1 + 0x68) == 9 || (*(int *)(param_1 + 0x68) == 8)))) {
    uVar1 = 1;
  }
  return uVar1;
}

