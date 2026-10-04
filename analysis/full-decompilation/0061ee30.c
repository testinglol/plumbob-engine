
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061ee30(double *param_1,double *param_2)

{
  double *pdVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 local_18;
  
  dVar2 = param_1[2];
  dVar4 = *param_1;
  dVar6 = *param_1;
  pdVar1 = param_1 + 1;
  dVar7 = *pdVar1;
  dVar5 = *pdVar1;
  dVar3 = dVar2;
  if (dVar2 < dVar5) {
    dVar3 = dVar5;
  }
  if ((*param_1 <= dVar3) && (dVar6 = dVar5, dVar5 <= dVar2)) {
    dVar6 = dVar2;
  }
  dVar3 = dVar2;
  if (dVar7 < dVar2) {
    dVar3 = dVar7;
  }
  if ((dVar3 <= *param_1) && (dVar4 = dVar2, dVar7 < dVar2)) {
    dVar4 = dVar7;
  }
  local_18 = dVar4 + dVar6;
  dVar3 = local_18 * _DAT_00667270;
  if (dVar6 == dVar4) {
    local_18 = 0.0;
    dVar4 = _DAT_006669e8;
  }
  else {
    dVar5 = dVar6 - dVar4;
    if (_DAT_00667270 < dVar3) {
      local_18 = (_DAT_00668308 - dVar6) - dVar4;
    }
    local_18 = dVar5 / local_18;
    if (*param_1 == dVar6) {
      dVar4 = (*pdVar1 - dVar2) / dVar5;
    }
    else if (dVar7 == dVar6) {
      dVar4 = (dVar2 - *param_1) / dVar5 + _DAT_00668308;
    }
    else {
      dVar4 = dVar3;
      if (dVar2 == dVar6) {
        dVar4 = (*param_1 - *pdVar1) / dVar5 + _DAT_00666750;
      }
    }
    dVar4 = dVar4 * _DAT_00677dd8;
    if (dVar4 < _DAT_006669e8) {
      dVar4 = dVar4 + _DAT_00677778;
    }
    dVar4 = dVar4 * _DAT_00677da0;
  }
  *param_2 = dVar4;
  *(undefined4 *)(param_2 + 1) = (undefined4)local_18;
  *(undefined4 *)((int)param_2 + 0xc) = local_18._4_4_;
  param_2[2] = dVar3;
  return;
}

