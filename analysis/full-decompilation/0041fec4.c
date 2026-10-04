
void FUN_0041fec4(LPCSTR param_1,int param_2,short *param_3,short param_4)

{
  UINT format;
  tagRECT local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_24.top = (LONG)*param_3;
  local_24.bottom = (LONG)param_3[2];
  local_24.left = (LONG)param_3[1];
  local_24.right = (LONG)param_3[3];
  format = 0x810;
  if (param_4 == 1) {
    format = 0x811;
  }
  else if (param_4 == -1) {
    format = 0x812;
  }
  local_14 = local_24.left;
  local_10 = local_24.top;
  local_c = local_24.right;
  local_8 = local_24.bottom;
  DrawTextA(DAT_006e48bc,param_1,param_2,&local_24,format);
  return;
}

