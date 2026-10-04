
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0060dd40(double param_1,double param_2,double param_3)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  float10 fVar4;
  
  dVar1 = param_1;
  if (param_1 < _DAT_006669e8) {
    dVar1 = -param_1;
  }
  dVar2 = dVar1 * dVar1;
  if (param_1 < _DAT_006669e8) {
    if (param_1 < _DAT_00667280) {
      return (float10)_DAT_006669e8;
    }
  }
  else if (param_1 < _DAT_00667280) {
    return ((((float10)param_2 * (float10)_DAT_006773e8 + (float10)param_3 * (float10)_DAT_00666dc0)
            - (float10)_DAT_006773e0) * (float10)dVar2 +
           ((float10)_DAT_00666dc0 - ((float10)param_2 + (float10)param_2)) +
           (((float10)_DAT_006773e8 - (float10)param_2 * (float10)_DAT_006773f0) -
           (float10)param_3 * (float10)_DAT_00666dc0) * (float10)(dVar2 * dVar1)) *
           (float10)_DAT_006683a0;
  }
  if (_DAT_00668308 <= param_1) {
    return (float10)_DAT_006669e8;
  }
  fVar3 = (float10)param_3;
  fVar4 = (float10)param_2;
  return (fVar3 * (float10)_DAT_006773c0 + fVar4 * (float10)_DAT_0066f3c0 +
         (fVar4 * (float10)_DAT_006773d0 - fVar3 * (float10)_DAT_006773c8) * (float10)param_1 +
         (fVar3 * (float10)_DAT_006773d8 + fVar4 * (float10)_DAT_00666dc0) * (float10)dVar2 +
         (-fVar4 - fVar3 * (float10)_DAT_00666dc0) * (float10)(dVar2 * dVar1)) *
         (float10)_DAT_006683a0;
}

