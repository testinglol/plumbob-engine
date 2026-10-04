
LPWIN32_FIND_DATAA __fastcall FUN_004de998(LPWIN32_FIND_DATAA param_1)

{
  DWORD *pDVar1;
  HANDLE pvVar2;
  BOOL BVar3;
  size_t sVar4;
  int iVar5;
  bool bVar6;
  LPCSTR local_220;
  undefined **local_114;
  char *local_110;
  undefined1 local_108 [260];
  
  if ((char)param_1[1].ftCreationTime.dwLowDateTime == '\0') {
    pDVar1 = &param_1[1].ftCreationTime.dwHighDateTime;
    FUN_00405584(pDVar1);
    FUN_0046f847(&DAT_006c8c28,0xffffffff);
    FUN_0046f847(param_1[1].cFileName + 0xec,0xffffffff);
    if ((HANDLE)param_1[1].dwFileAttributes == (HANDLE)0x0) {
      pvVar2 = FindFirstFileA(local_220,param_1);
      param_1[1].dwFileAttributes = (DWORD)pvVar2;
      bVar6 = pvVar2 == (HANDLE)0xffffffff;
    }
    else {
      BVar3 = FindNextFileA((HANDLE)param_1[1].dwFileAttributes,param_1);
      bVar6 = BVar3 == 0;
    }
    if (bVar6) {
      *(undefined1 *)&param_1[1].ftCreationTime.dwLowDateTime = 1;
    }
    else {
      FUN_0046fb9b(local_108,0x104);
      local_114 = &PTR_LAB_00666cdc;
      FUN_0046f8e4(pDVar1);
      FUN_0046f847(param_1->cFileName,0xffffffff);
      sVar4 = _strlen(local_110);
      iVar5 = 0;
      if (0 < (int)sVar4) {
        do {
          if (local_110[iVar5] == '\\') {
            local_110[iVar5] = '/';
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)sVar4);
      }
      FUN_0046f8e4(&local_114);
    }
  }
  return param_1;
}

