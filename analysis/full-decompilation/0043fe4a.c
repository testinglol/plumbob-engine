
void __thiscall FUN_0043fe4a(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  undefined1 local_dc;
  undefined4 local_88;
  int *local_84;
  int local_80;
  int local_7c;
  int local_78;
  short local_74;
  int local_70;
  short local_6c;
  int local_68;
  short local_64;
  int local_60;
  short local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  uint local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int *local_2c;
  undefined4 local_28;
  int local_24;
  undefined2 local_20 [2];
  int *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  char local_8 [4];
  
  if (0x2e < param_3) {
    local_8[0] = '\x01';
    FUN_0046494e(local_8);
    if (local_8[0] != '\0') {
      FUN_004645e3();
    }
  }
  if (0x2e < param_3) {
    local_10 = FUN_0043e07d();
    local_c = FUN_0043e088();
    local_14 = FUN_0043e093();
    local_18 = FUN_0043e09e();
    if ((*(ushort *)(DAT_006e486c + 0x66) & 0x20) == 0) {
      local_14 = FUN_0043e07d();
      local_18 = FUN_0043e07d();
    }
    if (*(int *)(param_2 + 0xc) == 0) {
      FUN_00464973(&local_28,1);
      while ((short)local_28 != 0) {
        FUN_0043bfaf(&local_34,&local_30,param_2,1,param_3);
        if (local_34 == 0) {
          if ((local_30 == 0) || (local_4c = *(int *)(local_30 + 0x14), local_4c != 2)) {
            local_34 = local_10;
          }
          else {
            local_50 = *(int *)(local_30 + 0x10);
            iVar2 = FUN_0045741b();
            if (local_50 == iVar2) {
              local_34 = local_c;
            }
            else {
              local_54 = *(int *)(local_30 + 0x10);
              iVar2 = FUN_0045741b();
              if (local_54 == iVar2) {
                local_34 = local_14;
              }
              else {
                local_58 = *(int *)(local_30 + 0x10);
                iVar2 = FUN_0045741b();
                if (local_58 == iVar2) {
                  local_34 = local_18;
                }
                else {
                  local_34 = local_c;
                }
              }
            }
          }
        }
        local_2c = (int *)FUN_004409db(local_34,0);
        FUN_0044350d(local_2c,local_28,1);
        (**(code **)(*local_2c + 0x3c))();
        local_2c[0x45] = local_2c[0x45] & 0xffffff7f;
        local_2c[0x45] = local_2c[0x45] | 0x80;
        FUN_00464973(&local_28,1);
      }
    }
    else {
      for (local_24 = *(int *)(param_1 + 0x30); local_24 != 0; local_24 = *(int *)(local_24 + 0xe0))
      {
        FUN_00464973(local_24 + 0xf0,1);
        local_48 = *(undefined4 *)(param_1 + 0x14);
        FUN_0043bfaf(local_24 + 0x11c,0,param_2,1,param_3);
      }
      local_20[0] = 0;
      FUN_00464973(local_20,1);
    }
    FUN_00464c0a();
    for (local_1c = *(int **)(param_1 + 0x30); local_1c != (int *)0x0;
        local_1c = (int *)local_1c[0x38]) {
      local_3c = local_1c[0x47];
      if ((((local_3c == local_10) || (local_3c == local_c)) || (local_3c == local_14)) ||
         (local_3c == local_18)) {
        local_dc = 1;
      }
      else {
        local_dc = 0;
      }
      local_38 = CONCAT31(local_38._1_3_,local_dc);
      (**(code **)(*local_1c + 0x7c))(param_2,param_3,local_38);
      if (0x35 < param_3) {
        if ((char)local_38 == '\0') {
          local_64 = (short)local_1c[0x3c];
          local_68 = *(int *)(param_1 + 0x24);
          FUN_00464a4e(local_68 + -4 + local_64 * 4,1);
        }
        else {
          local_5c = (short)local_1c[0x3c];
          local_60 = *(int *)(param_1 + 0x24);
          puVar1 = (uint *)(local_60 + -4 + local_5c * 4);
          *puVar1 = *puVar1 | 0x10000;
        }
        if (param_3 < 0x39) {
          local_6c = (short)local_1c[0x3c];
          local_70 = *(int *)(param_1 + 0x24);
          puVar1 = (uint *)(local_70 + -4 + local_6c * 4);
          *puVar1 = *puVar1 & 0xffff;
          local_74 = (short)local_1c[0x3c];
          local_78 = *(int *)(param_1 + 0x24);
          puVar1 = (uint *)(local_78 + -4 + local_74 * 4);
          *puVar1 = *puVar1 | 0x10000;
        }
      }
      if (*(int *)(param_2 + 0xc) == 0) {
        FUN_00464c6e();
      }
      FUN_00464c0a();
    }
  }
  FUN_0043fd68(param_2,param_1 + 0xa8);
  if (0x33 < param_3) {
    local_84 = (int *)(param_1 + 0x38);
    local_7c = *(int *)(param_1 + 0x3c);
    local_80 = *local_84;
    local_44 = local_7c - local_80 >> 2;
    FUN_00464a4e(&local_44,1);
    local_88 = 0;
    FUN_00448887(local_44,&local_88);
    for (local_40 = 0; local_40 < (uint)(*(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x38) >> 2);
        local_40 = local_40 + 1) {
      FUN_0043fd68(param_2,*(int *)(param_1 + 0x38) + local_40 * 4);
    }
    FUN_00464c84(&DAT_006e4a70);
  }
  return;
}

