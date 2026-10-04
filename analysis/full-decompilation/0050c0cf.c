
undefined4 * __thiscall FUN_0050c0cf(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != param_2) {
    *param_1 = *param_2;
    FUN_005d499c(param_2 + 1);
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
    param_1[6] = param_2[6];
    param_1[7] = param_2[7];
    FUN_00636510(param_1 + 0xc,param_2 + 0xc,0x10);
    param_1[0x10] = param_2[0x10];
    param_1[0x11] = param_2[0x11];
    param_1[8] = param_2[8];
    param_1[9] = param_2[9];
    param_1[10] = param_2[10];
    param_1[0xb] = param_2[0xb];
  }
  return param_1;
}

