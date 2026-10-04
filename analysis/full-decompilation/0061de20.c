
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061de20(byte *param_1,int param_2,double param_3,double param_4,double param_5,
                 double param_6)

{
  byte bVar1;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  if (0 < param_2) {
    param_3 = param_3 * _DAT_00677da0;
    do {
      local_20 = (double)param_1[2] * _DAT_00677580;
      local_18 = (double)param_1[1] * _DAT_00677580;
      local_10 = (double)*param_1 * _DAT_00677580;
      FUN_0061e170(&local_20,&local_38);
      local_38 = param_3 + local_38;
      if (local_38 < _DAT_006669e8) {
        local_38 = local_38 + _DAT_00667280;
      }
      if (_DAT_00667280 <= local_38) {
        local_38 = local_38 - _DAT_00667280;
      }
      if (_DAT_006669e8 <= param_4) {
        if (local_28 != _DAT_006669e8) {
          local_30 = (_DAT_00666740 - param_4) * local_30 + param_4;
          goto LAB_0061df22;
        }
      }
      else {
        local_30 = (param_4 + _DAT_00666740) * local_30;
LAB_0061df22:
        local_30 = local_30 * _DAT_00667260;
      }
      if (_DAT_00667280 < local_30) {
        local_30 = 1.0;
      }
      else if (local_30 < _DAT_006669e8) {
        local_30 = 0.0;
      }
      if (_DAT_006669e8 <= param_6) {
        local_28 = (_DAT_00666740 - param_6) * local_28 + param_6;
      }
      else {
        local_28 = (param_6 + _DAT_00666740) * local_28;
      }
      local_28 = local_28 * _DAT_00667260;
      if (_DAT_00667280 < local_28) {
        local_28 = 1.0;
      }
      else if (local_28 < _DAT_006669e8) {
        local_28 = 0.0;
      }
      FUN_0061e390(&local_38,&local_20);
      if (_DAT_006669e8 <= param_5) {
        local_20 = (_DAT_00666740 - param_5) * local_20 + param_5;
        local_18 = (_DAT_00666740 - param_5) * local_18 + param_5;
      }
      else {
        local_20 = (param_5 + _DAT_00666740) * local_20;
        local_18 = (param_5 + _DAT_00666740) * local_18;
      }
      local_18 = local_18 * _DAT_00667260;
      local_20 = local_20 * _DAT_00667260;
      if (_DAT_00667280 < local_20) {
        local_20 = 1.0;
      }
      else if (local_20 < _DAT_006669e8) {
        local_20 = 0.0;
      }
      if (_DAT_00667280 < local_18) {
        local_18 = 1.0;
      }
      else if (local_18 < _DAT_006669e8) {
        local_18 = 0.0;
      }
      bVar1 = __ftol();
      param_1[2] = bVar1;
      bVar1 = __ftol();
      param_1[1] = bVar1;
      bVar1 = __ftol();
      *param_1 = bVar1;
      param_1 = param_1 + 4;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

