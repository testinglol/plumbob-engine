
undefined1 __thiscall FUN_005d70ad(int *param_1,char param_2)

{
  char cVar1;
  ATOM AVar2;
  BOOL BVar3;
  DWORD dwStyle;
  int *piVar4;
  undefined1 uStack00000007;
  tagWNDCLASSA local_3c;
  tagRECT local_14;
  
  if (param_2 == '\0') {
    if (DAT_006fe8cc == (HWND)0x0) goto LAB_005d722b;
  }
  else if (DAT_006fe8cc == (HWND)0x0) {
    BVar3 = GetClassInfoA(DAT_006fefc4,PTR_s_Gonzo_006d6fa0,&local_3c);
    if (BVar3 == 0) {
      local_3c.style = 0x2b;
      local_3c.lpfnWndProc = FUN_005d6a20;
      local_3c.cbClsExtra = 0;
      local_3c.cbWndExtra = 4;
      local_3c.hInstance = DAT_006fefc4;
      local_3c.hIcon = LoadIconA(DAT_006fefc4,(LPCSTR)0x7f);
      local_3c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      local_3c.hbrBackground = GetStockObject(5);
      local_3c.lpszClassName = PTR_s_Gonzo_006d6fa0;
      local_3c.lpszMenuName = (LPCSTR)0x0;
      AVar2 = RegisterClassA(&local_3c);
      if (AVar2 == 0) {
        return 0;
      }
    }
    dwStyle = FUN_005d704f(param_1[0x36]);
    local_14.right = param_1[0x21] - param_1[0x1f];
    local_14.bottom = param_1[0x22] - param_1[0x20];
    local_14.left = 0;
    local_14.top = 0;
    BVar3 = AdjustWindowRect(&local_14,dwStyle,0);
    uStack00000007 = BVar3 != 0;
    if ((bool)uStack00000007) {
      piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
      cVar1 = (**(code **)(*piVar4 + 0x18))();
      DAT_006fe8cc = CreateWindowExA(-(uint)(cVar1 != '\0') & 8,PTR_s_Gonzo_006d6fa0,
                                     (LPCSTR)param_1[0x37],dwStyle,local_14.left,local_14.top,
                                     local_14.right - local_14.left,local_14.bottom - local_14.top,
                                     (HWND)0x0,(HMENU)0x0,DAT_006fefc4,(LPVOID)0x0);
      if (DAT_006fe8cc == (HWND)0x0) {
        return 0;
      }
      SetWindowLongA(DAT_006fe8cc,0,(LONG)param_1);
      (**(code **)(*param_1 + 0x68))(0);
      return uStack00000007;
    }
    return 0;
  }
  SetWindowLongA(DAT_006fe8cc,0,0);
  DestroyWindow(DAT_006fe8cc);
  DAT_006fe8cc = (HWND)0x0;
LAB_005d722b:
  FUN_006321f0(param_1[0x37]);
  param_1[0x37] = 0;
  return 1;
}

