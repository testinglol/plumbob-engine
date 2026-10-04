
bool FUN_005d8a11(undefined4 *param_1)

{
  HANDLE hFindFile;
  _WIN32_FIND_DATAA local_158;
  undefined4 local_18;
  
  FUN_005d48d9();
  local_18 = 0;
  hFindFile = FindFirstFileA((LPCSTR)*param_1,&local_158);
  FindClose(hFindFile);
  FUN_005b8770();
  return hFindFile != (HANDLE)0xffffffff;
}

