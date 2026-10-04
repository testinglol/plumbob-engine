
int FUN_006148c0(byte *param_1,int *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_20;
  int local_1c;
  
  pbVar1 = param_1 + 2;
  pbVar2 = param_1 + 3;
  bVar4 = *param_1;
  pbVar3 = param_1 + 1;
  local_1c = 0;
  if (param_2[3] != 0) {
    return (uint)*(byte *)(param_2[3] + ((uint)(*pbVar1 >> 2) * 0x40 + (uint)(*pbVar3 >> 2)) * 0x40
                          + (uint)(bVar4 >> 2)) + *param_2;
  }
  pbVar5 = (byte *)param_2[2];
  param_1 = (byte *)0x7fffffff;
  local_20 = 0;
  if (0 < param_2[1]) {
    do {
      if (param_1 == (byte *)0x0) break;
      iVar7 = (uint)*pbVar3 - (uint)pbVar5[1];
      iVar8 = (uint)*pbVar1 - (uint)pbVar5[2];
      iVar6 = (uint)bVar4 - (uint)*pbVar5;
      iVar6 = ((uint)*pbVar2 - (uint)pbVar5[3]) * ((uint)*pbVar2 - (uint)pbVar5[3]) * 0x10 +
              iVar8 * iVar8 + iVar7 * iVar7 + iVar6 * iVar6;
      if (iVar6 < (int)param_1) {
        local_1c = local_20;
        param_1 = (byte *)iVar6;
      }
      local_20 = local_20 + 1;
      pbVar5 = pbVar5 + 4;
    } while (local_20 < param_2[1]);
  }
  return *param_2 + local_1c;
}

