
bool __fastcall FUN_005d8e0c(int param_1)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
  DVar1 = GetCurrentThreadId();
  if (DVar1 != *(DWORD *)(param_1 + 0x10)) {
    pvVar2 = GetCurrentThread();
    if (pvVar2 != *(HANDLE *)(param_1 + 0x10)) {
      DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),0xffffffff);
      return DVar1 != 0xffffffff;
    }
  }
  return false;
}

