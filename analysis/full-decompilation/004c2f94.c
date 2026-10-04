
void FUN_004c2f94(byte *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  ushort *puVar2;
  undefined2 *puVar3;
  ushort uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  byte **ppbVar7;
  byte *pbVar8;
  byte *pbVar9;
  ushort *puVar10;
  undefined2 *puVar11;
  byte *local_2c;
  byte *local_28;
  byte *local_24;
  byte *local_20;
  ushort *local_1c;
  undefined2 *local_18;
  byte *local_14;
  byte *local_10;
  byte *local_c;
  byte *local_8;
  
  pbVar5 = (byte *)(int)*(short *)((int)param_1 + 10);
  local_28 = pbVar5 + -(int)DAT_006f0bc2;
  local_10 = (byte *)((int)DAT_006f0bc6 - (int)DAT_006f0bc2);
  local_24 = (byte *)(int)*(short *)((int)param_1 + 8);
  local_c = local_24 + -1;
  local_1c = (ushort *)(DAT_006f0bd0 + (int)local_24 * DAT_006f0bd4 + (int)pbVar5 * 2);
  local_18 = (undefined2 *)(DAT_006f0bcc + (int)(pbVar5 + ((int)local_24 * DAT_006f0bbc) / 2) * 2);
  DAT_006f0a94 = *(int *)((int)param_1 + 0x30);
  uVar6 = param_2;
  pbVar8 = *(byte **)param_1;
  puVar10 = (ushort *)0x0;
  puVar11 = (undefined2 *)0x0;
  param_1 = pbVar5;
  do {
    while( true ) {
      while( true ) {
        puVar3 = local_18;
        puVar2 = local_1c;
        pbVar5 = param_1;
        local_2c = (byte *)(uint)*pbVar8;
        local_8 = (byte *)(uint)pbVar8[1];
        pbVar9 = pbVar8 + 2;
        local_14 = pbVar9;
        if (local_2c == (byte *)0x1) break;
        uVar4 = (ushort)uVar6;
        if (local_2c == (byte *)0x2) {
          uVar1 = *(undefined2 *)(DAT_006f0a94 + (uint)*pbVar9 * 2);
          local_20 = (byte *)CONCAT22(local_20._2_2_,uVar1);
          pbVar9 = param_1 + (int)local_8;
          pbVar8 = pbVar8 + 4;
          local_14 = pbVar8;
          if ((int)pbVar9 < 0) {
            puVar11 = puVar11 + (int)local_8;
            puVar10 = puVar10 + (int)local_8;
            param_1 = pbVar9;
          }
          else {
            if ((int)param_1 < 0) {
              param_1 = (byte *)0x0;
              local_8 = pbVar9;
              puVar11 = puVar11 + -(int)pbVar5;
              puVar10 = puVar10 + -(int)pbVar5;
              local_14 = local_10;
              ppbVar7 = &local_14;
              if ((int)pbVar9 <= (int)local_10) {
                ppbVar7 = &local_8;
              }
              pbVar5 = *ppbVar7;
            }
            else {
              local_2c = local_10 + -(int)param_1;
              ppbVar7 = &local_2c;
              if ((int)local_8 <= (int)(local_10 + -(int)param_1)) {
                ppbVar7 = &local_8;
              }
              pbVar5 = *ppbVar7;
            }
            if (3 < (int)pbVar5) {
              local_14 = (byte *)((uint)pbVar5 >> 2);
              pbVar5 = pbVar5 + (int)local_14 * -4;
              param_1 = param_1 + (int)local_14 * 4;
              do {
                if (uVar4 <= *puVar10) {
                  *puVar11 = uVar1;
                  *puVar10 = uVar4;
                }
                if (uVar4 <= puVar10[1]) {
                  puVar11[1] = uVar1;
                  puVar10[1] = uVar4;
                }
                if (uVar4 <= puVar10[2]) {
                  puVar11[2] = uVar1;
                  puVar10[2] = uVar4;
                }
                if (uVar4 <= puVar10[3]) {
                  puVar11[3] = uVar1;
                  puVar10[3] = uVar4;
                }
                puVar11 = puVar11 + 4;
                puVar10 = puVar10 + 4;
                local_14 = local_14 + -1;
              } while (local_14 != (byte *)0x0);
            }
            if (1 < (int)pbVar5) {
              local_14 = (byte *)((uint)pbVar5 >> 1);
              pbVar5 = pbVar5 + (int)local_14 * -2;
              param_1 = param_1 + (int)local_14 * 2;
              do {
                if (uVar4 <= *puVar10) {
                  *puVar11 = uVar1;
                  *puVar10 = uVar4;
                }
                if (uVar4 <= puVar10[1]) {
                  puVar11[1] = uVar1;
                  puVar10[1] = uVar4;
                }
                puVar11 = puVar11 + 2;
                puVar10 = puVar10 + 2;
                local_14 = local_14 + -1;
              } while (local_14 != (byte *)0x0);
            }
            if (pbVar5 != (byte *)0x0) {
              if (uVar4 <= *puVar10) {
                *puVar11 = uVar1;
                *puVar10 = uVar4;
              }
              puVar11 = puVar11 + 1;
              puVar10 = puVar10 + 1;
              param_1 = param_1 + 1;
            }
          }
          if ((int)local_10 <= (int)param_1) goto LAB_004c33c7;
        }
        else if (local_2c == (byte *)0x3) {
          pbVar8 = param_1 + (int)local_8;
          if ((int)pbVar8 < 0) {
            puVar11 = puVar11 + (int)local_8;
            puVar10 = puVar10 + (int)local_8;
            pbVar9 = (byte *)((uint)(pbVar9 + (int)(local_8 + 1)) & 0xfffffffe);
            param_1 = pbVar8;
            local_20 = pbVar8;
          }
          else {
            if ((int)param_1 < 0) {
              param_1 = (byte *)0x0;
              pbVar9 = pbVar9 + -(int)pbVar5;
              puVar11 = puVar11 + -(int)pbVar5;
              puVar10 = puVar10 + -(int)pbVar5;
              local_20 = local_10;
              local_8 = pbVar8;
              ppbVar7 = &local_20;
              if ((int)pbVar8 <= (int)local_10) {
                ppbVar7 = &local_8;
              }
              pbVar8 = *ppbVar7;
            }
            else {
              local_20 = local_10 + -(int)param_1;
              ppbVar7 = &local_20;
              if ((int)local_8 <= (int)(local_10 + -(int)param_1)) {
                ppbVar7 = &local_8;
              }
              pbVar8 = *ppbVar7;
            }
            if (3 < (int)pbVar8) {
              local_20 = (byte *)((uint)pbVar8 >> 2);
              pbVar8 = pbVar8 + (int)local_20 * -4;
              param_1 = param_1 + (int)local_20 * 4;
              do {
                if (uVar4 <= *puVar10) {
                  *puVar11 = *(undefined2 *)(DAT_006f0a94 + (uint)*pbVar9 * 2);
                  *puVar10 = uVar4;
                }
                if (uVar4 <= puVar10[1]) {
                  puVar11[1] = *(undefined2 *)(DAT_006f0a94 + (uint)pbVar9[1] * 2);
                  puVar10[1] = uVar4;
                }
                if (uVar4 <= puVar10[2]) {
                  puVar11[2] = *(undefined2 *)(DAT_006f0a94 + (uint)pbVar9[2] * 2);
                  puVar10[2] = uVar4;
                }
                if (uVar4 <= puVar10[3]) {
                  puVar11[3] = *(undefined2 *)(DAT_006f0a94 + (uint)pbVar9[3] * 2);
                  puVar10[3] = uVar4;
                }
                puVar11 = puVar11 + 4;
                pbVar9 = pbVar9 + 4;
                puVar10 = puVar10 + 4;
                local_20 = local_20 + -1;
              } while (local_20 != (byte *)0x0);
              local_20 = (byte *)0x0;
            }
            if (1 < (int)pbVar8) {
              local_20 = (byte *)((uint)pbVar8 >> 1);
              pbVar8 = pbVar8 + (int)local_20 * -2;
              param_1 = param_1 + (int)local_20 * 2;
              do {
                if (uVar4 <= *puVar10) {
                  *puVar11 = *(undefined2 *)(DAT_006f0a94 + (uint)*pbVar9 * 2);
                  *puVar10 = uVar4;
                }
                if (uVar4 <= puVar10[1]) {
                  puVar11[1] = *(undefined2 *)(DAT_006f0a94 + (uint)pbVar9[1] * 2);
                  puVar10[1] = uVar4;
                }
                puVar11 = puVar11 + 2;
                pbVar9 = pbVar9 + 2;
                puVar10 = puVar10 + 2;
                local_20 = local_20 + -1;
              } while (local_20 != (byte *)0x0);
              local_20 = (byte *)0x0;
            }
            if (pbVar8 != (byte *)0x0) {
              if (uVar4 <= *puVar10) {
                *puVar11 = *(undefined2 *)(DAT_006f0a94 + (uint)*pbVar9 * 2);
                *puVar10 = uVar4;
              }
              puVar11 = puVar11 + 1;
              pbVar9 = pbVar9 + 1;
              puVar10 = puVar10 + 1;
              param_1 = param_1 + 1;
            }
          }
          if ((int)local_10 <= (int)param_1) goto LAB_004c33c7;
          pbVar8 = (byte *)((uint)(pbVar9 + 1) & 0xfffffffe);
        }
        else if (local_2c == (byte *)0x4) {
          pbVar5 = local_c + 1;
          local_24 = pbVar9 + (int)(local_8 + -2);
          pbVar8 = pbVar9;
          if ((int)pbVar5 < (int)DAT_006f0bc0) {
            pbVar8 = local_24;
          }
          local_18 = local_18 + DAT_006f0bbc / 2;
          local_1c = (ushort *)((int)local_1c + DAT_006f0bd4);
          uVar6 = param_2;
          local_c = pbVar5;
          FUN_004cebb0(param_2,pbVar5);
          uVar6 = FUN_0049a73d(uVar6,pbVar5);
          param_1 = local_28;
          puVar10 = puVar2;
          puVar11 = puVar3;
          if ((int)DAT_006f0bc4 <= (int)local_c) {
            return;
          }
        }
        else {
          if (local_2c != (byte *)0x9) goto LAB_004c33d8;
          pbVar8 = local_c + (int)local_8;
          local_18 = local_18 + (DAT_006f0bbc * (int)local_8) / 2;
          local_1c = (ushort *)((int)local_1c + DAT_006f0bd4 * (int)local_8);
          uVar6 = param_2;
          local_c = pbVar8;
          FUN_004cebb0(param_2,pbVar8);
          uVar6 = FUN_0049a73d(uVar6,pbVar8);
          pbVar8 = pbVar9;
        }
      }
      param_1 = param_1 + (int)local_8;
      if ((int)local_10 <= (int)param_1) break;
      puVar11 = puVar11 + (int)local_8;
      puVar10 = puVar10 + (int)local_8;
LAB_004c33d8:
      pbVar8 = pbVar9;
      if (local_2c == (byte *)0x5) {
        return;
      }
    }
LAB_004c33c7:
    pbVar8 = local_24;
  } while( true );
}

