
undefined4 * __thiscall FUN_004b8d99(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  
  if (param_1 != param_2) {
    *param_1 = *param_2;
    if (param_2[1] != 0) {
      piVar1 = (int *)(param_2[1] + 0x14);
      *piVar1 = *piVar1 + 1;
    }
    if (param_1[1] != 0) {
      FUN_00415317();
    }
    param_1[1] = param_2[1];
  }
  return param_1;
}

