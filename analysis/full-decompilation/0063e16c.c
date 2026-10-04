
undefined4 FUN_0063e16c(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_0063d862();
  DAT_006db310 = TlsAlloc();
  if (DAT_006db310 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_00643e71(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_006db310,lpTlsValue);
      if (BVar1 != 0) {
        FUN_0063e1c0(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}

