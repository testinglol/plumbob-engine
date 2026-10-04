
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0059a567(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = _DAT_006720e8;
  iVar2 = *param_1;
  if (0 < iVar2) {
    if (iVar2 < 0x8000) {
      fVar4 = (float)iVar2;
      fVar3 = _DAT_006720ec - fVar4;
      *param_2 = (fVar4 * *param_3 + fVar3 * *param_2) * _DAT_006720e8;
      param_2[1] = (fVar3 * param_2[1] + fVar4 * param_3[1]) * fVar1;
      param_2[2] = (fVar3 * param_2[2] + fVar4 * param_3[2]) * fVar1;
      param_2[3] = (fVar3 * param_2[3] + fVar4 * param_3[3]) * fVar1;
      param_2[4] = (fVar3 * param_2[4] + fVar4 * param_3[4]) * fVar1;
      param_2[5] = (fVar3 * param_2[5] + fVar4 * param_3[5]) * fVar1;
      FUN_0049b802();
    }
    else {
      fVar1 = *param_3;
      param_2[1] = param_3[1];
      fVar3 = param_3[2];
      *param_2 = fVar1;
      param_2[2] = fVar3;
      param_2[3] = param_3[3];
      fVar1 = param_3[5];
      param_2[4] = param_3[4];
      param_2[5] = fVar1;
    }
  }
  return;
}

