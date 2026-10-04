
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f280(undefined4 param_1,float param_2,float param_3,undefined1 *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_64;
  int local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  undefined1 local_50;
  undefined1 uStack_4f;
  byte bStack_4e;
  byte local_48;
  undefined1 uStack_47;
  byte bStack_46;
  undefined1 local_40;
  undefined1 uStack_3f;
  byte bStack_3e;
  byte bStack_3d;
  byte local_38;
  undefined1 uStack_37;
  byte bStack_36;
  byte bStack_35;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  float local_14;
  float local_c;
  float local_8;
  float local_4;
  
  local_5c = 1;
  bVar4 = true;
  iVar6 = __ftol();
  iVar7 = __ftol();
  iVar8 = iVar6 + 1;
  if (param_2 < (float)_DAT_006669e8) {
    iVar8 = iVar6 + -1;
  }
  iVar9 = iVar7 + 1;
  if (param_3 < (float)_DAT_006669e8) {
    iVar9 = iVar7 + -1;
  }
  FUN_0060f950(param_1,iVar6,iVar7,&local_58,&local_50);
  FUN_0060f950(param_1,iVar8,iVar7,&local_64,&local_48);
  FUN_0060f950(param_1,iVar6,iVar9,&local_54,&local_40);
  FUN_0060f950(param_1,iVar8,iVar9,&local_60,&local_38);
  fVar1 = param_2 - (float)iVar6;
  if (param_2 < (float)_DAT_006669e8) {
    fVar1 = _DAT_00666748 - fVar1;
  }
  fVar2 = param_3 - (float)iVar7;
  if (param_3 < (float)_DAT_006669e8) {
    fVar2 = _DAT_00666748 - fVar2;
  }
  if (local_58 == 0) {
    if (local_64 == 0) {
      local_c = 0.0;
      local_8 = 0.0;
      local_4 = 0.0;
      local_5c = 0;
    }
    else {
      local_c = (float)bStack_46;
      local_8 = (float)(CONCAT11(bStack_46,uStack_47) & 0xff);
      local_58 = CONCAT12(bStack_46,CONCAT11(uStack_47,local_48)) & 0xff;
      local_4 = (float)local_58;
    }
  }
  else if (local_64 == 0) {
    local_c = (float)bStack_4e;
    local_8 = (float)(CONCAT11(bStack_4e,uStack_4f) & 0xff);
    local_58 = CONCAT12(bStack_4e,CONCAT11(uStack_4f,local_50)) & 0xff;
    local_4 = (float)local_58;
  }
  else {
    fVar3 = _DAT_00666748 - fVar1;
    local_c = (float)bStack_4e * fVar3 + (float)bStack_46 * fVar1;
    local_58 = CONCAT12(bStack_4e,CONCAT11(uStack_4f,local_50)) & 0xff;
    local_8 = (float)(CONCAT11(bStack_4e,uStack_4f) & 0xff) * fVar3 +
              (float)(CONCAT11(bStack_46,uStack_47) & 0xff) * fVar1;
    local_4 = (float)local_58 * fVar3 + (float)local_48 * fVar1;
  }
  if (local_54 == 0) {
    if (local_60 == 0) {
      local_30 = 0.0;
      local_2c = 0.0;
      local_28 = 0.0;
      local_24 = 0.0;
      bVar4 = false;
    }
    else {
      local_30 = (float)bStack_35;
      local_2c = (float)bStack_36;
      local_54 = CONCAT12(bStack_36,CONCAT11(uStack_37,local_38)) & 0xff;
      local_28 = (float)(CONCAT11(bStack_36,uStack_37) & 0xff);
      local_24 = (float)local_54;
    }
  }
  else if (local_60 == 0) {
    local_30 = (float)bStack_3d;
    local_2c = (float)bStack_3e;
    local_54 = CONCAT12(bStack_3e,CONCAT11(uStack_3f,local_40)) & 0xff;
    local_28 = (float)(CONCAT11(bStack_3e,uStack_3f) & 0xff);
    local_24 = (float)local_54;
  }
  else {
    fVar3 = _DAT_00666748 - fVar1;
    local_30 = (float)bStack_3d * fVar3 + (float)bStack_35 * fVar1;
    local_2c = (float)bStack_3e * fVar3 + (float)bStack_36 * fVar1;
    local_54 = CONCAT12(bStack_3e,CONCAT11(uStack_3f,local_40)) & 0xff;
    local_28 = (float)(CONCAT11(bStack_3e,uStack_3f) & 0xff) * fVar3 +
               (float)(CONCAT11(bStack_36,uStack_37) & 0xff) * fVar1;
    local_24 = (float)local_54 * fVar3 + (float)local_38 * fVar1;
  }
  if (local_5c == 0) {
    if (bVar4) {
      local_1c = local_2c;
      local_18 = local_28;
      local_14 = local_24;
    }
    else {
      local_1c = 0.0;
      local_18 = 0.0;
      local_14 = 0.0;
    }
  }
  else if (bVar4) {
    fVar1 = _DAT_00666748 - fVar2;
    local_1c = local_2c * fVar2 + fVar1 * local_c;
    local_18 = local_28 * fVar2 + fVar1 * local_8;
    local_14 = local_24 * fVar2 + fVar1 * local_4;
  }
  else {
    local_1c = local_c;
    local_18 = local_8;
    local_14 = local_4;
  }
  uVar5 = __ftol();
  param_4[3] = uVar5;
  uVar5 = __ftol();
  param_4[2] = uVar5;
  uVar5 = __ftol();
  fVar1 = (float)_DAT_006683b0;
  param_4[1] = uVar5;
  if (local_14 <= fVar1) {
    if ((float)_DAT_006669e8 <= local_14) {
      uVar5 = __ftol();
      *param_4 = uVar5;
      return;
    }
    uVar5 = __ftol();
    *param_4 = uVar5;
    return;
  }
  uVar5 = __ftol();
  *param_4 = uVar5;
  return;
}

