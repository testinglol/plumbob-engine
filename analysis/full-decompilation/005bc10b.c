
void __fastcall FUN_005bc10b(int param_1)

{
  HMODULE pHVar1;
  DWORD dwLen;
  void *lpData;
  BOOL BVar2;
  CHAR local_114 [264];
  uint local_c;
  DWORD local_8;
  
  if (*(int *)(param_1 + 8) == 0) {
    pHVar1 = GetModuleHandleA((LPCSTR)0x0);
    *(HMODULE *)(param_1 + 4) = pHVar1;
    pHVar1 = GetModuleHandleA((LPCSTR)0x0);
    GetModuleFileNameA(pHVar1,local_114,0x104);
    dwLen = GetFileVersionInfoSizeA(local_114,&local_8);
    if (dwLen != 0) {
      lpData = operator_new(dwLen);
      *(void **)(param_1 + 8) = lpData;
      BVar2 = GetFileVersionInfoA(local_114,local_8,dwLen,lpData);
      if (BVar2 != 0) {
        BVar2 = VerQueryValueA(*(LPCVOID *)(param_1 + 8),s__VarFileInfo_Translation_006d255c,
                               (LPVOID *)(param_1 + 0xc),&local_c);
        if (BVar2 == 0) {
          FUN_006321f0(*(undefined4 *)(param_1 + 8));
          *(undefined4 *)(param_1 + 8) = 0;
        }
      }
    }
  }
  return;
}

