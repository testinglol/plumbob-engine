
byte * FUN_0063c3a6(byte *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  
  if (DAT_0070513c == 0) {
    param_1 = (byte *)_strncpy((char *)param_1,(char *)param_2,param_3);
  }
  else {
    FUN_0063d88b(0x19);
    uVar5 = 0;
    pbVar6 = param_1;
    do {
      while( true ) {
        pbVar3 = pbVar6;
        pbVar6 = pbVar3;
        if (param_3 == 0) goto LAB_0063c40d;
        bVar1 = *param_2;
        uVar5 = param_3 - 1;
        bVar2 = *(byte *)((int)&DAT_00705240 + bVar1 + 1);
        *pbVar3 = bVar1;
        param_3 = uVar5;
        if ((bVar2 & 4) == 0) break;
        bVar1 = param_2[1];
        pbVar3[1] = bVar1;
        pbVar6 = pbVar3 + 2;
        param_2 = param_2 + 2;
        if (bVar1 == 0) {
          *pbVar3 = 0;
          goto LAB_0063c40d;
        }
      }
      pbVar6 = pbVar3 + 1;
      param_2 = param_2 + 1;
    } while (bVar1 != 0);
LAB_0063c40d:
    if (uVar5 != 0) {
      for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        pbVar6[0] = 0;
        pbVar6[1] = 0;
        pbVar6[2] = 0;
        pbVar6[3] = 0;
        pbVar6 = pbVar6 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pbVar6 = 0;
        pbVar6 = pbVar6 + 1;
      }
    }
    FUN_0063d8ec(0x19);
  }
  return param_1;
}

