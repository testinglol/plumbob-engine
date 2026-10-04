
void __fastcall FUN_004de981(int param_1)

{
  HANDLE hFindFile;
  
  hFindFile = *(HANDLE *)(param_1 + 0x140);
  if ((hFindFile != (HANDLE)0x0) && (hFindFile != (HANDLE)0xffffffff)) {
    FindClose(hFindFile);
  }
  return;
}

