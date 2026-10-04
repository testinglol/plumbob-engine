
undefined4 __fastcall FUN_005e4f8d(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xd4);
  if (iVar1 != 0) {
    return CONCAT31((int3)((uint)iVar1 >> 8),*(int *)(iVar1 + 0xe0) != 0);
  }
  return 0;
}

