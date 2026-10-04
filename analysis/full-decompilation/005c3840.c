
void FUN_005c3840(float *param_1,float *param_2,int param_3)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(param_3 + 0x40) == 1) {
    *param_1 = *param_2;
    fVar1 = param_2[2];
    param_1[1] = param_2[1];
    param_1[2] = fVar1;
    return;
  }
  if (*(int *)(param_3 + 0x40) == 2) {
    *param_1 = *(float *)(param_3 + 0x30) + *param_2;
    param_1[1] = *(float *)(param_3 + 0x34) + param_2[1];
    param_1[2] = *(float *)(param_3 + 0x38) + param_2[2];
    return;
  }
  FUN_005c4390(&local_c);
  *param_1 = local_c;
  param_1[1] = local_8;
  param_1[2] = local_4;
  return;
}

