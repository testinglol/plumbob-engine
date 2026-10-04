
uint __thiscall FUN_0059a02d(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_2c;
  int local_28;
  int local_24;
  undefined *local_20;
  undefined *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_28 = (*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40)) / 0x18;
  local_24 = 0;
  local_18 = *(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c) >> 3;
  if (0 < local_28) {
    local_14 = 0;
    iVar2 = param_3;
    do {
      iVar4 = local_14 + *(int *)(param_1 + 0x40);
      if ((char)param_3 == '\0') {
        iVar1 = *(int *)(*(int *)(param_2 + 0x10) + local_24 * 4);
        if (iVar1 == 0) goto LAB_0059a075;
        local_20 = (undefined *)(iVar1 + 0x4c);
      }
      else {
        iVar1 = 0;
LAB_0059a075:
        local_20 = &DAT_006f75d0;
      }
      if (iVar1 == 0) {
        local_1c = &DAT_006722b8;
      }
      else {
        local_1c = (undefined *)(iVar1 + 0xc4);
      }
      local_c = 0;
      do {
        if (local_c == 0) {
          local_8 = *(int *)(iVar4 + 8);
          if (0 < local_8) {
            local_10 = *(int *)(param_1 + 100) + *(int *)(iVar4 + 4) * 0x18;
            iVar2 = FUN_0059a1bc();
            iVar1 = *(int *)(iVar4 + 4);
LAB_0059a113:
            iVar2 = iVar2 + iVar1 * 0x20;
            goto LAB_0059a118;
          }
        }
        else if (local_c == 1) {
          local_8 = *(int *)(iVar4 + 0x10);
          if (0 < local_8) {
            local_10 = *(int *)(param_1 + 100) + (*(int *)(iVar4 + 0xc) + local_18) * 0x18;
            iVar2 = FUN_0059a1bc();
            iVar1 = *(int *)(iVar4 + 0xc) + local_18;
            goto LAB_0059a113;
          }
        }
        else {
LAB_0059a118:
          if (0 < local_8) {
            FUN_005a6f40(0x18);
            FUN_005a6f60(0x20);
            FUN_005a6ef0(local_1c);
            FUN_005a6ec0(local_20);
            FUN_005a8130(6,local_8,local_10,iVar2);
            FUN_005a8130(2,local_8,local_10 + 0xc,iVar2 + 0xc);
          }
        }
        local_c = local_c + 1;
      } while (local_c < 2);
      local_14 = local_14 + 0x18;
      local_24 = local_24 + 1;
    } while (local_24 < local_28);
  }
  local_2c = 0;
  local_28 = local_18 + -1;
  FUN_005d1259(&local_2c,0);
  FUN_0059a4f6(param_2);
  uVar3 = FUN_00463049(param_2 + 0x1c);
  return uVar3 & 0xffffff00;
}

