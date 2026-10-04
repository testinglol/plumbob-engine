
undefined4 * __fastcall FUN_00418ce5(undefined4 *param_1)

{
  param_1[3] = 0;
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  *(undefined2 *)(param_1 + 2) = 0xffff;
  *(undefined2 *)((int)param_1 + 10) = 0xffff;
  FUN_0046f824(param_1 + 7,0,0x40);
  param_1[4] = &PTR_FUN_0066651c;
  return param_1;
}

