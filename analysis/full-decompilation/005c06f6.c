
int FUN_005c06f6(byte *param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  if ((param_3 == -2) || (param_3 == -1)) {
    param_3 = FUN_005bfe47();
  }
  if ((param_3 != 0) && (param_3 != 0x10)) {
    if (param_3 != 8) {
      cVar2 = FUN_005c0804(*param_1,param_3);
      return (cVar2 != '\0') + 1;
    }
    bVar1 = *param_1;
    if ((((0x7f < bVar1) && (0xbf < bVar1)) && (bVar1 < 0xfe)) &&
       ((0x7f < param_1[1] && (param_1[1] < 0xc0)))) {
      if (bVar1 < 0xe0) {
        return 2;
      }
      if (bVar1 < 0xf0) {
        return 3;
      }
      if (bVar1 < 0xf8) {
        return 4;
      }
      return 6 - (uint)(bVar1 < 0xfc);
    }
  }
  return 1;
}

