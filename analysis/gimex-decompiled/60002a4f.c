
int * _GIMEX_loadframe_8(byte *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
                    /* 0x2a4f  13  _GIMEX_loadframe@8 */
  local_18 = 0;
  local_8 = 0;
  local_c = 0;
  local_1c = 0;
  local_24 = (int *)0x0;
  local_14 = 0;
  local_20 = 0;
  local_10 = _GIMEX_get_0();
  local_18 = _GIMEX_gopen_8(param_1,(byte *)0x0);
  if (local_18 != 0) {
    local_20 = _GIMEX_open_16(&local_1c,local_18,param_1,0);
    if (local_20 != 0) {
      local_c = _GIMEX_about_0();
      if (local_c != 0) {
        local_8 = _GIMEX_info_8(local_1c,param_2);
        if (local_8 != 0) {
          iVar1 = *(int *)(local_8 + 0x10) * *(int *)(local_8 + 0x14) * *(int *)(local_8 + 0x18);
          local_14 = FUN_600021ef((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3);
          if (local_14 != 0) {
            iVar1 = *(int *)(local_8 + 0x10) * *(int *)(local_8 + 0x18);
            local_20 = _GIMEX_read_16(local_1c,local_8,local_14,
                                      (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3);
            if (local_20 != 0) {
              local_20 = 0;
              local_24 = (int *)FUN_600021ef(0xc);
              if (local_24 != (int *)0x0) {
                local_20 = 1;
                *local_24 = local_8;
                local_24[1] = local_14;
                iVar1 = *(int *)(local_8 + 0x10) * *(int *)(local_8 + 0x18);
                local_24[2] = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
              }
            }
          }
        }
      }
    }
  }
  if (local_c != 0) {
    FUN_60002200(local_c);
  }
  if (local_1c != 0) {
    _GIMEX_close_4(local_1c);
  }
  if (local_18 != 0) {
    FUN_60002175(local_18);
  }
  if (local_20 == 0) {
    _GIMEX_freebitmap_4(local_24);
    local_24 = (int *)0x0;
  }
  _GIMEX_set_4(local_10);
  return local_24;
}

