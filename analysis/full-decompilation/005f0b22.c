
bool __thiscall FUN_005f0b22(int param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  BOOL BVar1;
  LPCSTR lpString;
  
  if (((LPCSTR)param_2[1] != (LPCSTR)*param_2) && ((LPCSTR)param_3[1] != (LPCSTR)*param_3)) {
    lpString = (LPCSTR)0x0;
    if ((LPCSTR)param_4[1] != (LPCSTR)*param_4) {
      lpString = (LPCSTR)*param_4;
    }
    BVar1 = WritePrivateProfileStringA
                      ((LPCSTR)*param_2,(LPCSTR)*param_3,lpString,*(LPCSTR *)(param_1 + 4));
    return BVar1 != 0;
  }
  return false;
}

