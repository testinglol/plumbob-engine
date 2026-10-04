
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_005def85(uint param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  double dVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined8 local_24;
  undefined8 local_1c;
  undefined8 local_14;
  undefined8 local_c;
  
  iVar9 = *param_4;
  iVar1 = param_4[1];
  iVar2 = param_4[2];
  iVar3 = param_4[3];
  local_c = (double)CONCAT44(iVar3,(int)local_c);
  local_44 = *param_3;
  bVar6 = false;
  local_28 = param_3[1];
  local_24 = (double)CONCAT44(iVar9,(int)local_24);
  local_2c = param_3[2];
  local_30 = param_3[3];
  iVar7 = iVar2 - *(int *)(param_1 + 0x1c);
  local_1c = (double)CONCAT44(iVar1,(int)local_1c);
  local_14 = (double)CONCAT44(iVar2,(int)local_14);
  local_4c = iVar2;
  if (0 < iVar7) {
    local_4c = iVar2 - iVar7;
    if (local_4c <= iVar9) goto LAB_005df1e9;
    bVar6 = true;
  }
  iVar7 = -iVar9;
  local_54 = iVar9;
  if (0 < iVar7) {
    local_54 = 0;
    if (local_4c < 1) goto LAB_005df1e9;
    bVar6 = true;
  }
  iVar7 = iVar3 - *(int *)(param_1 + 0x20);
  local_48 = iVar3;
  if (0 < iVar7) {
    local_48 = iVar3 - iVar7;
    if (local_48 <= iVar1) goto LAB_005df1e9;
    bVar6 = true;
  }
  iVar7 = -iVar1;
  local_50 = iVar1;
  if (0 < iVar7) {
    local_50 = 0;
    if (local_48 < 1) goto LAB_005df1e9;
    bVar6 = true;
  }
  if (param_5 != (int *)0x0) {
    if (0 < local_4c - param_5[2]) {
      local_4c = local_4c - (local_4c - param_5[2]);
      bVar6 = true;
    }
    if (0 < *param_5 - local_54) {
      local_54 = local_54 + (*param_5 - local_54);
      bVar6 = true;
    }
    if (0 < local_48 - param_5[3]) {
      local_48 = local_48 - (local_48 - param_5[3]);
      bVar6 = true;
    }
    iVar7 = param_5[1] - local_50;
    if (0 < iVar7) {
      local_50 = local_50 + iVar7;
      bVar6 = true;
    }
  }
  if ((local_54 < local_4c) && (local_50 < local_48)) {
    local_40 = local_28;
    local_3c = local_2c;
    local_38 = local_30;
    if (bVar6) {
      dVar5 = (double)(local_2c - local_44) / (double)(iVar2 - iVar9);
      fVar4 = (float)(local_30 - local_28) / (float)(iVar3 - iVar1);
      local_c = (double)(local_48 - iVar3) * (double)fVar4 + _DAT_00673d40;
      local_14 = (double)(local_4c - iVar2) * dVar5 + _DAT_00673d40;
      local_1c = (double)(local_50 - iVar1) * (double)fVar4 + _DAT_00673d40;
      local_24 = (double)(local_54 - iVar9) * dVar5 + _DAT_00673d40;
      local_44 = local_44 + -0x80000000 + (int)local_24;
      local_40 = local_28 + -0x80000000 + (int)local_1c;
      local_3c = local_2c + -0x80000000 + (int)local_14;
      local_38 = local_30 + -0x80000000 + (int)local_c;
      if (local_44 == local_3c) {
        if (local_44 == 0) {
          local_3c = local_3c + 1;
        }
        else {
          local_44 = local_44 + -1;
        }
      }
      if (local_40 == local_38) {
        if (local_40 == 0) {
          local_38 = local_38 + 1;
        }
        else {
          local_40 = local_40 + -1;
        }
      }
      if ((*(uint *)(param_2 + 0x28) & 4) != 0) {
        iVar9 = *(int *)(param_2 + 0x1c) - local_3c;
        local_3c = *(int *)(param_2 + 0x1c) - local_44;
        local_44 = iVar9;
      }
      if ((*(uint *)(param_2 + 0x28) & 8) != 0) {
        iVar9 = *(int *)(param_2 + 0x20) - local_38;
        local_38 = *(int *)(param_2 + 0x20) - local_40;
        local_40 = iVar9;
      }
    }
    if (*(int **)(param_1 + 0x48) != (int *)0x0) {
      local_34 = param_1;
      uVar8 = (**(code **)(**(int **)(param_1 + 0x48) + 0x1c))
                        (*(undefined4 *)(param_2 + 0x48),&local_44,&local_54);
      return uVar8;
    }
    return param_1 & 0xffffff00;
  }
LAB_005df1e9:
  return CONCAT31((int3)((uint)iVar7 >> 8),1);
}

