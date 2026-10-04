
bool __thiscall FUN_0045f8b0(int param_1,undefined4 param_2)

{
  bool bVar1;
  
  bVar1 = (uint)(*(int *)(param_1 + 0x224) - *(int *)(param_1 + 0x220)) < 8;
  if (bVar1) {
    FUN_0041edc1(param_2);
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
  }
  return bVar1;
}

