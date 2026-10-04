
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d5363(float *param_1)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  undefined4 uStack_14;
  
  fVar2 = (float10)fptan((float10)DAT_00673438 * (float10)_DAT_00668fe8);
  fVar3 = (float10)FUN_004d5442();
  if (SQRT(fVar3) < (float10)_DAT_0066674c) {
    return 0x1a;
  }
  if (_DAT_0067343c < ABS(*param_1)) {
    if (_DAT_0067343c < ABS(param_1[1])) {
      fVar1 = *param_1;
      if ((float)fVar2 <= ABS(param_1[1] / *param_1)) {
        if ((float)fVar2 <= ABS(fVar1 / param_1[1])) {
          if (_DAT_0066657c <= *param_1) {
            if (param_1[1] < _DAT_0066657c) {
              return 0x18;
            }
            return 0x16;
          }
          if (param_1[1] < _DAT_0066657c) {
            return 0x17;
          }
          return 0x15;
        }
        goto LAB_004d53fa;
      }
    }
    else {
      fVar1 = *param_1;
    }
    if (_DAT_0066657c <= fVar1) {
      uStack_14 = 0x11;
    }
    else {
      uStack_14 = 0x12;
    }
  }
  else {
LAB_004d53fa:
    if (_DAT_0066657c <= param_1[1]) {
      uStack_14 = 0x13;
    }
    else {
      uStack_14 = 0x14;
    }
  }
  return uStack_14;
}

