
undefined4 FUN_006250e0(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *local_3c;
  int local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_14;
  undefined4 *local_10;
  int local_c;
  
  puVar5 = *(undefined4 **)(param_1 + 0x14);
  puVar4 = *(undefined4 **)(*(int *)(param_1 + 0xc) + 4);
  local_20 = 0;
  local_1c = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_2c = 0;
  if (puVar5 != (undefined4 *)0x0) {
    iVar1 = *(int *)(param_1 + 0x10);
    if (0 < iVar1) {
      local_20 = *puVar5;
      local_1c = puVar5[1];
    }
    if (1 < iVar1) {
      local_28 = puVar5[2];
      local_24 = puVar5[3];
    }
    if (2 < iVar1) {
      local_30 = puVar5[4];
      local_2c = puVar5[5];
    }
  }
  if (param_3 != puVar4) {
    iVar1 = *(int *)(param_2 + 0x18) * *(int *)(param_2 + 0x10);
    local_38 = *(int *)(param_2 + 0x14);
    uVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    local_3c = param_3;
    if (0 < local_38) {
      iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 8);
      do {
        puVar5 = puVar4;
        puVar6 = local_3c;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        local_3c = (undefined4 *)((int)local_3c + param_4);
        puVar4 = (undefined4 *)((int)puVar4 + iVar1);
        local_38 = local_38 + -1;
      } while (local_38 != 0);
    }
  }
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  if (*(int *)(param_2 + 0x18) < 9) {
    FUN_00625370(&local_14,local_20,local_1c,local_28,local_24,local_30,local_2c);
    return 1;
  }
  FUN_00625260(&local_14,local_20,local_1c,local_28,local_24,local_30,local_2c);
  return 1;
}

