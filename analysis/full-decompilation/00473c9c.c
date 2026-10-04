
undefined4 * __thiscall FUN_00473c9c(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  *(undefined1 *)(param_1 + 3) = *(undefined1 *)(param_2 + 3);
  *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)((int)param_2 + 0xe);
  *(undefined1 *)(param_1 + 4) = *(undefined1 *)(param_2 + 4);
  *(undefined2 *)((int)param_1 + 0x12) = *(undefined2 *)((int)param_2 + 0x12);
  *(undefined2 *)(param_1 + 5) = *(undefined2 *)(param_2 + 5);
  *(undefined2 *)((int)param_1 + 0x16) = *(undefined2 *)((int)param_2 + 0x16);
  FUN_005d499c(param_2 + 6);
  FUN_005d499c(param_2 + 9);
  return param_1;
}

