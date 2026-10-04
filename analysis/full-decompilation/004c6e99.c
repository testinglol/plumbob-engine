
void FUN_004c6e99(undefined4 *param_1,undefined4 *param_2,ushort *param_3,int param_4,int param_5,
                 int *param_6,int *param_7)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  ushort *puVar13;
  ushort *puVar14;
  uint local_1c;
  uint local_18;
  int *local_14;
  uint local_10;
  int *local_c;
  undefined4 *local_8;
  
  piVar3 = (int *)*param_1;
  iVar4 = param_1[1];
  local_8 = (undefined4 *)*param_2;
  uVar1 = param_3[1];
  iVar5 = param_7[1];
  iVar6 = param_7[3];
  piVar7 = param_6;
  piVar9 = param_6;
  piVar10 = piVar3;
  puVar13 = param_3 + 8;
  do {
    while( true ) {
      while( true ) {
        uVar2 = *puVar13;
        local_18 = uVar2 & 0x1fff;
        uVar11 = uVar2 & 0xe000;
        puVar14 = puVar13 + 1;
        if ((uVar2 & 0xe000) != 0) break;
        param_1 = local_8;
        piVar8 = (int *)((int)piVar10 + iVar4 * 2);
        local_8 = (undefined4 *)((int)local_8 + param_2[1] * 2);
        piVar7 = (int *)(*param_6 + param_5);
        piVar9 = piVar10;
        if (piVar10 < (int *)((int)piVar3 + iVar5 * iVar4 * 2)) {
          piVar10 = piVar8;
          puVar13 = (ushort *)((int)puVar13 + local_18);
          param_6 = param_6 + 1;
        }
        else {
          if ((int *)((int)piVar3 + ((uint)uVar1 - iVar6) * iVar4 * 2) <= piVar10) {
            return;
          }
          local_14 = (int *)((int)piVar10 + *param_7 * 2);
          local_c = (int *)((int)piVar10 + ((uint)*param_3 - param_7[2]) * 2);
          piVar10 = piVar8;
          puVar13 = puVar14;
          param_6 = param_6 + 1;
        }
      }
      if (uVar11 != 0x2000) break;
      local_1c = 0;
      if ((piVar9 < local_14) || (local_c <= (int *)((int)piVar9 + local_18 * 2))) {
        iVar12 = local_18 * 2;
        piVar8 = (int *)(iVar12 + (int)piVar9);
        if ((local_14 < piVar8) && (piVar9 < local_c)) {
          if (local_c < piVar8) {
            local_1c = (iVar12 - (int)local_c) + (int)piVar9 >> 1;
            local_18 = local_18 - local_1c;
          }
          if (piVar9 < local_14) {
            iVar12 = (int)local_14 - (int)piVar9 >> 1;
            local_18 = local_18 - iVar12;
            param_1 = (undefined4 *)((int)param_1 + iVar12 * 2);
            piVar9 = (int *)((int)piVar9 + iVar12 * 2);
            puVar14 = puVar14 + iVar12;
          }
          goto LAB_004c6fc8;
        }
        puVar14 = puVar14 + local_18;
LAB_004c7010:
        param_1 = (undefined4 *)((int)param_1 + iVar12);
        piVar9 = piVar8;
        puVar13 = puVar14;
      }
      else {
LAB_004c6fc8:
        if (0 < (int)local_18) {
          do {
            if ((*puVar14 & 0xf8) != 0) {
              *(short *)param_1 = (short)piVar7;
              *(undefined2 *)piVar9 =
                   *(undefined2 *)(param_4 + (uint)*(byte *)((int)puVar14 + 1) * 2);
            }
            param_1 = (undefined4 *)((int)param_1 + 2);
            puVar14 = puVar14 + 1;
            piVar9 = (int *)((int)piVar9 + 2);
            local_18 = local_18 - 1;
          } while (local_18 != 0);
        }
        puVar13 = puVar14;
        if (local_1c != 0) {
          puVar14 = puVar14 + local_1c;
          goto LAB_004c6f69;
        }
      }
    }
    local_1c = local_18;
    if (uVar11 == 0x6000) {
LAB_004c6f69:
      iVar12 = local_1c * 2;
      piVar8 = (int *)((int)piVar9 + iVar12);
      goto LAB_004c7010;
    }
    if (uVar11 == 0x8000) {
      puVar13 = puVar14;
      if ((uVar2 & 0x1fff) != 0) {
        local_10 = local_18;
        do {
          piVar9 = piVar10;
          param_1 = local_8;
          local_8 = (undefined4 *)((int)local_8 + param_2[1] * 2);
          piVar10 = (int *)((int)piVar9 + iVar4 * 2);
          piVar8 = param_6 + 1;
          piVar7 = (int *)(*param_6 + param_5);
          local_10 = local_10 - 1;
          param_6 = piVar8;
        } while (local_10 != 0);
      }
    }
    else {
      puVar13 = puVar14;
      if (uVar11 == 0xa000) {
        return;
      }
    }
  } while( true );
}

