
undefined2 * __thiscall
FUN_0041ba28(undefined2 *param_1,undefined2 param_2,byte param_3,undefined2 param_4)

{
  *param_1 = param_2;
  param_1[2] = 0xffff;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0xffffffff;
  param_1[1] = (ushort)param_3 << 8;
  param_1[3] = param_4;
  FUN_0046f824(param_1 + 0xe,0,0x40);
  *(undefined ***)(param_1 + 8) = &PTR_FUN_0066651c;
  return param_1;
}

