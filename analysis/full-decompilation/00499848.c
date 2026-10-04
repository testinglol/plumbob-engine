
void __fastcall
FUN_00499848(int param_1,int param_2,ushort *param_3,ushort *param_4,ushort *param_5,ushort *param_6
            ,int param_7,int param_8,byte param_9,ushort param_10)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  ushort *puVar11;
  ushort *puVar12;
  uint uVar13;
  int iVar14;
  ushort *puVar15;
  ushort *puVar16;
  uint local_1c;
  int local_18;
  uint local_8;
  
  iVar8 = (int)param_6;
  iVar7 = (int)param_5;
  iVar6 = (int)param_4;
  uVar9 = (uint)(param_9 >> 3);
  iVar10 = param_8 + -1;
  if (param_8 != 0) {
    puVar16 = (ushort *)(iVar10 * (int)param_4 + param_1);
    puVar12 = (ushort *)(iVar10 * (int)param_6 + (int)param_3);
    puVar15 = (ushort *)(iVar10 * (int)param_5 + param_2);
    local_18 = param_8;
    do {
      iVar10 = param_7;
      param_4 = puVar12;
      puVar1 = puVar15;
      _param_9 = puVar16;
      if (0x20 < param_7) {
        local_1c = param_7 - 1U >> 5;
        iVar10 = param_7 + local_1c * -0x20;
        param_6 = puVar15;
        do {
          puVar11 = &DAT_006e5ccc;
          do {
            puVar1 = param_6 + 1;
            *puVar11 = *param_6;
            puVar11 = puVar11 + 1;
            param_6 = puVar1;
          } while ((int)puVar11 < 0x6e5d0c);
          param_5 = (ushort *)0x0;
          uVar13 = 1;
          puVar11 = &DAT_006e5ccc;
          do {
            if (*puVar11 != param_10) {
              param_5 = (ushort *)((uint)param_5 | uVar13);
            }
            puVar11 = puVar11 + 1;
            uVar13 = uVar13 << 1;
          } while ((int)puVar11 < 0x6e5d0c);
          if (param_5 == (ushort *)0xffffffff) {
            param_5 = &DAT_006e5ccc;
            iVar14 = uVar9 * 0x20;
            do {
              puVar11 = param_5 + 1;
              puVar2 = param_4 + 1;
              uVar4 = *param_4;
              uVar5 = *param_5;
              puVar3 = _param_9 + 1;
              *_param_9 = ((ushort)(byte)(&DAT_006e5e5c)
                                         [(uVar5 >> 10 & 0x1f) +
                                          ((uVar4 >> 10 & 0x1f) + iVar14) * 0x20] << 5 |
                          (ushort)(byte)(&DAT_006e5e5c)
                                        [(uVar5 >> 5 & 0x1f) + ((uVar4 >> 5 & 0x1f) + iVar14) * 0x20
                                        ]) << 5 |
                          (ushort)(byte)(&DAT_006e5e5c)
                                        [(uVar5 & 0x1f) + ((uVar4 & 0x1f) + iVar14) * 0x20];
              param_4 = puVar2;
              param_5 = puVar11;
              _param_9 = puVar3;
            } while ((int)puVar11 < 0x6e5d0c);
          }
          else if (param_5 == (ushort *)0x0) {
            param_4 = param_4 + 0x20;
            _param_9 = _param_9 + 0x20;
          }
          else {
            local_8 = 1;
            param_3 = &DAT_006e5ccc;
            do {
              if ((local_8 & (uint)param_5) != 0) {
                uVar4 = *param_4;
                uVar5 = *param_3;
                iVar14 = uVar9 * 0x20;
                *_param_9 = ((ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar5 >> 10 & 0x1f) +
                                            ((uVar4 >> 10 & 0x1f) + iVar14) * 0x20] << 5 |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar5 >> 5 & 0x1f) +
                                           ((uVar4 >> 5 & 0x1f) + iVar14) * 0x20]) << 5 |
                            (ushort)(byte)(&DAT_006e5e5c)
                                          [(uVar5 & 0x1f) + ((uVar4 & 0x1f) + iVar14) * 0x20];
              }
              param_3 = param_3 + 1;
              _param_9 = _param_9 + 1;
              local_8 = local_8 << 1;
              param_4 = param_4 + 1;
            } while ((int)param_3 < 0x6e5d0c);
          }
          local_1c = local_1c - 1;
        } while (local_1c != 0);
      }
      for (; iVar10 != 0; iVar10 = iVar10 + -1) {
        uVar4 = *puVar1;
        if ((uint)uVar4 != (uint)param_10) {
          iVar14 = uVar9 * 0x20;
          uVar5 = *param_4;
          *_param_9 = ((ushort)(byte)(&DAT_006e5e5c)
                                     [(uVar4 >> 10 & 0x1f) + ((uVar5 >> 10 & 0x1f) + iVar14) * 0x20]
                       << 5 | (ushort)(byte)(&DAT_006e5e5c)
                                            [(uVar4 >> 5 & 0x1f) +
                                             ((uVar5 >> 5 & 0x1f) + iVar14) * 0x20]) << 5 |
                      (ushort)(byte)(&DAT_006e5e5c)
                                    [(uVar4 & 0x1f) + ((uVar5 & 0x1f) + iVar14) * 0x20];
        }
        param_4 = param_4 + 1;
        puVar1 = puVar1 + 1;
        _param_9 = _param_9 + 1;
      }
      local_18 = local_18 + -1;
      puVar12 = (ushort *)((int)puVar12 - iVar8);
      puVar16 = (ushort *)((int)puVar16 - iVar6);
      puVar15 = (ushort *)((int)puVar15 - iVar7);
    } while (local_18 != 0);
  }
  return;
}

