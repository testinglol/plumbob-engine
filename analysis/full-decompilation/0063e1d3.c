
DWORD * FUN_0063e1d3(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_006db310);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_00643e71(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_006db310,lpTlsValue);
      if (BVar1 != 0) {
        FUN_0063e1c0(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_0063e22e;
      }
    }
    __amsg_exit(0x10);
  }
LAB_0063e22e:
  SetLastError(dwErrCode);
  return lpTlsValue;
}

