
void __fastcall
FUN_00499b54(int param_1,int param_2,int param_3,ushort *param_4,int param_5,int param_6,
            ushort *param_7)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  ushort *puVar8;
  uint uVar9;
  ushort *puVar10;
  int iVar11;
  ushort *puVar12;
  uint uVar13;
  int iVar14;
  int local_28;
  uint local_1c;
  ushort *local_18;
  int local_14;
  ushort *local_10;
  uint local_c;
  uint local_8;
  
  iVar5 = param_5;
  iVar4 = (int)param_4;
  if (param_7 != (ushort *)0x0) {
    puVar12 = (ushort *)(((int)param_7 + -1) * (int)param_4 + param_1);
    param_2 = ((int)param_7 + -1) * param_5 + param_2;
    local_28 = (int)param_7;
    do {
      local_14 = param_6;
      param_4 = puVar12;
      param_5 = param_2;
      iVar6 = param_6;
      if (0x20 < param_6) {
        local_18 = (ushort *)(param_6 - 1U >> 5);
        iVar6 = param_6 + (int)local_18 * -0x20;
        do {
          iVar11 = 0;
          param_7 = (ushort *)0x0;
          local_8 = 0;
          uVar13 = 1;
          do {
            uVar3 = *(uint *)(param_3 + (uint)*(byte *)(iVar11 + param_5) * 4);
            uVar9 = uVar3 >> 0x10;
            if ((uVar9 < 8) || (0xf7 < uVar9)) {
              if (0xf7 < uVar9) {
                local_8 = local_8 | uVar13;
              }
            }
            else {
              param_7 = (ushort *)((uint)param_7 | uVar13);
            }
            (&DAT_006e5c0c)[iVar11] = (short)(uVar3 >> 0x10);
            (&DAT_006e5c4c)[iVar11] = (short)uVar3;
            iVar11 = iVar11 + 1;
            uVar13 = uVar13 << 1;
          } while (iVar11 < 0x20);
          if (param_7 == (ushort *)0xffffffff) {
            puVar7 = &DAT_006e5d0c;
            do {
              *puVar7 = *(undefined2 *)((int)(param_4 + -0x372e86) + (int)puVar7);
              puVar7 = puVar7 + 1;
            } while ((int)puVar7 < 0x6e5d4c);
            param_7 = param_4;
            iVar11 = 0;
            do {
              uVar1 = *(ushort *)((int)&DAT_006e5c4c + iVar11);
              uVar2 = *(ushort *)((int)&DAT_006e5d0c + iVar11);
              iVar14 = (*(short *)((int)&DAT_006e5c0c + iVar11) >> 3) * 0x20;
              iVar11 = iVar11 + 2;
              *param_7 = ((ushort)(byte)(&DAT_006e5e5c)
                                        [(uVar2 >> 6 & 0x1f) + ((uVar1 >> 6 & 0x1f) + iVar14) * 0x20
                                        ] |
                         (ushort)(byte)(&DAT_006e5e5c)
                                       [(uint)(uVar2 >> 0xb) +
                                        ((uint)(uVar1 >> 0xb) + iVar14) * 0x20] << 5) << 6 |
                         (ushort)(byte)(&DAT_006e5e5c)
                                       [(uVar2 & 0x1f) + ((uVar1 & 0x1f) + iVar14) * 0x20];
              param_7 = param_7 + 1;
            } while (iVar11 < 0x40);
          }
          else if (param_7 != (ushort *)0x0) {
            puVar7 = &DAT_006e5d0c;
            do {
              *puVar7 = *(undefined2 *)((int)puVar7 + (int)(param_4 + -0x372e86));
              puVar7 = puVar7 + 1;
            } while ((int)puVar7 < 0x6e5d4c);
            local_10 = param_4;
            local_c = 1;
            iVar11 = 0;
            do {
              if ((local_c & (uint)param_7) != 0) {
                uVar1 = *(ushort *)((int)&DAT_006e5c4c + iVar11);
                uVar2 = *(ushort *)((int)&DAT_006e5d0c + iVar11);
                iVar14 = (*(short *)((int)&DAT_006e5c0c + iVar11) >> 3) * 0x20;
                *local_10 = ((ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar2 >> 6 & 0x1f) +
                                            ((uVar1 >> 6 & 0x1f) + iVar14) * 0x20] |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uint)(uVar2 >> 0xb) +
                                           ((uint)(uVar1 >> 0xb) + iVar14) * 0x20] << 5) << 6 |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar2 & 0x1f) + ((uVar1 & 0x1f) + iVar14) * 0x20];
              }
              local_10 = local_10 + 1;
              local_c = local_c << 1;
              iVar11 = iVar11 + 2;
            } while (iVar11 < 0x40);
          }
          if (local_8 == 0xffffffff) {
            puVar8 = &DAT_006e5c4c;
            puVar10 = param_4;
            do {
              *puVar10 = *puVar8;
              puVar10 = puVar10 + 1;
              puVar8 = puVar8 + 1;
            } while ((int)puVar8 < 0x6e5c8c);
          }
          else if (local_8 != 0) {
            uVar13 = 1;
            puVar8 = &DAT_006e5c4c;
            puVar10 = param_4;
            do {
              if ((local_8 & uVar13) != 0) {
                *puVar10 = *puVar8;
              }
              puVar8 = puVar8 + 1;
              puVar10 = puVar10 + 1;
              uVar13 = uVar13 << 1;
            } while ((int)puVar8 < 0x6e5c8c);
          }
          param_5 = param_5 + 0x20;
          param_4 = param_4 + 0x20;
          local_18 = (ushort *)((int)local_18 - 1);
          local_14 = iVar6;
        } while (local_18 != (ushort *)0x0);
      }
      while (iVar6 != 0) {
        iVar11 = 0;
        local_8 = 0;
        local_10 = (ushort *)0x0;
        uVar13 = 1;
        if (0 < local_14) {
          do {
            uVar3 = *(uint *)(param_3 + (uint)*(byte *)(iVar11 + param_5) * 4);
            uVar9 = uVar3 >> 0x10;
            if ((uVar9 < 8) || (0xf7 < uVar9)) {
              if (0xf7 < uVar9) {
                local_10 = (ushort *)((uint)local_10 | uVar13);
              }
            }
            else {
              local_8 = local_8 | uVar13;
            }
            (&DAT_006e5c0c)[iVar11] = (short)(uVar3 >> 0x10);
            (&DAT_006e5c4c)[iVar11] = (short)uVar3;
            iVar11 = iVar11 + 1;
            uVar13 = uVar13 << 1;
          } while (iVar11 < local_14);
          if (local_8 != 0) {
            puVar7 = &DAT_006e5d0c;
            iVar11 = local_14;
            do {
              *puVar7 = *(undefined2 *)((int)puVar7 + (int)(param_4 + -0x372e86));
              puVar7 = puVar7 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            local_c = 0;
            local_1c = 1;
            local_18 = param_4;
            do {
              if ((local_8 & local_1c) != 0) {
                uVar1 = (&DAT_006e5c4c)[local_c];
                uVar2 = (&DAT_006e5d0c)[local_c];
                iVar11 = ((short)(&DAT_006e5c0c)[local_c] >> 3) * 0x20;
                *local_18 = ((ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar2 >> 6 & 0x1f) +
                                            ((uVar1 >> 6 & 0x1f) + iVar11) * 0x20] |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uint)(uVar2 >> 0xb) +
                                           ((uint)(uVar1 >> 0xb) + iVar11) * 0x20] << 5) << 6 |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar2 & 0x1f) + ((uVar1 & 0x1f) + iVar11) * 0x20];
              }
              local_c = local_c + 1;
              local_18 = local_18 + 1;
              local_1c = local_1c << 1;
            } while ((int)local_c < local_14);
          }
          if (local_10 != (ushort *)0x0) {
            puVar8 = &DAT_006e5c4c;
            uVar13 = 1;
            puVar10 = param_4;
            iVar11 = local_14;
            do {
              if (((uint)local_10 & uVar13) != 0) {
                *puVar10 = *puVar8;
              }
              puVar8 = puVar8 + 1;
              puVar10 = puVar10 + 1;
              uVar13 = uVar13 << 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
          }
        }
        param_4 = param_4 + local_14;
        param_5 = param_5 + local_14;
        iVar6 = iVar6 - local_14;
      }
      local_28 = local_28 + -1;
      param_2 = param_2 - iVar5;
      puVar12 = (ushort *)((int)puVar12 - iVar4);
    } while (local_28 != 0);
  }
  return;
}

