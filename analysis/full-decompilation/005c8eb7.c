
undefined4 __thiscall FUN_005c8eb7(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
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
  int *local_14;
  int local_10;
  int *local_c;
  char local_6;
  char local_5;
  
  local_6 = '\0';
  local_10 = 0;
  local_14 = (int *)0x0;
  *(char *)param_2 = '\0';
  local_5 = '\x01';
  FUN_005cab9b();
  piVar3 = (int *)(*(int *)(param_1 + 0x4b4) - *(int *)(param_1 + 0x4b0) >> 4);
  local_c = piVar3;
  if (*(char *)(param_1 + 0x4e1) == '\0') {
    if (*(int *)(param_1 + 0x52c) != 1) {
      iVar2 = param_1 + 0x28;
      cVar1 = FUN_005c8cc4(param_1 + 0xf4,iVar2,param_1 + 0xe8,iVar2);
      if (cVar1 == '\0') {
        if (*(int *)(param_1 + 4) == -0x7789fe3e) {
          FUN_005caa0d();
          local_5 = FUN_005c8cc4(param_1 + 0xf4,iVar2,param_1 + 0xe8,iVar2);
          if (local_5 != '\0') goto LAB_005c9147;
        }
        *(char *)param_2 = '\x01';
        param_2 = *(int **)(param_1 + 0x4b0);
        local_14 = *(int **)(param_1 + 0x4b4);
        if (param_2 != local_14) {
          do {
            local_48 = *param_2;
            local_44 = param_2[1];
            local_40 = param_2[2];
            local_3c = param_2[3];
            FUN_005cddcf(&local_48);
            param_2 = param_2 + 4;
          } while (param_2 != local_14);
        }
        goto LAB_005c933c;
      }
      local_5 = '\x01';
    }
  }
  else {
    local_30 = *(int *)(param_1 + 0x18);
    local_10 = *(int *)(param_1 + 0x4f4) - *(int *)(param_1 + 0x4e4);
    local_28 = *(int *)(param_1 + 0x4e4) + local_30;
    local_20 = *(int *)(param_1 + 0x4ec) + local_30;
    local_38 = *(int *)(param_1 + 0x4f4) + local_30;
    local_30 = *(int *)(param_1 + 0x4fc) + local_30;
    local_14 = (int *)(*(int *)(param_1 + 0x4f8) - *(int *)(param_1 + 0x4e8));
    local_2c = *(int *)(param_1 + 0x1c);
    local_24 = *(int *)(param_1 + 0x4e8) + local_2c;
    local_1c = *(int *)(param_1 + 0x4f0) + local_2c;
    local_34 = *(int *)(param_1 + 0x4f8) + local_2c;
    local_2c = *(int *)(param_1 + 0x500) + local_2c;
    FUN_004a7901();
    FUN_004a7901();
    cVar1 = FUN_005c8cc4(param_1 + 0xf4,&local_38,param_1 + 0xe8,&local_28);
    if (cVar1 == '\0') {
      if (*(int *)(param_1 + 4) == -0x7789fe3e) {
        FUN_005caa0d();
        local_5 = FUN_005c8cc4(param_1 + 0xf4,&local_38,param_1 + 0xe8,&local_28);
        if (local_5 != '\0') goto LAB_005c8fb0;
      }
      *(char *)param_2 = '\x01';
      *(int *)(param_1 + 0x508) = local_28;
      *(int *)(param_1 + 0x50c) = local_24;
      *(int *)(param_1 + 0x510) = local_20;
      *(int *)(param_1 + 0x514) = local_1c;
      *(int *)(param_1 + 0x518) = local_38;
      *(int *)(param_1 + 0x51c) = local_34;
      param_2 = *(int **)(param_1 + 0x4b0);
      *(undefined4 *)(param_1 + 0x504) = *(undefined4 *)(param_1 + 4);
      *(int *)(param_1 + 0x520) = local_30;
      *(int *)(param_1 + 0x524) = local_2c;
      local_c = *(int **)(param_1 + 0x4b4);
      if (param_2 != local_c) {
        do {
          local_48 = *param_2 + local_10;
          local_40 = param_2[2] + local_10;
          local_44 = param_2[1] + (int)local_14;
          local_3c = param_2[3] + (int)local_14;
          FUN_004a7901();
          FUN_005cddcf(&local_48);
          param_2 = param_2 + 4;
        } while (param_2 != local_c);
      }
      goto LAB_005c933c;
    }
    local_5 = '\x01';
LAB_005c8fb0:
    iVar2 = *(int *)(param_1 + 4);
    *(undefined1 *)(param_1 + 0x4e1) = 0;
    *(int *)(param_1 + 0x504) = iVar2;
    local_6 = '\x01';
    piVar3 = local_c;
    if (iVar2 != 0) {
      *(int *)(param_1 + 0x504) = iVar2;
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
LAB_005c9147:
  *(int **)(param_1 + 0x57c) = piVar3;
  if (piVar3 != (int *)0x0) {
    local_c = *(int **)(param_1 + 0x4b0);
    local_18 = *(int **)(param_1 + 0x4b4);
    if (local_c != local_18) {
      do {
        local_28 = *local_c;
        local_24 = local_c[1];
        local_20 = local_c[2];
        local_1c = local_c[3];
        if ((local_28 < local_20) && (local_24 < local_1c)) {
          local_48 = local_28;
          local_44 = local_24;
          local_40 = local_20;
          local_3c = local_1c;
          if (*(char *)param_2 == '\0') {
            if (*(char *)(param_1 + 0x10) == '\0') {
              if ((local_5 == '\0') ||
                 (cVar1 = FUN_005c8cc4(param_1 + 0xf4,&local_48,param_1 + 0x100,&local_28),
                 cVar1 == '\0')) {
                local_5 = '\0';
                goto LAB_005c9207;
              }
            }
            else if ((local_5 == '\0') ||
                    (cVar1 = FUN_005c8d94(param_1 + 0xf4,&local_48,param_1 + 0x100,&local_28),
                    cVar1 == '\0')) {
              local_5 = '\0';
              goto LAB_005c920d;
            }
            local_5 = '\x01';
          }
          else {
LAB_005c9207:
            if (local_5 == '\0') {
LAB_005c920d:
              *(char *)param_2 = '\x01';
            }
          }
          if (*(char *)param_2 != '\0') {
            if (local_6 != '\0') {
              local_28 = local_28 + local_10;
              local_20 = local_20 + local_10;
              local_24 = local_24 + (int)local_14;
              local_1c = local_1c + (int)local_14;
              FUN_004a7901();
            }
            FUN_005cddcf(&local_28);
          }
          local_c = local_c + 4;
        }
      } while (local_c != local_18);
    }
  }
  if (local_5 == '\0') {
LAB_005c92d0:
    *(char *)param_2 = '\x01';
  }
  else {
    if ((*(char *)(param_1 + 0x44c) == '\0') && (*(char *)param_2 == '\0')) {
      FUN_005c8b39(*(undefined4 *)(param_1 + 0x60));
      iVar2 = (**(code **)(**(int **)(param_1 + 0xec) + 0x2c))(*(int **)(param_1 + 0xec),0,1);
      *(int *)(param_1 + 4) = iVar2;
      if (iVar2 == -0x7789fe3e) {
        iVar2 = FUN_005caa0d();
        *(int *)(param_1 + 4) = iVar2;
        if (iVar2 != 0) goto LAB_005c92ca;
        FUN_005c8b39(*(undefined4 *)(param_1 + 0x60));
        iVar2 = (**(code **)(**(int **)(param_1 + 0xec) + 0x2c))(*(int **)(param_1 + 0xec),0,1);
        *(int *)(param_1 + 4) = iVar2;
      }
      if (iVar2 != 0) {
        local_5 = '\0';
      }
    }
LAB_005c92ca:
    if (local_5 == '\0') goto LAB_005c92d0;
  }
  if (*(char *)param_2 != '\0') {
    param_2 = *(int **)(param_1 + 0x4b0);
    local_18 = *(int **)(param_1 + 0x4b4);
    if (param_2 != local_18) {
      do {
        local_48 = *param_2;
        local_44 = param_2[1];
        local_40 = param_2[2];
        local_3c = param_2[3];
        if (local_6 != '\0') {
          local_48 = local_48 + local_10;
          local_40 = local_40 + local_10;
          local_44 = local_44 + (int)local_14;
          local_3c = local_3c + (int)local_14;
          FUN_004a7901();
        }
        FUN_005cddcf(&local_48);
        param_2 = param_2 + 4;
      } while (param_2 != local_18);
    }
  }
LAB_005c933c:
  return *(undefined4 *)(param_1 + 4);
}

