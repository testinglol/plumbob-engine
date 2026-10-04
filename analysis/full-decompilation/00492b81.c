
bool __thiscall FUN_00492b81(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  if (param_2 < 1) {
    bVar1 = true;
  }
  else {
    iVar2 = FUN_0046d9e5();
    bVar1 = *(int *)(param_1 + 0x20) + param_2 <= iVar2;
  }
  return bVar1;
}

