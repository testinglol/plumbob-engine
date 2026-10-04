
void FUN_004c0463(int *param_1,int *param_2,ushort *param_3,int param_4,int param_5,int param_6,
                 int *param_7)

{
  int *piVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  ushort *puVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  ushort *puVar16;
  int *local_24;
  uint local_1c;
  uint local_18;
  uint local_14;
  ushort *local_10;
  int *local_c;
  ushort *local_8;
  
  uVar2 = *param_3;
  iVar6 = (uint)uVar2 * 2;
  iVar5 = param_1[1];
  uVar3 = param_3[1];
  piVar1 = (int *)(*param_1 + -2 + iVar6);
  local_10 = (ushort *)(*param_2 + -2 + iVar6);
  iVar6 = param_7[1];
  iVar7 = param_7[3];
  piVar13 = param_2;
  puVar12 = param_3 + 8;
  local_c = piVar1;
LAB_004c04bb:
  while( true ) {
    while( true ) {
      uVar4 = *puVar12;
      uVar14 = (uint)uVar4;
      uVar15 = uVar14 & 0x1fff;
      uVar9 = uVar14 & 0xe000;
      puVar16 = puVar12 + 1;
      if ((uVar4 & 0xe000) != 0) break;
      piVar11 = (int *)((int)local_c + iVar5 * 2);
      param_3 = local_10;
      local_10 = local_10 + param_2[1];
      piVar13 = local_c;
      if (local_c < (int *)((int)piVar1 + iVar6 * iVar5 * 2)) {
        puVar12 = (ushort *)((int)puVar12 + uVar15);
        local_c = piVar11;
      }
      else {
        if ((int *)((int)piVar1 + ((uint)uVar3 - iVar7) * iVar5 * 2) <= local_c) {
          return;
        }
        local_24 = (int *)((int)local_c + param_7[2] * -2);
        param_1 = (int *)((int)local_c + (*param_7 - (uint)uVar2) * 2);
        puVar12 = puVar16;
        local_c = piVar11;
      }
    }
    if (uVar9 == 0x2000) break;
    if (uVar9 == 0x4000) {
      local_18 = 0;
      if ((local_24 < piVar13) || ((int *)((int)piVar13 + uVar15 * -2) <= param_1)) {
        piVar11 = (int *)((int)piVar13 + uVar15 * -2);
        if ((local_24 <= piVar11) || (piVar13 <= param_1)) {
          puVar12 = (ushort *)((int)puVar16 + uVar15 * 3 + (uVar14 & 1));
          piVar13 = piVar11;
          goto LAB_004c06dd;
        }
        if (piVar11 < param_1) {
          local_18 = (int)((uVar15 * 2 - (int)piVar13) + (int)param_1) >> 1;
          uVar15 = uVar15 - local_18;
        }
        if (local_24 < piVar13) {
          iVar10 = (int)piVar13 - (int)local_24 >> 1;
          uVar15 = uVar15 - iVar10;
          piVar13 = (int *)((int)piVar13 + iVar10 * -2);
          param_3 = param_3 + -iVar10;
          puVar16 = (ushort *)(iVar10 * 3 + (int)puVar16);
        }
      }
      if (0 < (int)uVar15) {
        local_14 = uVar15;
        local_8 = (ushort *)piVar13;
        do {
          iVar10 = *(short *)(param_6 + (uint)(byte)*puVar16 * 2) + param_5;
          if (iVar10 <= (int)(uint)*(ushort *)(((int)param_3 - (int)piVar13) + (int)local_8)) {
            uVar8 = FUN_0049a775(CONCAT31((int3)((uint)iVar10 >> 8),(byte)puVar16[1]));
            *local_8 = uVar8;
          }
          local_8 = (ushort *)((int)local_8 + -2);
          puVar16 = (ushort *)((int)puVar16 + 3);
          local_14 = local_14 - 1;
        } while (local_14 != 0);
      }
      param_3 = param_3 + -uVar15;
      piVar13 = (int *)((int)piVar13 + uVar15 * -2);
      if (local_18 != 0) {
        puVar16 = (ushort *)(local_18 * 3 + (int)puVar16);
        piVar13 = (int *)((int)piVar13 + local_18 * -2);
        param_3 = param_3 + -local_18;
      }
      puVar12 = (ushort *)((int)puVar16 + ((uint)puVar16 & 1));
    }
    else if (uVar9 == 0x6000) {
      piVar13 = (int *)((int)piVar13 + uVar15 * -2);
      param_3 = param_3 + -uVar15;
      puVar12 = puVar16;
    }
    else if (uVar9 == 0x8000) {
      puVar12 = puVar16;
      if ((uVar4 & 0x1fff) != 0) {
        do {
          param_3 = local_10;
          piVar11 = (int *)((int)local_c + iVar5 * 2);
          local_10 = local_10 + param_2[1];
          uVar15 = uVar15 - 1;
          piVar13 = local_c;
          local_c = piVar11;
        } while (uVar15 != 0);
      }
    }
    else {
      puVar12 = puVar16;
      if (uVar9 == 0xa000) {
        return;
      }
    }
  }
  local_1c = 0;
  if ((local_24 < piVar13) || ((int *)((int)piVar13 + uVar15 * -2) <= param_1)) {
    piVar11 = (int *)((int)piVar13 + uVar15 * -2);
    if ((piVar11 < local_24) && (param_1 < piVar13)) {
      if (piVar11 < param_1) {
        local_1c = (int)((uVar15 * 2 - (int)piVar13) + (int)param_1) >> 1;
        uVar15 = uVar15 - local_1c;
      }
      if (local_24 < piVar13) {
        iVar10 = (int)piVar13 - (int)local_24 >> 1;
        uVar15 = uVar15 - iVar10;
        param_3 = param_3 + -iVar10;
        piVar13 = (int *)((int)piVar13 + iVar10 * -2);
        puVar16 = puVar16 + iVar10;
      }
      goto LAB_004c0670;
    }
    puVar12 = puVar16 + uVar15;
    piVar13 = piVar11;
  }
  else {
LAB_004c0670:
    if (0 < (int)uVar15) {
      puVar12 = param_3;
      local_18 = uVar15;
      local_8 = puVar16;
      do {
        iVar10 = *(short *)(param_6 + (uint)(byte)*local_8 * 2) + param_5;
        if (iVar10 <= (int)(uint)*puVar12) {
          *puVar12 = (ushort)iVar10;
          *(undefined2 *)(((int)piVar13 - (int)param_3) + (int)puVar12) =
               *(undefined2 *)(param_4 + (uint)*(byte *)((int)local_8 + 1) * 2);
        }
        local_8 = local_8 + 1;
        puVar12 = puVar12 + -1;
        local_18 = local_18 - 1;
      } while (local_18 != 0);
    }
    param_3 = param_3 + -uVar15;
    piVar13 = (int *)((int)piVar13 + uVar15 * -2);
    puVar12 = puVar16 + uVar15;
    if (local_1c == 0) goto LAB_004c04bb;
    puVar12 = puVar16 + uVar15 + local_1c;
    piVar13 = (int *)((int)piVar13 + local_1c * -2);
    uVar15 = local_1c;
  }
LAB_004c06dd:
  param_3 = param_3 + -uVar15;
  goto LAB_004c04bb;
}

