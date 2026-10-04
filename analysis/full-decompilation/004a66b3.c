
void FUN_004a66b3(int *param_1,undefined4 *param_2,ushort *param_3,undefined4 param_4,int param_5,
                 int *param_6,int *param_7)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  int *piVar13;
  int *piVar14;
  undefined2 uVar15;
  bool bVar16;
  int *local_3c;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  int *local_20;
  ushort *local_1c;
  int *local_18;
  uint local_14;
  uint local_10;
  ushort *local_c;
  ushort *local_8;
  
  local_14 = 0xffffffff;
  local_1c = (ushort *)*param_2;
  uVar2 = param_3[1];
  piVar4 = (int *)*param_1;
  iVar5 = param_1[1];
  iVar6 = param_7[1];
  iVar7 = param_7[3];
  piVar13 = param_1;
  local_18 = piVar4;
  local_8 = param_3 + 8;
  do {
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            uVar3 = *local_8;
            local_28 = uVar3 & 0x1fff;
            uVar9 = uVar3 & 0xe000;
            puVar12 = local_8 + 1;
            if ((uVar3 & 0xe000) != 0) break;
            local_c = local_1c;
            local_1c = local_1c + param_2[1];
            if (local_18 < (int *)((int)piVar4 + iVar6 * iVar5 * 2)) {
              local_8 = (ushort *)((int)local_8 + local_28);
            }
            else {
              if ((int *)((int)piVar4 + ((uint)uVar2 - iVar7) * iVar5 * 2) <= local_18) {
                return;
              }
              local_3c = (int *)((int)local_18 + *param_7 * 2);
              local_20 = (int *)((int)local_18 + ((uint)*param_3 - param_7[2]) * 2);
              local_8 = puVar12;
            }
            local_10 = 0;
            local_30 = *param_6 + param_5;
            local_14 = local_14 + 1;
            piVar13 = local_18;
            param_6 = param_6 + 1;
            local_18 = (int *)((int)local_18 + param_1[1] * 2);
          }
          if (uVar9 != 0x6000) break;
          local_c = local_c + local_28;
          piVar13 = (int *)((int)piVar13 + local_28 * 2);
          local_10 = local_10 + local_28;
          local_8 = puVar12;
        }
        if (uVar9 != 0x8000) break;
        if ((uVar3 & 0x1fff) != 0) {
          uVar9 = local_28;
          do {
            piVar14 = (int *)((int)local_18 + param_1[1] * 2);
            puVar1 = local_1c + param_2[1];
            uVar9 = uVar9 - 1;
            local_c = local_1c;
            piVar13 = local_18;
            local_1c = puVar1;
            local_18 = piVar14;
          } while (uVar9 != 0);
        }
        local_14 = local_14 + local_28;
        local_8 = puVar12;
      }
      if (uVar9 == 0xa000) {
        return;
      }
      local_8 = puVar12;
    } while (uVar9 != 0xc000);
    local_2c = 0;
    if ((piVar13 < local_3c) || (local_20 <= (int *)((int)piVar13 + local_28 * 2))) {
      iVar10 = local_28 * 2;
      piVar14 = (int *)(iVar10 + (int)piVar13);
      if ((local_3c < piVar14) && (piVar13 < local_20)) {
        if (local_20 < piVar14) {
          local_2c = (iVar10 - (int)local_20) + (int)piVar13 >> 1;
          local_28 = local_28 - local_2c;
        }
        if (piVar13 < local_3c) {
          iVar10 = (int)local_3c - (int)piVar13 >> 1;
          local_8 = (ushort *)((int)puVar12 + iVar10);
          local_28 = local_28 - iVar10;
          local_c = local_c + iVar10;
          piVar13 = (int *)((int)piVar13 + iVar10 * 2);
          local_10 = local_10 + iVar10;
        }
        goto LAB_004a679b;
      }
      local_8 = (ushort *)((int)puVar12 + local_28);
LAB_004a688f:
      local_c = (ushort *)((int)local_c + iVar10);
    }
    else {
LAB_004a679b:
      if (0 < (int)local_28) {
        local_8 = (ushort *)((int)local_8 + local_28);
        local_24 = local_10;
        do {
          local_24 = local_24 + 1;
          if (local_30 <= (int)(uint)*local_c) {
            if ((((local_10 & 3) == 0) && ((local_14 & 3) == 0)) ||
               (((local_10 & 3) == 2 && (((byte)local_14 & 3) == 2)))) {
              bVar8 = true;
            }
            else {
              bVar8 = false;
            }
            uVar15 = 0;
            iVar10 = ((int)local_24 >> 1) + local_14;
            iVar11 = local_14 - ((int)local_10 >> 1);
            uVar3 = param_3[1];
            if (uVar3 == 0x10) {
              if ((iVar10 != 8) && (iVar11 != -7)) {
                if (iVar10 != 0x17) {
                  bVar16 = iVar11 == 8;
LAB_004a6846:
                  if (!bVar16) goto LAB_004a6854;
                }
                goto LAB_004a6848;
              }
LAB_004a684c:
              uVar15 = 0xffff;
              bVar8 = true;
LAB_004a6854:
              if (!bVar8) goto LAB_004a6865;
            }
            else {
              if (uVar3 == 0x20) {
                if ((iVar10 == 0x10) || (iVar11 == -0xf)) goto LAB_004a684c;
                if (iVar10 != 0x2f) {
                  bVar16 = iVar11 == 0x10;
                  goto LAB_004a6846;
                }
              }
              else {
                if (uVar3 != 0x40) goto LAB_004a6854;
                if ((iVar10 == 0x20) || (iVar11 == -0x1f)) goto LAB_004a684c;
                if (iVar10 != 0x5f) {
                  bVar16 = iVar11 == 0x20;
                  goto LAB_004a6846;
                }
              }
LAB_004a6848:
              uVar15 = 0;
            }
            *(undefined2 *)piVar13 = uVar15;
            *local_c = (ushort)local_30;
          }
LAB_004a6865:
          local_c = local_c + 1;
          piVar13 = (int *)((int)piVar13 + 2);
          local_10 = local_10 + 1;
          local_28 = local_28 - 1;
        } while (local_28 != 0);
      }
      piVar14 = piVar13;
      if (local_2c != 0) {
        local_8 = (ushort *)((int)local_8 + local_2c);
        iVar10 = local_2c * 2;
        piVar14 = (int *)((int)piVar13 + iVar10);
        goto LAB_004a688f;
      }
    }
    piVar13 = piVar14;
    local_8 = (ushort *)((int)local_8 + ((uint)local_8 & 1));
  } while( true );
}

