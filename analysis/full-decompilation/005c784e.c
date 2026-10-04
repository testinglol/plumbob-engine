
undefined4 * __fastcall FUN_005c784e(undefined4 *param_1)

{
  FARPROC pFVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  if (DAT_006fe820 != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(DAT_006fe820,s__GIMEX_find_8_006d0310);
    *param_1 = pFVar1;
    pFVar1 = GetProcAddress(DAT_006fe820,s__GIMEX_open_16_006d03c8);
    param_1[1] = pFVar1;
    pFVar1 = GetProcAddress(DAT_006fe820,s__GIMEX_info_8_006d03b8);
    param_1[2] = pFVar1;
    pFVar1 = GetProcAddress(DAT_006fe820,s__GIMEX_read_16_006d03a8);
    param_1[3] = pFVar1;
    pFVar1 = GetProcAddress(DAT_006fe820,s__GIMEX_close_4_006d0398);
    param_1[4] = pFVar1;
  }
  return param_1;
}

