
undefined4 * __thiscall FUN_005e7372(undefined4 *param_1,undefined4 *param_2)

{
  HCURSOR pHVar1;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = &PTR_FUN_00674354;
  param_1[5] = 0;
  pHVar1 = LoadCursorFromFileA((LPCSTR)*param_2);
  param_1[1] = pHVar1;
  return param_1;
}

