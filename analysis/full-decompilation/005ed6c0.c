
bool FUN_005ed6c0(undefined4 param_1,byte param_2,char param_3)

{
  LPCSTR pCVar1;
  uint dwFileAttributes;
  BOOL BVar2;
  
  pCVar1 = (LPCSTR)FUN_004096c2();
  dwFileAttributes = GetFileAttributesA(pCVar1);
  if ((param_2 & 1) != 0) {
    if (param_3 == '\0') {
      dwFileAttributes = dwFileAttributes & 0xfffffffe;
    }
    else {
      dwFileAttributes = dwFileAttributes | 1;
    }
  }
  if ((param_2 & 2) != 0) {
    if (param_3 == '\0') {
      dwFileAttributes = dwFileAttributes & 0xfffffffd;
    }
    else {
      dwFileAttributes = dwFileAttributes | 2;
    }
  }
  pCVar1 = (LPCSTR)FUN_004096c2();
  BVar2 = SetFileAttributesA(pCVar1,dwFileAttributes);
  return BVar2 != 0;
}

