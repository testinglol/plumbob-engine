
char FUN_00646330(byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  
  iVar2 = DAT_00705360;
  if (DAT_00703bec == 0) {
    bVar5 = 0xff;
    do {
      do {
        if (bVar5 == 0) {
          return '\0';
        }
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
  }
  else {
    LOCK();
    DAT_00705360 = DAT_00705360 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_0070535c;
    if (bVar1) {
      LOCK();
      UNLOCK();
      DAT_00705360 = iVar2;
      FUN_0063d88b(0x13);
    }
    uVar7 = (uint)bVar1;
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_006463df;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      bVar4 = FUN_006381a9(bVar4,bVar5);
      bVar5 = FUN_006381a9();
    } while (bVar4 == bVar5);
    cVar6 = (bVar4 < bVar5) * -2 + '\x01';
LAB_006463df:
    if (uVar7 == 0) {
      LOCK();
      DAT_00705360 = DAT_00705360 + -1;
      UNLOCK();
    }
    else {
      FUN_0063d8ec(0x13);
    }
  }
  return cVar6;
}

