
void FUN_005c37a0(float *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(param_3 + 0x40) == 1) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    fVar2 = param_2[3];
    param_1[2] = param_2[2];
    param_1[3] = fVar2;
    return;
  }
  if (*(int *)(param_3 + 0x40) == 2) {
    fVar2 = *(float *)(param_3 + 0x30);
    fVar1 = *param_2;
    param_1[3] = 1.0;
    *param_1 = fVar2 + fVar1;
    param_1[1] = *(float *)(param_3 + 0x34) + param_2[1];
    param_1[2] = *(float *)(param_3 + 0x38) + param_2[2];
    return;
  }
  FUN_005c4300(&local_10);
  param_1[1] = local_c;
  param_1[2] = local_8;
  *param_1 = local_10;
  param_1[3] = local_4;
  return;
}

