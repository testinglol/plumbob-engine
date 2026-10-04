
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005faf0d(int *param_1,uint param_2)

{
  float fVar1;
  int *local_8;
  
  if (param_2 == 0) {
    param_2 = 1;
  }
  if (10 < param_2) {
    param_2 = 10;
  }
  local_8 = param_1;
  (**(code **)(*DAT_006fed78 + 0x44))(&local_8);
  fVar1 = (float)(&DAT_006d7c60)[param_2] / (float)local_8;
  (**(code **)(*param_1 + 0xec))(fVar1);
  (**(code **)(*param_1 + 0xf4))(fVar1 * _DAT_0066674c);
  return;
}

