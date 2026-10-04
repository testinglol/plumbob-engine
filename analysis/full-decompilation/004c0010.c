
void FUN_004c0010(int *param_1,undefined4 *param_2,ushort *param_3,int param_4,int param_5,
                 int param_6,int *param_7)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  ushort *puVar11;
  undefined4 *puVar12;
  ushort *puVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined4 *local_24;
  uint local_1c;
  uint local_18;
  int *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar3 = (undefined4 *)*param_1;
  iVar4 = param_1[1];
  local_14 = (int *)*param_2;
  uVar1 = param_3[1];
  iVar5 = param_7[1];
  iVar6 = param_7[3];
  puVar10 = param_3 + 8;
  puVar16 = param_2;
  local_10 = puVar3;
LAB_004c0057:
  while( true ) {
    while( true ) {
      uVar2 = *puVar10;
      uVar14 = (uint)uVar2;
      uVar15 = uVar14 & 0x1fff;
      uVar8 = uVar14 & 0xe000;
      puVar13 = puVar10 + 1;
      if ((uVar2 & 0xe000) != 0) break;
      puVar12 = (undefined4 *)((int)local_10 + iVar4 * 2);
      param_1 = local_14;
      local_14 = (int *)((int)local_14 + param_2[1] * 2);
      puVar16 = local_10;
      if (local_10 < (undefined4 *)((int)puVar3 + iVar5 * iVar4 * 2)) {
        puVar10 = (ushort *)((int)puVar10 + uVar15);
        local_10 = puVar12;
      }
      else {
        if ((undefined4 *)((int)puVar3 + ((uint)uVar1 - iVar6) * iVar4 * 2) <= local_10) {
          return;
        }
        local_24 = (undefined4 *)((int)local_10 + *param_7 * 2);
        local_8 = (undefined4 *)((int)local_10 + ((uint)*param_3 - param_7[2]) * 2);
        puVar10 = puVar13;
        local_10 = puVar12;
      }
    }
    if (uVar8 == 0x2000) break;
    if (uVar8 == 0x4000) {
      local_1c = 0;
      if ((puVar16 < local_24) || (local_8 <= (undefined4 *)((int)puVar16 + uVar15 * 2))) {
        puVar12 = (undefined4 *)(uVar15 * 2 + (int)puVar16);
        if ((puVar12 <= local_24) || (local_8 <= puVar16)) {
          puVar10 = (ushort *)((int)puVar13 + uVar15 * 3 + (uVar14 & 1));
          goto LAB_004c0274;
        }
        if (local_8 < puVar12) {
          local_1c = (int)((uVar15 * 2 - (int)local_8) + (int)puVar16) >> 1;
          uVar15 = uVar15 - local_1c;
        }
        if (puVar16 < local_24) {
          iVar9 = (int)local_24 - (int)puVar16 >> 1;
          uVar15 = uVar15 - iVar9;
          puVar16 = (undefined4 *)((int)puVar16 + iVar9 * 2);
          param_1 = (int *)((int)param_1 + iVar9 * 2);
          puVar13 = (ushort *)(iVar9 * 3 + (int)puVar13);
        }
      }
      if (0 < (int)uVar15) {
        local_18 = uVar15;
        local_c = puVar16;
        do {
          iVar9 = *(short *)(param_6 + (uint)(byte)*puVar13 * 2) + param_5;
          if (iVar9 <= (int)(uint)*(ushort *)(((int)param_1 - (int)puVar16) + (int)local_c)) {
            uVar7 = FUN_0049a775(CONCAT31((int3)((uint)iVar9 >> 8),(byte)puVar13[1]));
            *(undefined2 *)local_c = uVar7;
          }
          local_c = (undefined4 *)((int)local_c + 2);
          puVar13 = (ushort *)((int)puVar13 + 3);
          local_18 = local_18 - 1;
        } while (local_18 != 0);
      }
      param_1 = (int *)((int)param_1 + uVar15 * 2);
      puVar16 = (undefined4 *)((int)puVar16 + uVar15 * 2);
      if (local_1c != 0) {
        puVar13 = (ushort *)(local_1c * 3 + (int)puVar13);
        puVar16 = (undefined4 *)((int)puVar16 + local_1c * 2);
        param_1 = (int *)((int)param_1 + local_1c * 2);
      }
      puVar10 = (ushort *)((int)puVar13 + ((uint)puVar13 & 1));
    }
    else if (uVar8 == 0x6000) {
      param_1 = (int *)((int)param_1 + uVar15 * 2);
      puVar10 = puVar13;
      puVar16 = (undefined4 *)((int)puVar16 + uVar15 * 2);
    }
    else if (uVar8 == 0x8000) {
      puVar10 = puVar13;
      if ((uVar2 & 0x1fff) != 0) {
        do {
          param_1 = local_14;
          puVar12 = (undefined4 *)((int)local_10 + iVar4 * 2);
          local_14 = (int *)((int)local_14 + param_2[1] * 2);
          uVar15 = uVar15 - 1;
          puVar16 = local_10;
          local_10 = puVar12;
        } while (uVar15 != 0);
      }
    }
    else {
      puVar10 = puVar13;
      if (uVar8 == 0xa000) {
        return;
      }
    }
  }
  local_18 = 0;
  if ((puVar16 < local_24) || (local_8 <= (undefined4 *)((int)puVar16 + uVar15 * 2))) {
    puVar12 = (undefined4 *)(uVar15 * 2 + (int)puVar16);
    if ((puVar12 <= local_24) || (local_8 <= puVar16)) {
      puVar10 = puVar13 + uVar15;
LAB_004c0274:
      param_1 = (int *)((int)param_1 + uVar15 * 2);
      puVar16 = puVar12;
      goto LAB_004c0057;
    }
    if (local_8 < puVar12) {
      local_18 = (int)((uVar15 * 2 - (int)local_8) + (int)puVar16) >> 1;
      uVar15 = uVar15 - local_18;
    }
    if (puVar16 < local_24) {
      iVar9 = (int)local_24 - (int)puVar16 >> 1;
      uVar15 = uVar15 - iVar9;
      param_1 = (int *)((int)param_1 + iVar9 * 2);
      puVar16 = (undefined4 *)((int)puVar16 + iVar9 * 2);
      puVar13 = puVar13 + iVar9;
    }
  }
  if (0 < (int)uVar15) {
    puVar10 = puVar13;
    local_1c = uVar15;
    do {
      iVar9 = *(short *)(param_6 + (uint)(byte)*puVar10 * 2) + param_5;
      puVar11 = (ushort *)(((int)param_1 - (int)puVar13) + (int)puVar10);
      if (iVar9 <= (int)(uint)*puVar11) {
        *puVar11 = (ushort)iVar9;
        *(undefined2 *)(((int)puVar16 - (int)puVar13) + (int)puVar10) =
             *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar10 + 1) * 2);
      }
      puVar10 = puVar10 + 1;
      local_1c = local_1c - 1;
    } while (local_1c != 0);
  }
  param_1 = (int *)((int)param_1 + uVar15 * 2);
  puVar16 = (undefined4 *)((int)puVar16 + uVar15 * 2);
  puVar10 = puVar13 + uVar15;
  if (local_18 != 0) {
    puVar16 = (undefined4 *)((int)puVar16 + local_18 * 2);
    param_1 = (int *)((int)param_1 + local_18 * 2);
    puVar10 = puVar13 + uVar15 + local_18;
  }
  goto LAB_004c0057;
}

