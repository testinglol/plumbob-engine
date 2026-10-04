
undefined4 __thiscall
FUN_005f0b6c(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  DWORD DVar1;
  char cVar2;
  DWORD DVar3;
  undefined4 uVar4;
  uint uVar5;
  uint nSize;
  LPSTR lpReturnedString;
  
  lpReturnedString = (LPSTR)0x0;
  uVar5 = 0;
  do {
    nSize = uVar5 + 0x400;
    FUN_006321f0(lpReturnedString);
    lpReturnedString = operator_new(nSize);
    DVar3 = GetPrivateProfileStringA
                      ((LPCSTR)*param_2,(LPCSTR)*param_3,s_NOT_FOUND_006d7b74,lpReturnedString,nSize
                       ,*(LPCSTR *)(param_1 + 4));
    DVar1 = uVar5 + 0x3ff;
    uVar5 = nSize;
  } while (DVar1 == DVar3);
  FUN_005d4bbf(lpReturnedString);
  FUN_006321f0(lpReturnedString);
  cVar2 = FUN_00460748(param_4,s_NOT_FOUND_006d7b74);
  if ((cVar2 == '\0') && (lpReturnedString != (LPSTR)0x0)) {
    uVar4 = 1;
  }
  else {
    FUN_005d4bbf(&DAT_006de560);
    uVar4 = 0;
  }
  return uVar4;
}

