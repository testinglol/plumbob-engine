
undefined4 FUN_0063c832(uint param_1)

{
  if (((*(byte *)((int)&DAT_00705240 + (param_1 >> 8 & 0xff) + 1) & 4) != 0) &&
     ((*(byte *)((int)&DAT_00705240 + (param_1 & 0xff) + 1) & 8) != 0)) {
    return 1;
  }
  return 0;
}

