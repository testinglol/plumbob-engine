
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042119e(int *param_1,undefined4 param_2,float param_3)

{
  char *_Str;
  int iVar1;
  int iVar2;
  int local_8;
  
  FUN_006357d8(param_2);
  iVar1 = 0;
  local_8 = 0;
  if (0 < param_1[1]) {
    do {
      if ((param_3 != 0.0) &&
         (_Str = (char *)FUN_004705f2(*(int *)(iVar1 + 0x10 + *param_1) + 1,0xffffffff),
         _Str != (char *)0x0)) {
        _strlen(_Str);
      }
      FUN_006357d8(param_2);
      local_8 = local_8 + 1;
      iVar1 = iVar1 + 0x14;
    } while (local_8 < param_1[1]);
  }
  FUN_006357d8(param_2,&DAT_006c08dc);
  param_3 = -100.0;
  do {
    FUN_006357d8(param_2,&DAT_006c23e8,(double)param_3);
    iVar2 = *param_1;
    iVar1 = iVar2 + param_1[1] * 0x14;
    for (; iVar2 != iVar1; iVar2 = iVar2 + 0x14) {
      FUN_004167d4();
      FUN_006357d8(param_2,&DAT_006c23e8);
      iVar1 = *param_1 + param_1[1] * 0x14;
    }
    FUN_006357d8(param_2,&DAT_006c08dc);
    param_3 = param_3 + _DAT_00666748;
  } while (param_3 <= _DAT_0066674c);
  return;
}

