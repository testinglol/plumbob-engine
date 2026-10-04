
undefined2 * __thiscall FUN_0041ba73(undefined2 *param_1,undefined2 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_2 + 6);
  FUN_004030b4(param_2 + 8);
  return param_1;
}

