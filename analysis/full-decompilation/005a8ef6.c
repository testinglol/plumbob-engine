
float * FUN_005a8ef6(float *param_1,float *param_2,undefined4 param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar1 = *param_1;
  fVar2 = param_2[1];
  fVar3 = *param_1;
  fVar4 = param_2[2];
  fVar5 = param_1[1];
  fVar6 = param_2[4];
  fVar7 = param_1[1];
  fVar8 = param_2[5];
  fVar9 = param_1[2];
  fVar10 = param_2[7];
  fVar11 = param_1[2];
  fVar12 = param_2[8];
  *param_4 = param_1[2] * param_2[6] + param_1[1] * param_2[3] + *param_1 * *param_2;
  param_4[1] = fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2;
  param_4[2] = fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4;
  return param_1 + 3;
}

