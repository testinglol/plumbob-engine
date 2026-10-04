
DWORD __fastcall FUN_005ed1e6(int param_1)

{
  DWORD DVar1;
  
  if (*(char *)(param_1 + 0x10) != '\0') {
    DVar1 = GetFileSize(*(HANDLE *)(param_1 + 0x14),(LPDWORD)0x0);
    return DVar1;
  }
  return 0;
}

