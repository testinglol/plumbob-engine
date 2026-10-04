
void __fastcall
FUN_00498830(int param_1,int param_2,int param_3,ushort *param_4,int param_5,int param_6,int param_7
            ,ushort *param_8,int param_9)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  undefined2 *puVar10;
  ushort *puVar11;
  uint uVar12;
  uint local_28;
  int local_24;
  uint local_14;
  uint local_10;
  ushort *local_c;
  int local_8;
  
  iVar5 = param_6;
  iVar4 = param_5;
  iVar3 = (int)param_4;
  iVar6 = (int)param_8 + -1;
  if (param_8 != (ushort *)0x0) {
    param_3 = iVar6 * param_6 + param_3;
    param_1 = iVar6 * (int)param_4 + param_1;
    puVar11 = (ushort *)(iVar6 * param_5 + param_2);
    local_24 = (int)param_8;
    do {
      local_8 = param_7;
      param_4 = puVar11;
      param_5 = param_3;
      param_6 = param_1;
      iVar6 = param_7;
      if (0x20 < param_7) {
        local_28 = param_7 - 1U >> 5;
        iVar6 = param_7 + local_28 * -0x20;
        do {
          uVar12 = 1;
          param_8 = (ushort *)0x0;
          local_14 = 0;
          iVar9 = 0;
          puVar10 = &DAT_006e5c0c;
          do {
            iVar7 = (uint)*(byte *)(iVar9 + param_5) + param_9;
            if ((iVar7 < 8) || (0xf7 < iVar7)) {
              if (0xf7 < iVar7) {
                local_14 = local_14 | uVar12;
              }
            }
            else {
              param_8 = (ushort *)((uint)param_8 | uVar12);
            }
            *puVar10 = (short)iVar7;
            iVar9 = iVar9 + 1;
            puVar10 = puVar10 + 1;
            uVar12 = uVar12 << 1;
          } while ((int)puVar10 < 0x6e5c4c);
          if (param_8 == (ushort *)0xffffffff) {
            puVar10 = &DAT_006e5d0c;
            do {
              *puVar10 = *(undefined2 *)(param_6 + -0x6e5d0c + (int)puVar10);
              puVar10 = puVar10 + 1;
            } while ((int)puVar10 < 0x6e5d4c);
            iVar9 = 0;
            param_8 = param_4;
            do {
              uVar1 = *param_8;
              uVar2 = *(ushort *)((int)&DAT_006e5d0c + iVar9);
              iVar7 = (uint)(*(byte *)((int)&DAT_006e5c0c + iVar9) >> 3) * 0x20;
              iVar9 = iVar9 + 2;
              *(ushort *)((param_6 - (int)param_4) + (int)param_8) =
                   ((ushort)(byte)(&DAT_006e5e5c)
                                  [(uVar2 >> 6 & 0x1f) + ((uVar1 >> 6 & 0x1f) + iVar7) * 0x20] |
                   (ushort)(byte)(&DAT_006e5e5c)
                                 [(uint)(uVar2 >> 0xb) + ((uint)(uVar1 >> 0xb) + iVar7) * 0x20] << 5
                   ) << 6 | (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar2 & 0x1f) + ((uVar1 & 0x1f) + iVar7) * 0x20];
              param_8 = param_8 + 1;
            } while (iVar9 < 0x40);
          }
          else if (param_8 != (ushort *)0x0) {
            puVar10 = &DAT_006e5d0c;
            do {
              *puVar10 = *(undefined2 *)((int)puVar10 + param_6 + -0x6e5d0c);
              puVar10 = puVar10 + 1;
            } while ((int)puVar10 < 0x6e5d4c);
            iVar9 = 0;
            local_c = param_4;
            local_10 = 1;
            do {
              if ((local_10 & (uint)param_8) != 0) {
                uVar1 = *local_c;
                uVar2 = *(ushort *)((int)&DAT_006e5d0c + iVar9);
                iVar7 = ((uint)(int)*(short *)((int)&DAT_006e5c0c + iVar9) >> 3) * 0x20;
                *(ushort *)((param_6 - (int)param_4) + (int)local_c) =
                     ((ushort)(byte)(&DAT_006e5e5c)
                                    [(uVar2 >> 6 & 0x1f) + ((uVar1 >> 6 & 0x1f) + iVar7) * 0x20] |
                     (ushort)(byte)(&DAT_006e5e5c)
                                   [(uint)(uVar2 >> 0xb) + ((uint)(uVar1 >> 0xb) + iVar7) * 0x20] <<
                     5) << 6 | (ushort)(byte)(&DAT_006e5e5c)
                                             [(uVar2 & 0x1f) + ((uVar1 & 0x1f) + iVar7) * 0x20];
              }
              local_c = local_c + 1;
              local_10 = local_10 << 1;
              iVar9 = iVar9 + 2;
            } while (iVar9 < 0x40);
          }
          if (local_14 == 0xffffffff) {
            iVar9 = 0x20;
            puVar8 = param_4;
            do {
              *(ushort *)((param_6 - (int)param_4) + (int)puVar8) = *puVar8;
              puVar8 = puVar8 + 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          else if (local_14 != 0) {
            uVar12 = 1;
            iVar9 = 0x20;
            puVar8 = param_4;
            do {
              if ((local_14 & uVar12) != 0) {
                *(ushort *)((param_6 - (int)param_4) + (int)puVar8) = *puVar8;
              }
              puVar8 = puVar8 + 1;
              uVar12 = uVar12 << 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          param_4 = param_4 + 0x20;
          param_6 = param_6 + 0x40;
          param_5 = param_5 + 0x20;
          local_28 = local_28 - 1;
          local_8 = iVar6;
        } while (local_28 != 0);
      }
      while (0 < iVar6) {
        iVar9 = 0;
        param_8 = (ushort *)0x0;
        local_10 = 0;
        uVar12 = 1;
        if (0 < local_8) {
          puVar10 = &DAT_006e5c0c;
          do {
            iVar7 = (uint)*(byte *)(iVar9 + param_5) + param_9;
            if ((iVar7 < 8) || (0xf7 < iVar7)) {
              if (0xf7 < iVar7) {
                local_10 = local_10 | uVar12;
              }
            }
            else {
              param_8 = (ushort *)((uint)param_8 | uVar12);
            }
            *puVar10 = (short)iVar7;
            iVar9 = iVar9 + 1;
            puVar10 = puVar10 + 1;
            uVar12 = uVar12 << 1;
          } while (iVar9 < local_8);
          if (param_8 != (ushort *)0x0) {
            puVar10 = &DAT_006e5d0c;
            iVar9 = local_8;
            do {
              *puVar10 = *(undefined2 *)((int)puVar10 + param_6 + -0x6e5d0c);
              puVar10 = puVar10 + 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
            local_c = (ushort *)0x0;
            local_14 = 1;
            puVar8 = param_4;
            do {
              if ((local_14 & (uint)param_8) != 0) {
                uVar1 = *puVar8;
                uVar2 = (&DAT_006e5d0c)[(int)local_c];
                iVar9 = ((uint)(int)(short)(&DAT_006e5c0c)[(int)local_c] >> 3) * 0x20;
                *(ushort *)((param_6 - (int)param_4) + (int)puVar8) =
                     ((ushort)(byte)(&DAT_006e5e5c)
                                    [(uVar2 >> 6 & 0x1f) + ((uVar1 >> 6 & 0x1f) + iVar9) * 0x20] |
                     (ushort)(byte)(&DAT_006e5e5c)
                                   [(uint)(uVar2 >> 0xb) + ((uint)(uVar1 >> 0xb) + iVar9) * 0x20] <<
                     5) << 6 | (ushort)(byte)(&DAT_006e5e5c)
                                             [(uVar2 & 0x1f) + ((uVar1 & 0x1f) + iVar9) * 0x20];
              }
              local_c = (ushort *)((int)local_c + 1);
              local_14 = local_14 << 1;
              puVar8 = puVar8 + 1;
            } while ((int)local_c < local_8);
          }
          if (local_10 != 0) {
            uVar12 = 1;
            puVar8 = param_4;
            iVar9 = local_8;
            do {
              if ((local_10 & uVar12) != 0) {
                *(ushort *)((param_6 - (int)param_4) + (int)puVar8) = *puVar8;
              }
              puVar8 = puVar8 + 1;
              uVar12 = uVar12 << 1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
        }
        param_4 = param_4 + local_8;
        param_5 = param_5 + local_8;
        param_6 = param_6 + local_8 * 2;
        iVar6 = iVar6 - local_8;
      }
      local_24 = local_24 + -1;
      puVar11 = (ushort *)((int)puVar11 - iVar4);
      param_1 = param_1 - iVar3;
      param_3 = param_3 - iVar5;
    } while (local_24 != 0);
  }
  return;
}

