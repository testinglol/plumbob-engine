
byte FUN_0064696a(uint param_1)

{
  if (DAT_00704100 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_00704000)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}

