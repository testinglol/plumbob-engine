
uint FUN_0063c63c(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  if (DAT_0070513c == 0) {
    iVar2 = FUN_00646270(param_1,param_2);
    uVar3 = (uint)(param_1 + iVar2) & -(uint)(param_1[iVar2] != 0);
  }
  else {
    FUN_0063d88b(0x19);
    bVar1 = *param_1;
    while (bVar1 != 0) {
      bVar1 = *param_2;
      pbVar4 = param_2;
      while (bVar1 != 0) {
        bVar1 = *pbVar4;
        if ((*(byte *)((int)&DAT_00705240 + bVar1 + 1) & 4) == 0) {
          pbVar5 = pbVar4;
          if (bVar1 == *param_1) break;
        }
        else if (((bVar1 == *param_1) && (pbVar4[1] == param_1[1])) ||
                (pbVar5 = pbVar4 + 1, pbVar4[1] == 0)) break;
        pbVar4 = pbVar5 + 1;
        bVar1 = *pbVar4;
      }
      if ((*pbVar4 == 0) ||
         (((*(byte *)((int)&DAT_00705240 + *param_1 + 1) & 4) != 0 &&
          (param_1 = param_1 + 1, *param_1 == 0)))) break;
      param_1 = param_1 + 1;
      bVar1 = *param_1;
    }
    FUN_0063d8ec(0x19);
    uVar3 = -(uint)(*param_1 != 0) & (uint)param_1;
  }
  return uVar3;
}

