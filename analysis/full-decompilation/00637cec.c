
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00637cec(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_00637d91();
  if (DAT_00703af0 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00703aec = 1;
  DAT_00703ae8 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_00705358 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_00705354 - 4), DAT_00705358 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_00705358 <= puVar1);
    }
    FUN_00637da3(&DAT_006c0848,&DAT_006c0854);
  }
  FUN_00637da3(&DAT_006c0858,&DAT_006c0860);
  if (param_3 == 0) {
    DAT_00703af0 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_00637d9a();
  return;
}

