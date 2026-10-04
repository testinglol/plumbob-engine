
undefined4 * __thiscall FUN_005d920a(undefined4 *param_1,BOOL param_2)

{
  HANDLE pvVar1;
  
  *param_1 = &PTR_LAB_00673b00;
  FUN_005d935e();
  param_1[1] = &PTR_FUN_00673af8;
  *param_1 = &PTR_LAB_00673adc;
  param_1[0xe] = 0;
  param_1[0xd] = param_2;
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,param_2,0,(LPCSTR)0x0);
  param_1[0xc] = pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    param_1[0xe] = 1;
  }
  return param_1;
}

