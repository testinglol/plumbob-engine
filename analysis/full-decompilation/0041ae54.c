
undefined4 * __thiscall FUN_0041ae54(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  *(undefined2 *)((int)param_1 + 10) = *(undefined2 *)((int)param_2 + 10);
  param_1[3] = param_2[3];
  FUN_0046f8e4(param_2 + 4);
  return param_1;
}

