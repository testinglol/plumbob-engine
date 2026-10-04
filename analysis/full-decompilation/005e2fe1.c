
undefined4 __thiscall
FUN_005e2fe1(int param_1,int param_2,undefined4 *param_3,int param_4,int param_5,undefined2 param_6,
            uint param_7)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *local_20;
  int local_1c;
  int local_18;
  undefined4 *local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  iVar6 = (int)param_3;
  if (param_3 == (undefined4 *)param_5) {
    iVar6 = param_4;
    if (param_4 < param_2) {
      iVar6 = param_2;
      param_2 = param_4;
    }
    puVar7 = (undefined4 *)
             (*(int *)(param_1 + 0x34) + ((int)param_3 * *(int *)(param_1 + 0x38) + param_2) * 2);
    iVar6 = (int)(short)(((short)iVar6 - (short)param_2) + 1);
    local_14 = (undefined4 *)((int)puVar7 + iVar6 * 2);
    for (; param_7 != 0; param_7 = param_7 - 1) {
      if (puVar7 < local_14) {
        uVar2 = (int)local_14 + (1 - (int)puVar7);
        uVar3 = uVar2 >> 1;
        puVar9 = puVar7;
        for (uVar2 = uVar2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar9 = CONCAT22(param_6,param_6);
          puVar9 = puVar9 + 1;
        }
        for (uVar2 = (uint)((uVar3 & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined2 *)puVar9 = param_6;
          puVar9 = (undefined4 *)((int)puVar9 + 2);
        }
        puVar7 = (undefined4 *)((int)puVar7 + uVar3 * 2);
      }
      puVar7 = (undefined4 *)((int)puVar7 + (*(int *)(param_1 + 0x38) - iVar6) * 2);
      local_14 = (undefined4 *)((int)puVar7 + iVar6 * 2);
    }
  }
  else if (param_2 == param_4) {
    iVar6 = param_5;
    if (param_5 < (int)param_3) {
      iVar6 = (int)param_3;
      param_3 = (undefined4 *)param_5;
    }
    puVar7 = (undefined4 *)
             (*(int *)(param_1 + 0x34) + ((int)param_3 * *(int *)(param_1 + 0x38) + param_2) * 2);
    local_14 = (undefined4 *)((int)puVar7 + param_7 * 2);
    for (iVar6 = (iVar6 - (int)param_3) + 1; iVar6 != 0; iVar6 = iVar6 + -1) {
      if (puVar7 < local_14) {
        uVar2 = (int)local_14 + (1 - (int)puVar7);
        uVar3 = uVar2 >> 1;
        puVar9 = puVar7;
        for (uVar2 = uVar2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar9 = CONCAT22(param_6,param_6);
          puVar9 = puVar9 + 1;
        }
        for (uVar2 = (uint)((uVar3 & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined2 *)puVar9 = param_6;
          puVar9 = (undefined4 *)((int)puVar9 + 2);
        }
        puVar7 = (undefined4 *)((int)puVar7 + uVar3 * 2);
      }
      puVar7 = (undefined4 *)((int)puVar7 + (*(int *)(param_1 + 0x38) - param_7) * 2);
      local_14 = (undefined4 *)((int)puVar7 + param_7 * 2);
    }
  }
  else {
    iVar4 = FUN_00636bef(param_4 - param_2);
    iVar5 = FUN_00636bef(param_5 - (int)param_3);
    bVar1 = iVar4 < iVar5;
    if (bVar1) {
      local_1c = iVar4 - iVar5;
      iVar8 = iVar4 * 2 - iVar5;
      local_18 = iVar4;
    }
    else {
      local_1c = iVar5 - iVar4;
      iVar8 = iVar5 * 2 - iVar4;
      local_18 = iVar5;
      iVar5 = iVar4;
    }
    local_14 = (undefined4 *)(iVar5 + 1);
    local_18 = local_18 * 2;
    local_1c = local_1c * 2;
    local_8 = (uint)bVar1;
    param_3 = (undefined4 *)(uint)!bVar1;
    if (param_4 < param_2) {
      param_3 = (undefined4 *)-(int)param_3;
      local_c = (undefined4 *)0xffffffff;
    }
    else {
      local_c = (undefined4 *)0x1;
    }
    if (param_5 < iVar6) {
      local_8 = -local_8;
      local_10 = 0xffffffff;
    }
    else {
      local_10 = 1;
    }
    param_5 = param_2;
    if (param_7 == 1) {
      if (0 < (int)local_14) {
        do {
          *(undefined2 *)
           (*(int *)(param_1 + 0x34) + (iVar6 * *(int *)(param_1 + 0x38) + param_5) * 2) = param_6;
          iVar5 = local_1c;
          uVar2 = local_10;
          puVar7 = local_c;
          if (iVar8 < 0) {
            iVar5 = local_18;
            uVar2 = local_8;
            puVar7 = param_3;
          }
          param_5 = param_5 + (int)puVar7;
          iVar6 = iVar6 + uVar2;
          iVar8 = iVar8 + iVar5;
          local_14 = (undefined4 *)((int)local_14 - 1);
        } while (local_14 != (undefined4 *)0x0);
        local_14 = (undefined4 *)0x0;
      }
    }
    else if (0 < (int)local_14) {
      local_20 = local_14;
      do {
        if (local_c == (undefined4 *)0xffffffff) {
          puVar7 = (undefined4 *)
                   (*(int *)(param_1 + 0x34) + 2 +
                   ((iVar6 * *(int *)(param_1 + 0x38) - param_7) + param_5) * 2);
        }
        else {
          puVar7 = (undefined4 *)
                   (*(int *)(param_1 + 0x34) + (iVar6 * *(int *)(param_1 + 0x38) + param_5) * 2);
        }
        for (uVar2 = param_7 & 0xffff; uVar2 != 0; uVar2 = uVar2 - 1) {
          if (param_7 != 0) {
            puVar9 = puVar7;
            for (uVar3 = param_7 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar9 = CONCAT22(param_6,param_6);
              puVar9 = puVar9 + 1;
            }
            for (uVar3 = (uint)((param_7 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
              *(undefined2 *)puVar9 = param_6;
              puVar9 = (undefined4 *)((int)puVar9 + 2);
            }
          }
          iVar5 = *(int *)(param_1 + 0x38);
          if (local_10 == 0xffffffff) {
            iVar5 = -iVar5;
          }
          puVar7 = (undefined4 *)((int)puVar7 + iVar5 * 2);
        }
        local_14 = local_c;
        iVar5 = local_1c;
        uVar2 = local_10;
        if (iVar8 < 0) {
          local_14 = param_3;
          iVar5 = local_18;
          uVar2 = local_8;
        }
        param_5 = param_5 + (int)local_14;
        iVar6 = iVar6 + uVar2;
        iVar8 = iVar8 + iVar5;
        local_20 = (undefined4 *)((int)local_20 - 1);
      } while (local_20 != (undefined4 *)0x0);
    }
  }
  return CONCAT31((int3)((uint)local_14 >> 8),1);
}

