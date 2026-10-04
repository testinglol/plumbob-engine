
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0062ba20(undefined4 *param_1,double param_2,int param_3)

{
  double dVar1;
  int iVar2;
  double *pdVar3;
  float10 fVar4;
  float10 fVar5;
  double local_74;
  double local_6c;
  double local_64;
  double local_5c;
  undefined4 local_38;
  undefined4 local_34;
  double local_2c;
  double local_24;
  double local_1c;
  double local_14;
  double local_c;
  
  pdVar3 = &local_74;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pdVar3 = *param_1;
    param_1 = param_1 + 1;
    pdVar3 = (double *)((int)pdVar3 + 4);
  }
  local_38 = local_34;
  local_24 = 999999999999999.0;
  local_14 = 0.0;
  local_1c = local_24;
  if (param_3 == 0) {
    iVar2 = FUN_0062b390();
    if (iVar2 != 0) {
      do {
        local_24 = (param_2 - local_74) / local_6c;
        local_2c = ROUND(local_24);
        dVar1 = local_2c * local_6c + local_74;
        if (dVar1 < local_64) {
          dVar1 = local_64;
        }
        if (local_5c < dVar1) {
          dVar1 = local_5c;
        }
        local_c = param_2 - dVar1;
        if (local_c < _DAT_006669e8) {
          local_c = -local_c - _DAT_006782d0;
        }
        if (local_c <= local_1c) {
          local_1c = local_c;
          local_14 = dVar1;
        }
        iVar2 = FUN_0062b390();
      } while (iVar2 != 0);
      return (float10)local_14;
    }
  }
  else if (param_3 == 1) {
    iVar2 = FUN_0062b390();
    if (iVar2 != 0) {
      do {
        fVar4 = (float10)FUN_006369f9((param_2 - local_74) / local_6c);
        fVar4 = fVar4 * (float10)local_6c + (float10)local_74;
        if (fVar4 < (float10)local_64) {
          fVar4 = (float10)local_64;
        }
        if ((float10)local_5c < fVar4) {
          fVar4 = (float10)local_5c;
        }
        fVar5 = (float10)param_2 - fVar4;
        local_c = (double)fVar5;
        if (fVar5 < (float10)_DAT_006669e8) {
          fVar5 = (float10)local_24;
          local_c = local_24;
        }
        if (fVar5 <= (float10)local_1c) {
          local_14 = (double)fVar4;
          local_1c = local_c;
        }
        iVar2 = FUN_0062b390();
      } while (iVar2 != 0);
      return (float10)local_14;
    }
  }
  else {
    iVar2 = FUN_0062b390();
    while (iVar2 != 0) {
      fVar4 = (float10)FUN_006369f9((param_2 - local_74) / local_6c + _DAT_006782d8);
      fVar4 = fVar4 * (float10)local_6c + (float10)local_74;
      if (fVar4 < (float10)local_64) {
        fVar4 = (float10)local_64;
      }
      if ((float10)local_5c < fVar4) {
        fVar4 = (float10)local_5c;
      }
      fVar5 = fVar4 - (float10)param_2;
      local_c = (double)fVar5;
      if (fVar5 < (float10)_DAT_006669e8) {
        fVar5 = (float10)local_24;
        local_c = local_24;
      }
      if (fVar5 <= (float10)local_1c) {
        local_14 = (double)fVar4;
        local_1c = local_c;
      }
      iVar2 = FUN_0062b390();
    }
  }
  return (float10)local_14;
}

