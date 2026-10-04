
uint FUN_005c0804(byte param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  
  if (param_2 == 0x3a4) {
    if ((0x80 < param_1) && (param_1 < 0xa0)) {
      return 1;
    }
    if (param_1 < 0xe0) {
      return 0;
    }
    bVar1 = param_1 < 0xfc;
    bVar2 = param_1 == 0xfc;
  }
  else if (param_2 == 0x3a8) {
    if (param_1 < 0xa1) {
      return 0;
    }
    bVar1 = param_1 < 0xfc;
    bVar2 = param_1 == 0xfc;
  }
  else if (param_2 == 0x3b5) {
    if (param_1 < 0xb0) {
      return 0;
    }
    bVar1 = param_1 < 200;
    bVar2 = param_1 == 200;
  }
  else {
    if (param_2 - 0x3b6U != 0) {
      return param_2 - 0x3b6U & 0xffffff00;
    }
    if (param_1 < 0x81) {
      return 0;
    }
    bVar1 = param_1 < 0xfe;
    bVar2 = param_1 == 0xfe;
  }
  if (bVar1 || bVar2) {
    return 1;
  }
  return 0;
}

