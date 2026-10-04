
void FUN_004c33e9(undefined4 *param_1,undefined4 param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 uVar3;
  ushort *puVar4;
  undefined2 *puVar5;
  ushort uVar6;
  int iVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  ushort *puVar15;
  uint uVar16;
  undefined2 *puVar17;
  uint local_24;
  byte *local_20;
  ushort *local_1c;
  undefined2 *local_18;
  uint local_14;
  int local_10;
  uint local_c;
  byte *local_8;
  
  iVar7 = (int)*(short *)(param_1 + 2);
  uVar16 = (uint)*(short *)((int)param_1 + 0xe);
  local_10 = iVar7 + -1;
  iVar11 = (int)DAT_006f0bc6;
  local_14 = iVar11 - DAT_006f0bc2;
  local_1c = (ushort *)(DAT_006f0bd0 + iVar7 * DAT_006f0bd4 + uVar16 * 2);
  local_18 = (undefined2 *)(DAT_006f0bcc + ((iVar7 * DAT_006f0bbc) / 2 + uVar16) * 2);
  DAT_006f0a94 = param_1[0xc];
  uVar8 = param_2;
  pbVar14 = (byte *)*param_1;
  puVar15 = (ushort *)0x0;
  puVar17 = (undefined2 *)0x0;
  param_1 = (undefined4 *)uVar16;
  do {
    while( true ) {
      while( true ) {
        puVar5 = local_18;
        puVar4 = local_1c;
        uVar10 = (uint)param_1;
        bVar2 = *pbVar14;
        pbVar1 = pbVar14 + 1;
        local_c = (uint)*pbVar1;
        pbVar13 = pbVar14 + 2;
        local_8 = pbVar13;
        if (bVar2 == 1) break;
        uVar6 = (ushort)uVar8;
        if (bVar2 == 2) {
          pbVar14 = pbVar14 + 4;
          local_8 = pbVar14;
          uVar3 = *(undefined2 *)(DAT_006f0a94 + (uint)*pbVar13 * 2);
          uVar12 = (int)param_1 + local_c;
          if ((int)uVar12 < 0) {
            param_1 = (undefined4 *)((int)param_1 + (int)(char)*pbVar1);
            puVar17 = puVar17 + -local_c;
            puVar15 = puVar15 + -local_c;
          }
          else {
            if ((int)param_1 < 0) {
              param_1 = (undefined4 *)0x0;
              local_c = uVar12;
              puVar17 = puVar17 + uVar10;
              puVar15 = puVar15 + uVar10;
              puVar9 = &local_14;
              if ((int)uVar12 <= (int)local_14) {
                puVar9 = &local_c;
              }
              uVar10 = *puVar9;
            }
            else {
              local_24 = local_14 - (int)param_1;
              puVar9 = &local_24;
              if ((int)local_c <= (int)(local_14 - (int)param_1)) {
                puVar9 = &local_c;
              }
              uVar10 = *puVar9;
            }
            if (3 < (int)uVar10) {
              local_24 = uVar10 >> 2;
              uVar10 = uVar10 + local_24 * -4;
              param_1 = (undefined4 *)((int)param_1 + local_24 * 4);
              do {
                if (uVar6 <= puVar15[-1]) {
                  puVar17[-1] = uVar3;
                  puVar15[-1] = uVar6;
                }
                if (uVar6 <= puVar15[-2]) {
                  puVar17[-2] = uVar3;
                  puVar15[-2] = uVar6;
                }
                if (uVar6 <= puVar15[-3]) {
                  puVar17[-3] = uVar3;
                  puVar15[-3] = uVar6;
                }
                puVar15 = puVar15 + -4;
                puVar17 = puVar17 + -4;
                if (uVar6 <= *puVar15) {
                  *puVar17 = uVar3;
                  *puVar15 = uVar6;
                }
                pbVar14 = pbVar14 + 4;
                local_24 = local_24 - 1;
              } while (local_24 != 0);
            }
            if (1 < (int)uVar10) {
              local_24 = uVar10 >> 1;
              uVar10 = uVar10 + local_24 * -2;
              param_1 = (undefined4 *)((int)param_1 + local_24 * 2);
              do {
                if (uVar6 <= puVar15[-1]) {
                  puVar17[-1] = uVar3;
                  puVar15[-1] = uVar6;
                }
                puVar15 = puVar15 + -2;
                puVar17 = puVar17 + -2;
                if (uVar6 <= *puVar15) {
                  *puVar17 = uVar3;
                  *puVar15 = uVar6;
                }
                pbVar14 = pbVar14 + 2;
                local_24 = local_24 - 1;
              } while (local_24 != 0);
            }
            if (uVar10 != 0) {
              puVar17 = puVar17 + -1;
              puVar15 = puVar15 + -1;
              if (uVar6 <= *puVar15) {
                *puVar17 = uVar3;
                *puVar15 = uVar6;
              }
              pbVar14 = pbVar14 + 1;
              param_1 = (undefined4 *)((int)param_1 + 1);
            }
          }
          if ((int)local_14 <= (int)param_1) goto LAB_004c3744;
        }
        else if (bVar2 == 3) {
          uVar12 = (int)param_1 + local_c;
          local_24 = uVar12;
          if ((int)uVar12 < 0) {
            puVar17 = puVar17 + -local_c;
            puVar15 = puVar15 + -local_c;
            pbVar13 = (byte *)((uint)(pbVar13 + local_c + 1) & 0xfffffffe);
            param_1 = (undefined4 *)uVar12;
          }
          else {
            if ((int)param_1 < 0) {
              param_1 = (undefined4 *)0x0;
              pbVar13 = pbVar13 + -uVar10;
              puVar17 = puVar17 + uVar10;
              puVar15 = puVar15 + uVar10;
              local_24 = local_14;
              local_c = uVar12;
              puVar9 = &local_24;
              if ((int)uVar12 <= (int)local_14) {
                puVar9 = &local_c;
              }
              uVar10 = *puVar9;
            }
            else {
              local_24 = local_14 - (int)param_1;
              puVar9 = &local_24;
              if ((int)local_c <= (int)(local_14 - (int)param_1)) {
                puVar9 = &local_c;
              }
              uVar10 = *puVar9;
            }
            param_1 = (undefined4 *)((int)param_1 + uVar10);
            if (0 < (int)uVar10) {
              do {
                local_24 = uVar10;
                puVar17 = puVar17 + -1;
                puVar15 = puVar15 + -1;
                if (uVar6 <= *puVar15) {
                  *puVar17 = *(undefined2 *)(DAT_006f0a94 + (uint)*pbVar13 * 2);
                  *puVar15 = uVar6;
                }
                pbVar13 = pbVar13 + 1;
                local_24 = local_24 - 1;
                uVar10 = local_24;
              } while (local_24 != 0);
            }
          }
          if ((int)local_14 <= (int)param_1) goto LAB_004c3744;
          pbVar14 = (byte *)((uint)(pbVar13 + 1) & 0xfffffffe);
        }
        else if (bVar2 == 4) {
          iVar7 = local_10 + 1;
          local_20 = pbVar13 + (local_c - 2);
          pbVar14 = pbVar13;
          if (iVar7 < DAT_006f0bc0) {
            pbVar14 = local_20;
          }
          local_1c = (ushort *)((int)local_1c + DAT_006f0bd4);
          local_18 = local_18 + DAT_006f0bbc / 2;
          uVar8 = param_2;
          local_10 = iVar7;
          FUN_004cebb0(param_2,iVar7);
          uVar8 = FUN_0049a73d(uVar8,iVar7);
          puVar15 = puVar4;
          puVar17 = puVar5;
          param_1 = (undefined4 *)(iVar11 - uVar16);
          if (DAT_006f0bc4 <= local_10) {
            return;
          }
        }
        else {
          if (bVar2 != 9) goto LAB_004c3755;
          iVar7 = local_10 + local_c;
          local_18 = local_18 + (int)(DAT_006f0bbc * local_c) / 2;
          local_1c = (ushort *)((int)local_1c + DAT_006f0bd4 * local_c);
          uVar8 = param_2;
          local_10 = iVar7;
          FUN_004cebb0(param_2,iVar7);
          uVar8 = FUN_0049a73d(uVar8,iVar7);
          pbVar14 = pbVar13;
        }
      }
      param_1 = (undefined4 *)((int)param_1 + local_c);
      if ((int)local_14 <= (int)param_1) break;
      puVar17 = puVar17 + -local_c;
      puVar15 = puVar15 + -local_c;
LAB_004c3755:
      pbVar14 = pbVar13;
      if (bVar2 == 5) {
        return;
      }
    }
LAB_004c3744:
    pbVar14 = local_20;
  } while( true );
}

