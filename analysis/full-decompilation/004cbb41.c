
uint __fastcall FUN_004cbb41(int param_1)

{
  int iVar1;
  uint in_EAX;
  
  if (*(int *)(param_1 + 0x24) == 1) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x28) + 0x60);
    return CONCAT31((int3)((uint)iVar1 >> 8),*(short *)(iVar1 + 0xbc) != 0);
  }
  return in_EAX & 0xffffff00;
}

