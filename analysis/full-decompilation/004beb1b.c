
void FUN_004beb1b(int param_1,byte *param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  undefined2 uVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  undefined2 *puVar5;
  byte bVar6;
  uint *puVar7;
  int iVar8;
  byte *pbVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  undefined2 *puVar13;
  ushort *puVar14;
  int local_1c;
  uint local_18;
  ushort *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  if (0 < param_1) {
    do {
      local_8 = param_1 - local_10;
      if (0xf < local_8) {
        local_8 = 0x10;
      }
      uVar12 = 0;
      if (0 < local_8) {
        puVar7 = &DAT_006f094c;
        puVar3 = (ushort *)(param_4 + local_10 * -2);
        iVar8 = local_8;
        do {
          *puVar7 = (uint)*puVar3;
          puVar3 = puVar3 + -1;
          puVar7 = puVar7 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar8 = 0;
      pbVar9 = param_2;
      if (0 < local_8) {
        do {
          iVar4 = *(short *)(param_7 + (uint)*pbVar9 * 2) + param_6;
          if (iVar4 <= (int)(&DAT_006f094c)[iVar8]) {
            *(int *)(&DAT_006f090c + iVar8 * 2) = iVar4;
            uVar12 = uVar12 | 1 << ((byte)iVar8 & 0x1f);
          }
          iVar8 = iVar8 + 1;
          pbVar9 = pbVar9 + 3;
        } while (iVar8 < local_8);
        if (uVar12 == 0xffff) {
          puVar10 = &DAT_006f09cc;
          pbVar9 = param_2 + 2;
          puVar7 = &DAT_006f09cc;
          do {
            *puVar7 = (uint)*pbVar9;
            puVar7 = puVar7 + 1;
            pbVar9 = pbVar9 + 3;
          } while ((int)puVar7 < 0x6f0a0c);
          bVar6 = 0;
          local_14 = (ushort *)0x0;
          local_18 = 0;
          do {
            uVar12 = *puVar10;
            if ((uVar12 < 8) || (0xf7 < uVar12)) {
              if (0xf7 < uVar12) {
                local_18 = local_18 | 1 << (bVar6 & 0x1f);
              }
            }
            else {
              local_14 = (ushort *)((uint)local_14 | 1 << (bVar6 & 0x1f));
            }
            puVar10 = puVar10 + 1;
            bVar6 = bVar6 + 1;
          } while ((int)puVar10 < 0x6f0a0c);
          if (local_14 != (ushort *)0x0) {
            puVar7 = &DAT_006f098c;
            if (local_14 == (ushort *)0xffff) {
              local_14 = (ushort *)(param_3 + local_10 * -2);
              puVar3 = local_14;
              do {
                *puVar7 = (uint)*puVar3;
                puVar7 = puVar7 + 1;
                puVar3 = puVar3 + -1;
              } while ((int)puVar7 < 0x6f09cc);
              pbVar9 = param_2 + 1;
              puVar7 = &DAT_006f0a0c;
              iVar8 = local_8;
              do {
                bVar6 = *pbVar9;
                pbVar9 = pbVar9 + 3;
                *puVar7 = (uint)*(ushort *)(param_5 + (uint)bVar6 * 2);
                puVar7 = puVar7 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
              puVar13 = &DAT_006f090c;
              puVar5 = (undefined2 *)(local_10 * -2 + param_4);
              do {
                uVar1 = *puVar13;
                puVar13 = puVar13 + 2;
                *puVar5 = uVar1;
                puVar5 = puVar5 + -1;
              } while ((int)puVar13 < 0x6f094c);
              iVar8 = 0;
              do {
                uVar12 = *(uint *)((int)&DAT_006f0a0c + iVar8);
                uVar11 = *(uint *)((int)&DAT_006f098c + iVar8);
                iVar4 = (*(uint *)((int)&DAT_006f09cc + iVar8) & 0x1f) * 0x20;
                iVar8 = iVar8 + 4;
                *local_14 = ((ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar11 >> 10 & 0x1f) +
                                            ((uVar12 >> 10 & 0x1f) + iVar4) * 0x20] << 5 |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar11 >> 5 & 0x1f) +
                                           ((uVar12 >> 5 & 0x1f) + iVar4) * 0x20]) << 5 |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar11 & 0x1f) + ((uVar12 & 0x1f) + iVar4) * 0x20];
                local_14 = local_14 + -1;
              } while (iVar8 < 0x40);
            }
            else {
              puVar14 = (ushort *)(param_3 + local_10 * -2);
              puVar3 = puVar14;
              iVar8 = local_8;
              do {
                *puVar7 = (uint)*puVar3;
                puVar3 = puVar3 + -1;
                puVar7 = puVar7 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
              pbVar9 = param_2 + 1;
              puVar7 = &DAT_006f0a0c;
              local_1c = local_8;
              do {
                bVar6 = *pbVar9;
                pbVar9 = pbVar9 + 3;
                *puVar7 = (uint)*(ushort *)(param_5 + (uint)bVar6 * 2);
                puVar7 = puVar7 + 1;
                local_1c = local_1c + -1;
              } while (local_1c != 0);
              local_c = 0;
              do {
                if (((uint)local_14 & 1 << ((byte)local_c & 0x1f)) != 0) {
                  *(undefined2 *)((param_4 - param_3) + (int)puVar14) = (&DAT_006f090c)[local_c * 2]
                  ;
                  uVar12 = (&DAT_006f0a0c)[local_c];
                  uVar11 = (&DAT_006f098c)[local_c];
                  iVar8 = ((&DAT_006f09cc)[local_c] & 0x1f) * 0x20;
                  *puVar14 = ((ushort)(byte)(&DAT_006e5e5c)
                                            [(uVar11 >> 10 & 0x1f) +
                                             ((uVar12 >> 10 & 0x1f) + iVar8) * 0x20] << 5 |
                             (ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar11 >> 5 & 0x1f) +
                                            ((uVar12 >> 5 & 0x1f) + iVar8) * 0x20]) << 5 |
                             (ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar11 & 0x1f) + ((uVar12 & 0x1f) + iVar8) * 0x20];
                }
                local_c = local_c + 1;
                puVar14 = puVar14 + -1;
              } while (local_c < local_8);
            }
          }
          if (local_18 != 0) {
            if (local_18 == 0xffff) {
              puVar13 = &DAT_006f090c;
              puVar5 = (undefined2 *)(param_4 + local_10 * -2);
              do {
                uVar1 = *puVar13;
                puVar13 = puVar13 + 2;
                *puVar5 = uVar1;
                puVar5 = puVar5 + -1;
              } while ((int)puVar13 < 0x6f094c);
              puVar5 = (undefined2 *)(local_10 * -2 + param_3);
              pbVar9 = param_2 + 1;
              iVar8 = 0x10;
              do {
                bVar6 = *pbVar9;
                pbVar9 = pbVar9 + 3;
                *puVar5 = *(undefined2 *)(param_5 + (uint)bVar6 * 2);
                puVar5 = puVar5 + -1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
            else {
              local_c = 0;
              pbVar9 = param_2 + 1;
              puVar5 = (undefined2 *)(param_3 + local_10 * -2);
              puVar13 = &DAT_006f090c;
              do {
                if ((local_18 & 1 << ((byte)local_c & 0x1f)) != 0) {
                  *(undefined2 *)((int)puVar5 + (param_4 - param_3)) = *puVar13;
                  *puVar5 = *(undefined2 *)(param_5 + (uint)*pbVar9 * 2);
                }
                local_c = local_c + 1;
                puVar5 = puVar5 + -1;
                puVar13 = puVar13 + 2;
                pbVar9 = pbVar9 + 3;
              } while (local_c < local_8);
            }
          }
        }
        else if (uVar12 != 0) {
          pbVar9 = param_2 + 2;
          puVar7 = &DAT_006f09cc;
          iVar8 = local_8;
          do {
            *puVar7 = (uint)*pbVar9;
            puVar7 = puVar7 + 1;
            pbVar9 = pbVar9 + 3;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          iVar8 = 0;
          puVar7 = &DAT_006f09cc;
          local_18 = 0;
          local_14 = (ushort *)0x0;
          do {
            uVar11 = 1 << ((byte)iVar8 & 0x1f);
            if ((uVar12 & uVar11) != 0) {
              uVar2 = *puVar7;
              if ((uVar2 < 8) || (0xf7 < uVar2)) {
                if (0xf7 < uVar2) {
                  local_14 = (ushort *)((uint)local_14 | uVar11);
                }
              }
              else {
                local_18 = local_18 | uVar11;
              }
            }
            iVar8 = iVar8 + 1;
            puVar7 = puVar7 + 1;
          } while (iVar8 < local_8);
          if (local_18 != 0) {
            puVar14 = (ushort *)(param_3 + local_10 * -2);
            puVar7 = &DAT_006f098c;
            puVar3 = puVar14;
            iVar8 = local_8;
            do {
              *puVar7 = (uint)*puVar3;
              puVar3 = puVar3 + -1;
              puVar7 = puVar7 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
            pbVar9 = param_2 + 1;
            puVar7 = &DAT_006f0a0c;
            iVar8 = local_8;
            do {
              bVar6 = *pbVar9;
              pbVar9 = pbVar9 + 3;
              *puVar7 = (uint)*(ushort *)(param_5 + (uint)bVar6 * 2);
              puVar7 = puVar7 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
            local_c = 0;
            do {
              if ((local_18 & 1 << ((byte)local_c & 0x1f)) != 0) {
                *(undefined2 *)((param_4 - param_3) + (int)puVar14) = (&DAT_006f090c)[local_c * 2];
                uVar12 = (&DAT_006f0a0c)[local_c];
                uVar11 = (&DAT_006f098c)[local_c];
                iVar8 = ((&DAT_006f09cc)[local_c] & 0x1f) * 0x20;
                *puVar14 = ((ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar11 >> 10 & 0x1f) +
                                           ((uVar12 >> 10 & 0x1f) + iVar8) * 0x20] << 5 |
                           (ushort)(byte)(&DAT_006e5e5c)
                                         [(uVar11 >> 5 & 0x1f) +
                                          ((uVar12 >> 5 & 0x1f) + iVar8) * 0x20]) << 5 |
                           (ushort)(byte)(&DAT_006e5e5c)
                                         [(uVar11 & 0x1f) + ((uVar12 & 0x1f) + iVar8) * 0x20];
              }
              local_c = local_c + 1;
              puVar14 = puVar14 + -1;
            } while (local_c < local_8);
          }
          if (local_14 != (ushort *)0x0) {
            local_c = 0;
            pbVar9 = param_2 + 1;
            puVar5 = (undefined2 *)(param_3 + local_10 * -2);
            puVar13 = &DAT_006f090c;
            do {
              if (((uint)local_14 & 1 << ((byte)local_c & 0x1f)) != 0) {
                *(undefined2 *)((int)puVar5 + (param_4 - param_3)) = *puVar13;
                *puVar5 = *(undefined2 *)(param_5 + (uint)*pbVar9 * 2);
              }
              local_c = local_c + 1;
              puVar5 = puVar5 + -1;
              puVar13 = puVar13 + 2;
              pbVar9 = pbVar9 + 3;
            } while (local_c < local_8);
          }
        }
      }
      local_10 = local_10 + local_8;
      param_2 = param_2 + local_8 * 3;
    } while (local_10 < param_1);
  }
  return;
}

