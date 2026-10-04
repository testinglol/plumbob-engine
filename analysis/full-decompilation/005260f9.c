
void __fastcall FUN_005260f9(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  undefined4 local_74;
  int local_70;
  int local_6c;
  undefined4 local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_28;
  int *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_005dde53();
  FUN_004f778b();
  uVar2 = FUN_005e74ca(3);
  FUN_005dde6d(uVar2);
  param_1[0x4e] = 0;
  (**(code **)(*param_1 + 0x90))(0x20,0);
  uVar7 = 0;
  if (param_1[0x3e] - param_1[0x3d] >> 2 != 0) {
    do {
      if (*(int *)(param_1[0x3d] + uVar7 * 4) != 0) {
        FUN_005e4b90(1);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < (uint)(param_1[0x3e] - param_1[0x3d] >> 2));
  }
  FUN_00526547();
  iVar3 = param_1[0x48];
  if (iVar3 == 0) {
    iVar3 = FUN_004b46a0();
    (**(code **)(*param_1 + 100))(iVar3 + 0x7c);
    return;
  }
  if (iVar3 != 1) {
    if (iVar3 != 2) {
      return;
    }
    iVar3 = FUN_004b46a0();
    (**(code **)(*param_1 + 100))(iVar3 + 0x7c);
    local_10 = param_1[0x20] + -5;
    local_14 = param_1[0x1f] + -5;
    local_c = param_1[0x21] + 5;
    local_8 = param_1[0x22] + 5;
    FUN_004b469d();
    FUN_004b469d();
    cVar1 = FUN_005240ec();
    if (cVar1 == '\0') {
      return;
    }
    local_14 = local_14 + 5;
    local_c = local_c + -5;
    local_10 = local_10 + 5;
    local_8 = local_8 + -5;
    piVar6 = param_1 + 0x4a;
    if ((param_1[0x20] - param_1[0x22]) + -10 + param_1[0x4a] < 0) {
      iVar4 = FUN_004b46a0();
      iVar3 = local_c;
      if (*(int *)(iVar4 + 0x88) <= (param_1[0x22] - param_1[0x20]) + 10 + param_1[0x4c]) {
        local_48 = local_14;
        local_40 = local_c;
        local_18 = (param_1[0x22] - param_1[0x20]) + 5;
        if (local_18 <= *piVar6) {
          piVar6 = &local_18;
        }
        local_3c = *piVar6;
        local_38 = local_14;
        iVar4 = FUN_004b46a0();
        iVar4 = *(int *)(iVar4 + 0x88) + -5;
        piVar6 = param_1 + 0x4c;
        local_18 = (param_1[0x20] - param_1[0x22]) + iVar4;
        if (*piVar6 <= local_18) {
          piVar6 = &local_18;
        }
        local_34 = *piVar6;
        local_18 = iVar4 - local_34;
        if ((float10)(local_40 - local_48) * (float10)(local_3c + -5) <=
            (float10)(iVar3 - local_38) * (float10)local_18) {
          iVar4 = FUN_004b46a0();
          iVar3 = *param_1;
          local_8 = *(int *)(iVar4 + 0x88) + -5;
          local_10 = (param_1[0x20] - param_1[0x22]) + local_8;
        }
        else {
          iVar3 = *param_1;
          local_10 = 5;
          local_8 = (param_1[0x22] - param_1[0x20]) + 5;
        }
        goto LAB_00526346;
      }
      local_10 = param_1[0x4c] + 5;
    }
    else {
      local_10 = (param_1[0x20] - param_1[0x22]) + -5 + param_1[0x4a];
    }
    iVar3 = *param_1;
    local_8 = (param_1[0x22] - param_1[0x20]) + local_10;
LAB_00526346:
    (**(code **)(iVar3 + 0x60))(local_14,local_10,local_c,local_8);
    return;
  }
  iVar4 = FUN_004b46a0();
  local_70 = *(int *)(iVar4 + 0x84);
  local_1c = -1;
  local_18 = 0;
  local_5c = *(int *)(iVar4 + 0x88);
  local_14 = param_1[0x1f];
  local_10 = param_1[0x20];
  local_c = param_1[0x21];
  iVar3 = param_1[0x22];
  local_7c = (local_5c + *(int *)(iVar4 + 0x80)) / 2;
  local_84 = 0;
  local_74 = 0;
  local_68 = 0;
  local_80 = (local_70 + *(int *)(iVar4 + 0x7c)) / 2;
  local_20 = 0;
  local_24 = &local_84;
  local_78 = local_80;
  local_6c = local_7c;
  local_64 = local_7c;
  local_60 = local_80;
  local_58 = local_80;
  local_54 = local_7c;
  local_50 = local_70;
  local_4c = local_5c;
  local_2c = local_5c;
  do {
    FUN_005de841(param_1 + 0x49,local_24 + -1);
    local_28 = local_24[-1];
    if (local_28 < local_24[1]) {
      if ((*local_24 < local_24[2]) &&
         ((iVar4 = (local_24[1] - local_28) * (local_24[2] - *local_24), local_1c == -1 ||
          (iVar4 - local_18 != 0 && local_18 <= iVar4)))) {
        local_1c = local_20;
        local_18 = iVar4;
      }
    }
    local_20 = local_20 + 1;
    local_24 = local_24 + 4;
  } while (local_20 < 4);
  if (local_1c == -1) {
    local_1c = 0;
  }
  if (local_1c == 0) {
    iVar5 = -local_10;
    local_10 = 0;
    iVar4 = param_1[0x4a];
LAB_0052650c:
    local_c = local_c - local_14;
    local_14 = param_1[0x49];
    local_c = local_c + local_14;
  }
  else {
    if (local_1c == 1) {
      iVar5 = -local_10;
      local_10 = 0;
      iVar4 = param_1[0x4a];
    }
    else {
      if (local_1c == 2) {
        iVar5 = -iVar3;
        local_10 = local_10 + iVar5;
        iVar4 = param_1[0x4c];
        goto LAB_0052650c;
      }
      if (local_1c != 3) goto LAB_00526519;
      iVar5 = -iVar3;
      local_10 = local_10 + iVar5;
      iVar4 = param_1[0x4c];
    }
    local_14 = local_14 - local_c;
    local_c = param_1[0x4b];
    local_14 = local_14 + local_c;
  }
  local_10 = local_10 + iVar4;
  iVar3 = iVar3 + iVar5 + iVar4;
LAB_00526519:
  (**(code **)(*param_1 + 0x60))(local_14,local_10,local_c,iVar3);
  return;
}

