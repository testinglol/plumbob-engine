
undefined4 __thiscall FUN_005c9346(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int local_10;
  int *local_c;
  char local_6;
  char local_5;
  
  local_6 = '\0';
  local_10 = 0;
  local_14 = 0;
  *(char *)param_2 = '\0';
  local_5 = '\x01';
  FUN_005cab9b();
  local_c = (int *)(*(int *)(param_1 + 0x4b4) - *(int *)(param_1 + 0x4b0) >> 4);
  if (*(char *)(param_1 + 0x4e1) != '\0') {
    local_28 = *(int *)(param_1 + 0x4e4);
    local_24 = *(int *)(param_1 + 0x4e8);
    local_20 = *(int *)(param_1 + 0x4ec);
    local_1c = *(int *)(param_1 + 0x4f0);
    local_58 = *(int *)(param_1 + 0x4f4);
    local_54 = *(int *)(param_1 + 0x4f8);
    local_50 = *(int *)(param_1 + 0x4fc);
    local_4c = *(int *)(param_1 + 0x500);
    local_10 = local_58 - local_28;
    local_14 = local_54 - local_24;
    if (*(char *)param_2 == '\0') {
      if (*(int *)(param_1 + 0x11c) == 0) {
        iVar3 = *(int *)(param_1 + 0x18);
        iVar1 = *(int *)(param_1 + 0x1c);
        local_28 = local_28 + iVar3;
        local_20 = local_20 + iVar3;
        local_58 = local_58 + iVar3;
        local_50 = local_50 + iVar3;
        local_24 = local_24 + iVar1;
        local_1c = local_1c + iVar1;
        local_54 = local_54 + iVar1;
        local_4c = local_4c + iVar1;
        FUN_004a7901();
        FUN_004a7901();
        iVar3 = param_1 + 0xe8;
      }
      else {
        local_28 = local_28 + *(int *)(param_1 + 0x18);
        local_20 = local_20 + *(int *)(param_1 + 0x18);
        local_24 = local_24 + *(int *)(param_1 + 0x1c);
        local_1c = local_1c + *(int *)(param_1 + 0x1c);
        FUN_004a7901();
        iVar3 = param_1 + 0x118;
      }
      local_5 = FUN_005c8cc4(iVar3,&local_58,param_1 + 0xe8,&local_28);
      if (local_5 == '\0') {
        *(char *)param_2 = '\x01';
        *(int *)(param_1 + 0x508) = local_28;
        *(int *)(param_1 + 0x50c) = local_24;
        *(int *)(param_1 + 0x510) = local_20;
        *(int *)(param_1 + 0x514) = local_1c;
        *(int *)(param_1 + 0x518) = local_58;
        *(int *)(param_1 + 0x51c) = local_54;
        param_2 = *(int **)(param_1 + 0x4b0);
        *(undefined4 *)(param_1 + 0x504) = *(undefined4 *)(param_1 + 4);
        *(int *)(param_1 + 0x520) = local_50;
        *(int *)(param_1 + 0x524) = local_4c;
        local_c = *(int **)(param_1 + 0x4b4);
        local_5 = 0;
        if (param_2 != local_c) {
          do {
            local_48 = *param_2 + local_10;
            local_40 = param_2[2] + local_10;
            local_44 = param_2[1] + local_14;
            local_3c = param_2[3] + local_14;
            FUN_004a7901();
            FUN_005cddcf(&local_48);
            param_2 = param_2 + 4;
          } while (param_2 != local_c);
        }
        goto LAB_005c9817;
      }
    }
    iVar3 = *(int *)(param_1 + 4);
    *(undefined1 *)(param_1 + 0x4e1) = 0;
    *(int *)(param_1 + 0x504) = iVar3;
    local_6 = '\x01';
    if (iVar3 != 0) {
      *(int *)(param_1 + 0x504) = iVar3;
      *(undefined4 *)(param_1 + 0x508) = 0x7fff;
      *(undefined4 *)(param_1 + 0x510) = 0xffff8001;
      *(undefined4 *)(param_1 + 0x50c) = 0x7fff;
      *(undefined4 *)(param_1 + 0x514) = 0xffff8001;
      *(undefined4 *)(param_1 + 0x518) = 0x7fff;
      *(undefined4 *)(param_1 + 0x520) = 0xffff8001;
      *(undefined4 *)(param_1 + 0x51c) = 0x7fff;
      *(undefined4 *)(param_1 + 0x524) = 0xffff8001;
    }
  }
  *(int **)(param_1 + 0x57c) = local_c;
  if (local_c != (int *)0x0) {
    local_c = *(int **)(param_1 + 0x4b0);
    local_18 = *(int **)(param_1 + 0x4b4);
    if (local_c != local_18) {
      do {
        local_38 = *local_c;
        local_34 = local_c[1];
        local_30 = local_c[2];
        local_2c = local_c[3];
        if ((local_38 < local_30) && (local_34 < local_2c)) {
          local_58 = local_38;
          local_54 = local_34;
          local_50 = local_30;
          local_4c = local_2c;
          if (*(char *)(param_1 + 8) == '\0') {
            if (*(char *)param_2 != '\0') goto LAB_005c9678;
            if (*(int *)(param_1 + 0x11c) == 0) {
              local_58 = local_38 + *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20);
              local_54 = local_34 + *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24);
              local_50 = local_30 + *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20);
              local_4c = local_2c + *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24);
              goto LAB_005c9647;
            }
            if (*(char *)(param_1 + 0x10) == '\0') {
              if (local_5 != '\0') {
                cVar2 = FUN_005c8cc4(param_1 + 0x118,&local_58,param_1 + 0x100,&local_38);
                goto LAB_005c960d;
              }
            }
            else if (local_5 != '\0') {
              cVar2 = FUN_005c8d94(param_1 + 0x118,&local_58,param_1 + 0x100,&local_38);
LAB_005c960d:
              if (cVar2 != '\0') goto LAB_005c966e;
            }
            local_5 = '\0';
LAB_005c967e:
            *(char *)param_2 = '\x01';
          }
          else if (*(char *)param_2 == '\0') {
LAB_005c9647:
            if ((local_5 == '\0') ||
               (cVar2 = FUN_005c8cc4(param_1 + 0xe8,&local_58,param_1 + 0x100,&local_38),
               cVar2 == '\0')) {
              local_5 = '\0';
              goto LAB_005c9678;
            }
LAB_005c966e:
            local_5 = '\x01';
          }
          else {
LAB_005c9678:
            if (local_5 == '\0') goto LAB_005c967e;
          }
          if (*(char *)param_2 != '\0') {
            if (local_6 != '\0') {
              local_38 = local_38 + local_10;
              local_30 = local_30 + local_10;
              local_34 = local_34 + local_14;
              local_2c = local_2c + local_14;
              FUN_004a7901();
            }
            FUN_005cddcf(&local_38);
          }
          local_c = local_c + 4;
        }
        else {
          *(int *)(param_1 + 0x57c) = *(int *)(param_1 + 0x57c) + -1;
        }
      } while (local_c != local_18);
    }
    if ((*(char *)param_2 == '\0') && (*(int *)(param_1 + 0x11c) != 0)) {
      local_48 = *(int *)(param_1 + 0x28);
      local_44 = *(int *)(param_1 + 0x2c);
      local_28 = *(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20);
      local_20 = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20);
      local_24 = *(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24);
      local_1c = *(int *)(param_1 + 0x34) + *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24);
      local_40 = *(int *)(param_1 + 0x30);
      local_3c = *(int *)(param_1 + 0x34);
      FUN_004a7901();
      iVar3 = *(int *)(param_1 + 0x18);
      iVar1 = *(int *)(param_1 + 0x1c);
      local_28 = local_28 + -iVar3 + -*(int *)(param_1 + 0x20);
      local_20 = local_20 + -iVar3 + -*(int *)(param_1 + 0x20);
      local_48 = local_48 + iVar3 + *(int *)(param_1 + 0x20);
      local_40 = local_40 + iVar3 + *(int *)(param_1 + 0x20);
      local_24 = local_24 + -iVar1 + -*(int *)(param_1 + 0x24);
      local_1c = local_1c + -iVar1 + -*(int *)(param_1 + 0x24);
      local_44 = local_44 + iVar1 + *(int *)(param_1 + 0x24);
      local_3c = local_3c + iVar1 + *(int *)(param_1 + 0x24);
      FUN_004a7901();
      if ((local_5 == '\0') ||
         (cVar2 = FUN_005c8cc4(param_1 + 0xe8,&local_48,param_1 + 0x118,&local_28), cVar2 == '\0'))
      {
        *(char *)param_2 = '\x01';
        param_2 = *(int **)(param_1 + 0x4b0);
        local_18 = *(int **)(param_1 + 0x4b4);
        if (param_2 != local_18) {
          do {
            local_68 = *param_2;
            local_64 = param_2[1];
            local_60 = param_2[2];
            local_5c = param_2[3];
            if (local_6 != '\0') {
              local_68 = local_68 + local_10;
              local_60 = local_60 + local_10;
              local_64 = local_64 + local_14;
              local_5c = local_5c + local_14;
              FUN_004a7901();
            }
            FUN_005cddcf(&local_68);
            param_2 = param_2 + 4;
          } while (param_2 != local_18);
        }
      }
    }
  }
LAB_005c9817:
  return *(undefined4 *)(param_1 + 4);
}

