
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00623dd0(byte *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  double local_30;
  double local_28;
  double local_20;
  undefined1 local_18 [24];
  
  local_30 = (double)param_1[2] * _DAT_00677580;
  local_28 = (double)param_1[1] * _DAT_00677580;
  local_20 = (double)*param_1 * _DAT_00677580;
  FUN_00623e80(&local_30,local_18);
  param_2[3] = param_1[3];
  uVar1 = __ftol();
  param_2[2] = uVar1;
  uVar1 = __ftol();
  param_2[1] = uVar1;
  uVar1 = __ftol();
  *param_2 = uVar1;
  return;
}

