
undefined4 FUN_006459bd(uint param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 < DAT_00704100) &&
     ((*(byte *)((&DAT_00704000)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_00704000)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  puVar1 = (undefined4 *)FUN_0063d796();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_0063d79f();
  *puVar1 = 0;
  return 0xffffffff;
}

