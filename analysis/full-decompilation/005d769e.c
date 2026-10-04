
void FUN_005d769e(void)

{
  char cVar1;
  int *piVar2;
  BOOL BVar3;
  int nWidth;
  int nHeight;
  bool bVar4;
  bool bVar5;
  tagRECT local_4c;
  tagRECT local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  tagRECT local_1c;
  tagPOINT local_c;
  
  piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  cVar1 = (**(code **)(*piVar2 + 0x18))();
  if (cVar1 == '\0') {
    BVar3 = SystemParametersInfoA(0x30,0,&local_2c,0);
    if (BVar3 != 0) {
      BVar3 = GetWindowRect(DAT_006fe8cc,&local_1c);
      if (BVar3 != 0) {
        nWidth = local_1c.right - local_1c.left;
        nHeight = local_1c.bottom - local_1c.top;
        local_1c.left = ((local_24 - local_2c) - nWidth) / 2 + local_2c;
        local_1c.top = ((local_20 - local_28) - nHeight) / 2 + local_28;
        local_1c.right = local_1c.left + nWidth;
        local_1c.bottom = local_1c.top + nHeight;
        BVar3 = IsWindowVisible(DAT_006fe8cc);
        MoveWindow(DAT_006fe8cc,local_1c.left,local_1c.top,nWidth,nHeight,BVar3);
        GetClientRect(DAT_006fe8cc,&local_4c);
        local_c.x = local_4c.left;
        local_c.y = local_4c.top;
        ClientToScreen(DAT_006fe8cc,&local_c);
        GetWindowRect(DAT_006fe8cc,&local_3c);
        bVar4 = local_c.x < 0;
        if (bVar4) {
          OffsetRect(&local_3c,-local_c.x,0);
        }
        bVar5 = local_c.y < 0;
        if (bVar5) {
          OffsetRect(&local_3c,0,-local_c.y);
        }
        if (bVar5 || bVar4) {
          BVar3 = IsWindowVisible(DAT_006fe8cc);
          MoveWindow(DAT_006fe8cc,local_3c.left,local_3c.top,nWidth,nHeight,BVar3);
        }
      }
    }
  }
  return;
}

