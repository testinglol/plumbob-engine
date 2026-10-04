
void FUN_004c1446(ushort *param_1,int *param_2,ushort *param_3,int param_4,int param_5,int param_6,
                 int *param_7)

{
  int *piVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  ushort *puVar11;
  ushort *puVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  int local_20;
  uint local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  ushort *local_c;
  int local_8;
  
  uVar2 = *param_3;
  iVar9 = (uint)uVar2 * 2;
  uVar3 = param_3[1];
  piVar1 = (int *)(*(int *)param_1 + -2 + iVar9);
  iVar5 = *(int *)((int)param_1 + 4);
  iVar6 = param_7[1];
  iVar7 = param_7[3];
  puVar11 = param_3 + 8;
  piVar14 = param_2;
  piVar15 = piVar1;
  param_1 = (ushort *)(*param_2 + -2 + iVar9);
  local_10 = piVar1;
LAB_004c14a5:
  do {
    while( true ) {
      while( true ) {
        local_8 = 2;
        uVar4 = *puVar11;
        piVar10 = (int *)(uVar4 & 0x1fff);
        uVar8 = uVar4 & 0xe000;
        puVar12 = puVar11 + 1;
        if ((uVar4 & 0xe000) != 0) break;
        param_3 = param_1;
        local_10 = (int *)((int)piVar15 + iVar5 * 2);
        param_1 = param_1 + param_2[1];
        piVar14 = piVar15;
        if (piVar15 < (int *)((int)piVar1 + iVar6 * iVar5 * 2)) {
          puVar11 = (ushort *)((int)puVar11 + (int)piVar10);
          piVar15 = local_10;
        }
        else {
          if ((int *)((int)piVar1 + ((uint)uVar3 - iVar7) * iVar5 * 2) <= piVar15) {
            return;
          }
          local_14 = (int *)((int)piVar15 + param_7[2] * -2);
          local_18 = (int *)((int)piVar15 + (*param_7 - (uint)uVar2) * 2);
          puVar11 = puVar12;
          piVar15 = local_10;
        }
      }
      if (uVar8 == 0x2000) break;
      if (uVar8 == 0x4000) {
        local_8 = 3;
        break;
      }
      if (uVar8 == 0x6000) {
        param_3 = param_3 + -(int)piVar10;
        puVar11 = puVar12;
        piVar14 = (int *)((int)piVar14 + (int)piVar10 * -2);
      }
      else if (uVar8 == 0x8000) {
        puVar11 = puVar12;
        if ((uVar4 & 0x1fff) != 0) {
          do {
            local_10 = piVar10;
            piVar14 = piVar15;
            param_3 = param_1;
            param_1 = param_1 + param_2[1];
            piVar15 = (int *)((int)piVar14 + iVar5 * 2);
            piVar10 = (int *)((int)local_10 - 1);
            local_10 = piVar15;
          } while (piVar10 != (int *)0x0);
        }
      }
      else {
        puVar11 = puVar12;
        if (uVar8 == 0xa000) {
          return;
        }
      }
    }
    local_20 = 0;
    if ((local_14 < piVar14) || ((int *)((int)piVar14 + (int)piVar10 * -2) <= local_18)) {
      piVar13 = (int *)((int)piVar14 + (int)piVar10 * -2);
      if ((local_14 <= piVar13) || (piVar14 <= local_18)) {
        puVar12 = (ushort *)((int)puVar12 + (int)piVar10 * local_8);
        param_3 = param_3 + -(int)piVar10;
        puVar11 = (ushort *)((int)puVar12 + ((uint)puVar12 & 1));
        piVar14 = piVar13;
        goto LAB_004c14a5;
      }
      if (piVar13 < local_18) {
        local_20 = ((int)piVar10 * 2 - (int)piVar14) + (int)local_18 >> 1;
        piVar10 = (int *)((int)piVar10 - local_20);
      }
      if (local_14 < piVar14) {
        iVar9 = (int)piVar14 - (int)local_14 >> 1;
        piVar10 = (int *)((int)piVar10 - iVar9);
        param_3 = param_3 + -iVar9;
        piVar14 = (int *)((int)piVar14 + iVar9 * -2);
        puVar12 = (ushort *)((int)puVar12 + iVar9 * local_8);
        piVar15 = local_10;
      }
    }
    if (0 < (int)piVar10) {
      local_c = param_3;
      local_1c = (uint)piVar10;
      do {
        iVar9 = *(short *)(param_6 + (uint)(byte)*puVar12 * 2) + param_5;
        if (iVar9 <= (int)(uint)*local_c) {
          *local_c = (ushort)iVar9;
          *(undefined2 *)(((int)piVar14 - (int)param_3) + (int)local_c) =
               *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar12 + 1) * 2);
          piVar15 = local_10;
        }
        puVar12 = (ushort *)((int)puVar12 + local_8);
        local_c = local_c + -1;
        local_1c = local_1c - 1;
      } while (local_1c != 0);
    }
    param_3 = param_3 + -(int)piVar10;
    piVar14 = (int *)((int)piVar14 + (int)piVar10 * -2);
    if (local_20 != 0) {
      puVar12 = (ushort *)((int)puVar12 + local_20 * local_8);
      piVar14 = (int *)((int)piVar14 + local_20 * -2);
      param_3 = param_3 + -local_20;
    }
    puVar11 = (ushort *)((int)puVar12 + ((uint)puVar12 & 1));
  } while( true );
}

