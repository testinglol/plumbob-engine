
float10 __thiscall FUN_00473496(float *param_1,float param_2)

{
  float10 fVar1;
  
  if ((uint)param_2 < (uint)param_1[3]) {
    fVar1 = (float10)*param_1 -
            (float10)(uint)((int)param_1[3] - (int)param_2) * (float10)param_1[2];
  }
  else {
    fVar1 = (float10)*param_1;
  }
  return fVar1;
}

