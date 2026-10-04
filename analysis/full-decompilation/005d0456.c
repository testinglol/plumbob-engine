
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005d0456(int param_1,undefined4 *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  
  *(undefined4 *)(param_1 + 0xa8) = *param_2;
  *(undefined4 *)(param_1 + 0xac) = param_2[1];
  *(undefined4 *)(param_1 + 0xb0) = param_2[2];
  *(float *)(param_1 + 0x9c) = *param_3;
  *(float *)(param_1 + 0xa0) = param_3[1];
  *(float *)(param_1 + 0xa4) = param_3[2];
  fVar3 = (float10)FUN_0049b828();
  fVar3 = (float10)FUN_00639204((double)-((float10)param_3[1] / fVar3));
  *(float *)(param_1 + 0xb8) = (float)fVar3;
  fVar1 = *param_3;
  fVar2 = param_3[2];
  FUN_0049b802();
  fVar3 = (float10)FUN_00636c44((double)fVar2);
  *(float *)(param_1 + 0xb4) = (float)fVar3;
  if (fVar1 < (float)_DAT_006669e8) {
    *(float *)(param_1 + 0xb4) = (float)-fVar3;
  }
  return;
}

