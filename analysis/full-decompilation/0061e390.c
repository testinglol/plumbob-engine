
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061e390(double *param_1,double *param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  undefined8 local_30;
  double local_28;
  
  dVar1 = param_1[1];
  dVar2 = param_1[2];
  if (dVar2 <= _DAT_006669e8) {
    local_28 = 0.0;
    local_30 = 0.0;
    dVar1 = _DAT_006669e8;
  }
  else {
    local_30 = dVar2;
    dVar5 = dVar2;
    dVar3 = dVar2;
    if (_DAT_006669e8 < dVar1) {
      dVar5 = *param_1 * _DAT_00666dc0;
      FUN_006369f9(dVar5);
      iVar6 = __ftol();
      dVar5 = dVar5 - (double)iVar6;
      dVar4 = (_DAT_00667280 - dVar1) * dVar2;
      dVar3 = (_DAT_00667280 - dVar5 * dVar1) * dVar2;
      dVar1 = (_DAT_00667280 - (_DAT_00667280 - dVar5) * dVar1) * dVar2;
      local_30 = dVar4;
      dVar5 = local_28;
      switch(iVar6) {
      case 0:
        dVar5 = dVar1;
        dVar3 = dVar2;
        break;
      case 1:
        dVar5 = dVar2;
        break;
      case 2:
        local_30 = dVar1;
        dVar5 = dVar2;
        dVar3 = dVar4;
        break;
      case 3:
        local_30 = dVar2;
        dVar5 = dVar3;
        dVar3 = dVar4;
        break;
      case 4:
        local_30 = dVar2;
        dVar5 = dVar4;
        dVar3 = dVar1;
        break;
      case 5:
        local_30 = dVar3;
        dVar5 = dVar4;
        dVar3 = dVar2;
      }
    }
    local_28 = dVar5;
    if ((_DAT_00667280 < dVar3) ||
       ((dVar1 = _DAT_006669e8, _DAT_006669e8 <= dVar3 && (dVar1 = dVar3, _DAT_00667280 < dVar3))))
    {
      dVar1 = _DAT_00667280;
    }
  }
  *param_2 = dVar1;
  dVar1 = _DAT_00667280;
  if ((local_28 <= _DAT_00667280) && (dVar1 = local_28, local_28 < _DAT_006669e8)) {
    dVar1 = _DAT_006669e8;
  }
  param_2[1] = dVar1;
  if (_DAT_00667280 < local_30) {
    *(undefined4 *)(param_2 + 2) = 0;
    *(undefined4 *)((int)param_2 + 0x14) = 0x3ff00000;
    return;
  }
  if (_DAT_006669e8 <= local_30) {
    *(undefined4 *)(param_2 + 2) = (undefined4)local_30;
    *(undefined4 *)((int)param_2 + 0x14) = local_30._4_4_;
    return;
  }
  *(undefined4 *)(param_2 + 2) = 0;
  *(undefined4 *)((int)param_2 + 0x14) = 0;
  return;
}

