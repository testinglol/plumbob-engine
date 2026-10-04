
undefined4 * __thiscall FUN_005d30b8(undefined4 *param_1,int *param_2)

{
  *param_1 = &PTR_FUN_00673590;
  param_1[1] = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  return param_1;
}

