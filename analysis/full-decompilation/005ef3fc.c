
undefined4 * __thiscall FUN_005ef3fc(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  FUN_005d499c(param_2 + 5);
  FUN_005d499c(param_2 + 8);
  FUN_005f07e8(param_2 + 0xb);
  return param_1;
}

