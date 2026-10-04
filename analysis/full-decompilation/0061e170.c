
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061e170(double *param_1,double *param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  dVar1 = param_1[1];
  dVar5 = *param_1;
  dVar4 = *param_1;
  dVar2 = param_1[2];
  dVar3 = dVar2;
  if (dVar2 < dVar1) {
    dVar3 = dVar1;
  }
  if ((*param_1 <= dVar3) && (dVar4 = dVar1, dVar1 <= dVar2)) {
    dVar4 = dVar2;
  }
  dVar3 = dVar2;
  if (dVar1 < dVar2) {
    dVar3 = dVar1;
  }
  if ((dVar3 <= *param_1) && (dVar5 = dVar1, dVar2 <= dVar1)) {
    dVar5 = dVar2;
  }
  dVar6 = _DAT_006669e8;
  dVar3 = _DAT_006669e8;
  if (dVar4 != _DAT_006669e8) {
    dVar5 = dVar4 - dVar5;
    dVar3 = dVar5 / dVar4;
    if (dVar3 != _DAT_006669e8) {
      if (*param_1 == dVar4) {
        dVar5 = (dVar1 - dVar2) / dVar5;
      }
      else if (dVar1 == dVar4) {
        dVar5 = (dVar2 - *param_1) / dVar5 + _DAT_00668308;
      }
      else {
        dVar5 = (*param_1 - dVar1) / dVar5 + _DAT_00666750;
      }
      dVar5 = dVar5 * _DAT_006683a0;
      if (dVar5 < _DAT_006669e8) {
        dVar5 = dVar5 + _DAT_00667280;
      }
      if ((_DAT_00667280 < dVar5) ||
         ((_DAT_006669e8 <= dVar5 && (dVar6 = dVar5, _DAT_00667280 < dVar5)))) {
        dVar6 = _DAT_00667280;
      }
    }
  }
  *param_2 = dVar6;
  dVar1 = _DAT_00667280;
  if ((dVar3 <= _DAT_00667280) && (dVar1 = dVar3, dVar3 < _DAT_006669e8)) {
    dVar1 = _DAT_006669e8;
  }
  param_2[1] = dVar1;
  if (_DAT_00667280 < dVar4) {
    *(undefined4 *)(param_2 + 2) = 0;
    *(undefined4 *)((int)param_2 + 0x14) = 0x3ff00000;
    return;
  }
  if (_DAT_006669e8 <= dVar4) {
    param_2[2] = dVar4;
    return;
  }
  *(undefined4 *)(param_2 + 2) = 0;
  *(undefined4 *)((int)param_2 + 0x14) = 0;
  return;
}

