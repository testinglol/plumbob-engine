
bool __thiscall FUN_005d98fc(int param_1,undefined4 param_2)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x20) == 0;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x20) = param_2;
  }
  return bVar1;
}

