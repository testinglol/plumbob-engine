
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00615560(double param_1,double param_2,int param_3,int param_4)

{
  double dVar1;
  
  dVar1 = (double)param_4 + param_2;
  param_2 = (double)param_3 + param_2;
  if (param_2 < _DAT_006669e8) {
    param_2 = param_2 + _DAT_00677778;
  }
  if (_DAT_00677778 <= dVar1) {
    dVar1 = dVar1 - _DAT_00677778;
  }
  if (param_2 <= dVar1) {
    if ((param_2 <= param_1) && (param_1 < dVar1)) {
      return 1;
    }
    if (param_2 <= dVar1) {
      return 0;
    }
  }
  if (param_2 <= param_1) {
    return 1;
  }
  if (dVar1 < param_1) {
    return 0;
  }
  return 1;
}

