
undefined2 * __fastcall FUN_0041c16f(undefined2 *param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *param_1 = 0xffff;
  param_1[1] = 0xffff;
  param_1[2] = 0xffff;
  param_1[3] = 0xffff;
  *(undefined4 *)(param_1 + 6) = 0xffffffff;
  FUN_0046f824(param_1 + 0xe,0,0x40);
  *(undefined ***)(param_1 + 8) = &PTR_FUN_0066651c;
  return param_1;
}

