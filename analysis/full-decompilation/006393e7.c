
undefined4 FUN_006393e7(char *param_1)

{
  size_t sVar1;
  void *pvVar2;
  int iVar3;
  LPWSTR lpWideCharStr;
  
  if (DAT_0070534c != 0) {
    sVar1 = _strlen(param_1);
    pvVar2 = _malloc(sVar1 + 1);
    if (pvVar2 != (void *)0x0) {
      FUN_006358b0(pvVar2,param_1);
      iVar3 = FUN_00645559(pvVar2,1);
      if ((iVar3 == 0) &&
         ((DAT_00703ad8 == 0 ||
          ((((iVar3 = MultiByteToWideChar(1,0,param_1,-1,(LPWSTR)0x0,0), iVar3 != 0 &&
             (lpWideCharStr = _malloc(iVar3 * 2), lpWideCharStr != (LPWSTR)0x0)) &&
            (iVar3 = MultiByteToWideChar(1,0,param_1,-1,lpWideCharStr,iVar3), iVar3 != 0)) &&
           (iVar3 = FUN_00645303(lpWideCharStr,0), iVar3 == 0)))))) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}

