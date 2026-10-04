
void FUN_004be421(undefined4 *param_1,undefined4 *param_2,ushort *param_3,ushort *param_4,
                 int param_5,int param_6,int *param_7)

{
  byte bVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  ushort *puVar10;
  ushort uVar11;
  int iVar12;
  uint *puVar13;
  ushort *puVar14;
  ushort *puVar15;
  uint uVar16;
  uint uVar17;
  ushort *puVar18;
  ushort *local_30;
  uint local_2c;
  int local_28;
  uint local_20;
  ushort *local_1c;
  ushort *local_18;
  uint *local_14;
  ushort *local_c;
  ushort *local_8;
  
  puVar3 = (ushort *)*param_1;
  iVar4 = param_1[1];
  local_1c = (ushort *)*param_2;
  uVar2 = param_3[1];
  iVar5 = param_7[1];
  iVar6 = param_7[3];
  puVar15 = param_4;
  puVar10 = param_3 + 8;
  local_18 = puVar3;
LAB_004be465:
  while( true ) {
    while( true ) {
      uVar16 = (uint)*puVar10;
      uVar17 = uVar16 & 0x1fff;
      uVar7 = uVar16 & 0xe000;
      puVar18 = puVar10 + 1;
      if ((*puVar10 & 0xe000) != 0) break;
      local_8 = local_1c;
      local_1c = local_1c + param_2[1];
      puVar15 = local_18;
      if (local_18 < puVar3 + iVar5 * iVar4) {
        puVar10 = (ushort *)((int)puVar10 + uVar17);
        local_18 = local_18 + param_1[1];
      }
      else {
        if (puVar3 + ((uint)uVar2 - iVar6) * iVar4 <= local_18) {
          return;
        }
        local_30 = local_18 + *param_7;
        local_c = local_18 + ((uint)*param_3 - param_7[2]);
        puVar10 = puVar18;
        local_18 = local_18 + param_1[1];
      }
    }
    if (uVar7 == 0x2000) break;
    if (uVar7 == 0x4000) {
      local_2c = 0;
      if ((puVar15 < local_30) || (local_c <= puVar15 + uVar17)) {
        if ((puVar15 + uVar17 <= local_30) || (local_c <= puVar15)) {
          puVar10 = (ushort *)((int)puVar18 + uVar17 * 3 + (uVar16 & 1));
          goto LAB_004be7df;
        }
        if (local_c < puVar15 + uVar17) {
          local_2c = (int)((uVar17 * 2 - (int)local_c) + (int)puVar15) >> 1;
          uVar17 = uVar17 - local_2c;
        }
        if (puVar15 < local_30) {
          iVar8 = (int)local_30 - (int)puVar15 >> 1;
          uVar17 = uVar17 - iVar8;
          puVar15 = puVar15 + iVar8;
          local_8 = local_8 + iVar8;
          puVar18 = (ushort *)(iVar8 * 3 + (int)puVar18);
        }
      }
      if ((int)uVar17 < 0x10) {
        if (0 < (int)uVar17) {
          puVar13 = &DAT_006f098c;
          puVar10 = puVar15;
          local_20 = uVar17;
          do {
            *puVar13 = (uint)*puVar10;
            puVar10 = puVar10 + 1;
            puVar13 = puVar13 + 1;
            local_20 = local_20 - 1;
          } while (local_20 != 0);
          pbVar9 = (byte *)((int)puVar18 + 1);
          local_14 = &DAT_006f0a0c;
          local_20 = uVar17;
          do {
            bVar1 = *pbVar9;
            pbVar9 = pbVar9 + 3;
            local_20 = local_20 - 1;
            *local_14 = (uint)param_4[bVar1];
            local_14 = local_14 + 1;
          } while (local_20 != 0);
        }
        local_14 = (uint *)0x0;
        if (0 < (int)uVar17) {
          puVar10 = local_8;
          do {
            iVar8 = *(short *)(param_6 + (uint)(byte)*puVar18 * 2) + param_5;
            if (iVar8 <= (int)(uint)*puVar10) {
              bVar1 = (byte)puVar18[1];
              uVar11 = (ushort)iVar8;
              if ((bVar1 < 8) || (0xf7 < bVar1)) {
                if (0xf7 < bVar1) {
                  *puVar10 = uVar11;
                  *(ushort *)(((int)puVar15 - (int)local_8) + (int)puVar10) =
                       param_4[*(byte *)((int)puVar18 + 1)];
                }
              }
              else {
                *puVar10 = uVar11;
                uVar7 = (&DAT_006f0a0c)[(int)local_14];
                uVar16 = (&DAT_006f098c)[(int)local_14];
                iVar8 = ((byte)puVar18[1] & 0x1f) * 0x20;
                *(ushort *)(((int)puVar15 - (int)local_8) + (int)puVar10) =
                     ((ushort)(byte)(&DAT_006e5e5c)
                                    [(uVar16 >> 10 & 0x1f) + ((uVar7 >> 10 & 0x1f) + iVar8) * 0x20]
                      << 5 | (ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar16 >> 5 & 0x1f) +
                                            ((uVar7 >> 5 & 0x1f) + iVar8) * 0x20]) << 5 |
                     (ushort)(byte)(&DAT_006e5e5c)
                                   [(uVar16 & 0x1f) + ((uVar7 & 0x1f) + iVar8) * 0x20];
              }
            }
            puVar18 = (ushort *)((int)puVar18 + 3);
            local_14 = (uint *)((int)local_14 + 1);
            puVar10 = puVar10 + 1;
          } while ((int)local_14 < (int)uVar17);
        }
      }
      else {
        FUN_004bde9b(uVar17,puVar18,puVar15,local_8,param_4,param_5,param_6);
        puVar18 = (ushort *)(uVar17 * 3 + (int)puVar18);
      }
      local_8 = local_8 + uVar17;
      puVar15 = puVar15 + uVar17;
      if (local_2c != 0) {
        puVar18 = (ushort *)(local_2c * 3 + (int)puVar18);
        puVar15 = puVar15 + local_2c;
        local_8 = local_8 + local_2c;
      }
      puVar10 = (ushort *)((int)puVar18 + ((uint)puVar18 & 1));
    }
    else if (uVar7 == 0x6000) {
      puVar15 = puVar15 + uVar17;
      local_8 = local_8 + uVar17;
      puVar10 = puVar18;
    }
    else if (uVar7 == 0x8000) {
      iVar8 = (uVar17 - 1) * param_1[1];
      iVar12 = param_2[1] * (uVar17 - 1);
      puVar15 = puVar15 + iVar8;
      local_8 = local_8 + iVar12;
      local_1c = local_1c + param_2[1] + iVar12;
      puVar10 = puVar18;
      local_18 = local_18 + param_1[1] + iVar8;
    }
    else {
      puVar10 = puVar18;
      if (uVar7 == 0xa000) {
        return;
      }
    }
  }
  local_28 = 0;
  if ((puVar15 < local_30) || (local_c <= puVar15 + uVar17)) {
    if ((puVar15 + uVar17 <= local_30) || (local_c <= puVar15)) {
      puVar10 = puVar18 + uVar17;
LAB_004be7df:
      puVar15 = puVar15 + uVar17;
      local_8 = local_8 + uVar17;
      goto LAB_004be465;
    }
    if (local_c < puVar15 + uVar17) {
      local_28 = (int)((uVar17 * 2 - (int)local_c) + (int)puVar15) >> 1;
      uVar17 = uVar17 - local_28;
    }
    if (puVar15 < local_30) {
      iVar8 = (int)local_30 - (int)puVar15 >> 1;
      uVar17 = uVar17 - iVar8;
      local_8 = local_8 + iVar8;
      puVar15 = puVar15 + iVar8;
      puVar18 = puVar18 + iVar8;
    }
  }
  if ((int)uVar17 < 0x10) {
    if (0 < (int)uVar17) {
      puVar10 = puVar18;
      local_2c = uVar17;
      do {
        iVar8 = *(short *)(param_6 + (uint)(byte)*puVar10 * 2) + param_5;
        puVar14 = (ushort *)(((int)local_8 - (int)puVar18) + (int)puVar10);
        if (iVar8 <= (int)(uint)*puVar14) {
          *puVar14 = (ushort)iVar8;
          *(ushort *)(((int)puVar15 - (int)puVar18) + (int)puVar10) =
               param_4[*(byte *)((int)puVar10 + 1)];
        }
        puVar10 = puVar10 + 1;
        local_2c = local_2c - 1;
      } while (local_2c != 0);
    }
  }
  else {
    FUN_004bbf78(uVar17,puVar18,puVar15,local_8,param_4,param_5,param_6,2);
  }
  local_8 = local_8 + uVar17;
  puVar15 = puVar15 + uVar17;
  puVar10 = puVar18 + uVar17;
  if (local_28 != 0) {
    puVar15 = puVar15 + local_28;
    local_8 = local_8 + local_28;
    puVar10 = puVar18 + uVar17 + local_28;
  }
  goto LAB_004be465;
}

