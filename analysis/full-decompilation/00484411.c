
undefined4 FUN_00484411(short param_1)

{
  if (DAT_006e56c0 == '\0') {
    FUN_0048423e();
  }
  if (param_1 < 1) {
    param_1 = 1;
  }
  else if (0xc < param_1) {
    param_1 = 0xc;
  }
  return *(undefined4 *)(&DAT_006e5624 + param_1 * 0xc);
}

