
undefined4 * __thiscall FUN_005a42e3(undefined4 *param_1,undefined4 param_2)

{
  FUN_0046f824(param_1 + 4,0,0x104);
  param_1[1] = &PTR_FUN_006664e8;
  FUN_0046f824(param_1 + 0x48,0,0x104);
  param_1[0x45] = &PTR_FUN_006664e8;
  FUN_005a5055();
  param_1[0x89] = 0;
  *param_1 = param_2;
  return param_1;
}

