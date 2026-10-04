
void FUN_004bfa92(int *param_1,int *param_2,ushort *param_3,int param_4,int param_5,int param_6,
                 int *param_7)

{
  int *piVar1;
  int *piVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  ushort *puVar12;
  uint uVar13;
  int *piVar14;
  int local_28;
  uint local_24;
  int *local_20;
  int *local_1c;
  ushort *local_18;
  ushort *local_14;
  int local_10;
  ushort *local_c;
  ushort *local_8;
  
  iVar5 = param_1[1];
  piVar2 = (int *)(*param_1 + -2 + (uint)*param_3 * 2);
  uVar3 = param_3[1];
  local_18 = (ushort *)(*param_2 + -2 + (uint)*param_3 * 2);
  iVar6 = param_7[1];
  iVar7 = param_7[3];
  puVar12 = param_3 + 8;
  piVar1 = piVar2;
  piVar14 = param_1;
LAB_004bfae7:
  do {
    while( true ) {
      while( true ) {
        piVar10 = piVar1;
        local_10 = 2;
        uVar4 = *puVar12;
        uVar13 = uVar4 & 0x1fff;
        uVar8 = uVar4 & 0xe000;
        local_c = puVar12 + 1;
        if ((uVar4 & 0xe000) != 0) break;
        local_8 = local_18;
        piVar1 = (int *)((int)piVar10 + param_1[1] * 2);
        local_18 = local_18 + param_2[1];
        piVar14 = piVar10;
        if (piVar10 < (int *)((int)piVar2 + iVar6 * iVar5 * 2)) {
          puVar12 = (ushort *)((int)puVar12 + uVar13);
        }
        else {
          if ((int *)((int)piVar2 + ((uint)uVar3 - iVar7) * iVar5 * 2) <= piVar10) {
            return;
          }
          local_1c = (int *)((int)piVar10 + param_7[2] * -2);
          local_20 = (int *)((int)piVar10 + (*param_7 - (uint)*param_3) * 2);
          puVar12 = local_c;
        }
      }
      piVar1 = piVar10;
      if (uVar8 == 0x2000) break;
      if (uVar8 == 0x4000) {
        local_10 = 3;
        break;
      }
      if (uVar8 == 0x6000) {
        local_8 = local_8 + -uVar13;
        puVar12 = local_c;
        piVar14 = (int *)((int)piVar14 + uVar13 * -2);
      }
      else if (uVar8 == 0x8000) {
        iVar9 = (uVar13 - 1) * param_1[1];
        iVar11 = param_2[1] * (uVar13 - 1);
        local_8 = local_8 + iVar11;
        local_18 = local_18 + param_2[1] + iVar11;
        puVar12 = local_c;
        piVar1 = (int *)((int)piVar10 + (param_1[1] + iVar9) * 2);
        piVar14 = (int *)((int)piVar14 + iVar9 * 2);
      }
      else {
        puVar12 = local_c;
        if (uVar8 == 0xa000) {
          return;
        }
      }
    }
    local_28 = 0;
    if ((local_1c < piVar14) || ((int *)((int)piVar14 + uVar13 * -2) <= local_20)) {
      piVar10 = (int *)((int)piVar14 + uVar13 * -2);
      if ((local_1c <= piVar10) || (piVar14 <= local_20)) {
        local_c = (ushort *)((int)local_c + uVar13 * local_10);
        puVar12 = (ushort *)((int)local_c + ((uint)local_c & 1));
        local_8 = local_8 + -uVar13;
        piVar14 = piVar10;
        goto LAB_004bfae7;
      }
      if (piVar10 < local_20) {
        local_28 = (int)((uVar13 * 2 - (int)piVar14) + (int)local_20) >> 1;
        uVar13 = uVar13 - local_28;
      }
      if (local_1c < piVar14) {
        iVar9 = (int)piVar14 - (int)local_1c >> 1;
        uVar13 = uVar13 - iVar9;
        local_8 = local_8 + -iVar9;
        piVar14 = (int *)((int)piVar14 + iVar9 * -2);
        local_c = (ushort *)((int)local_c + iVar9 * local_10);
      }
    }
    if ((int)uVar13 < 0x10) {
      if (0 < (int)uVar13) {
        local_14 = local_8;
        local_24 = uVar13;
        do {
          iVar9 = *(short *)(param_6 + (uint)(byte)*local_c * 2) + param_5;
          if (iVar9 <= (int)(uint)*local_14) {
            *local_14 = (ushort)iVar9;
            *(undefined2 *)(((int)piVar14 - (int)local_8) + (int)local_14) =
                 *(undefined2 *)(param_4 + (uint)*(byte *)((int)local_c + 1) * 2);
          }
          local_c = (ushort *)((int)local_c + local_10);
          local_14 = local_14 + -1;
          local_24 = local_24 - 1;
        } while (local_24 != 0);
      }
    }
    else {
      FUN_004bcef1(uVar13,local_c,piVar14,local_8,param_4,param_5,param_6,local_10);
      local_c = (ushort *)((int)local_c + uVar13 * local_10);
    }
    local_8 = local_8 + -uVar13;
    piVar14 = (int *)((int)piVar14 + uVar13 * -2);
    if (local_28 != 0) {
      local_c = (ushort *)((int)local_c + local_28 * local_10);
      piVar14 = (int *)((int)piVar14 + local_28 * -2);
      local_8 = local_8 + -local_28;
    }
    puVar12 = (ushort *)((int)local_c + ((uint)local_c & 1));
  } while( true );
}

