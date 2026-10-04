
void __thiscall FUN_0049dc44(int param_1,int param_2,int param_3,byte *param_4,undefined4 param_5)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c;
  code *local_28;
  undefined4 local_24;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  pbVar1 = param_4;
  if (*(int *)(param_1 + 0x37c) == 0) {
    local_24 = *(undefined4 *)(param_1 + 0x70);
  }
  else {
    local_24 = *(undefined4 *)(param_1 + 0x78);
  }
  local_28 = FUN_0049db98;
  bVar5 = (byte)param_5;
  local_34 = 0x10 << (bVar5 & 0x1f);
  local_14 = local_34;
  if ((int)DAT_006f0bc6 < (int)(local_34 + param_2)) {
    local_14 = DAT_006f0bc6 - param_2 & 0xfffc;
  }
  if (param_2 < DAT_006f0bc2) {
    local_10 = (DAT_006f0bc2 - param_2) + 3U & 0xfffc;
  }
  else {
    local_10 = 0;
  }
  uVar7 = (uint)*param_4;
  local_1c = ((uint)param_4[1] - (uint)param_4[3]) + 4;
  local_18 = (param_4[1] - uVar7) + 2;
  uVar2 = local_10 / 4;
  param_4 = (byte *)((uVar2 * local_1c - (uint)param_4[3]) + 2 + uVar7);
  uVar3 = (uint)*(byte *)(param_1 + 0xc);
  iVar8 = (((int)local_10 / -4) * local_18 - (uVar7 << (bVar5 + 1 & 0x1f))) + param_3;
  bVar4 = bVar5 + 1;
  local_3c = (int)((*(byte *)(param_1 + 0xd) - uVar3) * 0x100) >> (bVar4 & 0x1f);
  local_4c = (int)((*(byte *)(param_1 + 0xf) - uVar3) * 0x100) >> (bVar4 & 0x1f);
  uVar7 = (uint)*(byte *)(param_1 + 0x360);
  local_44 = (int)((*(byte *)(param_1 + 0x361) - uVar7) * 0x100) >> (bVar4 & 0x1f);
  local_54 = (int)((*(byte *)(param_1 + 0x363) - uVar7) * 0x100) >> (bVar4 & 0x1f);
  local_40 = uVar3 * 0x100 + local_3c * uVar2;
  local_50 = uVar3 * 0x100 + local_4c * uVar2;
  local_48 = uVar7 * 0x100 + local_44 * uVar2;
  local_58 = uVar7 * 0x100 + local_54 * uVar2;
  local_20 = local_14;
  local_38 = 8 << (bVar5 & 0x1f);
  if ((int)local_38 < (int)local_14) {
    local_20 = local_38;
  }
  for (local_8 = local_10; (int)local_8 < (int)local_20; local_8 = local_8 + 4) {
    if (param_4 != (byte *)0x0) {
      local_64 = (local_50 - local_40) / (int)param_4;
      local_68 = local_40;
      local_5c = (local_58 - local_48) / (int)param_4;
      local_60 = local_48;
    }
    local_2c = local_8 + param_2;
    local_30 = param_1 + 0xe0 + ((int)local_8 / 4) * 0x14;
    local_c = iVar8;
    FUN_0049d914(local_30,local_2c,iVar8,param_4,param_5,&local_68,&local_60);
    iVar6 = (int)param_4;
    if (iVar8 < DAT_006f0bc0) {
      iVar6 = DAT_006f0bc0 - iVar8;
      local_68 = local_68 + local_64 * iVar6;
      local_60 = local_60 + local_5c * iVar6;
      local_c = (int)DAT_006f0bc0;
      iVar6 = (int)param_4 - iVar6;
    }
    if ((int)DAT_006f0bc4 < local_c + iVar6) {
      iVar6 = DAT_006f0bc4 - local_c;
    }
    (*local_28)(iVar6,local_24,&local_68,&local_60,param_1 + 0x18);
    FUN_0049da72(local_30,1);
    iVar8 = iVar8 - local_18;
    param_4 = (byte *)((int)param_4 + local_1c);
    local_40 = local_40 + local_3c;
    local_50 = local_50 + local_4c;
    local_48 = local_48 + local_44;
    local_58 = local_58 + local_54;
  }
  uVar2 = (uint)pbVar1[2];
  local_18 = (pbVar1[1] - uVar2) + 2;
  iVar8 = (int)(local_34 - local_14) / 4;
  param_4 = (byte *)((iVar8 * local_1c - (uint)pbVar1[3]) + 2 + uVar2);
  bVar5 = bVar5 + 1;
  param_3 = (param_3 - ((int)(local_34 - local_14) / 4) * local_18) - (uVar2 << (bVar5 & 0x1f));
  uVar2 = (uint)*(byte *)(param_1 + 0xe);
  local_44 = (int)((*(byte *)(param_1 + 0xd) - uVar2) * 0x100) >> (bVar5 & 0x1f);
  local_54 = (int)((*(byte *)(param_1 + 0xf) - uVar2) * 0x100) >> (bVar5 & 0x1f);
  uVar3 = (uint)*(byte *)(param_1 + 0x362);
  local_3c = (int)((*(byte *)(param_1 + 0x361) - uVar3) * 0x100) >> (bVar5 & 0x1f);
  iVar6 = uVar2 * 0x100 + local_44 * iVar8;
  local_58 = uVar2 * 0x100 + local_54 * iVar8;
  local_4c = (int)((*(byte *)(param_1 + 0x363) - uVar3) * 0x100) >> (bVar5 & 0x1f);
  iVar9 = uVar3 * 0x100 + local_3c * iVar8;
  local_50 = uVar3 * 0x100 + local_4c * iVar8;
  local_20 = local_10;
  if ((int)local_10 < (int)local_38) {
    local_20 = local_38;
  }
  local_8 = local_14 - 4;
  if ((int)local_20 <= (int)local_8) {
    param_2 = local_8 + param_2;
    do {
      iVar6 = iVar6 + local_44;
      local_58 = local_58 + local_54;
      iVar9 = iVar9 + local_3c;
      local_50 = local_50 + local_4c;
      local_c = param_3;
      if (param_4 != (byte *)0x0) {
        local_5c = (local_58 - iVar6) / (int)param_4;
        local_64 = (local_50 - iVar9) / (int)param_4;
        local_68 = iVar9;
        local_60 = iVar6;
      }
      local_34 = param_1 + 0xe0 + ((int)local_8 / 4) * 0x14;
      FUN_0049d914(local_34,param_2,param_3,param_4,param_5,&local_60,&local_68);
      iVar8 = (int)param_4;
      if (param_3 < DAT_006f0bc0) {
        local_38 = DAT_006f0bc0 - param_3;
        local_60 = local_60 + local_5c * local_38;
        local_68 = local_68 + local_64 * local_38;
        local_c = (int)DAT_006f0bc0;
        iVar8 = (int)param_4 - local_38;
      }
      if ((int)DAT_006f0bc4 < local_c + iVar8) {
        iVar8 = DAT_006f0bc4 - local_c;
      }
      (*local_28)(iVar8,local_24,&local_60,&local_68,param_1 + 0x18);
      FUN_0049da72(local_34,1);
      local_8 = local_8 + -4;
      param_3 = param_3 - local_18;
      param_4 = (byte *)((int)param_4 + local_1c);
      param_2 = param_2 + -4;
    } while ((int)local_20 <= (int)local_8);
  }
  return;
}

