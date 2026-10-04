
void FUN_004a976d(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  int local_1c;
  short local_18 [2];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  local_14._0_2_ = (short)param_2;
  local_14._2_2_ = param_2._2_2_;
  iVar4 = (int)(short)(param_2._2_2_ - (short)DAT_006f0080) / 2;
  bVar5 = (char)DAT_006f0088 + 3;
  iVar7 = (short)((short)param_2 - (short)DAT_006f0084) - iVar4 >> (bVar5 & 0x1f);
  iVar4 = (short)((short)param_2 - (short)DAT_006f0084) + iVar4 >> (bVar5 & 0x1f);
  FUN_004a9e60(&local_14,iVar4,iVar7,param_3,DAT_006f0088,0);
  local_8 = (uint)(param_2._2_2_ <= local_14._2_2_);
  iVar6 = iVar4;
  local_1c = iVar7;
  while ((iVar6 < 0 || (local_1c < 0))) {
    uVar2 = local_8 & 1;
    local_8 = local_8 + 1;
    if (uVar2 == 0) {
      iVar6 = iVar6 + 1;
    }
    else {
      local_1c = local_1c + 1;
    }
  }
  local_10 = *(int *)(DAT_006e54d8 + 0x74) + 1;
  local_14 = *(int *)(DAT_006e54d8 + 0x7c) + 1;
  if ((iVar6 < local_10) && (local_1c < local_14)) {
    while( true ) {
      uVar2 = local_8 & 1;
      local_8 = local_8 + 1;
      if (uVar2 == 0) {
        iVar6 = iVar6 + 1;
        bVar8 = SBORROW4(iVar6,local_10);
        iVar1 = iVar6 - local_10;
      }
      else {
        local_1c = local_1c + 1;
        bVar8 = SBORROW4(local_1c,local_14);
        iVar1 = local_1c - local_14;
      }
      if (bVar8 == iVar1 < 0) break;
      FUN_004a9e60(local_18,iVar6,local_1c,param_3,DAT_006f0088,0);
      if (local_18[0] < (short)param_2) {
        iVar4 = iVar6;
        iVar7 = local_1c;
      }
    }
  }
  while( true ) {
    while( true ) {
      FUN_004a9e60(&local_8,iVar4,iVar7,param_3,DAT_006f0088,0);
      sVar3 = local_8._2_2_;
      if (local_8._2_2_ <= param_2._2_2_) break;
      FUN_004a9e60(&local_10,iVar4,iVar7 + 1,param_3,DAT_006f0088,0);
      if ((((int)(short)local_8 - (int)(short)param_2) * 0x10000) /
          ((int)sVar3 - (int)param_2._2_2_) <=
          (((int)(short)local_8 - (int)(short)local_10) * 0x10000) /
          ((int)sVar3 - (int)local_10._2_2_)) goto LAB_004a993b;
      iVar4 = iVar4 + -1;
    }
    if (param_2._2_2_ == local_8._2_2_) break;
    FUN_004a9e60(&local_14,iVar4 + 1,iVar7,param_3,DAT_006f0088,0);
    if ((((int)(short)local_8 - (int)(short)local_14) * 0x10000) /
        ((int)sVar3 - (int)local_14._2_2_) <=
        (((int)(short)local_8 - (int)(short)param_2) * 0x10000) / ((int)sVar3 - (int)param_2._2_2_))
    break;
    iVar7 = iVar7 + -1;
  }
LAB_004a993b:
  *param_1 = iVar4;
  param_1[1] = iVar7;
  return;
}

