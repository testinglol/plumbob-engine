
undefined4 FUN_005ed4a5(void)

{
  LPCSTR lpFileName;
  DWORD dwDesiredAccess;
  DWORD dwShareMode;
  _SECURITY_ATTRIBUTES *lpSecurityAttributes;
  DWORD dwCreationDisposition;
  DWORD dwFlagsAndAttributes;
  HANDLE pvVar1;
  _SECURITY_ATTRIBUTES local_10;
  
  local_10.lpSecurityDescriptor = (LPVOID)0x0;
  local_10.bInheritHandle = 0;
  pvVar1 = (HANDLE)0x0;
  dwFlagsAndAttributes = 0x80;
  lpSecurityAttributes = &local_10;
  dwCreationDisposition = 3;
  dwShareMode = 3;
  dwDesiredAccess = 0x80000000;
  local_10.nLength = 0xc;
  lpFileName = (LPCSTR)FUN_004096c2();
  pvVar1 = CreateFileA(lpFileName,dwDesiredAccess,dwShareMode,lpSecurityAttributes,
                       dwCreationDisposition,dwFlagsAndAttributes,pvVar1);
  if (pvVar1 != (HANDLE)0xffffffff) {
    CloseHandle(pvVar1);
    return 1;
  }
  return 0;
}

