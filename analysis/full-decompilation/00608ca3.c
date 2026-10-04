
undefined4 FUN_00608ca3(uint param_1)

{
  bool bVar1;
  bool bVar2;
  
  if (DAT_006ff2e4 == 0xf) {
    if (0xff < param_1) {
      return 1;
    }
    if ((0x80 < param_1) && (param_1 < 0xa0)) {
      return 1;
    }
    if (param_1 < 0xe0) {
      return 0;
    }
    bVar1 = param_1 < 0xfc;
    bVar2 = param_1 == 0xfc;
  }
  else if (DAT_006ff2e4 == 0x11) {
    if (0xff < param_1) {
      return 1;
    }
    if (param_1 < 0xa1) {
      return 0;
    }
    bVar1 = param_1 < 0xfc;
    bVar2 = param_1 == 0xfc;
  }
  else if (DAT_006ff2e4 == 0x12) {
    if (0xff < param_1) {
      return 1;
    }
    if (param_1 < 0x81) {
      return 0;
    }
    bVar1 = param_1 < 0xfe;
    bVar2 = param_1 == 0xfe;
  }
  else {
    if (DAT_006ff2e4 == 0x13) {
      return 0;
    }
    if (DAT_006ff2e4 != 0x14) {
      return 0;
    }
    if (0xff < param_1) {
      return 1;
    }
    if (param_1 < 0xb0) {
      return 0;
    }
    bVar1 = param_1 < 200;
    bVar2 = param_1 == 200;
  }
  if (bVar1 || bVar2) {
    return 1;
  }
  return 0;
}

