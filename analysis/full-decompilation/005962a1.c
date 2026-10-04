
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005962a1(float *param_1,float *param_2,float *param_3)

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
  
  fVar3 = param_3[1] * *param_3 * _DAT_0066740c;
  fVar4 = param_3[3] * param_3[2] * _DAT_0066740c;
  fVar5 = param_3[3] * *param_3 * _DAT_0066740c;
  fVar6 = param_3[2] * param_3[1] * _DAT_0066740c;
  fVar7 = param_3[3] * param_3[1] * _DAT_0066740c;
  fVar8 = param_3[2] * *param_3 * _DAT_0066740c;
  fVar9 = param_3[3] * param_3[3];
  fVar10 = *param_3 * *param_3;
  fVar1 = param_3[1] * param_3[1];
  fVar2 = param_3[2] * param_3[2];
  *param_1 = (fVar3 - fVar4) * param_2[1] +
             (fVar8 + fVar7) * param_2[2] + (((fVar10 + fVar9) - fVar1) - fVar2) * *param_2;
  fVar9 = fVar9 - fVar10;
  param_1[1] = (fVar4 + fVar3) * *param_2 +
               (fVar6 - fVar5) * param_2[2] + ((fVar9 + fVar1) - fVar2) * param_2[1];
  param_1[2] = (fVar6 + fVar5) * param_2[1] +
               (fVar8 - fVar7) * *param_2 + ((fVar9 - fVar1) + fVar2) * param_2[2];
  return;
}

