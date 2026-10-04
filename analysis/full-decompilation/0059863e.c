
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0059863e(int param_1,float *param_2)

{
  float fVar1;
  
  fVar1 = *param_2;
  *(float *)(param_1 + 0x24) = fVar1;
  if (_DAT_0067343c < ABS(fVar1)) {
    *(float *)(param_1 + 0x20) = *(float *)(*(int *)(param_1 + 4) + 0x2c) / fVar1;
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  if (*(float *)(param_1 + 0x20) < _DAT_0066657c) {
    *(float *)(param_1 + 0x20) = -*(float *)(param_1 + 0x20);
  }
  return;
}

