
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_005ea6b0(int *param_1)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int local_4c;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  (**(code **)(*param_1 + 0xc))();
  iVar3 = param_1[0x3b];
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  piVar1 = param_1 + 0x45;
  if (iVar3 != 0) {
    *piVar1 = *(int *)(iVar3 + 0x1c);
    param_1[0x46] = *(int *)(iVar3 + 0x20);
  }
  iVar3 = *piVar1 / -2;
  local_18 = param_1[0x46];
  iVar4 = local_18 / -2;
  param_1[0x43] = iVar3;
  param_1[0x44] = iVar4;
  if (param_1[0x58] == 0) {
    if (param_1[0x3b] == 0) {
      param_1[0x58] = 8;
    }
    else {
      piVar5 = param_1 + 0x46;
      if (param_1[0x46] <= *piVar1) {
        piVar5 = piVar1;
      }
      local_28 = *piVar5 / 2;
      local_24 = 1;
      piVar6 = &local_28;
      if (*piVar5 / 2 < 2) {
        piVar6 = &local_24;
      }
      param_1[0x58] = *piVar6;
    }
  }
  iVar10 = param_1[0x5b];
  local_10 = iVar3 - iVar10;
  local_1c = iVar10 + iVar3 + *piVar1;
  local_14 = iVar4 - iVar10;
  local_20 = iVar10 + iVar4 + local_18;
  iVar3 = *(int *)param_1[0x39];
  uVar7 = FUN_005d49d6();
  uVar7 = FUN_004096c2(uVar7);
  (**(code **)(iVar3 + 0x50))(&local_3c,uVar7);
  iVar4 = (local_34 + 3) - (local_3c + -3);
  iVar10 = (local_30 + 3) - (local_38 + -3);
  param_1[0x49] = iVar4;
  local_28 = iVar4 / -2;
  param_1[0x4a] = iVar10;
  param_1[0x47] = local_28;
  iVar3 = iVar10 / -2;
  param_1[0x48] = iVar3;
  if (local_28 < local_10) {
    local_10 = local_28;
  }
  if (iVar3 < local_14) {
    local_14 = iVar3;
  }
  if (local_1c < iVar4 + local_28) {
    local_1c = iVar4 + local_28;
  }
  if (local_20 < iVar3 + iVar10) {
    local_20 = iVar3 + iVar10;
  }
  uVar8 = (param_1[0x65] - param_1[100]) / 0x28;
  iVar3 = 2;
  if (uVar8 == 0) {
    param_1[0x56] = 1;
  }
  else {
    if ((2 < uVar8) && (iVar3 = 4, 4 < uVar8)) {
      iVar3 = 8;
    }
    param_1[0x56] = iVar3;
  }
  local_c = 0;
  if ((param_1[0x65] - param_1[100]) / 0x28 != 0) {
    local_28 = 0;
    do {
      iVar3 = 0;
      local_24 = param_1[100] + local_28;
      iVar4 = *(int *)(local_24 + 0xc);
      if (iVar4 == 0) {
        iVar3 = *(int *)param_1[0x39];
        uVar7 = FUN_005d49d6();
        uVar7 = FUN_004096c2(uVar7);
        (**(code **)(iVar3 + 0x50))(&local_3c,uVar7);
        local_4c = local_3c + -3;
        iVar3 = local_38 + -3;
        local_8 = local_34 + 3;
        local_18 = local_30 + 3;
      }
      else {
        local_8 = *(int *)(iVar4 + 0x84) - *(int *)(iVar4 + 0x7c);
        local_4c = 0;
        local_18 = *(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80);
      }
      local_8 = local_8 - local_4c;
      local_18 = local_18 - iVar3;
      iVar3 = 0;
      uVar8 = param_1[0x56];
      if (uVar8 <= local_c) {
        uVar8 = local_c - uVar8;
        if ((uVar8 & 1) == 0) {
          if (uVar8 == 0) {
            uVar8 = param_1[0x57] & 7;
          }
          else {
            uVar8 = local_c - 2;
          }
          fVar2 = _DAT_00674b4c * _DAT_00666ccc;
          iVar3 = *(int *)(param_1[100] + 0x1c + uVar8 * 0x28) - local_18;
          iVar4 = local_8 / -2;
        }
        else {
          if (uVar8 == 1) {
            uVar8 = param_1[0x57] - 4U & 7;
          }
          else {
            uVar8 = local_c - 2;
          }
          iVar3 = param_1[100] + uVar8 * 0x28;
          iVar3 = *(int *)(iVar3 + 0x24) + *(int *)(iVar3 + 0x1c);
          iVar4 = local_8 / -2;
          fVar2 = _DAT_00674b4c;
        }
        goto LAB_005eaa9f;
      }
      if (uVar8 == 1) {
        uVar9 = 0;
      }
      else if (uVar8 == 2) {
        uVar9 = local_c << 2;
      }
      else if (uVar8 == 4) {
        uVar9 = local_c * 2;
      }
      else {
        uVar9 = 0;
        if (uVar8 == 8) {
          uVar9 = local_c;
        }
      }
      uVar8 = param_1[0x57] + uVar9 & 7;
      local_2c = 2 - uVar8;
      fVar2 = _DAT_00674b4c * _DAT_00666a48 * (float)local_2c;
      if (fVar2 < (float)_DAT_006669e8) {
        do {
          fVar2 = _DAT_00674b4c + _DAT_00674b4c + fVar2;
        } while (fVar2 < (float)_DAT_006669e8);
      }
      iVar4 = 0;
      switch(uVar8) {
      case 0:
        iVar4 = local_8 / -2;
        iVar3 = param_1[0x61] + local_18;
        goto code_r0x005eaa9d;
      case 1:
        iVar4 = param_1[0x62];
        iVar3 = iVar4 + local_18;
        goto code_r0x005eaa9d;
      case 2:
        iVar4 = param_1[0x61];
        goto code_r0x005eaa7d;
      case 3:
        iVar3 = param_1[0x62];
        iVar4 = iVar3;
        break;
      case 4:
        iVar3 = param_1[0x61];
        iVar4 = local_8 / -2;
        break;
      case 5:
        iVar3 = param_1[0x62];
        iVar4 = -(iVar3 + local_8);
        break;
      case 6:
        iVar4 = -(param_1[0x61] + local_8);
code_r0x005eaa7d:
        iVar3 = local_18 / -2;
        break;
      case 7:
        iVar4 = -(param_1[0x62] + local_8);
        iVar3 = param_1[0x62] + local_18;
code_r0x005eaa9d:
        iVar3 = -iVar3;
      }
LAB_005eaa9f:
      *(float *)(local_24 + 0x14) = fVar2;
      *(int *)(local_24 + 0x18) = iVar4;
      *(int *)(local_24 + 0x1c) = iVar3;
      *(int *)(local_24 + 0x20) = local_8;
      *(int *)(local_24 + 0x24) = local_18;
      if (iVar4 < local_10) {
        local_10 = iVar4;
      }
      if (iVar3 < local_14) {
        local_14 = iVar3;
      }
      if (local_1c < iVar4 + local_8) {
        local_1c = iVar4 + local_8;
      }
      if (local_20 < iVar3 + local_18) {
        local_20 = iVar3 + local_18;
      }
      local_c = local_c + 1;
      local_28 = local_28 + 0x28;
    } while (local_c < (uint)((param_1[0x65] - param_1[100]) / 0x28));
  }
  local_10 = local_10 + -4;
  local_14 = local_14 + -4;
  iVar3 = -local_10;
  param_1[0x43] = param_1[0x43] + iVar3;
  param_1[0x47] = param_1[0x47] + iVar3;
  iVar4 = -local_14;
  param_1[0x44] = param_1[0x44] + iVar4;
  param_1[0x48] = param_1[0x48] + iVar4;
  param_1[0x4d] = iVar3;
  param_1[0x4e] = iVar4;
  param_1[0x51] = (local_1c - local_10) + 4;
  param_1[0x52] = (local_20 - local_14) + 4;
  uVar8 = 0;
  if ((param_1[0x65] - param_1[100]) / 0x28 != 0) {
    iVar3 = 0;
    do {
      piVar1 = (int *)(param_1[100] + 0x18 + iVar3);
      *piVar1 = *piVar1 + param_1[0x4d];
      piVar1 = (int *)(param_1[100] + 0x1c + iVar3);
      *piVar1 = *piVar1 + param_1[0x4e];
      uVar8 = uVar8 + 1;
      iVar3 = iVar3 + 0x28;
    } while (uVar8 < (uint)((param_1[0x65] - param_1[100]) / 0x28));
  }
  (**(code **)(*param_1 + 0x168))();
  return 1;
}

