
int FUN_0063bc76(byte *param_1,byte *param_2,size_t param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  if (param_3 != 0) {
    if (DAT_0070513c == 0) {
      iVar3 = _strncmp((char *)param_1,(char *)param_2,param_3);
      return iVar3;
    }
    FUN_0063d88b(0x19);
    do {
      param_3 = param_3 - 1;
      uVar4 = (ushort)*param_1;
      pbVar7 = param_1 + 1;
      if ((*(byte *)((int)&DAT_00705240 + uVar4 + 1) & 4) != 0) {
        bVar1 = *pbVar7;
        if (bVar1 == 0) {
          uVar4 = 0;
        }
        else {
          pbVar7 = param_1 + 2;
          uVar4 = CONCAT11(*param_1,bVar1);
        }
      }
      bVar1 = *param_2;
      uVar5 = (ushort)bVar1;
      pbVar6 = param_2 + 1;
      if ((*(byte *)((int)&DAT_00705240 + bVar1 + 1) & 4) != 0) {
        bVar2 = *pbVar6;
        if (bVar2 == 0) {
          uVar5 = 0;
        }
        else {
          pbVar6 = param_2 + 2;
          uVar5 = CONCAT11(bVar1,bVar2);
        }
      }
      if (uVar4 != uVar5) {
        FUN_0063d8ec(0x19);
        return (-(uint)(uVar5 < uVar4) & 2) - 1;
      }
    } while ((uVar4 != 0) && (param_2 = pbVar6, param_1 = pbVar7, param_3 != 0));
    FUN_0063d8ec(0x19);
  }
  return 0;
}

