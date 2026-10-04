
int FUN_0063bd3e(byte *param_1,byte *param_2,size_t param_3)

{
  byte bVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  if (param_3 == 0) {
    return 0;
  }
  if (DAT_0070513c == 0) {
    iVar3 = _strncmp((char *)param_1,(char *)param_2,param_3);
    return iVar3;
  }
  FUN_0063d88b(0x19);
  sVar2 = param_3;
  do {
    param_3 = sVar2 - 1;
    uVar5 = (ushort)*param_1;
    pbVar7 = param_1 + 1;
    if ((*(byte *)((int)&DAT_00705240 + uVar5 + 1) & 4) == 0) {
LAB_0063bdbf:
      bVar1 = *param_2;
      uVar4 = (uint)(ushort)bVar1;
      pbVar6 = param_2 + 1;
      if ((*(byte *)((int)&DAT_00705240 + (ushort)bVar1 + 1) & 4) != 0) {
        if (param_3 != 0) {
          param_3 = sVar2 - 2;
          if (*pbVar6 != 0) {
            uVar4 = (uint)CONCAT11(bVar1,*pbVar6);
            pbVar6 = param_2 + 2;
            goto LAB_0063bdec;
          }
        }
        uVar4 = 0;
      }
    }
    else {
      if (param_3 != 0) {
        bVar1 = *pbVar7;
        if (bVar1 == 0) {
          uVar5 = 0;
        }
        else {
          pbVar7 = param_1 + 2;
          uVar5 = CONCAT11(*param_1,bVar1);
        }
        goto LAB_0063bdbf;
      }
      uVar4 = (uint)*param_2;
      uVar5 = 0;
      pbVar6 = param_2;
      if ((*(byte *)((int)&DAT_00705240 + uVar4 + 1) & 4) != 0) {
LAB_0063be1e:
        FUN_0063d8ec(0x19);
        return 0;
      }
    }
LAB_0063bdec:
    if (uVar5 != (ushort)uVar4) {
      FUN_0063d8ec(0x19);
      return (-(uint)((ushort)uVar4 < uVar5) & 2) - 1;
    }
    if ((uVar5 == 0) || (param_2 = pbVar6, param_1 = pbVar7, sVar2 = param_3, param_3 == 0))
    goto LAB_0063be1e;
  } while( true );
}

