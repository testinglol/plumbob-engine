
void FUN_004bf678(int *param_1,undefined4 *param_2,ushort *param_3,int param_4,int param_5,
                 int param_6,int *param_7)

{
  int *piVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  ushort *puVar12;
  int *piVar13;
  uint uVar14;
  int *local_34;
  int local_24;
  uint local_20;
  int *local_1c;
  ushort *local_18;
  ushort *local_14;
  int local_10;
  ushort *local_c;
  ushort *local_8;
  
  piVar4 = (int *)*param_1;
  local_18 = (ushort *)*param_2;
  uVar2 = param_3[1];
  iVar5 = param_1[1];
  iVar6 = param_7[1];
  iVar7 = param_7[3];
  puVar12 = param_3 + 8;
  piVar1 = piVar4;
  piVar13 = param_1;
LAB_004bf6c0:
  do {
    while( true ) {
      while( true ) {
        piVar11 = piVar1;
        local_10 = 2;
        uVar3 = *puVar12;
        uVar14 = uVar3 & 0x1fff;
        uVar8 = uVar3 & 0xe000;
        local_c = puVar12 + 1;
        if ((uVar3 & 0xe000) != 0) break;
        local_8 = local_18;
        piVar1 = (int *)((int)piVar11 + param_1[1] * 2);
        local_18 = local_18 + param_2[1];
        piVar13 = piVar11;
        if (piVar11 < (int *)((int)piVar4 + iVar6 * iVar5 * 2)) {
          puVar12 = (ushort *)((int)puVar12 + uVar14);
        }
        else {
          if ((int *)((int)piVar4 + ((uint)uVar2 - iVar7) * iVar5 * 2) <= piVar11) {
            return;
          }
          local_34 = (int *)((int)piVar11 + *param_7 * 2);
          local_1c = (int *)((int)piVar11 + ((uint)*param_3 - param_7[2]) * 2);
          puVar12 = local_c;
        }
      }
      piVar1 = piVar11;
      if (uVar8 == 0x2000) break;
      if (uVar8 == 0x4000) {
        local_10 = 3;
        break;
      }
      if (uVar8 == 0x6000) {
        local_8 = local_8 + uVar14;
        puVar12 = local_c;
        piVar13 = (int *)((int)piVar13 + uVar14 * 2);
      }
      else if (uVar8 == 0x8000) {
        iVar9 = (uVar14 - 1) * param_1[1];
        iVar10 = param_2[1] * (uVar14 - 1);
        local_8 = local_8 + iVar10;
        local_18 = local_18 + param_2[1] + iVar10;
        puVar12 = local_c;
        piVar1 = (int *)((int)piVar11 + (param_1[1] + iVar9) * 2);
        piVar13 = (int *)((int)piVar13 + iVar9 * 2);
      }
      else {
        puVar12 = local_c;
        if (uVar8 == 0xa000) {
          return;
        }
      }
    }
    local_24 = 0;
    if ((piVar13 < local_34) || (local_1c <= (int *)((int)piVar13 + uVar14 * 2))) {
      piVar11 = (int *)(uVar14 * 2 + (int)piVar13);
      if ((piVar11 <= local_34) || (local_1c <= piVar13)) {
        local_c = (ushort *)((int)local_c + uVar14 * local_10);
        puVar12 = (ushort *)((int)local_c + ((uint)local_c & 1));
        local_8 = local_8 + uVar14;
        piVar13 = piVar11;
        goto LAB_004bf6c0;
      }
      if (local_1c < piVar11) {
        local_24 = (int)((uVar14 * 2 - (int)local_1c) + (int)piVar13) >> 1;
        uVar14 = uVar14 - local_24;
      }
      if (piVar13 < local_34) {
        iVar9 = (int)local_34 - (int)piVar13 >> 1;
        uVar14 = uVar14 - iVar9;
        local_8 = local_8 + iVar9;
        piVar13 = (int *)((int)piVar13 + iVar9 * 2);
        local_c = (ushort *)((int)local_c + iVar9 * local_10);
      }
    }
    if ((int)uVar14 < 0x10) {
      if (0 < (int)uVar14) {
        local_14 = local_8;
        local_20 = uVar14;
        do {
          iVar9 = *(short *)(param_6 + (uint)(byte)*local_c * 2) + param_5;
          if (iVar9 <= (int)(uint)*local_14) {
            *local_14 = (ushort)iVar9;
            *(undefined2 *)(((int)piVar13 - (int)local_8) + (int)local_14) =
                 *(undefined2 *)(param_4 + (uint)*(byte *)((int)local_c + 1) * 2);
          }
          local_c = (ushort *)((int)local_c + local_10);
          local_14 = local_14 + 1;
          local_20 = local_20 - 1;
        } while (local_20 != 0);
      }
    }
    else {
      FUN_004bbf78(uVar14,local_c,piVar13,local_8,param_4,param_5,param_6,local_10);
      local_c = (ushort *)((int)local_c + uVar14 * local_10);
    }
    local_8 = local_8 + uVar14;
    piVar13 = (int *)((int)piVar13 + uVar14 * 2);
    if (local_24 != 0) {
      local_c = (ushort *)((int)local_c + local_24 * local_10);
      piVar13 = (int *)((int)piVar13 + local_24 * 2);
      local_8 = local_8 + local_24;
    }
    puVar12 = (ushort *)((int)local_c + ((uint)local_c & 1));
  } while( true );
}

