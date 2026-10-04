
undefined4 * __fastcall FUN_005d909f(undefined4 *param_1)

{
  param_1[7] = 0;
  param_1[8] = 0;
  *param_1 = &PTR_LAB_00673ab8;
  _memset((LPCRITICAL_SECTION)(param_1 + 1),0,0x18);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  param_1[7] = 1;
  return param_1;
}

