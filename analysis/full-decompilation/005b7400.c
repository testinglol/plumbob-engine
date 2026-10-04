
void FUN_005b7400(int param_1)

{
  HANDLE hTargetProcessHandle;
  HANDLE hSourceHandle;
  HANDLE hSourceProcessHandle;
  LPHANDLE lpTargetHandle;
  DWORD dwDesiredAccess;
  BOOL bInheritHandle;
  DWORD dwOptions;
  
  if (DAT_006fd7c8 == 0) {
    DAT_006fd7c8 = 1;
    if (param_1 == 0) {
      param_1 = 100;
    }
    FUN_005b7480(param_1);
    DAT_006fd7c4 = GetCurrentThreadId();
    dwOptions = 2;
    bInheritHandle = 0;
    dwDesiredAccess = 0;
    lpTargetHandle = (LPHANDLE)&DAT_006fd7c0;
    hTargetProcessHandle = GetCurrentProcess();
    hSourceHandle = GetCurrentThread();
    hSourceProcessHandle = GetCurrentProcess();
    DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,lpTargetHandle,
                    dwDesiredAccess,bInheritHandle,dwOptions);
    if (DAT_006fd7cc == 0) {
      DAT_006fd7cc = 1;
      FUN_005b66f0();
      return;
    }
  }
  return;
}

