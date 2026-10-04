
undefined * FUN_004e9bbd(int param_1)

{
  int iVar1;
  
  if ((DAT_006f262c & 1) == 0) {
    DAT_006f262c = DAT_006f262c | 1;
    FUN_005b870f(s_No_Selector__006c9e10);
    FUN_00635543(&LAB_004e9c2a);
  }
  if (-1 < param_1) {
    if (param_1 < (DAT_006f264c - DAT_006f2648) / 0x44) {
      iVar1 = FUN_004e8a7a();
      if (iVar1 != 0) {
        iVar1 = FUN_00457ea7();
        return (undefined *)(iVar1 + 0xc);
      }
    }
  }
  return &DAT_006f2620;
}

