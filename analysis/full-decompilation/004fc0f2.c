
bool FUN_004fc0f2(LPCSTR param_1)

{
  LSTATUS LVar1;
  DWORD cbData;
  BYTE *lpData;
  bool bVar2;
  HKEY local_8;
  
  bVar2 = false;
  LVar1 = RegCreateKeyExA((HKEY)0x80000002,s_Software_Maxis_The_Sims_006cc09c,0,(LPSTR)0x0,0,0x20006
                          ,(LPSECURITY_ATTRIBUTES)0x0,&local_8,(LPDWORD)0x0);
  if (LVar1 == 0) {
    cbData = FUN_005d49d6();
    lpData = (BYTE *)FUN_004096c2();
    LVar1 = RegSetValueExA(local_8,param_1,0,1,lpData,cbData);
    bVar2 = LVar1 == 0;
    RegCloseKey(local_8);
  }
  return bVar2;
}

