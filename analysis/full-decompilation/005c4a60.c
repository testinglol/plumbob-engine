
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * __thiscall FUN_005c4a60(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  
  fVar1 = *param_2;
  fVar5 = (float)_DAT_00667270;
  fVar2 = *param_3;
  fVar6 = (float)_DAT_00667270;
  fVar3 = *param_4;
  fVar7 = (float)_DAT_00667270;
  fVar8 = (float10)FUN_00637084((double)(fVar1 * fVar5));
  fVar9 = (float10)FUN_00637084((double)(fVar2 * fVar6));
  fVar4 = (float)fVar9;
  fVar9 = (float10)FUN_00637084((double)(fVar3 * fVar7));
  fVar10 = (float10)FUN_00636d14((double)(fVar1 * fVar5));
  fVar11 = (float10)FUN_00636d14((double)(fVar2 * fVar6));
  fVar1 = (float)fVar11;
  fVar11 = (float10)FUN_00636d14((double)(fVar3 * fVar7));
  fVar3 = (float)fVar9 * (float)fVar8;
  fVar2 = (float)(fVar11 * (float10)(float)fVar8);
  fVar5 = (float)fVar10 * (float)fVar9;
  fVar11 = fVar11 * (float10)(float)fVar10;
  *param_1 = fVar5 * fVar4 - fVar2 * fVar1;
  param_1[1] = (float)(fVar11 * (float10)fVar4 + (float10)fVar3 * (float10)fVar1);
  param_1[2] = fVar2 * fVar4 - fVar5 * fVar1;
  param_1[3] = (float)((float10)fVar3 * (float10)fVar4 + fVar11 * (float10)fVar1);
  return param_1;
}

