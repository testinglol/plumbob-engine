
void FUN_004bc271(int param_1,byte *param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  undefined2 uVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  undefined2 *puVar5;
  ushort *puVar6;
  byte bVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  uint *puVar12;
  undefined2 *puVar13;
  uint uVar14;
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
      uVar9 = 0;
      if (0 < local_8) {
        puVar8 = &DAT_006f094c;
        puVar3 = (ushort *)(param_4 + local_10 * 2);
        iVar10 = local_8;
        do {
          *puVar8 = (uint)*puVar3;
          puVar3 = puVar3 + 1;
          puVar8 = puVar8 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      iVar10 = 0;
      pbVar11 = param_2;
      if (0 < local_8) {
        do {
          iVar4 = *(short *)(param_7 + (uint)*pbVar11 * 2) + param_6;
          if (iVar4 <= (int)(&DAT_006f094c)[iVar10]) {
            *(int *)(&DAT_006f090c + iVar10 * 2) = iVar4;
            uVar9 = uVar9 | 1 << ((byte)iVar10 & 0x1f);
          }
          iVar10 = iVar10 + 1;
          pbVar11 = pbVar11 + 3;
        } while (iVar10 < local_8);
        if (uVar9 == 0xffff) {
          puVar12 = &DAT_006f09cc;
          pbVar11 = param_2 + 2;
          puVar8 = &DAT_006f09cc;
          do {
            *puVar8 = (uint)*pbVar11;
            puVar8 = puVar8 + 1;
            pbVar11 = pbVar11 + 3;
          } while ((int)puVar8 < 0x6f0a0c);
          bVar7 = 0;
          local_14 = (ushort *)0x0;
          local_18 = 0;
          do {
            uVar9 = *puVar12;
            if ((uVar9 < 8) || (0xf7 < uVar9)) {
              if (0xf7 < uVar9) {
                local_18 = local_18 | 1 << (bVar7 & 0x1f);
              }
            }
            else {
              local_14 = (ushort *)((uint)local_14 | 1 << (bVar7 & 0x1f));
            }
            puVar12 = puVar12 + 1;
            bVar7 = bVar7 + 1;
          } while ((int)puVar12 < 0x6f0a0c);
          if (local_14 != (ushort *)0x0) {
            puVar8 = &DAT_006f098c;
            if (local_14 == (ushort *)0xffff) {
              local_14 = (ushort *)(local_10 * 2 + param_3);
              puVar3 = local_14;
              do {
                *puVar8 = (uint)*puVar3;
                puVar8 = puVar8 + 1;
                puVar3 = puVar3 + 1;
              } while ((int)puVar8 < 0x6f09cc);
              pbVar11 = param_2 + 1;
              puVar8 = &DAT_006f0a0c;
              do {
                bVar7 = *pbVar11;
                pbVar11 = pbVar11 + 3;
                *puVar8 = (uint)*(ushort *)(param_5 + (uint)bVar7 * 2);
                puVar8 = puVar8 + 1;
              } while ((int)puVar8 < 0x6f0a4c);
              puVar13 = &DAT_006f090c;
              puVar5 = (undefined2 *)(local_10 * 2 + param_4);
              do {
                uVar1 = *puVar13;
                puVar13 = puVar13 + 2;
                *puVar5 = uVar1;
                puVar5 = puVar5 + 1;
              } while ((int)puVar13 < 0x6f094c);
              iVar10 = 0;
              do {
                uVar9 = *(uint *)((int)&DAT_006f0a0c + iVar10);
                uVar14 = *(uint *)((int)&DAT_006f098c + iVar10);
                iVar4 = (*(uint *)((int)&DAT_006f09cc + iVar10) & 0x1f) * 0x20;
                iVar10 = iVar10 + 4;
                *local_14 = ((ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar14 >> 0xb & 0x1f) +
                                            ((uVar9 >> 0xb & 0x1f) + iVar4) * 0x20] << 5 |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar14 >> 6 & 0x1f) +
                                           ((uVar9 >> 6 & 0x1f) + iVar4) * 0x20]) << 6 |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar14 & 0x1f) + ((uVar9 & 0x1f) + iVar4) * 0x20];
                local_14 = local_14 + 1;
              } while (iVar10 < 0x40);
            }
            else {
              puVar3 = (ushort *)(param_3 + local_10 * 2);
              puVar6 = puVar3;
              iVar10 = local_8;
              do {
                *puVar8 = (uint)*puVar6;
                puVar6 = puVar6 + 1;
                puVar8 = puVar8 + 1;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
              pbVar11 = param_2 + 1;
              puVar8 = &DAT_006f0a0c;
              iVar10 = local_8;
              do {
                bVar7 = *pbVar11;
                pbVar11 = pbVar11 + 3;
                *puVar8 = (uint)*(ushort *)(param_5 + (uint)bVar7 * 2);
                puVar8 = puVar8 + 1;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
              local_c = 0;
              do {
                if (((uint)local_14 & 1 << ((byte)local_c & 0x1f)) != 0) {
                  *(undefined2 *)((param_4 - param_3) + (int)puVar3) = (&DAT_006f090c)[local_c * 2];
                  uVar9 = (&DAT_006f0a0c)[local_c];
                  uVar14 = (&DAT_006f098c)[local_c];
                  iVar10 = ((&DAT_006f09cc)[local_c] & 0x1f) * 0x20;
                  *puVar3 = ((ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar14 >> 0xb & 0x1f) +
                                            ((uVar9 >> 0xb & 0x1f) + iVar10) * 0x20] << 5 |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar14 >> 6 & 0x1f) +
                                           ((uVar9 >> 6 & 0x1f) + iVar10) * 0x20]) << 6 |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar14 & 0x1f) + ((uVar9 & 0x1f) + iVar10) * 0x20];
                }
                local_c = local_c + 1;
                puVar3 = puVar3 + 1;
              } while (local_c < local_8);
            }
          }
          if (local_18 != 0) {
            if (local_18 == 0xffff) {
              puVar13 = &DAT_006f090c;
              puVar5 = (undefined2 *)(param_4 + local_10 * 2);
              do {
                uVar1 = *puVar13;
                puVar13 = puVar13 + 2;
                *puVar5 = uVar1;
                puVar5 = puVar5 + 1;
              } while ((int)puVar13 < 0x6f094c);
              puVar5 = (undefined2 *)(param_3 + local_10 * 2);
              pbVar11 = param_2 + 1;
              iVar10 = 0x10;
              do {
                bVar7 = *pbVar11;
                pbVar11 = pbVar11 + 3;
                *puVar5 = *(undefined2 *)(param_5 + (uint)bVar7 * 2);
                puVar5 = puVar5 + 1;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
            }
            else {
              local_c = 0;
              pbVar11 = param_2 + 1;
              puVar13 = &DAT_006f090c;
              puVar5 = (undefined2 *)(param_3 + local_10 * 2);
              do {
                if ((local_18 & 1 << ((byte)local_c & 0x1f)) != 0) {
                  *(undefined2 *)((int)puVar5 + (param_4 - param_3)) = *puVar13;
                  *puVar5 = *(undefined2 *)(param_5 + (uint)*pbVar11 * 2);
                }
                local_c = local_c + 1;
                puVar5 = puVar5 + 1;
                puVar13 = puVar13 + 2;
                pbVar11 = pbVar11 + 3;
              } while (local_c < local_8);
            }
          }
        }
        else if (uVar9 != 0) {
          pbVar11 = param_2 + 2;
          puVar8 = &DAT_006f09cc;
          iVar10 = local_8;
          do {
            *puVar8 = (uint)*pbVar11;
            puVar8 = puVar8 + 1;
            pbVar11 = pbVar11 + 3;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          iVar10 = 0;
          puVar8 = &DAT_006f09cc;
          local_18 = 0;
          local_14 = (ushort *)0x0;
          do {
            uVar14 = 1 << ((byte)iVar10 & 0x1f);
            if ((uVar9 & uVar14) != 0) {
              uVar2 = *puVar8;
              if ((uVar2 < 8) || (0xf7 < uVar2)) {
                if (0xf7 < uVar2) {
                  local_14 = (ushort *)((uint)local_14 | uVar14);
                }
              }
              else {
                local_18 = local_18 | uVar14;
              }
            }
            iVar10 = iVar10 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar10 < local_8);
          if (local_18 != 0) {
            puVar8 = &DAT_006f098c;
            puVar3 = (ushort *)(param_3 + local_10 * 2);
            puVar6 = puVar3;
            iVar10 = local_8;
            do {
              *puVar8 = (uint)*puVar6;
              puVar6 = puVar6 + 1;
              puVar8 = puVar8 + 1;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
            pbVar11 = param_2 + 1;
            puVar8 = &DAT_006f0a0c;
            iVar10 = local_8;
            do {
              bVar7 = *pbVar11;
              pbVar11 = pbVar11 + 3;
              *puVar8 = (uint)*(ushort *)(param_5 + (uint)bVar7 * 2);
              puVar8 = puVar8 + 1;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
            local_c = 0;
            do {
              if ((local_18 & 1 << ((byte)local_c & 0x1f)) != 0) {
                *(undefined2 *)((param_4 - param_3) + (int)puVar3) = (&DAT_006f090c)[local_c * 2];
                uVar9 = (&DAT_006f0a0c)[local_c];
                uVar14 = (&DAT_006f098c)[local_c];
                iVar10 = ((&DAT_006f09cc)[local_c] & 0x1f) * 0x20;
                *puVar3 = ((ushort)(byte)(&DAT_006e5e5c)
                                         [(uVar14 >> 0xb & 0x1f) +
                                          ((uVar9 >> 0xb & 0x1f) + iVar10) * 0x20] << 5 |
                          (ushort)(byte)(&DAT_006e5e5c)
                                        [(uVar14 >> 6 & 0x1f) +
                                         ((uVar9 >> 6 & 0x1f) + iVar10) * 0x20]) << 6 |
                          (ushort)(byte)(&DAT_006e5e5c)
                                        [(uVar14 & 0x1f) + ((uVar9 & 0x1f) + iVar10) * 0x20];
              }
              local_c = local_c + 1;
              puVar3 = puVar3 + 1;
            } while (local_c < local_8);
          }
          if (local_14 != (ushort *)0x0) {
            local_c = 0;
            pbVar11 = param_2 + 1;
            puVar13 = &DAT_006f090c;
            puVar5 = (undefined2 *)(param_3 + local_10 * 2);
            do {
              if (((uint)local_14 & 1 << ((byte)local_c & 0x1f)) != 0) {
                *(undefined2 *)((param_4 - param_3) + (int)puVar5) = *puVar13;
                *puVar5 = *(undefined2 *)(param_5 + (uint)*pbVar11 * 2);
              }
              local_c = local_c + 1;
              puVar5 = puVar5 + 1;
              puVar13 = puVar13 + 2;
              pbVar11 = pbVar11 + 3;
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

