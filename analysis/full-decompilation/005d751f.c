
undefined4 __fastcall FUN_005d751f(int *param_1)

{
  undefined3 uVar3;
  DWORD dwExStyle;
  HMENU pHVar1;
  DWORD dwStyle;
  undefined4 uVar2;
  uint bMenu;
  tagRECT local_14;
  
  if (DAT_006fe8cc == (HWND)0x0) {
    uVar3 = 0;
  }
  else {
    GetWindowLongA(DAT_006fe8cc,-0x10);
    SetWindowLongA(DAT_006fe8cc,-0x10,-0x6f380000);
    SetRect(&local_14,0,0,param_1[0x21] - param_1[0x1f],param_1[0x22] - param_1[0x20]);
    dwExStyle = GetWindowLongA(DAT_006fe8cc,-0x14);
    pHVar1 = GetMenu(DAT_006fe8cc);
    bMenu = (uint)(pHVar1 != (HMENU)0x0);
    dwStyle = GetWindowLongA(DAT_006fe8cc,-0x10);
    AdjustWindowRectEx(&local_14,dwStyle,bMenu,dwExStyle);
    SetWindowPos(DAT_006fe8cc,(HWND)0x0,local_14.left,local_14.top,local_14.right - local_14.left,
                 local_14.bottom - local_14.top,0x14);
    uVar2 = (**(code **)(*param_1 + 0x68))(0);
    uVar3 = (undefined3)((uint)uVar2 >> 8);
  }
  return CONCAT31(uVar3,1);
}

