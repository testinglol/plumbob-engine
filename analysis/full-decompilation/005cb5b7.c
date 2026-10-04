
undefined4 * __thiscall FUN_005cb5b7(undefined4 *param_1,int *param_2)

{
  *param_1 = &PTR_FUN_0067347c;
  param_1[1] = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  return param_1;
}

