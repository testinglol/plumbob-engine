
uint FUN_00435a8f(undefined4 param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 local_c;
  
  cVar2 = FUN_00433136(param_1);
  if (cVar2 == '\0') {
    pbVar5 = (byte *)FUN_00435b46(param_1);
    bVar1 = *pbVar5;
    uVar4 = 0;
    if ((bVar1 & 1) != 0) {
      uVar4 = 0x40;
    }
    if ((bVar1 & 2) != 0) {
      uVar4 = uVar4 | 1;
    }
    if ((bVar1 & 4) != 0) {
      uVar4 = uVar4 | 4;
    }
    if ((bVar1 & 8) != 0) {
      uVar4 = uVar4 | 0x10;
    }
    uVar8 = 0;
    sVar3 = FUN_004325af(param_1);
    uVar6 = FUN_00407498((int)sVar3);
    FUN_0043f3a4(uVar6,uVar8);
    while (local_c != 0) {
      if (*(short *)(local_c + 0xb4) != 0) {
        uVar7 = FUN_00435a73();
        uVar4 = uVar4 | uVar7;
      }
      FUN_0043f3b9();
    }
    if (param_2 != 0) {
      uVar4 = uVar4 << (8U - (char)param_2 & 0x1f);
      uVar4 = uVar4 & 0xff | uVar4 >> 8 & 0xff;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

