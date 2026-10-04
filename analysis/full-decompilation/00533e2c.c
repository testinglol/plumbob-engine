
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00533e2c(int param_1)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  if (1 < uVar1) {
    if (uVar1 == 0) {
      fVar2 = 1.0;
    }
    else {
      fVar2 = *(float *)(param_1 + 0x18) / (float)uVar1;
    }
    fVar3 = fVar2 * *(float *)(param_1 + 0x18);
    fVar4 = (float10)FUN_00636264((double)(fVar2 * fVar2 +
                                          ((_DAT_00666748 / ((float)uVar1 - _DAT_00666748) +
                                           *(float *)(param_1 + 0x1c)) - (fVar3 + fVar3))));
    return fVar4;
  }
  return (float10)_DAT_00666748;
}

