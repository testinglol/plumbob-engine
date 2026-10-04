
int FUN_005b81e0(byte *param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = 0;
  if (*param_1 != 0) {
    param_2 = param_2 - (int)param_1;
    do {
      bVar2 = param_1[param_2];
      if (bVar2 == 0) {
        return iVar4;
      }
      bVar3 = *param_1;
      if ((bVar3 < 0x41) || (0x5a < bVar3)) {
        uVar5 = (uint)bVar3;
      }
      else {
        uVar5 = bVar3 + 0x20;
      }
      if ((bVar2 < 0x41) || (0x5a < bVar2)) {
        uVar6 = (uint)bVar2;
      }
      else {
        uVar6 = bVar2 + 0x20;
      }
      if (uVar5 != uVar6) {
        return iVar4;
      }
      pbVar1 = param_1 + 1;
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
    } while (*pbVar1 != 0);
  }
  return iVar4;
}

