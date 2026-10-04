
HANDLE FUN_00637dbd(LPSECURITY_ATTRIBUTES param_1,SIZE_T param_2,undefined4 param_3,
                   undefined4 param_4,DWORD param_5,LPDWORD param_6)

{
  LPVOID lpParameter;
  HANDLE pvVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  lpParameter = (LPVOID)FUN_00643e71(1,0x74);
  if (lpParameter != (LPVOID)0x0) {
    FUN_0063e1c0(lpParameter);
    *(undefined4 *)((int)lpParameter + 4) = 0xffffffff;
    *(undefined4 *)((int)lpParameter + 0x48) = param_3;
    *(undefined4 *)((int)lpParameter + 0x4c) = param_4;
    pvVar1 = CreateThread(param_1,param_2,FUN_00637e28,lpParameter,param_5,param_6);
    if (pvVar1 != (HANDLE)0x0) {
      return pvVar1;
    }
    DVar2 = GetLastError();
  }
  FUN_00634ecc(lpParameter);
  if (DVar2 != 0) {
    FUN_0063d723(DVar2);
  }
  return (HANDLE)0x0;
}

