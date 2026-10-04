
byte __fastcall FUN_00484015(char *param_1)

{
  if (param_1[1] != '\0') {
    return 9;
  }
  if (param_1[4] != '\0') {
    return 0xd;
  }
  if (param_1[3] != '\0') {
    return 8;
  }
  if (param_1[5] != '\0') {
    return 0xb;
  }
  if (param_1[6] != '\0') {
    return 0xc;
  }
  return -(*param_1 != '\0') & 10;
}

