
undefined2 FUN_004021ff(short param_1)

{
  if ((param_1 < 0) || (0xff < param_1)) {
    if ((0xff < param_1) && (param_1 < 0x1000)) {
      return 1;
    }
    if ((0x1fff < param_1) && (param_1 < 0x2329)) {
      return 3;
    }
    if ((0xfff < param_1) && (param_1 < 0x2000)) {
      return 2;
    }
  }
  return 0;
}

