
bool __thiscall FUN_00458fc2(int param_1,short *param_2,int param_3)

{
  int iVar1;
  HBITMAP h;
  HGDIOBJ pvVar2;
  BYTE *pBVar3;
  BYTE *pBVar4;
  BITMAPINFO local_488 [24];
  undefined1 local_60 [12];
  int local_54;
  HDC local_c;
  void *local_8;
  
  FUN_00458f91();
  *(int *)(param_1 + 0x20) = param_3;
  local_c = CreateCompatibleDC(DAT_006e48bc);
  *(HDC *)(param_1 + 0xc) = local_c;
  local_488[0].bmiHeader.biWidth = (int)param_2[3] - (int)param_2[1];
  local_488[0].bmiHeader.biSize = 0x28;
  local_488[0].bmiHeader.biPlanes = 1;
  local_488[0].bmiHeader.biHeight = (int)param_2[2] - (int)*param_2;
  local_488[0].bmiHeader.biBitCount = 8;
  local_488[0].bmiHeader.biCompression = 0;
  local_488[0].bmiHeader.biSizeImage = 0;
  local_488[0].bmiHeader.biXPelsPerMeter = 0;
  local_488[0].bmiHeader.biYPelsPerMeter = 0;
  local_488[0].bmiHeader.biClrUsed = 0;
  local_488[0].bmiHeader.biClrImportant = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 8);
  if (iVar1 != 0) {
    pBVar3 = &local_488[0].bmiColors[0].rgbGreen;
    pBVar4 = (BYTE *)(iVar1 + 2);
    param_3 = 0x100;
    do {
      pBVar3[1] = pBVar4[-2];
      *pBVar3 = pBVar4[-1];
      ((RGBQUAD *)(pBVar3 + -1))->rgbBlue = *pBVar4;
      pBVar3[2] = '\0';
      pBVar4 = pBVar4 + 4;
      pBVar3 = pBVar3 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  h = CreateDIBSection(local_c,local_488,0,&local_8,(HANDLE)0x0,0);
  *(HBITMAP *)(param_1 + 4) = h;
  pvVar2 = SelectObject(*(HDC *)(param_1 + 0xc),h);
  *(HGDIOBJ *)(param_1 + 8) = pvVar2;
  SelectPalette(*(HDC *)(param_1 + 0xc),*(HPALETTE *)(*(int *)(param_1 + 0x20) + 4),0);
  _memset(local_60,0,0x54);
  GetObjectA(*(HANDLE *)(param_1 + 4),0x54,local_60);
  *(void **)(param_1 + 0x24) =
       (void *)((local_488[0].bmiHeader.biHeight + -1) * local_54 + (int)local_8);
  *(int *)(param_1 + 0x28) = -local_54;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 2);
  return *(int *)(param_1 + 4) != 0;
}

