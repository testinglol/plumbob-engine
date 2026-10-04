
undefined1 __fastcall FUN_0056e742(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  undefined1 local_8c [4];
  undefined1 local_88 [4];
  int local_84 [25];
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  undefined1 local_5;
  
  local_5 = 0;
  local_84[0] = -1;
  local_84[4] = 0xffffffff;
  local_84[7] = 0xffffffff;
  local_84[0xb] = 0xffffffff;
  local_84[0xc] = 0xffffffff;
  local_84[0xd] = 0xffffffff;
  local_84[0x18] = *(int *)(param_1 + 0xc) + -1;
  local_84[1] = 0;
  local_84[2] = 1;
  local_84[3] = 0;
  local_84[5] = 1;
  local_84[6] = 1;
  local_84[8] = 0;
  local_84[9] = 1;
  local_84[10] = 0;
  local_84[0xe] = 1;
  local_84[0xf] = 1;
  local_84[0x10] = 0x2c;
  local_84[0x11] = 0x46;
  local_84[0x12] = 0x83;
  local_84[0x13] = 0x19;
  local_84[0x14] = 0x6e;
  local_84[0x15] = 199;
  local_84[0x16] = 0x9b;
  local_84[0x17] = 0x3d;
  local_c = 1;
  local_1c = param_1;
  if (1 < local_84[0x18]) {
    do {
      local_10 = 1;
      if (1 < local_84[0x18]) {
        do {
          piVar2 = (int *)FUN_0047c7b7(local_8c,local_c);
          pbVar1 = (byte *)(*piVar2 + local_10 * 2);
          if ((*(byte *)(*piVar2 + local_10 * 2) & 1) != 0) {
            iVar5 = 0;
            local_20 = (uint)pbVar1[1];
            local_18 = 0;
            local_14 = 0;
            do {
              piVar2 = (int *)FUN_0047c7b7(local_88,local_84[iVar5 + 8] + local_c);
              if ((*(byte *)(*piVar2 + (local_84[iVar5] + local_10) * 2) & 1) != 0) {
                uVar3 = (uint)*(byte *)(*piVar2 + (local_84[iVar5] + local_10) * 2 + 1);
                if (uVar3 == local_20) {
                  local_14 = local_14 | 1 << ((byte)iVar5 & 0x1f);
                }
                else if ((int)local_20 < (int)uVar3) {
                  local_18 = 1;
                  break;
                }
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < 8);
            iVar5 = 0;
            if ((local_14 != 0) && (local_18 == 0)) {
              puVar4 = (uint *)(local_84 + 0x10);
              do {
                if ((*puVar4 & local_14) == *puVar4) {
                  local_18 = 1;
                  break;
                }
                iVar5 = iVar5 + 1;
                puVar4 = puVar4 + 1;
              } while (iVar5 < 8);
            }
            FUN_0056e8c4(local_18);
            if ((*pbVar1 & 1) == 0) {
              return local_5;
            }
          }
          local_10 = local_10 + 1;
        } while (local_10 < local_84[0x18]);
      }
      local_c = local_c + 1;
    } while (local_c < local_84[0x18]);
  }
  return 1;
}

