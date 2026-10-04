
void __fastcall FUN_00459120(char *param_1)

{
  HGDIOBJ pvVar1;
  
  if (*param_1 == '\0') {
    pvVar1 = SelectObject(*(HDC *)(param_1 + 0xc),*(HGDIOBJ *)(param_1 + 8));
    *(HGDIOBJ *)(param_1 + 8) = pvVar1;
    DeleteObject(*(HGDIOBJ *)(param_1 + 4));
    DeleteDC(*(HDC *)(param_1 + 0xc));
  }
  FUN_00458f91();
  return;
}

