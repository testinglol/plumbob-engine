
undefined4 * __thiscall FUN_005d93ef(undefined4 *param_1,undefined4 *param_2)

{
  HANDLE pvVar1;
  
  param_1[2] = 0;
  *param_1 = &PTR_LAB_00673b18;
  pvVar1 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,(LPCSTR)*param_2);
  param_1[1] = pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    param_1[2] = 1;
  }
  return param_1;
}

