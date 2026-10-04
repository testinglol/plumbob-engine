
undefined4 __fastcall FUN_0056e5fc(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_5c [8];
  undefined1 local_3c [4];
  undefined1 local_38 [4];
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
  int local_c;
  int local_8;
  
  iVar2 = *(int *)(param_1 + 0xc);
  local_8 = 1;
  iVar3 = iVar2 + -1;
  local_2c = param_1;
  local_28 = iVar2;
  if (1 < iVar3) {
    do {
      local_c = 1;
      if (1 < iVar3) {
LAB_0056e62c:
        piVar1 = (int *)FUN_0047c7b7(local_38,local_8);
        local_34 = *piVar1 + local_c * 2;
        if ((*(byte *)(*piVar1 + local_c * 2) & 1) != 0) {
          local_5c[6] = 0xffffffff;
          local_5c[3] = 0xffffffff;
          local_30 = local_c - local_8;
          local_24 = 1;
          local_14 = 0;
          local_5c[4] = 1;
          local_5c[5] = 0;
          local_5c[7] = 0;
          local_5c[0] = 0;
          local_5c[1] = 1;
          local_5c[2] = 0;
          local_18 = 2;
          iVar3 = local_8;
          do {
            iVar3 = iVar3 + -1;
            iVar2 = local_30 + iVar3;
            local_10 = 0;
            local_1c = iVar3;
            do {
              if (local_14 != 0) goto LAB_0056e70f;
              local_20 = 0;
              if (0 < local_18) {
                do {
                  if ((((iVar2 < 0) || (local_28 <= iVar2)) || (local_1c < 0)) ||
                     (local_28 <= local_1c)) {
                    local_14 = 1;
                    break;
                  }
                  piVar1 = (int *)FUN_0047c7b7(local_3c,local_1c);
                  if ((*(byte *)(*piVar1 + iVar2 * 2) & 1) == 0) {
                    local_14 = 1;
                    break;
                  }
                  local_20 = local_20 + 1;
                  iVar2 = iVar2 + *(int *)((int)local_5c + local_10 + 0x10);
                  local_1c = local_1c + *(int *)((int)local_5c + local_10);
                } while (local_20 < local_18);
              }
              local_10 = local_10 + 4;
            } while (local_10 < 0x10);
            if (local_14 != 0) goto LAB_0056e70f;
            local_24 = local_24 + 1;
            local_18 = local_18 + 2;
          } while( true );
        }
        goto LAB_0056e720;
      }
LAB_0056e72f:
      local_8 = local_8 + 1;
    } while (local_8 < iVar3);
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
LAB_0056e70f:
  *(char *)(local_34 + 1) = (char)local_24 + -1;
  iVar2 = local_28;
LAB_0056e720:
  local_c = local_c + 1;
  iVar3 = iVar2 + -1;
  if (iVar3 <= local_c) goto LAB_0056e72f;
  goto LAB_0056e62c;
}

