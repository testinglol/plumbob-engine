
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004734bd(float *param_1,float param_2,float param_3,int param_4,int param_5)

{
  bool bVar1;
  float fVar2;
  
  fVar2 = (param_3 - param_2) / (float)param_4;
  *param_1 = param_3;
  bVar1 = fVar2 < _DAT_0066657c;
  param_1[2] = fVar2;
  if (bVar1) {
    fVar2 = -fVar2;
  }
  param_1[1] = fVar2;
  param_1[3] = (float)(param_4 + param_5);
  return;
}

