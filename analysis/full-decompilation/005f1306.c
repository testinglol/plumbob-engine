
void __thiscall FUN_005f1306(int *param_1,HWND param_2,uint param_3)

{
  HIMC pHVar1;
  DWORD dwBytes;
  LPCANDIDATELIST lpCandList;
  DWORD deIndex;
  
  deIndex = 0;
  if ((HGLOBAL)param_1[0x44] != (HGLOBAL)0x0) {
    GlobalFree((HGLOBAL)param_1[0x44]);
    param_1[0x44] = 0;
  }
  pHVar1 = ImmGetContext(param_2);
  if (pHVar1 != (HIMC)0x0) {
    do {
      if ((param_3 & 1 << ((byte)deIndex & 0x1f)) != 0) {
        dwBytes = ImmGetCandidateListA(pHVar1,deIndex,(LPCANDIDATELIST)0x0,0);
        lpCandList = GlobalAlloc(0x40,dwBytes);
        param_1[0x44] = (int)lpCandList;
        ImmGetCandidateListA(pHVar1,deIndex,lpCandList,dwBytes);
      }
      deIndex = deIndex + 1;
    } while (deIndex < 0x20);
    ImmReleaseContext(param_2,pHVar1);
  }
  (**(code **)(*param_1 + 0x168))();
  return;
}

