
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004e5c2f(undefined4 param_1,int *param_2,int param_3,int *param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = param_4[2];
  local_8 = param_4[3];
  local_14 = *param_4;
  local_10 = param_4[1];
  iVar2 = local_8 - local_10;
  iVar7 = local_c - local_14;
  if (iVar2 < iVar7) {
    iVar2 = *param_2;
    iVar3 = ((iVar2 - local_c) + local_14) / 2;
    iVar5 = ((iVar2 + iVar3 * -2) - local_c) + local_14;
    if (iVar7 < iVar2) {
      local_c = local_c + iVar3;
      local_14 = local_14 - iVar3;
      if (0 < iVar5) {
        local_c = local_c + iVar5;
      }
    }
    goto LAB_004e5cfc;
  }
  if (iVar7 < iVar2) {
    iVar7 = param_2[1];
    iVar3 = ((iVar7 - local_8) + local_10) / 2;
    iVar5 = ((iVar7 + iVar3 * -2) - local_8) + local_10;
    if (iVar7 <= iVar2) goto LAB_004e5cfc;
    local_8 = local_8 + iVar3;
    local_10 = local_10 - iVar3;
    if (iVar5 < 1) goto LAB_004e5cfc;
  }
  else {
    iVar2 = *param_2;
    iVar3 = ((iVar2 - local_c) + local_14) / 2;
    iVar5 = ((iVar2 + iVar3 * -2) - local_c) + local_14;
    if (iVar2 <= iVar7) goto LAB_004e5cfc;
    local_c = local_c + iVar3;
    local_8 = local_8 + iVar3;
    local_10 = local_10 - iVar3;
    local_14 = local_14 - iVar3;
    if (iVar5 < 1) goto LAB_004e5cfc;
    local_c = local_c + iVar5;
  }
  local_8 = local_8 + iVar5;
LAB_004e5cfc:
  uVar6 = ((local_10 - local_8) - local_14) + local_c;
  if ((int)uVar6 < 1) {
    if ((int)uVar6 < 0) {
      local_c = local_c - (int)uVar6 / 2;
      local_14 = local_14 + (int)uVar6 / 2;
      if ((uVar6 & 1) != 0) {
        local_c = local_c + 1;
      }
    }
  }
  else {
    local_8 = local_8 + (int)uVar6 / 2;
    local_10 = local_10 - (int)uVar6 / 2;
    if ((uVar6 & 1) != 0) {
      local_8 = local_8 + 1;
    }
  }
  if (local_14 < 0) {
    local_14 = 0;
  }
  if (param_3 <= local_c) {
    local_c = param_3 + -1;
  }
  if (local_10 < 0) {
    local_10 = 0;
  }
  if (param_3 <= local_8) {
    local_8 = param_3 + -1;
  }
  fVar1 = (float)*param_2 / (float)(local_c - local_14);
  if ((local_14 < local_c) && (local_10 < local_8)) {
    if (_DAT_00666748 < fVar1) {
      fVar1 = 1.0;
    }
    uVar4 = FUN_004ba969(fVar1,param_1,&local_14,0);
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

