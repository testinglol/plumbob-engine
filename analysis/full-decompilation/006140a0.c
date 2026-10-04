
int FUN_006140a0(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int local_24;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar1 = *param_1;
  local_24 = 0;
  param_1 = (int *)0x0;
  uVar5 = 999999;
  pbVar3 = (byte *)(iVar1 + 0x2a);
  while( true ) {
    local_8 = (uint)pbVar3[1];
    local_c = (uint)*pbVar3;
    local_10 = (uint)pbVar3[-1];
    local_14 = (uint)pbVar3[-2];
    iVar6 = (param_2 & 0xff) - local_14;
    iVar7 = (param_2 >> 8 & 0xff) - local_10;
    iVar4 = (param_2 >> 0x10 & 0xff) - local_c;
    iVar1 = (param_2 >> 0x18) - local_8;
    uVar2 = iVar1 * iVar1 + iVar4 * iVar4 + iVar7 * iVar7 + iVar6 * iVar6;
    if (uVar2 < uVar5) {
      local_24 = (int)param_1;
      uVar5 = uVar2;
    }
    if (uVar2 == 0) break;
    param_1 = (int *)((int)param_1 + 1);
    pbVar3 = pbVar3 + 4;
    if (0xff < (int)param_1) {
      return local_24;
    }
  }
  return local_24;
}

