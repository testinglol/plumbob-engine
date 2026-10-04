
byte * FUN_0063c436(byte *param_1,int param_2,size_t param_3)

{
  bool bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  bVar1 = false;
  if (DAT_0070513c == 0) {
    pbVar3 = (byte *)__strnset((char *)param_1,param_2,param_3);
    return pbVar3;
  }
  FUN_0063d88b(0x19);
  bVar2 = (byte)((uint)param_2 >> 8);
  if (bVar2 == 0) {
    pbVar3 = param_1;
    if (param_3 == 0) goto LAB_0063c50f;
    do {
      param_3 = param_3 - 1;
      if (*pbVar3 == 0) break;
      if ((bVar1) || ((*(byte *)((int)&DAT_00705240 + *pbVar3 + 1) & 4) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      *pbVar3 = (byte)param_2;
      pbVar3 = pbVar3 + 1;
    } while (param_3 != 0);
  }
  else {
    pbVar4 = param_1;
    if (param_3 == 0) goto LAB_0063c50f;
    do {
      param_3 = param_3 - 1;
      pbVar3 = pbVar4;
      if (*pbVar4 == 0) break;
      if ((bVar1) || ((*(byte *)((int)&DAT_00705240 + *pbVar4 + 1) & 4) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      *pbVar4 = bVar2;
      pbVar3 = pbVar4 + 1;
      if (pbVar4[1] == 0) {
        *pbVar4 = 0x20;
      }
      else {
        if ((bVar1) || ((*(byte *)((int)&DAT_00705240 + pbVar4[1] + 1) & 4) == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        *pbVar3 = (byte)param_2;
        pbVar3 = pbVar4 + 2;
      }
      pbVar4 = pbVar3;
    } while (param_3 != 0);
  }
  if ((bVar1) && (*pbVar3 != 0)) {
    *pbVar3 = 0x20;
  }
LAB_0063c50f:
  FUN_0063d8ec(0x19);
  return param_1;
}

