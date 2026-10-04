
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0049ba2e(undefined4 param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float local_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_10;
  undefined4 local_8;
  
  local_8 = 0;
  local_58[5] = *param_4 * _DAT_00666578;
  local_58[0] = local_58[5] / *param_5;
  local_58[1] = 0.0;
  local_58[2] = 0.0;
  local_58[3] = 0.0;
  local_58[4] = 0.0;
  local_40 = 0;
  local_3c = 0;
  local_1c = local_58[0] * local_58[5];
  local_30 = local_1c / (*param_3 - *param_2);
  local_38 = 0;
  local_34 = 0;
  local_2c = 0;
  local_20 = -((local_58[0] * *param_2 * local_58[5]) / (*param_3 - *param_2));
  local_28 = 0;
  local_24 = 0;
  local_10 = local_20;
  FUN_005c3650(local_58);
  return param_1;
}

