
undefined4 FUN_00608d3f(uint param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = DAT_006ff2e8;
  if ((DAT_006ff2e8 == (char *)0x0) && (pcVar3 = PTR_DAT_006d95f0, DAT_006ff2e4 != 0xf)) {
    if (DAT_006ff2e4 == 0x11) {
      pcVar3 = &DAT_006d95f4;
    }
    else {
      pcVar3 = PTR_DAT_006d9638;
      if (((DAT_006ff2e4 != 0x12) && (pcVar3 = PTR_DAT_006d963c, DAT_006ff2e4 != 0x13)) &&
         (pcVar3 = DAT_006ff2e8, DAT_006ff2e4 == 0x14)) {
        pcVar3 = &DAT_006d9640;
      }
    }
  }
  DAT_006ff2e8 = pcVar3;
  if (param_1 < 0x100) {
    uVar2 = 0;
    do {
      if (param_1 == (byte)(&DAT_006d9670)[uVar2]) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 10);
  }
  else {
    cVar1 = *DAT_006ff2e8;
    pcVar3 = DAT_006ff2e8;
    while (cVar1 != '\0') {
      if ((cVar1 == (char)(param_1 >> 8)) && (pcVar3[1] == (char)param_1)) {
        return 1;
      }
      pcVar3 = pcVar3 + 2;
      cVar1 = *pcVar3;
    }
  }
  return 0;
}

