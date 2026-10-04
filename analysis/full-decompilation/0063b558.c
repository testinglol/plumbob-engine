
byte * FUN_0063b558(byte *param_1,byte *param_2,size_t param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  size_t sVar6;
  
  if (param_3 != 0) {
    if (DAT_0070513c == 0) {
      param_1 = (byte *)_strncat((char *)param_1,(char *)param_2,param_3);
    }
    else {
      FUN_0063d88b(0x19);
      pbVar5 = param_1;
      do {
        pbVar4 = pbVar5;
        pbVar5 = pbVar4 + 1;
      } while (*pbVar4 != 0);
      iVar3 = FUN_006460e8(param_1,pbVar4 + (-1 - (int)param_1));
      if (iVar3 == 1) {
        pbVar4 = pbVar4 + -1;
      }
      do {
        sVar6 = param_3 - 1;
        bVar1 = *param_2;
        bVar2 = *(byte *)((int)&DAT_00705240 + bVar1 + 1);
        *pbVar4 = bVar1;
        if ((bVar2 & 4) == 0) {
          pbVar5 = pbVar4 + 1;
          param_2 = param_2 + 1;
          param_3 = sVar6;
          if (bVar1 == 0) break;
        }
        else {
          pbVar5 = pbVar4 + 1;
          param_3 = param_3 - 2;
          if (sVar6 == 0) {
            *pbVar4 = 0;
            break;
          }
          bVar1 = param_2[1];
          *pbVar5 = bVar1;
          pbVar5 = pbVar4 + 2;
          param_2 = param_2 + 2;
          if (bVar1 == 0) {
            *pbVar4 = 0;
            break;
          }
        }
        pbVar4 = pbVar5;
      } while (param_3 != 0);
      iVar3 = FUN_006460e8(param_1,pbVar5 + (-1 - (int)param_1));
      if (iVar3 == 1) {
        pbVar5[-1] = 0;
      }
      else {
        *pbVar5 = 0;
      }
      FUN_0063d8ec(0x19);
    }
  }
  return param_1;
}

