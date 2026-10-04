
void __thiscall
FUN_00420b7d(int param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4,
            undefined2 *param_5)

{
  HWND hWnd;
  BOOL BVar1;
  tagMSG local_20;
  
  hWnd = DAT_006fe8cc;
  *param_4 = 0;
  *param_5 = 0;
  BVar1 = TrackPopupMenu(*(HMENU *)(param_1 + 4),0,(int)param_2._2_2_,(int)(short)param_2,0,hWnd,
                         (RECT *)0x0);
  if (BVar1 != 0) {
    BVar1 = PeekMessageA(&local_20,hWnd,0x111,0x111,0);
    if (BVar1 != 0) {
      *param_5 = (undefined2)local_20.wParam;
      *param_4 = *(undefined2 *)(param_1 + 0xc);
    }
  }
  return;
}

