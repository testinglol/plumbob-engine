
bool FUN_004e076c(int param_1)

{
  char cVar1;
  DWORD dwProcessId;
  HANDLE hObject;
  int iVar2;
  
  if ((((DAT_006f222c != '\0') || (cVar1 = FUN_004e0015(), cVar1 != '\0')) && (param_1 != 0)) &&
     (DAT_006f2228 != (code *)0x0)) {
    dwProcessId = GetCurrentProcessId();
    hObject = OpenProcess(0x410,0,dwProcessId);
    if (hObject != (HANDLE)0x0) {
      iVar2 = (*DAT_006f2228)(hObject,param_1,0x28);
      CloseHandle(hObject);
      return iVar2 != 0;
    }
  }
  return false;
}

