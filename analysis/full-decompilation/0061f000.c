
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061f000(double *param_1,double *param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  undefined8 local_18;
  double local_10;
  
  local_18 = param_1[2];
  fVar4 = (float10)local_18;
  fVar5 = (float10)param_1[1];
  if ((float10)_DAT_00667270 < fVar4) {
    fVar6 = (fVar4 + fVar5) - fVar4 * fVar5;
  }
  else {
    fVar6 = (fVar5 + (float10)_DAT_00667280) * fVar4;
  }
  dVar1 = (double)fVar6;
  dVar2 = (double)((fVar4 + fVar4) - fVar6);
  local_10 = local_18;
  if (fVar5 != (float10)_DAT_006669e8) {
    dVar3 = *param_1 * _DAT_00677778;
    fVar5 = (float10)FUN_0061f110(dVar2,dVar1,dVar3 + _DAT_00677de0);
    local_10 = (double)fVar5;
    fVar5 = (float10)FUN_0061f110(dVar2,dVar1,dVar3);
    local_18 = (double)fVar5;
    fVar4 = (float10)FUN_0061f110(dVar2,dVar1,dVar3 - _DAT_00677de0);
  }
  *param_2 = local_10;
  param_2[2] = (double)fVar4;
  *(undefined4 *)(param_2 + 1) = (undefined4)local_18;
  *(undefined4 *)((int)param_2 + 0xc) = local_18._4_4_;
  return;
}

