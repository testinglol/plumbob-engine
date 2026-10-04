
int FUN_004a0005(char param_1)

{
  if (('/' < param_1) && (param_1 < ':')) {
    return param_1 + -0x30;
  }
  if (('@' < param_1) && (param_1 < 'G')) {
    return param_1 + -0x37;
  }
  return 0;
}

