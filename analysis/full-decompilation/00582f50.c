
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HMODULE FUN_00582f50(undefined4 *param_1)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = LoadLibraryA(s_gimex_006d0418);
  DAT_006fe820 = hModule;
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,s__GIMEX_init_0_006d0408);
    *param_1 = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_restore_0_006d03f4);
    param_1[1] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_about_0_006d03e4);
    param_1[2] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_is_4_006d03d8);
    param_1[3] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_open_16_006d03c8);
    param_1[4] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_info_8_006d03b8);
    param_1[5] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_read_16_006d03a8);
    param_1[6] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_close_4_006d0398);
    param_1[7] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_wopen_16_006d0388);
    param_1[8] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_write_16_006d0378);
    param_1[9] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_wclose_4_006d0368);
    param_1[10] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_gopenstream_8_006d0350);
    param_1[0xb] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_gopen_8_006d0340);
    param_1[0xc] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_set_4_006d0330);
    param_1[0xd] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_get_0_006d0320);
    param_1[0xe] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_find_8_006d0310);
    param_1[0xf] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_count_0_006d0300);
    param_1[0x10] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_freebitmap_4_006d02ec);
    param_1[0x11] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_loadframe_8_006d02d8);
    param_1[0x12] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_installcallbacks_4_006d02bc);
    param_1[0x13] = pFVar1;
    pFVar1 = GetProcAddress(hModule,s__GIMEX_open_12_006d02ac);
    param_1[0x14] = pFVar1;
    _DAT_006f6ae4 = GetProcAddress(hModule,s_GIMEXabout_006d02a0);
  }
  return hModule;
}

