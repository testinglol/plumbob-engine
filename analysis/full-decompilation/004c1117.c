
void FUN_004c1117(ushort *param_1,undefined4 *param_2,ushort *param_3,int param_4,int param_5,
                 int param_6,int *param_7)

{
  undefined4 *puVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  ushort *puVar12;
  ushort *puVar13;
  int local_24;
  uint local_20;
  undefined4 *local_1c;
  undefined4 *local_14;
  ushort *local_10;
  undefined4 *local_c;
  int local_8;
  
  puVar4 = *(undefined4 **)param_1;
  iVar5 = *(int *)(param_1 + 2);
  local_10 = (ushort *)*param_2;
  uVar2 = param_3[1];
  iVar6 = param_7[1];
  iVar7 = param_7[3];
  puVar11 = param_2;
  puVar12 = param_3 + 8;
  local_c = puVar4;
LAB_004c1165:
  do {
    while( true ) {
      while( true ) {
        local_8 = 2;
        uVar3 = *puVar12;
        uVar10 = uVar3 & 0x1fff;
        uVar8 = uVar3 & 0xe000;
        puVar13 = puVar12 + 1;
        if ((uVar3 & 0xe000) != 0) break;
        puVar1 = (undefined4 *)((int)local_c + iVar5 * 2);
        param_1 = local_10;
        local_10 = local_10 + param_2[1];
        if (local_c < (undefined4 *)((int)puVar4 + iVar6 * iVar5 * 2)) {
          puVar11 = local_c;
          puVar12 = (ushort *)((int)puVar12 + uVar10);
          local_c = puVar1;
        }
        else {
          if ((undefined4 *)((int)puVar4 + ((uint)uVar2 - iVar7) * iVar5 * 2) <= local_c) {
            return;
          }
          local_1c = (undefined4 *)((int)local_c + *param_7 * 2);
          local_14 = (undefined4 *)((int)local_c + ((uint)*param_3 - param_7[2]) * 2);
          puVar11 = local_c;
          puVar12 = puVar13;
          local_c = puVar1;
        }
      }
      if (uVar8 == 0x2000) break;
      if (uVar8 == 0x4000) {
        local_8 = 3;
        break;
      }
      if (uVar8 == 0x6000) {
        param_1 = param_1 + uVar10;
        puVar11 = (undefined4 *)((int)puVar11 + uVar10 * 2);
        puVar12 = puVar13;
      }
      else if (uVar8 == 0x8000) {
        puVar12 = puVar13;
        if ((uVar3 & 0x1fff) != 0) {
          do {
            param_1 = local_10;
            puVar1 = (undefined4 *)((int)local_c + iVar5 * 2);
            local_10 = local_10 + param_2[1];
            uVar10 = uVar10 - 1;
            puVar11 = local_c;
            local_c = puVar1;
          } while (uVar10 != 0);
        }
      }
      else {
        puVar12 = puVar13;
        if (uVar8 == 0xa000) {
          return;
        }
      }
    }
    local_24 = 0;
    if ((puVar11 < local_1c) || (local_14 <= (undefined4 *)((int)puVar11 + uVar10 * 2))) {
      puVar1 = (undefined4 *)(uVar10 * 2 + (int)puVar11);
      if ((puVar1 <= local_1c) || (local_14 <= puVar11)) {
        puVar13 = (ushort *)((int)puVar13 + uVar10 * local_8);
        param_1 = param_1 + uVar10;
        puVar11 = puVar1;
        puVar12 = (ushort *)((int)puVar13 + ((uint)puVar13 & 1));
        goto LAB_004c1165;
      }
      if (local_14 < puVar1) {
        local_24 = (int)((uVar10 * 2 - (int)local_14) + (int)puVar11) >> 1;
        uVar10 = uVar10 - local_24;
      }
      if (puVar11 < local_1c) {
        iVar9 = (int)local_1c - (int)puVar11 >> 1;
        uVar10 = uVar10 - iVar9;
        param_1 = param_1 + iVar9;
        puVar11 = (undefined4 *)((int)puVar11 + iVar9 * 2);
        puVar13 = (ushort *)((int)puVar13 + iVar9 * local_8);
      }
    }
    if (0 < (int)uVar10) {
      puVar12 = param_1;
      local_20 = uVar10;
      do {
        iVar9 = *(short *)(param_6 + (uint)(byte)*puVar13 * 2) + param_5;
        if (iVar9 <= (int)(uint)*puVar12) {
          *puVar12 = (ushort)iVar9;
          *(undefined2 *)(((int)puVar11 - (int)param_1) + (int)puVar12) =
               *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar13 + 1) * 2);
        }
        puVar13 = (ushort *)((int)puVar13 + local_8);
        puVar12 = puVar12 + 1;
        local_20 = local_20 - 1;
      } while (local_20 != 0);
    }
    param_1 = param_1 + uVar10;
    puVar11 = (undefined4 *)((int)puVar11 + uVar10 * 2);
    if (local_24 != 0) {
      puVar13 = (ushort *)((int)puVar13 + local_24 * local_8);
      puVar11 = (undefined4 *)((int)puVar11 + local_24 * 2);
      param_1 = param_1 + local_24;
    }
    puVar12 = (ushort *)((int)puVar13 + ((uint)puVar13 & 1));
  } while( true );
}

