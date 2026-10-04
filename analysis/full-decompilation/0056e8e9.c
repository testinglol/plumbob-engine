
undefined4 __fastcall FUN_0056e8e9(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined1 local_88 [4];
  undefined1 local_84 [4];
  undefined1 local_80 [4];
  uint local_7c [25];
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  uVar4 = *(int *)(param_1 + 0xc) + -1;
  local_10 = 1;
  local_7c[0x18] = uVar4;
  local_14 = param_1;
  if (1 < (int)uVar4) {
    do {
      local_c = 1;
      if (1 < (int)uVar4) {
        do {
          piVar5 = (int *)FUN_0047c7b7(local_84,local_10);
          pbVar1 = (byte *)(*piVar5 + local_c * 2);
          bVar3 = *(byte *)(*piVar5 + local_c * 2);
          if ((bVar3 & 1) != 0) {
            local_18 = (uint)pbVar1[1];
            iVar7 = 0;
            local_7c[8] = 0;
            local_7c[9] = 1;
            local_7c[10] = 0xffffffff;
            local_7c[0xb] = 0;
            local_7c[0xc] = 0xffffffff;
            local_7c[0xd] = 1;
            local_7c[0xe] = 1;
            local_7c[0xf] = 0xffffffff;
            local_7c[0x10] = 1;
            local_7c[0x11] = 0;
            local_7c[0x12] = 0;
            local_7c[0x13] = 0xffffffff;
            local_7c[0x14] = 0xffffffff;
            local_7c[0x15] = 0xffffffff;
            local_7c[0x16] = 1;
            local_7c[0x17] = 1;
            if ((bVar3 & 2) == 0) {
              local_8 = 0;
              do {
                piVar5 = (int *)FUN_0047c7b7(local_80,local_7c[iVar7 + 0x10] + local_10);
                pbVar2 = (byte *)(*piVar5 + (local_7c[iVar7 + 8] + local_c) * 2);
                bVar3 = *pbVar2;
                if ((((bVar3 & 1) != 0) && ((bVar3 & 2) == 0)) && (pbVar2[1] == local_18)) {
                  local_8 = local_8 | 1 << ((byte)iVar7 & 0x1f);
                }
                iVar7 = iVar7 + 1;
              } while (iVar7 < 4);
              bVar3 = *pbVar1;
            }
            else {
              local_7c[0] = 0xc;
              local_7c[1] = 10;
              local_7c[2] = 5;
              local_7c[3] = 3;
              local_7c[4] = 7;
              local_7c[5] = 0xb;
              local_7c[6] = 0xe;
              local_7c[7] = 0xd;
              local_8 = 0xf;
              do {
                piVar5 = (int *)FUN_0047c7b7(local_88,*(int *)((int)local_7c + iVar7 + 0x40) +
                                                      local_10);
                iVar6 = *(int *)((int)local_7c + iVar7 + 0x20) + local_c;
                if (((*(byte *)(*piVar5 + iVar6 * 2) & 1) == 0) ||
                   ((int)(uint)*(byte *)(*piVar5 + iVar6 * 2 + 1) < (int)local_18)) {
                  local_8 = local_8 & *(uint *)((int)local_7c + iVar7);
                }
                iVar7 = iVar7 + 4;
              } while (iVar7 < 0x20);
              bVar3 = *pbVar1;
            }
            *pbVar1 = bVar3 & 0xf | (char)local_8 << 4;
          }
          local_c = local_c + 1;
          uVar4 = local_7c[0x18];
        } while (local_c < (int)local_7c[0x18]);
      }
      local_10 = local_10 + 1;
    } while (local_10 < (int)uVar4);
  }
  return 1;
}

