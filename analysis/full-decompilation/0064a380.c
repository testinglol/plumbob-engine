
void FUN_0064a380(SIZE_T *param_1)

{
  SIZE_T dwSize;
  _SYSTEM_INFO local_24;
  
  if (DAT_00703e6c == 0) {
    GetSystemInfo(&local_24);
    DAT_00703e6c = local_24.dwPageSize;
  }
  dwSize = ((int)((*param_1 - 1) + DAT_00703e6c) / (int)DAT_00703e6c) * DAT_00703e6c;
  *param_1 = dwSize;
  VirtualAlloc((LPVOID)0x0,dwSize,0x3000,4);
  return;
}

