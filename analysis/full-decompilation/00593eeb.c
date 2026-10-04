
undefined4 __thiscall FUN_00593eeb(float *param_1,undefined4 param_2,float *param_3)

{
  float local_10;
  float local_c;
  float local_8;
  
  local_8 = param_3[2] + param_1[2];
  local_c = param_3[1] + param_1[1];
  local_10 = *param_3 + *param_1;
  param_3 = (float *)(param_3[3] + param_1[3]);
  FUN_005c4840(&local_10,&local_c,&local_8,&param_3);
  return param_2;
}

