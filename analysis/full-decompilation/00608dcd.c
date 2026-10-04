
undefined4 FUN_00608dcd(uint param_1)

{
  uint uVar1;
  char *pcVar2;
  
  if (DAT_006ff2f0 == (char *)0x0) {
    if (DAT_006ff2e4 == 0xf) {
      DAT_006ff2f0 = &DAT_006d967c;
    }
    else if (DAT_006ff2e4 == 0x11) {
      DAT_006ff2f0 = &DAT_006d96b4;
    }
    else if (DAT_006ff2e4 == 0x12) {
      DAT_006ff2f0 = &DAT_006d96cc;
    }
    else if (DAT_006ff2e4 == 0x13) {
      DAT_006ff2f0 = &DAT_006ff2ec;
    }
    else if (DAT_006ff2e4 == 0x14) {
      DAT_006ff2f0 = &DAT_006d969c;
    }
  }
  pcVar2 = DAT_006ff2f0;
  if (param_1 < 0x100) {
    uVar1 = 0;
    do {
      if (param_1 == (byte)(&DAT_006d96dc)[uVar1]) {
        return 1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 3);
  }
  else {
    for (; *pcVar2 != '\0'; pcVar2 = pcVar2 + 2) {
      if ((*pcVar2 == (char)(param_1 >> 8)) && (pcVar2[1] == (char)param_1)) {
        return 1;
      }
    }
  }
  return 0;
}

