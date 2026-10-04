
undefined8 FUN_0060c6e4(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_10 = 0x40;
  local_c = 0;
  local_8 = 0;
  local_18 = param_1;
  local_14 = param_2;
  do {
    local_8 = local_8 * 2 | local_c >> 0x1f;
    local_c = local_14 >> 0x1f | local_c * 2;
    local_14 = local_14 * 2 | local_18 >> 0x1f;
    local_18 = local_18 << 1;
    if ((param_4 < local_8) || ((local_8 == param_4 && (param_3 <= local_c)))) {
      local_18 = local_18 | 1;
      local_8 = local_8 - param_4;
      if (local_c < param_3) {
        local_8 = local_8 - 1;
      }
      local_c = local_c - param_3;
    }
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  if (param_5 != (uint *)0x0) {
    *param_5 = local_c;
    param_5[1] = local_8;
  }
  return CONCAT44(local_14,local_18);
}

