
float10 __thiscall FUN_004c496a(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar4 = (float10)FUN_00434e9b();
  fVar1 = *(float *)(param_1 + 0x1e8);
  fVar2 = *(float *)(param_1 + 0x1ec);
  fVar3 = *(float *)(param_1 + 0x1f0);
  fVar5 = (float10)FUN_00636264((double)(fVar4 * fVar4 +
                                        (float10)(param_2 * param_2 + param_3 * param_3)));
  fVar5 = (float10)(float)(fVar4 * (float10)fVar3 +
                          (float10)param_3 * (float10)fVar2 + (float10)param_2 * (float10)fVar1) /
          fVar5;
  return fVar5 * fVar5;
}

