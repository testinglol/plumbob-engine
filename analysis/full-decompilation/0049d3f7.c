
void __thiscall FUN_0049d3f7(int param_1,int param_2,int param_3,byte *param_4,uint param_5)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  code *local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0x37c) == 0) {
    local_14 = *(undefined4 *)(param_1 + 0x70);
  }
  else {
    local_14 = *(undefined4 *)(param_1 + 0x78);
  }
  local_18 = FUN_0049db98;
  uVar4 = (uint)*param_4;
  local_20 = ((uint)param_4[1] - (uint)param_4[3]) + 4;
  local_1c = (param_4[1] - uVar4) + 2;
  bVar2 = (byte)param_5;
  bVar3 = bVar2 + 1;
  iVar5 = (uVar4 - param_4[3]) + 2;
  local_8 = param_3 - (uVar4 << (bVar3 & 0x1f));
  uVar4 = (uint)*(byte *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0x370) == 0) {
    local_2c = (int)((*(byte *)(param_1 + 0xd) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_10 = 0;
    local_30 = uVar4 << 8;
    local_44 = (int)((*(byte *)(param_1 + 0xf) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_48 = uVar4 << 8;
    uVar4 = (uint)*(byte *)(param_1 + 0x360);
    local_3c = (int)((*(byte *)(param_1 + 0x361) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_40 = uVar4 << 8;
    local_34 = (int)((*(byte *)(param_1 + 0x363) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_c = 8 << (bVar2 & 0x1f);
    local_38 = uVar4 << 8;
    if (0 < local_c) {
      do {
        if (iVar5 != 0) {
          local_58 = local_40;
          local_4c = (local_48 - local_30) / iVar5;
          local_50 = local_30;
          local_54 = (local_38 - local_40) / iVar5;
        }
        (*local_18)(iVar5,local_14,&local_50,&local_58,param_1 + 0x18);
        local_10 = local_10 + 4;
        local_8 = local_8 - local_1c;
        local_30 = local_30 + local_2c;
        local_48 = local_48 + local_44;
        local_40 = local_40 + local_3c;
        local_38 = local_38 + local_34;
        iVar5 = iVar5 + local_20;
      } while (local_10 < local_c);
    }
  }
  else {
    local_10 = 0;
    local_2c = (int)((*(byte *)(param_1 + 0xd) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_30 = uVar4 << 8;
    local_34 = (int)((*(byte *)(param_1 + 0xf) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_38 = uVar4 << 8;
    uVar4 = (uint)*(byte *)(param_1 + 0x360);
    local_3c = (int)((*(byte *)(param_1 + 0x361) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_40 = uVar4 << 8;
    local_44 = (int)((*(byte *)(param_1 + 0x363) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_c = 8 << (bVar2 & 0x1f);
    local_48 = uVar4 << 8;
    if (0 < local_c) {
      do {
        if (iVar5 != 0) {
          local_50 = local_40;
          local_54 = (local_38 - local_30) / iVar5;
          local_58 = local_30;
          local_4c = (local_48 - local_40) / iVar5;
        }
        local_24 = local_10 + param_2;
        local_28 = param_1 + 0xe0 + (local_10 / 4) * 0x14;
        FUN_0049d914(local_28,local_24,local_8,iVar5,param_5,&local_58,&local_50);
        (*local_18)(iVar5,local_14,&local_58,&local_50,param_1 + 0x18);
        FUN_0049da72(local_28,0);
        local_10 = local_10 + 4;
        local_8 = local_8 - local_1c;
        local_30 = local_30 + local_2c;
        local_38 = local_38 + local_34;
        local_40 = local_40 + local_3c;
        local_48 = local_48 + local_44;
        iVar5 = iVar5 + local_20;
      } while (local_10 < local_c);
    }
  }
  uVar4 = (uint)param_4[2];
  local_1c = (param_4[1] - uVar4) + 2;
  iVar5 = (uVar4 - param_4[3]) + 2;
  local_8 = param_3 - (uVar4 << (bVar3 & 0x1f));
  uVar4 = (uint)*(byte *)(param_1 + 0xe);
  if (*(int *)(param_1 + 0x370) == 0) {
    local_44 = (int)((*(byte *)(param_1 + 0xd) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_48 = uVar4 << 8;
    local_3c = (int)((*(byte *)(param_1 + 0xf) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_40 = uVar4 << 8;
    uVar4 = (uint)*(byte *)(param_1 + 0x362);
    local_2c = (int)((*(byte *)(param_1 + 0x361) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_38 = uVar4 << 8;
    local_34 = (int)((*(byte *)(param_1 + 0x363) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_30 = uVar4 << 8;
    iVar6 = (0x10 << (bVar2 & 0x1f)) + -4;
    if (local_c <= iVar6) {
      param_5 = (iVar6 - local_c) + 4U >> 2;
      do {
        iVar6 = local_8;
        local_48 = local_48 + local_44;
        local_40 = local_40 + local_3c;
        local_30 = local_30 + local_2c;
        local_38 = local_38 + local_34;
        if (iVar5 != 0) {
          local_4c = (local_40 - local_48) / iVar5;
          local_54 = (local_38 - local_30) / iVar5;
          local_58 = local_30;
          local_50 = local_48;
        }
        (*local_18)(iVar5,local_14,&local_50,&local_58,param_1 + 0x18);
        local_8 = iVar6 - local_1c;
        iVar5 = iVar5 + local_20;
        param_5 = param_5 - 1;
      } while (param_5 != 0);
    }
  }
  else {
    local_3c = (int)((*(byte *)(param_1 + 0xd) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_40 = uVar4 << 8;
    local_34 = (int)((*(byte *)(param_1 + 0xf) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_38 = uVar4 << 8;
    uVar4 = (uint)*(byte *)(param_1 + 0x362);
    local_2c = (int)((*(byte *)(param_1 + 0x361) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_44 = (int)((*(byte *)(param_1 + 0x363) - uVar4) * 0x100) >> (bVar3 & 0x1f);
    local_30 = uVar4 << 8;
    local_48 = uVar4 << 8;
    iVar6 = (0x10 << (bVar2 & 0x1f)) + -4;
    if (local_c <= iVar6) {
      param_2 = param_2 + iVar6;
      do {
        local_30 = local_30 + local_2c;
        local_40 = local_40 + local_3c;
        local_38 = local_38 + local_34;
        local_48 = local_48 + local_44;
        if (iVar5 != 0) {
          local_4c = (local_38 - local_40) / iVar5;
          local_54 = (local_48 - local_30) / iVar5;
          local_58 = local_30;
          local_50 = local_40;
        }
        iVar1 = param_1 + 0xe0 + (iVar6 / 4) * 0x14;
        FUN_0049d914(iVar1,param_2,local_8,iVar5,param_5,&local_50,&local_58);
        (*local_18)(iVar5,local_14,&local_50,&local_58,param_1 + 0x18);
        FUN_0049da72(iVar1,0);
        iVar5 = iVar5 + local_20;
        local_8 = local_8 - local_1c;
        param_2 = param_2 + -4;
        iVar6 = iVar6 + -4;
      } while (local_c <= iVar6);
    }
  }
  return;
}

