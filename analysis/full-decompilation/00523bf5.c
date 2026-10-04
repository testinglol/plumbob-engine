
void __fastcall FUN_00523bf5(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
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
  param_1[0x51] = 0;
  if (*(char *)((int)param_1 + 0x129) != '\0') {
    (**(code **)(*param_1 + 0x90))(0x20,0);
  }
  uVar6 = 0;
  if (param_1[0x3e] - param_1[0x3d] >> 2 != 0) {
    do {
      if (*(int *)(param_1[0x3d] + uVar6 * 4) != 0) {
        FUN_005e4b90(1);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)(param_1[0x3e] - param_1[0x3d] >> 2));
  }
  FUN_00524112();
  iVar2 = param_1[0x4b];
  if (iVar2 == 0) {
    iVar2 = FUN_004b46a0();
    (**(code **)(*param_1 + 100))(iVar2 + 0x7c);
    goto LAB_0052402c;
  }
  if (iVar2 != 1) {
    if (iVar2 != 2) goto LAB_0052402c;
    iVar2 = FUN_004b46a0();
    (**(code **)(*param_1 + 100))(iVar2 + 0x7c);
    local_10 = param_1[0x20] + -5;
    local_14 = param_1[0x1f] + -5;
    local_c = param_1[0x21] + 5;
    local_8 = param_1[0x22] + 5;
    FUN_004b469d();
    FUN_004b469d();
    cVar1 = FUN_005240ec();
    if (cVar1 == '\0') goto LAB_0052402c;
    local_14 = local_14 + 5;
    local_c = local_c + -5;
    local_10 = local_10 + 5;
    local_8 = local_8 + -5;
    piVar5 = param_1 + 0x4d;
    if ((param_1[0x20] - param_1[0x22]) + -10 + param_1[0x4d] < 0) {
      iVar3 = FUN_004b46a0();
      iVar2 = local_c;
      if ((param_1[0x22] - param_1[0x20]) + 10 + param_1[0x4f] < *(int *)(iVar3 + 0x88)) {
        local_10 = param_1[0x4f] + 5;
        goto LAB_00523d32;
      }
      local_48 = local_14;
      local_40 = local_c;
      local_18 = (param_1[0x22] - param_1[0x20]) + 5;
      if (local_18 <= *piVar5) {
        piVar5 = &local_18;
      }
      local_3c = *piVar5;
      local_38 = local_14;
      iVar3 = FUN_004b46a0();
      iVar3 = *(int *)(iVar3 + 0x88) + -5;
      piVar5 = param_1 + 0x4f;
      local_18 = (param_1[0x20] - param_1[0x22]) + iVar3;
      if (*piVar5 <= local_18) {
        piVar5 = &local_18;
      }
      local_34 = *piVar5;
      local_18 = iVar3 - local_34;
      if ((float10)(local_40 - local_48) * (float10)(local_3c + -5) <=
          (float10)(iVar2 - local_38) * (float10)local_18) {
        iVar3 = FUN_004b46a0();
        iVar2 = *param_1;
        local_8 = *(int *)(iVar3 + 0x88) + -5;
        local_10 = (param_1[0x20] - param_1[0x22]) + local_8;
      }
      else {
        iVar2 = *param_1;
        local_10 = 5;
        local_8 = (param_1[0x22] - param_1[0x20]) + 5;
      }
    }
    else {
      local_10 = (param_1[0x20] - param_1[0x22]) + -5 + param_1[0x4d];
LAB_00523d32:
      iVar2 = *param_1;
      local_8 = (param_1[0x22] - param_1[0x20]) + local_10;
    }
    (**(code **)(iVar2 + 0x60))(local_14,local_10,local_c,local_8);
    goto LAB_0052402c;
  }
  iVar3 = FUN_004b46a0();
  local_70 = *(int *)(iVar3 + 0x84);
  local_1c = -1;
  local_18 = 0;
  local_5c = *(int *)(iVar3 + 0x88);
  local_14 = param_1[0x1f];
  local_10 = param_1[0x20];
  local_c = param_1[0x21];
  iVar2 = param_1[0x22];
  local_7c = (local_5c + *(int *)(iVar3 + 0x80)) / 2;
  local_84 = 0;
  local_74 = 0;
  local_68 = 0;
  local_80 = (local_70 + *(int *)(iVar3 + 0x7c)) / 2;
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
    FUN_005de841(param_1 + 0x4c,local_24 + -1);
    local_28 = local_24[-1];
    if (local_28 < local_24[1]) {
      if ((*local_24 < local_24[2]) &&
         ((iVar3 = (local_24[1] - local_28) * (local_24[2] - *local_24), local_1c == -1 ||
          (iVar3 - local_18 != 0 && local_18 <= iVar3)))) {
        local_1c = local_20;
        local_18 = iVar3;
      }
    }
    local_20 = local_20 + 1;
    local_24 = local_24 + 4;
  } while (local_20 < 4);
  if (local_1c == -1) {
    local_1c = 0;
  }
  if (local_1c == 0) {
    iVar4 = -local_10;
    local_10 = 0;
    iVar3 = param_1[0x4d];
LAB_00523ff6:
    local_c = local_c - local_14;
    local_14 = param_1[0x4c];
    local_c = local_c + local_14;
LAB_00523ffe:
    local_10 = local_10 + iVar3;
    iVar2 = iVar2 + iVar4 + iVar3;
  }
  else {
    if (local_1c == 1) {
      iVar4 = -local_10;
      local_10 = 0;
      iVar3 = param_1[0x4d];
LAB_00523fcd:
      local_14 = local_14 - local_c;
      local_c = param_1[0x4e];
      local_14 = local_14 + local_c;
      goto LAB_00523ffe;
    }
    if (local_1c == 2) {
      iVar4 = -iVar2;
      local_10 = local_10 + iVar4;
      iVar3 = param_1[0x4f];
      goto LAB_00523ff6;
    }
    if (local_1c == 3) {
      iVar4 = -iVar2;
      local_10 = local_10 + iVar4;
      iVar3 = param_1[0x4f];
      goto LAB_00523fcd;
    }
  }
  (**(code **)(*param_1 + 0x60))(local_14,local_10,local_c,iVar2);
LAB_0052402c:
  uVar6 = 0;
  if (param_1[0x47] != 0) {
    FUN_005dadff(param_1,param_1[0x47],0);
  }
  if (param_1[0x3c] != 0) {
    FUN_00436e16();
    if (param_1[0x3e] - param_1[0x3d] >> 2 != 0) {
      do {
        piVar5 = *(int **)(param_1[0x3d] + uVar6 * 4);
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0x90))(0x2000,1);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)(param_1[0x3e] - param_1[0x3d] >> 2));
    }
    if ((int *)param_1[0x39] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x39] + 0x90))(0x2000,1);
    }
    if ((int *)param_1[0x3b] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x3b] + 0x90))(0x2000,1);
    }
    if ((int *)param_1[0x3a] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x3a] + 0x90))(0x2000,1);
    }
    (**(code **)(*param_1 + 0x90))(0x2000,1);
  }
  return;
}

