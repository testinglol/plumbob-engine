
undefined4 * __thiscall
FUN_0041ee31(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  FUN_005b8680();
  param_1[1] = param_2;
  *param_1 = 2;
  param_1[7] = 100;
  param_1[0x10] = 0;
  if (param_3 == 0) {
    param_1[4] = 0xffffffff;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  else {
    param_1[2] = param_3;
    param_1[3] = param_3;
    param_1[4] = param_4;
  }
  *(undefined2 *)(param_1 + 5) = 0;
  *(undefined2 *)((int)param_1 + 0x16) = 0;
  param_1[9] = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)((int)param_1 + 0x1a) = 0;
  param_1[0xf] = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  param_1[0x10] = 0;
  return param_1;
}

