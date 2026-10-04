
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00467a62(int param_1)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  float10 fVar6;
  float10 fVar7;
  float local_8;
  
  cVar5 = FUN_00468851();
  if (cVar5 == '\0') {
    fVar2 = (((float)*(int *)(param_1 + 0x48) * _DAT_00667420) /
            (float)(*(int *)(param_1 + 0x38) / 2)) * _DAT_006c4758;
    fVar7 = (float10)FUN_004674e7();
    fVar6 = (((float10)*(int *)(param_1 + 0x44) * (float10)_DAT_00667420) /
            (float10)(*(int *)(param_1 + 0x38) / 2)) * fVar7 * (float10)_DAT_006c4758;
    if (fVar7 < fVar6) {
      fVar6 = fVar7;
    }
    local_8 = (float)fVar6;
    fVar6 = (float10)local_8 + (float10)fVar2;
    if ((float10)_DAT_00666a4c <= fVar6) {
      if ((float10)_DAT_00667670 < fVar6) {
        fVar6 = (float10)1;
      }
    }
    else {
      fVar6 = (float10)0;
    }
  }
  else {
    fVar6 = (float10)FUN_004674e7();
  }
  *(float *)(param_1 + 0x6c) = (float)fVar6;
  cVar5 = FUN_00468851();
  if (cVar5 == '\0') {
    fVar2 = (float)(*(int *)(param_1 + 0x38) / 2);
    fVar3 = fVar2;
    if (_DAT_006e53d4 < fVar2) {
      fVar3 = _DAT_006e53d4;
    }
    fVar4 = _DAT_006e53c0;
    if ((_DAT_006e53c0 <= fVar2) && (fVar4 = fVar2, _DAT_006e53bc < fVar2)) {
      fVar4 = _DAT_006e53bc;
    }
    fVar2 = ((float)*(int *)(param_1 + 0x50) * _DAT_006e53b8) / fVar4 +
            ((float)*(int *)(param_1 + 0x3c) / (float)*(int *)(param_1 + 0x38)) * _DAT_006e539c +
            _DAT_006e5398 +
            ((float)*(int *)(param_1 + 100) / (float)*(int *)(param_1 + 0x60)) * _DAT_006e5394 +
            _DAT_006e5390 + *(float *)(param_1 + 0x6c) * _DAT_006e53c4 + _DAT_006e53c8 +
            (fVar3 / _DAT_006e53d4) * _DAT_006e53cc + _DAT_006e53d0;
    bVar1 = _DAT_00666a60 <= fVar2;
    *(float *)(param_1 + 0x68) = fVar2;
    if (bVar1) {
      if (_DAT_0066674c < fVar2) {
        *(undefined4 *)(param_1 + 0x68) = 0x42c80000;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x68) = 0xc2c80000;
    }
  }
  else {
    *(float *)(param_1 + 0x68) =
         (float)*(int *)(param_1 + 0x50) * _DAT_006e53b4 +
         (float)*(int *)(param_1 + 0x54) * _DAT_006e53b0;
  }
  cVar5 = FUN_00468851();
  if ((cVar5 != '\0') ||
     ((fVar2 = DAT_00667638, *(char *)(param_1 + 0x75) == '\0' &&
      ((((*(char *)(param_1 + 0x73) == '\0' || (*(int *)(param_1 + 0x280) != 0)) ||
        (*(int *)(param_1 + 0x284) == 0)) || (DAT_00667638 <= *(float *)(param_1 + 0x6c))))))) {
    fVar2 = *(float *)(param_1 + 0x6c);
  }
  FUN_00467805(param_1 + 4,fVar2);
  return;
}

