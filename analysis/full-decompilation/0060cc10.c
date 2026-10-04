
undefined1 FUN_0060cc10(byte *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int local_14;
  int local_10;
  int local_c;
  
  uVar1 = (uint)param_1[3];
  local_14 = 0x7fffffff;
  local_c = 0;
  local_10 = 0;
  if (param_2 < 1) {
    return 0;
  }
  pbVar6 = (byte *)(param_3 + 2);
  do {
    if (local_14 == 0) {
      return (undefined1)local_c;
    }
    uVar3 = (uint)pbVar6[1];
    iVar4 = (uVar1 - uVar3) * 4;
    if (-1 < iVar4) {
      iVar4 = (uVar1 - uVar3) * 0x10;
    }
    iVar5 = ((int)(*param_1 * uVar1) >> 8) - ((int)(pbVar6[-2] * uVar3) >> 8);
    iVar7 = ((int)(param_1[1] * uVar1) >> 8) - ((int)(pbVar6[-1] * uVar3) >> 8);
    iVar2 = ((int)(param_1[2] * uVar1) >> 8) - ((int)(*pbVar6 * uVar3) >> 8);
    iVar4 = iVar2 * iVar2 + iVar7 * iVar7 + iVar5 * iVar5 + iVar4 * iVar4;
    if (iVar4 < local_14) {
      local_c = local_10;
      local_14 = iVar4;
    }
    local_10 = local_10 + 1;
    pbVar6 = pbVar6 + 4;
  } while (local_10 < param_2);
  return (undefined1)local_c;
}

