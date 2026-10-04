
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004734f9(undefined4 *param_1,undefined4 param_2,undefined4 param_3,float param_4,
            undefined4 param_5)

{
  bool bVar1;
  
  bVar1 = param_4 < _DAT_0066657c;
  param_1[2] = param_4;
  *param_1 = param_3;
  if (bVar1) {
    param_4 = -param_4;
  }
  param_1[1] = param_4;
  FUN_00473454(param_2,param_5);
  return;
}

