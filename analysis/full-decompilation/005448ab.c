
undefined4 __fastcall FUN_005448ab(int param_1)

{
  undefined4 uVar1;
  
  if ((-1 < (int)*(uint *)(param_1 + 0x10c)) &&
     (*(uint *)(param_1 + 0x10c) < (uint)(*(int *)(param_1 + 0xdc) - *(int *)(param_1 + 0xd8) >> 2))
     ) {
    uVar1 = FUN_00543a86();
    return uVar1;
  }
  return 0;
}

