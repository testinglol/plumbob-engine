
void __thiscall FUN_004a5031(int param_1,int param_2,int param_3,byte *param_4,byte param_5)

{
  undefined4 uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_c;
  uint local_8;
  
  pbVar2 = param_4;
  uVar11 = 0x10 << (param_5 & 0x1f);
  local_24 = uVar11;
  if ((int)DAT_006f0bc6 < (int)(uVar11 + param_2)) {
    local_24 = DAT_006f0bc6 - param_2 & 0xfffc;
  }
  if (param_2 < DAT_006f0bc2) {
    local_14 = (DAT_006f0bc2 - param_2) + 3U & 0xfffc;
  }
  else {
    local_14 = 0;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  uVar12 = (uint)*param_4;
  iVar3 = ((uint)param_4[1] - (uint)param_4[3]) + 4;
  iVar8 = (param_4[1] - uVar12) + 2;
  param_4 = (byte *)(((local_14 / 4) * iVar3 - (uint)param_4[3]) + 2 + uVar12);
  uVar13 = (uint)*(byte *)(param_1 + 0xc);
  iVar14 = (((int)local_14 / -4) * iVar8 - (uVar12 << (param_5 + 1 & 0x1f))) + param_3;
  iVar4 = (int)((*(byte *)(param_1 + 0xd) - uVar13) * 0x100) >> (param_5 + 1 & 0x1f);
  iVar5 = (int)((*(byte *)(param_1 + 0xf) - uVar13) * 0x100) >> (param_5 + 1 & 0x1f);
  local_20 = (int)(iVar4 * local_14) / 4 + uVar13 * 0x100;
  local_8 = local_14;
  iVar6 = (int)(iVar5 * local_14) / 4 + uVar13 * 0x100;
  if ((int)local_14 < (int)local_24) {
    do {
      if (8 << (param_5 & 0x1f) <= (int)local_8) break;
      if (param_4 == (byte *)0x0) {
        local_18 = 0;
      }
      else {
        local_18 = (iVar6 - local_20) / (int)param_4;
      }
      iVar9 = (int)DAT_006f0bc0;
      local_1c = (int)param_4;
      iVar15 = local_20;
      local_c = iVar14;
      if (iVar14 < iVar9) {
        local_1c = (iVar14 - iVar9) + (int)param_4;
        iVar15 = (iVar9 - iVar14) * local_18 + local_20;
        local_c = iVar9;
      }
      if ((int)DAT_006f0bc4 < local_c + local_1c) {
        local_1c = DAT_006f0bc4 - local_c;
      }
      FUN_004a4fba(local_1c,uVar1,iVar15,local_18,local_c,local_8 + param_2);
      local_8 = local_8 + 4;
      param_4 = (byte *)((int)param_4 + iVar3);
      local_20 = local_20 + iVar4;
      iVar6 = iVar6 + iVar5;
      iVar14 = iVar14 - iVar8;
    } while ((int)local_8 < (int)local_24);
  }
  uVar12 = (uint)pbVar2[2];
  iVar4 = (pbVar2[1] - uVar12) + 2;
  iVar5 = uVar11 - local_24;
  param_4 = (byte *)(((iVar5 / 4) * iVar3 - (uint)pbVar2[3]) + 2 + uVar12);
  bVar7 = param_5 + 1;
  param_3 = (param_3 - (iVar5 / 4) * iVar4) - (uVar12 << (bVar7 & 0x1f));
  uVar11 = (uint)*(byte *)(param_1 + 0xe);
  iVar15 = (int)((*(byte *)(param_1 + 0xd) - uVar11) * 0x100) >> (bVar7 & 0x1f);
  iVar8 = (int)((*(byte *)(param_1 + 0xf) - uVar11) * 0x100) >> (bVar7 & 0x1f);
  iVar14 = (iVar5 * iVar15) / 4 + uVar11 * 0x100;
  local_8 = local_24 - 4;
  iVar6 = 8 << (param_5 & 0x1f);
  iVar5 = (iVar5 * iVar8) / 4 + uVar11 * 0x100;
  if (iVar6 <= (int)local_8) {
    _param_5 = param_2 + local_8;
    do {
      if ((int)local_8 < (int)local_14) {
        return;
      }
      iVar5 = iVar5 + iVar8;
      iVar14 = iVar14 + iVar15;
      local_c = param_3;
      if (param_4 == (byte *)0x0) {
        local_18 = 0;
      }
      else {
        local_18 = (iVar5 - iVar14) / (int)param_4;
      }
      iVar10 = (int)DAT_006f0bc0;
      local_1c = (int)param_4;
      iVar9 = iVar14;
      if (param_3 < iVar10) {
        local_1c = (param_3 - iVar10) + (int)param_4;
        iVar9 = (iVar10 - param_3) * local_18 + iVar14;
        local_c = iVar10;
      }
      if ((int)DAT_006f0bc4 < local_c + local_1c) {
        local_1c = DAT_006f0bc4 - local_c;
      }
      FUN_004a4fba(local_1c,uVar1,iVar9,local_18,local_c,_param_5);
      local_8 = local_8 + -4;
      param_3 = param_3 - iVar4;
      param_4 = (byte *)((int)param_4 + iVar3);
      _param_5 = _param_5 + -4;
    } while (iVar6 <= (int)local_8);
  }
  return;
}

