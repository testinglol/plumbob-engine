
void FUN_0041fdff(HWND param_1,HDC param_2)

{
  if (param_1 == (HWND)0x0) {
    FUN_0041fdd5();
    DAT_006e48b8 = param_1;
  }
  else {
    FUN_0041fdd5();
    DAT_006e48b8 = param_1;
    param_2 = GetDC(param_1);
  }
  DAT_006e48bc = param_2;
  return;
}

