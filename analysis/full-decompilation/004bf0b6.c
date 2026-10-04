
void FUN_004bf0b6(int *param_1,int *param_2,ushort *param_3,int param_4,int param_5,int param_6,
                 int *param_7)

{
  ushort *puVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  ushort *puVar10;
  ushort uVar11;
  int iVar12;
  ushort *puVar13;
  uint *puVar14;
  ushort *puVar15;
  uint uVar16;
  uint uVar17;
  ushort *puVar18;
  ushort *local_30;
  uint local_2c;
  uint local_28;
  ushort *local_20;
  ushort *local_1c;
  uint *local_18;
  uint local_14;
  ushort *local_10;
  ushort *local_c;
  ushort *local_8;
  
  uVar3 = param_3[1];
  puVar1 = (ushort *)(*param_1 + -2 + (uint)*param_3 * 2);
  local_20 = (ushort *)(*param_2 + -2 + (uint)*param_3 * 2);
  iVar4 = param_1[1];
  iVar5 = param_7[1];
  iVar6 = param_7[3];
  puVar15 = local_c;
  puVar10 = param_3 + 8;
  local_1c = puVar1;
LAB_004bf107:
  while( true ) {
    while( true ) {
      uVar16 = (uint)*puVar10;
      uVar17 = uVar16 & 0x1fff;
      uVar7 = uVar16 & 0xe000;
      puVar18 = puVar10 + 1;
      if ((*puVar10 & 0xe000) != 0) break;
      local_8 = local_20;
      local_c = local_1c;
      local_20 = local_20 + param_2[1];
      puVar15 = local_1c;
      if (local_1c < puVar1 + iVar5 * iVar4) {
        puVar10 = (ushort *)((int)puVar10 + uVar17);
        local_1c = local_1c + param_1[1];
      }
      else {
        if (puVar1 + ((uint)uVar3 - iVar6) * iVar4 <= local_1c) {
          return;
        }
        local_30 = local_1c + -param_7[2];
        local_10 = local_1c + (*param_7 - (uint)*param_3);
        puVar10 = puVar18;
        local_1c = local_1c + param_1[1];
      }
    }
    if (uVar7 == 0x2000) break;
    if (uVar7 == 0x4000) {
      local_2c = 0;
      if ((local_30 < puVar15) || (puVar15 + -uVar17 <= local_10)) {
        puVar13 = puVar15 + -uVar17;
        if ((local_30 <= puVar13) || (puVar15 <= local_10)) {
          puVar10 = (ushort *)((int)puVar18 + uVar17 * 3 + (uVar16 & 1));
          puVar15 = puVar13;
          goto LAB_004bf494;
        }
        if (puVar13 < local_10) {
          local_2c = (int)((uVar17 * 2 - (int)puVar15) + (int)local_10) >> 1;
          uVar17 = uVar17 - local_2c;
        }
        if (local_30 < puVar15) {
          iVar8 = (int)puVar15 - (int)local_30 >> 1;
          uVar17 = uVar17 - iVar8;
          puVar15 = puVar15 + -iVar8;
          local_8 = local_8 + -iVar8;
          puVar18 = (ushort *)(iVar8 * 3 + (int)puVar18);
          local_c = puVar15;
        }
      }
      if ((int)uVar17 < 0x10) {
        if (0 < (int)uVar17) {
          puVar14 = &DAT_006f098c;
          puVar10 = puVar15;
          local_18 = (uint *)uVar17;
          do {
            *puVar14 = (uint)*puVar10;
            puVar10 = puVar10 + -1;
            puVar14 = puVar14 + 1;
            local_18 = (uint *)((int)local_18 - 1);
          } while (local_18 != (uint *)0x0);
          pbVar9 = (byte *)((int)puVar18 + 1);
          local_18 = &DAT_006f0a0c;
          local_14 = uVar17;
          do {
            bVar2 = *pbVar9;
            pbVar9 = pbVar9 + 3;
            local_14 = local_14 - 1;
            *local_18 = (uint)*(ushort *)(param_4 + (uint)bVar2 * 2);
            local_18 = local_18 + 1;
          } while (local_14 != 0);
        }
        local_18 = (uint *)0x0;
        if (0 < (int)uVar17) {
          iVar8 = (int)puVar15 - (int)local_8;
          puVar10 = local_8;
          do {
            iVar12 = *(short *)(param_6 + (uint)(byte)*puVar18 * 2) + param_5;
            if (iVar12 <= (int)(uint)*puVar10) {
              bVar2 = (byte)puVar18[1];
              uVar11 = (ushort)iVar12;
              if ((bVar2 < 8) || (0xf7 < bVar2)) {
                if (0xf7 < bVar2) {
                  *puVar10 = uVar11;
                  *(undefined2 *)(iVar8 + (int)puVar10) =
                       *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar18 + 1) * 2);
                }
              }
              else {
                *puVar10 = uVar11;
                uVar7 = (&DAT_006f0a0c)[(int)local_18];
                uVar16 = (&DAT_006f098c)[(int)local_18];
                iVar12 = ((byte)puVar18[1] & 0x1f) * 0x20;
                *(ushort *)(iVar8 + (int)puVar10) =
                     ((ushort)(byte)(&DAT_006e5e5c)
                                    [(uVar16 >> 10 & 0x1f) + ((uVar7 >> 10 & 0x1f) + iVar12) * 0x20]
                      << 5 | (ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar16 >> 5 & 0x1f) +
                                            ((uVar7 >> 5 & 0x1f) + iVar12) * 0x20]) << 5 |
                     (ushort)(byte)(&DAT_006e5e5c)
                                   [(uVar16 & 0x1f) + ((uVar7 & 0x1f) + iVar12) * 0x20];
                puVar15 = local_c;
              }
            }
            puVar18 = (ushort *)((int)puVar18 + 3);
            local_18 = (uint *)((int)local_18 + 1);
            puVar10 = puVar10 + -1;
          } while ((int)local_18 < (int)uVar17);
        }
      }
      else {
        FUN_004beb1b(uVar17,puVar18,puVar15,local_8,param_4,param_5,param_6);
        puVar18 = (ushort *)(uVar17 * 3 + (int)puVar18);
      }
      local_8 = local_8 + -uVar17;
      puVar15 = puVar15 + -uVar17;
      if (local_2c != 0) {
        puVar18 = (ushort *)(local_2c * 3 + (int)puVar18);
        puVar15 = puVar15 + -local_2c;
        local_8 = local_8 + -local_2c;
      }
      puVar10 = (ushort *)((int)puVar18 + ((uint)puVar18 & 1));
      local_c = puVar15;
    }
    else if (uVar7 == 0x6000) {
      puVar15 = puVar15 + -uVar17;
      local_8 = local_8 + -uVar17;
      puVar10 = puVar18;
      local_c = puVar15;
    }
    else if (uVar7 == 0x8000) {
      iVar8 = (uVar17 - 1) * param_1[1];
      iVar12 = param_2[1] * (uVar17 - 1);
      puVar15 = puVar15 + iVar8;
      local_8 = local_8 + iVar12;
      local_20 = local_20 + param_2[1] + iVar12;
      puVar10 = puVar18;
      local_1c = local_1c + param_1[1] + iVar8;
      local_c = puVar15;
    }
    else {
      puVar10 = puVar18;
      if (uVar7 == 0xa000) {
        return;
      }
    }
  }
  local_28 = 0;
  if ((local_30 < puVar15) || (puVar15 + -uVar17 <= local_10)) {
    puVar13 = puVar15 + -uVar17;
    if ((puVar13 < local_30) && (local_10 < puVar15)) {
      if (puVar13 < local_10) {
        local_28 = (int)((uVar17 * 2 - (int)puVar15) + (int)local_10) >> 1;
        uVar17 = uVar17 - local_28;
      }
      if (local_30 < puVar15) {
        iVar8 = (int)puVar15 - (int)local_30 >> 1;
        uVar17 = uVar17 - iVar8;
        local_8 = local_8 + -iVar8;
        puVar15 = puVar15 + -iVar8;
        puVar18 = puVar18 + iVar8;
      }
      goto LAB_004bf404;
    }
    puVar10 = puVar18 + uVar17;
    puVar15 = puVar13;
  }
  else {
LAB_004bf404:
    if ((int)uVar17 < 0x10) {
      if (0 < (int)uVar17) {
        puVar10 = local_8;
        local_2c = uVar17;
        local_18 = (uint *)puVar18;
        do {
          iVar8 = *(short *)(param_6 + (uint)(byte)*local_18 * 2) + param_5;
          if (iVar8 <= (int)(uint)*puVar10) {
            *puVar10 = (ushort)iVar8;
            *(undefined2 *)((int)puVar10 + ((int)puVar15 - (int)local_8)) =
                 *(undefined2 *)(param_4 + (uint)*(byte *)((int)local_18 + 1) * 2);
          }
          local_18 = (uint *)((int)local_18 + 2);
          puVar10 = puVar10 + -1;
          local_2c = local_2c - 1;
        } while (local_2c != 0);
      }
    }
    else {
      FUN_004bcef1(uVar17,puVar18,puVar15,local_8,param_4,param_5,param_6,2);
    }
    local_8 = local_8 + -uVar17;
    puVar15 = puVar15 + -uVar17;
    puVar10 = puVar18 + uVar17;
    local_c = puVar15;
    if (local_28 == 0) goto LAB_004bf107;
    puVar10 = puVar18 + uVar17 + local_28;
    puVar15 = puVar15 + -local_28;
    uVar17 = local_28;
  }
LAB_004bf494:
  local_8 = local_8 + -uVar17;
  local_c = puVar15;
  goto LAB_004bf107;
}

