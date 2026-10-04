
int FUN_005f7e84(char *param_1)

{
  if (((*param_1 == 'I') && (param_1[1] == 'D')) && (param_1[2] == '3')) {
    return (((uint)(byte)param_1[6] * 0x80 + (uint)(byte)param_1[7]) * 0x80 + (uint)(byte)param_1[8]
           ) * 0x80 + 10 + (uint)(byte)param_1[9];
  }
  return 0;
}

