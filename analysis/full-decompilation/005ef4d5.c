
int * FUN_005ef4d5(int *param_1)

{
  HDC hdc;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  hdc = GetDC((HWND)0x0);
  iVar1 = GetDeviceCaps(hdc,0xe);
  iVar2 = GetDeviceCaps(hdc,0xc);
  ReleaseDC((HWND)0x0,hdc);
  iVar3 = GetSystemMetrics(1);
  iVar4 = GetSystemMetrics(0);
  param_1[2] = iVar2 * iVar1;
  *param_1 = iVar4;
  param_1[1] = iVar3;
  return param_1;
}

