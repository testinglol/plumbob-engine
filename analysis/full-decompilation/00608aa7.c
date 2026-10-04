
uint FUN_00608aa7(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1 >> 8;
  uVar4 = param_1 & 0xff;
  if (DAT_006ff2e4 == 0xf) {
    if ((((0x80 < uVar3) && (uVar3 < 0xa0)) || ((0xdf < uVar3 && (uVar3 < 0xfd)))) &&
       (((0x3f < uVar4 && (uVar4 < 0x7f)) || ((0x7f < uVar4 && (uVar4 < 0xfd)))))) {
      if (uVar4 < 0x80) {
        iVar1 = -0x40;
      }
      else {
        iVar1 = -0x41;
      }
      if (uVar3 < 0xe0) {
        iVar2 = -0x81;
      }
      else {
        iVar2 = -0xc1;
      }
      return (uVar3 + iVar2) * 0xbc + uVar4 + iVar1;
    }
  }
  else if (DAT_006ff2e4 == 0x11) {
    if ((((0xa0 < uVar3) && (uVar3 < 0xfd)) && (0xa0 < uVar4)) && (uVar4 < 0xff)) {
      return uVar3 * 0x5e + -0x3bbf + uVar4;
    }
  }
  else if (DAT_006ff2e4 == 0x12) {
    if (((0xa0 < uVar3) && (uVar3 < 0xfa)) &&
       (((0x3f < uVar4 && (uVar4 < 0x7f)) || ((0xa0 < uVar4 && (uVar4 < 0xff)))))) {
      if (uVar4 < 0x80) {
        iVar1 = -0x40;
      }
      else {
        iVar1 = -0x62;
      }
      return uVar3 * 0x9d + -0x62bd + uVar4 + iVar1;
    }
  }
  else {
    if (DAT_006ff2e4 == 0x13) {
      return param_1;
    }
    if ((((DAT_006ff2e4 == 0x14) && (0xaf < uVar3)) && (uVar3 < 0xc9)) &&
       ((0xa0 < uVar4 && (uVar4 < 0xff)))) {
      return uVar3 * 0x5e + -0x4141 + uVar4;
    }
  }
  return 0;
}

