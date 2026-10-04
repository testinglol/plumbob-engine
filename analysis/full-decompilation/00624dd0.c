
undefined4 FUN_00624dd0(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_30;
  int local_2c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = *(int *)(param_2 + 0x10);
  local_30 = *(undefined4 **)(*(int *)(param_1 + 0xc) + 4);
  iVar2 = *(int *)(param_2 + 0x18);
  iVar3 = iVar2 * iVar1;
  puVar6 = *(undefined4 **)(param_1 + 0x14);
  uVar4 = (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3;
  local_10 = 0;
  local_c = 0;
  local_18 = 0;
  local_14 = 0;
  if (puVar6 != (undefined4 *)0x0) {
    if (0 < *(int *)(param_1 + 0x10)) {
      local_10 = *puVar6;
      local_c = puVar6[1];
    }
    if (1 < *(int *)(param_1 + 0x10)) {
      local_18 = puVar6[2];
      local_14 = puVar6[3];
    }
  }
  local_2c = *(int *)(param_2 + 0x14);
  if (0 < local_2c) {
    iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    do {
      puVar6 = local_30;
      puVar7 = param_3;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      if (iVar2 == 0x20) {
        FUN_00624c20(param_3,iVar1,local_10,local_c,local_18,local_14);
      }
      local_30 = (undefined4 *)((int)local_30 + iVar3);
      param_3 = (undefined4 *)((int)param_3 + param_4);
      local_2c = local_2c + -1;
    } while (local_2c != 0);
  }
  return 1;
}

