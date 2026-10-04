
int FUN_0053c135(int param_1)

{
  if (param_1 == 1) {
    return 4;
  }
  if (param_1 == 2) {
    return 8;
  }
  if (param_1 == 4) {
    return 1;
  }
  if (param_1 != 8) {
    if ((param_1 != 0x10) && (param_1 != 0x20)) {
      return 0;
    }
    return param_1;
  }
  return 2;
}

