
void FUN_004b7118(int *param_1,undefined4 *param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  int *piVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  int in_stack_0000001c;
  int *in_stack_00000020;
  int *in_stack_00000024;
  int local_44;
  int *local_40;
  int local_30;
  uint local_2c;
  int *local_20;
  ushort *local_1c;
  ushort *local_18;
  ushort *local_14;
  ushort *local_8;
  
  local_1c = (ushort *)*param_2;
  piVar3 = (int *)*param_1;
  uVar1 = param_3[1];
  iVar4 = param_1[1];
  iVar5 = in_stack_00000024[1];
  iVar6 = in_stack_00000024[3];
  puVar10 = param_3 + 8;
  piVar13 = param_1;
  piVar14 = piVar3;
  do {
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            uVar2 = *puVar10;
            uVar12 = uVar2 & 0x1fff;
            uVar8 = uVar2 & 0xe000;
            local_14 = puVar10 + 1;
            if ((uVar2 & 0xe000) != 0) break;
            local_8 = local_1c;
            local_1c = local_1c + param_2[1];
            if (piVar14 < (int *)((int)piVar3 + iVar5 * iVar4 * 2)) {
              puVar10 = (ushort *)((int)puVar10 + uVar12);
            }
            else {
              if ((int *)((int)piVar3 + ((uint)uVar1 - iVar6) * iVar4 * 2) <= piVar14) {
                return;
              }
              local_40 = (int *)((int)piVar14 + *in_stack_00000024 * 2);
              local_20 = (int *)((int)piVar14 + ((uint)*param_3 - in_stack_00000024[2]) * 2);
              puVar10 = local_14;
            }
            local_44 = *in_stack_00000020 + in_stack_0000001c;
            in_stack_00000020 = in_stack_00000020 + 1;
            piVar13 = piVar14;
            piVar14 = (int *)((int)piVar14 + param_1[1] * 2);
          }
          if (uVar8 != 0x6000) break;
          local_8 = local_8 + uVar12;
          puVar10 = local_14;
          piVar13 = (int *)((int)piVar13 + uVar12 * 2);
        }
        if (uVar8 != 0x8000) break;
        piVar14 = (int *)((int)piVar14 + param_1[1] * uVar12 * 2);
        local_1c = local_1c + param_2[1] * uVar12;
        local_8 = local_1c + -param_2[1];
        puVar10 = local_14;
        piVar13 = (int *)((int)piVar14 + param_1[1] * -2);
      }
      if (uVar8 == 0xa000) {
        return;
      }
      puVar10 = local_14;
    } while (uVar8 != 0xc000);
    local_30 = 0;
    if ((piVar13 < local_40) || (local_20 <= (int *)((int)piVar13 + uVar12 * 2))) {
      piVar11 = (int *)(uVar12 * 2 + (int)piVar13);
      if ((local_40 < piVar11) && (piVar13 < local_20)) {
        if (local_20 < piVar11) {
          local_30 = (int)((uVar12 * 2 - (int)local_20) + (int)piVar13) >> 1;
          uVar12 = uVar12 - local_30;
        }
        if (piVar13 < local_40) {
          iVar9 = (int)local_40 - (int)piVar13 >> 1;
          uVar12 = uVar12 - iVar9;
          local_8 = local_8 + iVar9;
          piVar13 = (int *)((int)piVar13 + iVar9 * 2);
          local_14 = (ushort *)((int)local_14 + iVar9);
        }
        goto LAB_004b7203;
      }
      uVar8 = (int)local_14 + uVar12;
      local_8 = local_8 + uVar12;
    }
    else {
LAB_004b7203:
      if (0 < (int)uVar12) {
        local_18 = local_8;
        local_2c = uVar12;
        do {
          if (local_44 <= (int)(uint)*local_18) {
            *local_18 = (ushort)local_44;
            uVar7 = FUN_00438f12();
            *(undefined2 *)(((int)piVar13 - (int)local_8) + (int)local_18) = uVar7;
          }
          local_18 = local_18 + 1;
          local_2c = local_2c - 1;
        } while (local_2c != 0);
      }
      local_8 = local_8 + uVar12;
      piVar11 = (int *)((int)piVar13 + uVar12 * 2);
      uVar8 = (int)local_14 + uVar12;
      if (local_30 != 0) {
        uVar8 = uVar8 + local_30;
        local_8 = local_8 + local_30;
        piVar11 = (int *)((int)piVar11 + local_30 * 2);
      }
    }
    puVar10 = (ushort *)(uVar8 + (uVar8 & 1));
    piVar13 = piVar11;
  } while( true );
}

