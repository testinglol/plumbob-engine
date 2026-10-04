
void FUN_004c29b0(undefined4 *param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  byte *pbVar11;
  byte *pbVar12;
  bool bVar13;
  uint local_18;
  byte *local_14;
  undefined2 *local_10;
  int local_c;
  uint local_8;
  
  sVar2 = *(short *)((int)param_1 + 10);
  iVar8 = (int)DAT_006f0bc2;
  local_c = *(short *)(param_1 + 2) + -1;
  local_8 = DAT_006f0bc6 - iVar8;
  local_10 = (undefined2 *)
             (DAT_006f0bcc + ((*(short *)(param_1 + 2) * DAT_006f0bbc) / 2 + (int)sVar2) * 2);
  DAT_006f0a78 = param_1[0xc];
  puVar9 = (undefined2 *)0x0;
  pbVar12 = (byte *)*param_1;
  do {
    while( true ) {
      while( true ) {
        puVar10 = local_10;
        bVar1 = *pbVar12;
        uVar6 = (uint)pbVar12[1];
        pbVar11 = pbVar12 + 2;
        if (bVar1 == 1) break;
        if (bVar1 == 2) {
          puVar7 = (undefined4 *)((int)param_1 + uVar6);
          if ((int)puVar7 < 0) {
            puVar9 = puVar9 + uVar6;
          }
          else {
            if ((int)param_1 < 0) {
              local_18 = local_8;
              puVar10 = puVar9 + -(int)param_1;
              bVar13 = SBORROW4(local_8,(int)puVar7);
              iVar3 = local_8 - (int)puVar7;
              puVar7 = (undefined4 *)0x0;
            }
            else {
              local_18 = local_8 - (int)param_1;
              bVar13 = SBORROW4(local_18,uVar6);
              iVar3 = local_18 - uVar6;
              puVar7 = param_1;
              puVar10 = puVar9;
            }
            puVar4 = &local_18;
            if (bVar13 == iVar3 < 0) {
              puVar4 = (uint *)&param_1;
            }
            uVar6 = *puVar4;
            if (3 < (int)uVar6) {
              uVar5 = uVar6 >> 2;
              uVar6 = uVar6 + uVar5 * -4;
              puVar7 = puVar7 + uVar5;
              puVar9 = puVar10;
              do {
                *puVar9 = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar11 * 2);
                puVar9[1] = *(undefined2 *)(DAT_006f0a78 + (uint)pbVar12[3] * 2);
                puVar9[2] = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar11 * 2);
                puVar10 = puVar9 + 4;
                uVar5 = uVar5 - 1;
                puVar9[3] = *(undefined2 *)(DAT_006f0a78 + (uint)pbVar12[3] * 2);
                puVar9 = puVar10;
              } while (uVar5 != 0);
            }
            if (1 < (int)uVar6) {
              uVar5 = uVar6 >> 1;
              uVar6 = uVar6 + uVar5 * -2;
              puVar7 = (undefined4 *)((int)puVar7 + uVar5 * 2);
              puVar9 = puVar10;
              do {
                *puVar9 = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar11 * 2);
                puVar10 = puVar9 + 2;
                uVar5 = uVar5 - 1;
                puVar9[1] = *(undefined2 *)(DAT_006f0a78 + (uint)pbVar12[3] * 2);
                puVar9 = puVar10;
              } while (uVar5 != 0);
            }
            puVar9 = puVar10;
            if (uVar6 != 0) {
              puVar9 = puVar10 + 1;
              *puVar10 = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar11 * 2);
              puVar7 = (undefined4 *)((int)puVar7 + 1);
            }
          }
          pbVar12 = pbVar12 + 4;
          param_1 = puVar7;
          if ((int)local_8 <= (int)puVar7) goto LAB_004c2c8b;
        }
        else if (bVar1 == 3) {
          puVar7 = (undefined4 *)((int)param_1 + uVar6);
          if ((int)puVar7 < 0) {
            puVar10 = puVar9 + uVar6;
            pbVar12 = (byte *)((uint)(pbVar11 + uVar6 + 1) & 0xfffffffe);
          }
          else {
            if ((int)param_1 < 0) {
              pbVar11 = pbVar11 + -(int)param_1;
              puVar9 = puVar9 + -(int)param_1;
              bVar13 = SBORROW4(local_8,(int)puVar7);
              iVar3 = local_8 - (int)puVar7;
              local_18 = local_8;
              puVar7 = (undefined4 *)0x0;
            }
            else {
              local_18 = local_8 - (int)param_1;
              bVar13 = SBORROW4(local_18,uVar6);
              iVar3 = local_18 - uVar6;
              puVar7 = param_1;
            }
            puVar4 = &local_18;
            if (bVar13 == iVar3 < 0) {
              puVar4 = (uint *)&param_1;
            }
            param_1 = (undefined4 *)*puVar4;
            if (3 < (int)param_1) {
              local_18 = (uint)param_1 >> 2;
              param_1 = (undefined4 *)((int)param_1 + local_18 * -4);
              puVar7 = puVar7 + local_18;
              do {
                FUN_004c2ca6(pbVar11,puVar9);
                puVar9 = puVar9 + 4;
                pbVar11 = pbVar11 + 4;
                local_18 = local_18 - 1;
              } while (local_18 != 0);
            }
            if (1 < (int)param_1) {
              uVar6 = (uint)param_1 >> 1;
              param_1 = (undefined4 *)((int)param_1 + uVar6 * -2);
              puVar7 = (undefined4 *)((int)puVar7 + uVar6 * 2);
              puVar10 = puVar9;
              do {
                *puVar10 = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar11 * 2);
                pbVar12 = pbVar11 + 1;
                puVar9 = puVar10 + 2;
                pbVar11 = pbVar11 + 2;
                puVar10[1] = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar12 * 2);
                uVar6 = uVar6 - 1;
                puVar10 = puVar9;
              } while (uVar6 != 0);
            }
            puVar10 = puVar9;
            pbVar12 = pbVar11;
            if (param_1 != (undefined4 *)0x0) {
              pbVar12 = pbVar11 + 1;
              puVar10 = puVar9 + 1;
              *puVar9 = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar11 * 2);
              puVar7 = (undefined4 *)((int)puVar7 + 1);
            }
          }
          puVar9 = puVar10;
          if ((int)local_8 <= (int)puVar7) goto LAB_004c2c8b;
          param_1 = puVar7;
          pbVar12 = (byte *)((uint)(pbVar12 + 1) & 0xfffffffe);
        }
        else if (bVar1 == 4) {
          local_c = local_c + 1;
          local_14 = pbVar11 + (uVar6 - 2);
          pbVar12 = pbVar11;
          if (local_c < DAT_006f0bc0) {
            pbVar12 = pbVar11 + (uVar6 - 2);
          }
          local_10 = local_10 + DAT_006f0bbc / 2;
          param_1 = (undefined4 *)(sVar2 - iVar8);
          puVar9 = puVar10;
          if (DAT_006f0bc4 <= local_c) {
            return;
          }
        }
        else {
          puVar7 = param_1;
          if (bVar1 != 9) goto LAB_004c2c96;
          local_c = local_c + uVar6;
          local_10 = local_10 + (int)(DAT_006f0bbc * uVar6) / 2;
          pbVar12 = pbVar11;
        }
      }
      puVar7 = (undefined4 *)((int)param_1 + uVar6);
      if ((int)local_8 <= (int)puVar7) break;
      puVar9 = puVar9 + uVar6;
LAB_004c2c96:
      param_1 = puVar7;
      pbVar12 = pbVar11;
      if (bVar1 == 5) {
        return;
      }
    }
LAB_004c2c8b:
    param_1 = puVar7;
    pbVar12 = local_14;
  } while( true );
}

