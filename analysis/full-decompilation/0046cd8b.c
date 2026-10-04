
undefined4 * __thiscall FUN_0046cd8b(undefined4 *param_1,LPCSTR param_2,short param_3,short param_4)

{
  short sVar1;
  int iVar2;
  HFONT pHVar3;
  tagPOINT local_14;
  tagPOINT local_c;
  
  param_1[1] = DAT_006e5454;
  local_c.x = 0;
  local_c.y = 0;
  DAT_006e5454 = param_1;
  iVar2 = GetDeviceCaps(DAT_006e48bc,0x5a);
  local_c.y = (iVar2 * param_3 * 10) / 0x2d0;
  DPtoLP(DAT_006e48bc,&local_c,1);
  local_14.x = 0;
  local_14.y = 0;
  DPtoLP(DAT_006e48bc,&local_14,1);
  sVar1 = FUN_00636bef(local_c.y - local_14.y);
  pHVar3 = CreateFontA((int)-sVar1,0,0,0,(-(uint)(param_4 != 0) & 300) + 400,0,0,0,0,0,0,0,0,param_2
                      );
  *param_1 = pHVar3;
  if (pHVar3 == (HFONT)0x0) {
    *(undefined2 *)(param_1 + 2) = 0;
  }
  else {
    *(undefined2 *)(param_1 + 2) = 1;
  }
  return param_1;
}

