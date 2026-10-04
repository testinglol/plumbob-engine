
undefined4 FUN_0063a75a(LPCSTR param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = CreateDirectoryA(param_1,(LPSECURITY_ATTRIBUTES)0x0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
  }
  else {
    DVar2 = 0;
  }
  if (DVar2 != 0) {
    FUN_0063d723(DVar2);
    return 0xffffffff;
  }
  return 0;
}

