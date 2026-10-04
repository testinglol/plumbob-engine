
void __cdecl FUN_600194a2(int *param_1,uint *param_2,int *param_3)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  int local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64;
  uint local_40;
  int local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_14;
  int local_10;
  uint local_8;
  
  puVar3 = (undefined4 *)FUN_600011b3((byte *)(*param_1 + 10),2);
  uVar4 = FUN_600011b3((byte *)(*param_1 + 0xc),4);
  bVar7 = (uVar4 & 8) != 0;
  local_8 = (uint)bVar7;
  if (!bVar7) {
    local_8 = 1;
  }
  piVar5 = (int *)FUN_600021ef((int)puVar3 << 2);
  for (local_14 = 0; local_14 < (int)puVar3; local_14 = local_14 + 1) {
    piVar5[local_14] = param_1[1] + local_14 * 0xb;
  }
  FUN_6009ed55(piVar5,puVar3,4,FUN_6001987f);
  FUN_6009ef30();
  __ftol();
  for (local_14 = 0; local_14 < (int)puVar3; local_14 = local_14 + 1) {
    FUN_600011b3((byte *)(piVar5[local_14] + 2),1);
  }
  local_10 = 0x20;
  bVar7 = false;
  while (!bVar7) {
    local_40 = 0;
    local_38 = 0;
    local_2c = 0;
    bVar2 = false;
    local_34 = local_8;
    local_30 = local_8;
    for (local_14 = 0; local_14 < (int)puVar3; local_14 = local_14 + 1) {
      iVar1 = piVar5[local_14];
      iVar6 = FUN_600011b3((byte *)(iVar1 + 2),1);
      if (local_10 < (int)(local_34 + iVar6 + local_8)) {
        local_30 = local_30 + local_2c;
        bVar2 = true;
      }
      local_64 = FUN_600011b3((byte *)(iVar1 + 3),1);
      local_64 = local_64 + local_8;
      if (local_64 < local_2c) {
        local_64 = local_2c;
      }
      if (local_10 < (int)local_30 % local_10 + local_64) {
        bVar2 = true;
        for (; (int)local_30 % local_10 != 0; local_30 = local_30 + 1) {
        }
        local_30 = local_30 + local_8;
      }
      if (bVar2) {
        local_34 = FUN_600198c7(local_8,param_1[4]);
        local_2c = 0;
        bVar2 = false;
      }
      FUN_60001265((undefined1 *)(iVar1 + 4),local_34,2);
      FUN_60001265((undefined1 *)(iVar1 + 6),local_30,2);
      iVar6 = FUN_600011b3((byte *)(iVar1 + 2),1);
      local_34 = local_34 + iVar6 + local_8;
      iVar6 = FUN_600011b3((byte *)(iVar1 + 2),1);
      iVar6 = iVar6 + local_8;
      if ((0 < iVar6) && (iVar6 < 4)) {
        local_34 = local_34 + (4 - iVar6);
      }
      local_34 = FUN_600198c7(local_34,param_1[4]);
      iVar6 = FUN_600011b3((byte *)(iVar1 + 3),1);
      if ((int)(iVar6 + local_8) < local_2c) {
        local_68 = local_2c;
      }
      else {
        local_68 = FUN_600011b3((byte *)(iVar1 + 3),1);
        local_68 = local_68 + local_8;
      }
      local_2c = local_68;
      local_6c = local_34;
      if ((int)local_34 < (int)local_40) {
        local_6c = local_40;
      }
      local_40 = local_6c;
      if ((int)(local_30 + local_68) < local_38) {
        local_70 = local_38;
      }
      else {
        local_70 = local_30 + local_68;
      }
      local_38 = local_70;
    }
    if (((int)local_40 < local_38) && (local_10 < 0x100)) {
      if (local_10 * 2 < 0x101) {
        local_74 = local_10 << 1;
      }
      else {
        local_74 = 0x100;
      }
      local_10 = local_74;
    }
    else {
      bVar7 = true;
    }
    *param_2 = local_40;
    *param_3 = local_38;
  }
  FUN_60002200(piVar5);
  return;
}

