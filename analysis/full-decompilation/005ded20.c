
undefined1 __thiscall FUN_005ded20(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  undefined1 local_5;
  
  piVar2 = param_4;
  local_c = param_1;
  if (param_1[0x11] == 3) {
    cVar3 = (**(code **)(*param_1 + 0x20))(0x40);
    if ((cVar3 != '\0') && (cVar3 = (**(code **)(*param_2 + 0x20))(0x40), cVar3 != '\0')) {
      iVar9 = *param_3;
      iVar1 = param_3[1];
      local_10 = (**(code **)(*param_2 + 0xd0))();
      iVar5 = (**(code **)(*param_2 + 0xcc))();
      iVar10 = local_10 * iVar1 + iVar9 + iVar5;
      iVar9 = param_4[1];
      iVar1 = *param_4;
      iVar5 = (**(code **)(*local_c + 0xd0))();
      iVar6 = (**(code **)(*local_c + 0xcc))();
      param_4 = (int *)0x0;
      puVar8 = (undefined1 *)(iVar5 * iVar9 + iVar1 + iVar6);
      if (piVar2[3] != piVar2[1] && -1 < piVar2[3] - piVar2[1]) {
        do {
          param_3 = (int *)0x0;
          if (piVar2[2] != *piVar2 && -1 < piVar2[2] - *piVar2) {
            puVar7 = puVar8;
            do {
              param_3 = (int *)((int)param_3 + 1);
              *puVar7 = puVar7[iVar10 - (int)puVar8];
              puVar7 = puVar7 + 1;
            } while ((int)param_3 < piVar2[2] - *piVar2);
          }
          param_4 = (int *)((int)param_4 + 1);
          puVar8 = puVar8 + iVar5;
          iVar10 = iVar10 + local_10;
        } while ((int)param_4 < piVar2[3] - piVar2[1]);
      }
      (**(code **)(*local_c + 0x24))(0x40);
      (**(code **)(*param_2 + 0x24))(0x40);
    }
  }
  else {
    local_5 = 0;
    local_20 = *param_3;
    local_1c = param_3[1];
    local_18 = param_3[2];
    local_14 = param_3[3];
    local_2c = param_4[1];
    local_28 = param_4[2];
    local_30 = *param_4;
    local_24 = param_4[3];
    iVar9 = local_28 - param_1[7];
    if (0 < iVar9) {
      local_18 = local_18 - iVar9;
      local_28 = local_28 - iVar9;
      if (local_28 <= local_30) {
        return 1;
      }
    }
    if (0 < -local_30) {
      local_20 = local_20 + -local_30;
      local_30 = 0;
      if (local_28 < 1) {
        return 1;
      }
    }
    iVar9 = local_24 - param_1[8];
    if (0 < iVar9) {
      local_14 = local_14 - iVar9;
      local_24 = local_24 - iVar9;
      if (local_24 <= local_2c) {
        return 1;
      }
    }
    iVar9 = -local_2c;
    if (0 < iVar9) {
      local_2c = 0;
      local_1c = local_1c + iVar9;
      if (local_24 < 1) {
        return 1;
      }
    }
    if (param_5 != (int *)0x0) {
      iVar9 = local_28 - param_5[2];
      if (0 < iVar9) {
        local_28 = local_28 - iVar9;
        local_18 = local_18 - iVar9;
      }
      iVar9 = *param_5 - local_30;
      if (0 < iVar9) {
        local_30 = local_30 + iVar9;
        local_20 = local_20 + iVar9;
      }
      iVar9 = local_24 - param_5[3];
      if (0 < iVar9) {
        local_24 = local_24 - iVar9;
        local_14 = local_14 - iVar9;
      }
      iVar9 = param_5[1] - local_2c;
      if (0 < iVar9) {
        local_2c = local_2c + iVar9;
        local_1c = local_1c + iVar9;
      }
    }
    if ((local_30 < local_28) && (local_2c < local_24)) {
      if (((int *)param_1[0x12] != (int *)0x0) && (param_2[0x12] != 0)) {
        uVar4 = (**(code **)(*(int *)param_1[0x12] + 0x1c))(param_2[0x12],&local_20,&local_30);
        return uVar4;
      }
      if (param_2[0x13] != 0) {
        uVar4 = FUN_00606395(param_1,&local_30,&local_20);
        return uVar4;
      }
      return 0;
    }
  }
  return 1;
}

