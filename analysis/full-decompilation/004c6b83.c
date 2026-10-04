
void FUN_004c6b83(int *param_1,undefined4 *param_2,ushort *param_3,int param_4,int param_5,
                 int *param_6,int *param_7)

{
  int *piVar1;
  ushort *puVar2;
  int *piVar3;
  ushort uVar4;
  ushort uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  undefined2 uVar11;
  int iVar12;
  uint uVar13;
  int *piVar14;
  int *piVar15;
  int *piVar16;
  int *local_28;
  uint local_18;
  uint local_14;
  int *local_10;
  int *local_c;
  ushort *local_8;
  
  local_c = (int *)*param_2;
  uVar4 = param_3[1];
  piVar6 = (int *)*param_1;
  iVar7 = param_1[1];
  iVar8 = param_7[1];
  iVar9 = param_7[3];
  piVar1 = piVar6;
  piVar15 = param_6;
  piVar16 = param_6;
  local_8 = param_3 + 8;
  do {
    while( true ) {
      while( true ) {
        piVar14 = piVar1;
        puVar2 = local_8 + 1;
        uVar5 = *local_8;
        local_18 = uVar5 & 0x1fff;
        uVar13 = uVar5 & 0xe000;
        if ((uVar5 & 0xe000) != 0) break;
        param_1 = local_c;
        piVar1 = (int *)((int)piVar14 + iVar7 * 2);
        local_c = (int *)((int)local_c + param_2[1] * 2);
        piVar16 = (int *)(*param_6 + param_5);
        piVar15 = piVar14;
        if (piVar14 < (int *)((int)piVar6 + iVar8 * iVar7 * 2)) {
          param_6 = param_6 + 1;
          local_8 = (ushort *)((int)local_8 + local_18);
        }
        else {
          if ((int *)((int)piVar6 + ((uint)uVar4 - iVar9) * iVar7 * 2) <= piVar14) {
            return;
          }
          local_28 = (int *)((int)piVar14 + *param_7 * 2);
          local_10 = (int *)((int)piVar14 + ((uint)*param_3 - param_7[2]) * 2);
          param_6 = param_6 + 1;
          local_8 = puVar2;
        }
      }
      piVar1 = piVar14;
      if (uVar13 == 0x2000) break;
      if (uVar13 == 0x6000) {
        piVar14 = (int *)((int)piVar15 + local_18 * 2);
        local_8 = puVar2;
LAB_004c6d21:
        param_1 = (int *)((int)param_1 + local_18 * 2);
        piVar15 = piVar14;
      }
      else if (uVar13 == 0x8000) {
        local_8 = puVar2;
        if ((uVar5 & 0x1fff) != 0) {
          local_14 = local_18;
          do {
            piVar15 = piVar14;
            param_1 = local_c;
            local_c = (int *)((int)local_c + param_2[1] * 2);
            piVar3 = param_6 + 1;
            piVar14 = (int *)((int)piVar15 + iVar7 * 2);
            piVar16 = (int *)(*param_6 + param_5);
            local_14 = local_14 - 1;
            piVar1 = piVar14;
            param_6 = piVar3;
          } while (local_14 != 0);
        }
      }
      else {
        local_8 = puVar2;
        if (uVar13 == 0xa000) {
          return;
        }
      }
    }
    local_14 = 0;
    if ((piVar15 < local_28) || (local_8 = puVar2, local_10 <= (int *)((int)piVar15 + local_18 * 2))
       ) {
      piVar14 = (int *)(local_18 * 2 + (int)piVar15);
      if ((piVar14 <= local_28) || (local_10 <= piVar15)) {
        local_8 = puVar2 + local_18;
        goto LAB_004c6d21;
      }
      if (local_10 < piVar14) {
        local_14 = (int)((local_18 * 2 - (int)local_10) + (int)piVar15) >> 1;
        local_18 = local_18 - local_14;
      }
      local_8 = puVar2;
      if (piVar15 < local_28) {
        iVar12 = (int)local_28 - (int)piVar15 >> 1;
        local_18 = local_18 - iVar12;
        param_1 = (int *)((int)param_1 + iVar12 * 2);
        piVar15 = (int *)((int)piVar15 + iVar12 * 2);
        local_8 = puVar2 + iVar12;
      }
    }
    if (0 < (int)local_18) {
      do {
        bVar10 = (byte)*local_8 >> 3;
        if (bVar10 != 0) {
          *(short *)param_1 = (short)piVar16;
          if (bVar10 < 0x1f) {
            uVar11 = FUN_0049a996(bVar10);
          }
          else {
            uVar11 = *(undefined2 *)(param_4 + (uint)*(byte *)((int)local_8 + 1) * 2);
          }
          *(undefined2 *)piVar15 = uVar11;
        }
        local_8 = local_8 + 1;
        param_1 = (int *)((int)param_1 + 2);
        piVar15 = (int *)((int)piVar15 + 2);
        local_18 = local_18 - 1;
      } while (local_18 != 0);
    }
    if (local_14 != 0) {
      param_1 = (int *)((int)param_1 + local_14 * 2);
      piVar15 = (int *)((int)piVar15 + local_14 * 2);
      local_8 = local_8 + local_14;
    }
  } while( true );
}

