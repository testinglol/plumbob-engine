
undefined4 * __thiscall FUN_005d90fb(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_LAB_00673ab8;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if ((param_2 & 1) != 0) {
    FUN_006321f0(param_1);
  }
  return param_1;
}

