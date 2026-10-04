
void FUN_0041fe48(RECT *param_1)

{
  bool bVar1;
  COLORREF color;
  HBRUSH hbr;
  int i;
  
  color = GetBkColor(DAT_006e48bc);
  if ((color & 0xffffff) == 0xffffff) {
    i = 0;
  }
  else {
    if ((color & 0xffffff) != 0) {
      hbr = CreateSolidBrush(color);
      bVar1 = true;
      goto LAB_0041fe85;
    }
    i = 4;
  }
  hbr = GetStockObject(i);
  bVar1 = false;
LAB_0041fe85:
  FillRect(DAT_006e48bc,param_1,hbr);
  if (bVar1) {
    DeleteObject(hbr);
  }
  return;
}

