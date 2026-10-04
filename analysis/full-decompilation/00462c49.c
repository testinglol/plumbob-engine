
undefined4 FUN_00462c49(undefined4 param_1,float *param_2,float *param_3)

{
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_14 = param_2[0xc] * *param_3 +
             param_2[0xd] * param_3[4] + param_2[0xe] * param_3[8] + param_3[0xc] * param_2[0xf];
  local_10 = param_2[0xc] * param_3[1] +
             param_2[0xe] * param_3[9] + param_2[0xd] * param_3[5] + param_3[0xd] * param_2[0xf];
  local_c = param_2[0xc] * param_3[2] +
            param_2[0xe] * param_3[10] + param_2[0xd] * param_3[6] + param_3[0xe] * param_2[0xf];
  local_8 = param_2[0xc] * param_3[3] +
            param_2[0xe] * param_3[0xb] + param_2[0xd] * param_3[7] + param_3[0xf] * param_2[0xf];
  local_24 = param_2[0xb] * param_3[0xc] +
             param_2[8] * *param_3 + param_3[4] * param_2[9] + param_2[10] * param_3[8];
  local_20 = param_2[9] * param_3[5] +
             param_2[10] * param_3[9] + param_2[0xb] * param_3[0xd] + param_2[8] * param_3[1];
  local_1c = param_2[9] * param_3[6] +
             param_2[10] * param_3[10] + param_2[0xb] * param_3[0xe] + param_2[8] * param_3[2];
  local_18 = param_2[9] * param_3[7] +
             param_2[10] * param_3[0xb] + param_2[0xb] * param_3[0xf] + param_2[8] * param_3[3];
  local_34 = param_3[0xc] * param_2[7] +
             param_2[4] * *param_3 + param_3[4] * param_2[5] + param_2[6] * param_3[8];
  local_30 = param_2[5] * param_3[5] +
             param_2[6] * param_3[9] + param_3[0xd] * param_2[7] + param_2[4] * param_3[1];
  local_2c = param_2[5] * param_3[6] +
             param_2[6] * param_3[10] + param_3[0xe] * param_2[7] + param_2[4] * param_3[2];
  local_28 = param_2[5] * param_3[7] +
             param_3[0xb] * param_2[6] + param_3[0xf] * param_2[7] + param_2[4] * param_3[3];
  local_44 = param_3[0xc] * param_2[3] +
             *param_2 * *param_3 + param_3[4] * param_2[1] + param_2[2] * param_3[8];
  local_40 = param_2[1] * param_3[5] +
             param_3[9] * param_2[2] + param_3[0xd] * param_2[3] + param_3[1] * *param_2;
  local_3c = param_3[6] * param_2[1] +
             param_3[10] * param_2[2] + param_3[0xe] * param_2[3] + param_3[2] * *param_2;
  local_38 = param_3[7] * param_2[1] +
             param_3[0xb] * param_2[2] + param_3[0xf] * param_2[3] + param_3[3] * *param_2;
  FUN_00462e7a(&local_44,&local_34,&local_24,&local_14);
  return param_1;
}

