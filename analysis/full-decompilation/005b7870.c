
bool FUN_005b7870(int param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  
  DVar1 = GetCurrentThreadId();
  if (DAT_006fd7c8 == 0) {
    FUN_005b7400(0);
  }
  if (param_1 == 0) {
    return DVar1 == DAT_006fd7c4;
  }
  if (param_1 == -1) {
    return true;
  }
  DVar2 = FUN_005b78d0(param_1);
  return DVar1 == DVar2;
}

