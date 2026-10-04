
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_004b9722(int param_1,float param_2)

{
  if (_DAT_0067343c < ABS(param_2 - _DAT_00666748)) {
    if (*(uint *)(param_1 + 0x1c) < DAT_006f0134) {
      *(float *)(param_1 + 0x18) = param_2;
      FUN_004b9471();
    }
    if (_DAT_0067343c < ABS(param_2 - *(float *)(param_1 + 0x18))) {
      FUN_004b978e(param_2);
    }
    param_1 = param_1 + 0xc20;
  }
  else {
    param_1 = param_1 + 0x420;
  }
  return param_1;
}

