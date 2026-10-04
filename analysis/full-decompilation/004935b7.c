
undefined4 * __thiscall FUN_004935b7(undefined4 *param_1,undefined4 param_2)

{
  FUN_00492f28();
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  *(undefined1 *)((int)param_1 + 0x32) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  param_1[0xf] = param_2;
  *param_1 = &PTR__scalar_deleting_destructor__006681c8;
  return param_1;
}

