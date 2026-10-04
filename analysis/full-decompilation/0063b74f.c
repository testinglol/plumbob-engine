
int FUN_0063b74f(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  if (DAT_0070513c == 0) {
    iVar2 = FUN_00646270(param_1,param_2);
    return iVar2;
  }
  FUN_0063d88b(0x19);
  bVar1 = *param_1;
  pbVar5 = param_1;
joined_r0x0063b77d:
  pbVar3 = param_2;
  if (bVar1 != 0) {
    do {
      if (*pbVar3 == 0) break;
      bVar1 = *pbVar3;
      if ((*(byte *)((int)&DAT_00705240 + bVar1 + 1) & 4) == 0) {
        pbVar4 = pbVar3;
        if (bVar1 == *pbVar5) goto LAB_0063b7b4;
      }
      else if (((bVar1 == *pbVar5) && (pbVar3[1] == pbVar5[1])) ||
              (pbVar4 = pbVar3 + 1, pbVar3[1] == 0)) goto LAB_0063b7b4;
      pbVar3 = pbVar4 + 1;
    } while( true );
  }
LAB_0063b7ce:
  FUN_0063d8ec(0x19);
  return (int)pbVar5 - (int)param_1;
LAB_0063b7b4:
  if ((*pbVar3 == 0) ||
     (((*(byte *)((int)&DAT_00705240 + *pbVar5 + 1) & 4) != 0 && (pbVar5 = pbVar5 + 1, *pbVar5 == 0)
      ))) goto LAB_0063b7ce;
  pbVar5 = pbVar5 + 1;
  bVar1 = *pbVar5;
  goto joined_r0x0063b77d;
}

