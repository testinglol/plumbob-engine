
byte * FUN_0063b977(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (DAT_0070513c == 0) {
    param_1 = (byte *)__strrev((char *)param_1);
  }
  else {
    FUN_0063d88b(0x19);
    pbVar3 = param_1;
    while (pbVar2 = pbVar3, pbVar3 = pbVar2, pbVar4 = param_1, *pbVar2 != 0) {
      pbVar3 = pbVar2 + 1;
      if ((*(byte *)((int)&DAT_00705240 + *pbVar2 + 1) & 4) != 0) {
        if (*pbVar3 == 0) break;
        bVar1 = *pbVar2;
        *pbVar2 = *pbVar3;
        *pbVar3 = bVar1;
        pbVar3 = pbVar2 + 2;
      }
    }
    for (; pbVar3 = pbVar3 + -1, pbVar4 < pbVar3; pbVar4 = pbVar4 + 1) {
      bVar1 = *pbVar4;
      *pbVar4 = *pbVar3;
      *pbVar3 = bVar1;
    }
    FUN_0063d8ec(0x19);
  }
  return param_1;
}

