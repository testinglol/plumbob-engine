
void FUN_004be841(int *param_1,int *param_2,ushort *param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  ushort uVar8;
  int iVar9;
  uint *puVar10;
  ushort *puVar11;
  uint uVar12;
  uint local_20;
  uint local_18;
  ushort *local_10;
  int local_c;
  ushort *local_8;
  
  local_10 = (ushort *)(*param_1 + -2 + (uint)*param_3 * 2);
  puVar7 = param_3 + 8;
  puVar3 = (ushort *)(*param_2 + -2 + (uint)*param_3 * 2);
  do {
    while( true ) {
      while( true ) {
        uVar8 = *puVar7;
        uVar12 = uVar8 & 0x1fff;
        uVar4 = uVar8 & 0xe000;
        puVar11 = puVar7 + 1;
        if ((uVar8 & 0xe000) != 0) break;
        param_3 = local_10;
        local_10 = local_10 + param_1[1];
        puVar7 = puVar11;
        local_8 = puVar3;
        puVar3 = puVar3 + param_2[1];
      }
      if (uVar4 != 0x2000) break;
      if (uVar12 < 0x10) {
        if ((uVar8 & 0x1fff) != 0) {
          puVar7 = local_8;
          puVar6 = puVar11;
          local_20 = uVar12;
          do {
            iVar5 = *(short *)(param_6 + (uint)(byte)*puVar6 * 2) + param_5;
            if (iVar5 <= (int)(uint)*puVar7) {
              *puVar7 = (ushort)iVar5;
              *(undefined2 *)((int)puVar7 + ((int)param_3 - (int)local_8)) =
                   *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar6 + 1) * 2);
            }
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + -1;
            local_20 = local_20 - 1;
          } while (local_20 != 0);
        }
      }
      else {
        FUN_004bcef1(uVar12,puVar11,param_3,local_8,param_4,param_5,param_6,2);
      }
      puVar11 = puVar11 + uVar12;
LAB_004beae5:
      param_3 = param_3 + -uVar12;
      puVar7 = puVar11;
      local_8 = local_8 + -uVar12;
    }
    if (uVar4 == 0x4000) {
      if (uVar12 < 0x10) {
        if ((uVar8 & 0x1fff) != 0) {
          puVar10 = &DAT_006f098c;
          puVar6 = param_3;
          uVar4 = uVar12;
          do {
            *puVar10 = (uint)*puVar6;
            puVar6 = puVar6 + -1;
            puVar10 = puVar10 + 1;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
          puVar10 = &DAT_006f0a0c;
          local_18 = uVar12;
          do {
            puVar7 = (ushort *)((int)puVar7 + 3);
            *puVar10 = (uint)*(ushort *)(param_4 + (uint)*(byte *)puVar7 * 2);
            puVar10 = puVar10 + 1;
            local_18 = local_18 - 1;
          } while (local_18 != 0);
        }
        local_c = 0;
        if ((uVar8 & 0x1fff) != 0) {
          puVar7 = local_8;
          do {
            iVar5 = *(short *)(param_6 + (uint)(byte)*puVar11 * 2) + param_5;
            if (iVar5 <= (int)(uint)*puVar7) {
              bVar1 = (byte)puVar11[1];
              uVar8 = (ushort)iVar5;
              if ((bVar1 < 8) || (0xf7 < bVar1)) {
                if (0xf7 < bVar1) {
                  *puVar7 = uVar8;
                  *(undefined2 *)(((int)param_3 - (int)local_8) + (int)puVar7) =
                       *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar11 + 1) * 2);
                }
              }
              else {
                *puVar7 = uVar8;
                uVar4 = (&DAT_006f0a0c)[local_c];
                uVar2 = (&DAT_006f098c)[local_c];
                iVar5 = ((byte)puVar11[1] & 0x1f) * 0x20;
                *(ushort *)(((int)param_3 - (int)local_8) + (int)puVar7) =
                     ((ushort)(byte)(&DAT_006e5e5c)
                                    [(uVar2 >> 10 & 0x1f) + ((uVar4 >> 10 & 0x1f) + iVar5) * 0x20]
                      << 5 | (ushort)(byte)(&DAT_006e5e5c)
                                           [(uVar2 >> 5 & 0x1f) +
                                            ((uVar4 >> 5 & 0x1f) + iVar5) * 0x20]) << 5 |
                     (ushort)(byte)(&DAT_006e5e5c)[(uVar2 & 0x1f) + ((uVar4 & 0x1f) + iVar5) * 0x20]
                ;
              }
            }
            puVar11 = (ushort *)((int)puVar11 + 3);
            local_c = local_c + 1;
            puVar7 = puVar7 + -1;
          } while (local_c < (int)uVar12);
        }
      }
      else {
        FUN_004beb1b(uVar12,puVar11,param_3,local_8,param_4,param_5,param_6);
        puVar11 = (ushort *)(uVar12 * 3 + (int)puVar11);
      }
      param_3 = param_3 + -uVar12;
      puVar7 = (ushort *)((int)puVar11 + ((uint)puVar11 & 1));
      local_8 = local_8 + -uVar12;
    }
    else {
      if (uVar4 == 0x6000) goto LAB_004beae5;
      if (uVar4 == 0x8000) {
        iVar5 = param_1[1] * (uVar12 - 1);
        iVar9 = param_2[1] * (uVar12 - 1);
        param_3 = param_3 + iVar5;
        local_10 = local_10 + param_1[1] + iVar5;
        puVar7 = puVar11;
        local_8 = local_8 + iVar9;
        puVar3 = puVar3 + param_2[1] + iVar9;
      }
      else {
        puVar7 = puVar11;
        if (uVar4 == 0xa000) {
          return;
        }
      }
    }
  } while( true );
}

