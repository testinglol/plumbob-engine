
void FUN_004c2cf7(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  uint local_1c;
  undefined4 *local_18;
  byte *local_14;
  undefined2 *local_10;
  int local_c;
  uint local_8;
  
  local_c = *(short *)(param_1 + 2) + -1;
  local_18 = (undefined4 *)((int)DAT_006f0bc6 - (int)*(short *)((int)param_1 + 0xe));
  local_8 = (int)DAT_006f0bc6 - (int)DAT_006f0bc2;
  local_10 = (undefined2 *)
             (DAT_006f0bcc +
             ((*(short *)(param_1 + 2) * DAT_006f0bbc) / 2 + (int)*(short *)((int)param_1 + 0xe)) *
             2);
  DAT_006f0a78 = param_1[0xc];
  puVar6 = (undefined2 *)0x0;
  pbVar10 = (byte *)*param_1;
  do {
    while( true ) {
      while( true ) {
        puVar5 = local_10;
        bVar1 = *pbVar10;
        uVar7 = (uint)pbVar10[1];
        pbVar9 = pbVar10 + 2;
        if (bVar1 == 1) break;
        puVar8 = param_1;
        if (bVar1 == 2) {
          iVar2 = (int)param_1 + uVar7;
          if (iVar2 < 0) {
            puVar6 = puVar6 + -uVar7;
            puVar8 = (undefined4 *)((int)param_1 + (int)(char)pbVar10[1]);
          }
          else {
            if ((int)param_1 < 0) {
              puVar6 = puVar6 + (int)param_1;
              puVar8 = (undefined4 *)0x0;
              bVar11 = SBORROW4(local_8,iVar2);
              iVar2 = local_8 - iVar2;
              puVar3 = &local_8;
            }
            else {
              local_1c = local_8 - (int)param_1;
              bVar11 = SBORROW4(local_1c,uVar7);
              iVar2 = local_1c - uVar7;
              puVar3 = &local_1c;
            }
            if (bVar11 == iVar2 < 0) {
              puVar3 = (uint *)&param_1;
            }
            uVar7 = *puVar3;
            if (3 < (int)uVar7) {
              uVar4 = uVar7 >> 2;
              uVar7 = uVar7 + uVar4 * -4;
              puVar8 = puVar8 + uVar4;
              puVar5 = puVar6;
              do {
                puVar5[-2] = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar9 * 2);
                puVar6 = puVar5 + -4;
                uVar4 = uVar4 - 1;
                puVar5[-1] = *(undefined2 *)(DAT_006f0a78 + (uint)pbVar10[3] * 2);
                *puVar6 = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar9 * 2);
                puVar5[-3] = *(undefined2 *)(DAT_006f0a78 + (uint)pbVar10[3] * 2);
                puVar5 = puVar6;
              } while (uVar4 != 0);
            }
            if (1 < (int)uVar7) {
              uVar4 = uVar7 >> 1;
              uVar7 = uVar7 + uVar4 * -2;
              puVar8 = (undefined4 *)((int)puVar8 + uVar4 * 2);
              puVar5 = puVar6;
              do {
                puVar6 = puVar5 + -2;
                uVar4 = uVar4 - 1;
                *puVar6 = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar9 * 2);
                puVar5[-1] = *(undefined2 *)(DAT_006f0a78 + (uint)pbVar10[3] * 2);
                puVar5 = puVar6;
              } while (uVar4 != 0);
            }
            if (uVar7 != 0) {
              puVar6 = puVar6 + -1;
              puVar8 = (undefined4 *)((int)puVar8 + 1);
              *puVar6 = *(undefined2 *)(DAT_006f0a78 + (uint)*pbVar9 * 2);
            }
          }
          pbVar10 = pbVar10 + 4;
          param_1 = puVar8;
          if ((int)local_8 <= (int)puVar8) goto LAB_004c2f6c;
        }
        else if (bVar1 == 3) {
          puVar8 = (undefined4 *)((int)param_1 + uVar7);
          if ((int)puVar8 < 0) {
            pbVar9 = (byte *)((uint)(pbVar9 + uVar7 + 1) & 0xfffffffe);
            puVar6 = puVar6 + -uVar7;
          }
          else {
            if ((int)param_1 < 0) {
              puVar6 = puVar6 + (int)param_1;
              pbVar9 = pbVar9 + -(int)param_1;
              param_1 = (undefined4 *)0x0;
              bVar11 = SBORROW4(local_8,(int)puVar8);
              iVar2 = local_8 - (int)puVar8;
              local_1c = local_8;
            }
            else {
              local_1c = local_8 - (int)param_1;
              bVar11 = SBORROW4(local_1c,uVar7);
              iVar2 = local_1c - uVar7;
            }
            puVar3 = &local_1c;
            if (bVar11 == iVar2 < 0) {
              puVar3 = (uint *)&param_1;
            }
            uVar7 = *puVar3;
            puVar8 = (undefined4 *)((int)param_1 + uVar7);
            if (0 < (int)uVar7) {
              do {
                bVar1 = *pbVar9;
                puVar6 = puVar6 + -1;
                pbVar9 = pbVar9 + 1;
                uVar7 = uVar7 - 1;
                *puVar6 = *(undefined2 *)(DAT_006f0a78 + (uint)bVar1 * 2);
              } while (uVar7 != 0);
            }
          }
          if ((int)local_8 <= (int)puVar8) goto LAB_004c2f6c;
          param_1 = puVar8;
          pbVar10 = (byte *)((uint)(pbVar9 + 1) & 0xfffffffe);
        }
        else if (bVar1 == 4) {
          local_c = local_c + 1;
          local_14 = pbVar9 + (uVar7 - 2);
          pbVar10 = pbVar9;
          if (local_c < DAT_006f0bc0) {
            pbVar10 = pbVar9 + (uVar7 - 2);
          }
          local_10 = local_10 + DAT_006f0bbc / 2;
          puVar6 = puVar5;
          param_1 = local_18;
          if (DAT_006f0bc4 <= local_c) {
            return;
          }
        }
        else {
          if (bVar1 != 9) goto LAB_004c2f79;
          local_c = local_c + uVar7;
          local_10 = local_10 + (int)(DAT_006f0bbc * uVar7) / 2;
          pbVar10 = pbVar9;
        }
      }
      puVar8 = (undefined4 *)((int)param_1 + uVar7);
      if ((int)local_8 <= (int)puVar8) break;
      puVar6 = puVar6 + -uVar7;
LAB_004c2f79:
      param_1 = puVar8;
      pbVar10 = pbVar9;
      if (bVar1 == 5) {
        return;
      }
    }
LAB_004c2f6c:
    param_1 = puVar8;
    pbVar10 = local_14;
  } while( true );
}

