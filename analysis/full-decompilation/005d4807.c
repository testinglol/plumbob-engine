
undefined4 * __thiscall FUN_005d4807(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[4] = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x45] = 0;
  *(undefined1 *)(param_1 + 0x46) = 0;
  *(undefined1 *)((int)param_1 + 0x119) = 0;
  *param_1 = &PTR_FUN_00673680;
  FUN_006358b0(param_1 + 5,param_3);
  return param_1;
}

