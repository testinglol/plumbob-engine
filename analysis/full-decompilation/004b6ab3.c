
void FUN_004b6ab3(int *param_1,int *param_2,ushort *param_3,undefined2 *param_4)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  uint uVar11;
  undefined2 *puVar12;
  undefined2 *puVar13;
  int in_stack_00000020;
  int *in_stack_00000024;
  int *in_stack_00000028;
  int local_50;
  undefined2 *local_4c;
  int local_38;
  uint local_34;
  undefined2 *local_2c;
  undefined2 *local_28;
  int local_20;
  ushort *local_1c;
  int local_8;
  
  local_20 = *param_2;
  puVar3 = (undefined2 *)*param_1;
  uVar1 = param_3[1];
  iVar4 = param_1[1];
  iVar5 = in_stack_00000028[1];
  iVar6 = in_stack_00000028[3];
  puVar10 = param_3 + 8;
  puVar13 = puVar3;
  do {
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            uVar2 = *puVar10;
            uVar11 = uVar2 & 0x1fff;
            uVar8 = uVar2 & 0xe000;
            local_1c = puVar10 + 1;
            if ((uVar2 & 0xe000) != 0) break;
            local_8 = local_20;
            local_20 = local_20 + param_2[1] * 2;
            if (puVar13 < puVar3 + iVar5 * iVar4) {
              puVar10 = (ushort *)((int)puVar10 + uVar11);
            }
            else {
              if (puVar3 + ((uint)uVar1 - iVar6) * iVar4 <= puVar13) {
                return;
              }
              local_4c = puVar13 + *in_stack_00000028;
              local_2c = puVar13 + ((uint)*param_3 - in_stack_00000028[2]);
              puVar10 = local_1c;
            }
            local_50 = *in_stack_00000024 + in_stack_00000020;
            in_stack_00000024 = in_stack_00000024 + 1;
            param_4 = puVar13;
            puVar13 = puVar13 + param_1[1];
          }
          if (uVar8 != 0x6000) break;
          local_8 = local_8 + uVar11 * 2;
          puVar10 = local_1c;
          param_4 = param_4 + uVar11;
        }
        if (uVar8 != 0x8000) break;
        local_20 = local_20 + param_2[1] * uVar11 * 2;
        local_8 = local_20 + param_2[1] * -2;
        puVar10 = local_1c;
        param_4 = puVar13 + param_1[1] * uVar11 + -param_1[1];
        puVar13 = puVar13 + param_1[1] * uVar11;
      }
      if (uVar8 == 0xa000) {
        return;
      }
      puVar10 = local_1c;
    } while (uVar8 != 0xc000);
    local_38 = 0;
    if ((param_4 < local_4c) || (local_2c <= param_4 + uVar11)) {
      puVar12 = param_4 + uVar11;
      if ((local_4c < puVar12) && (param_4 < local_2c)) {
        if (local_2c < puVar12) {
          local_38 = (int)((uVar11 * 2 - (int)local_2c) + (int)param_4) >> 1;
          uVar11 = uVar11 - local_38;
        }
        if (param_4 < local_4c) {
          iVar9 = (int)local_4c - (int)param_4 >> 1;
          uVar11 = uVar11 - iVar9;
          local_8 = local_8 + iVar9 * 2;
          param_4 = param_4 + iVar9;
          local_1c = (ushort *)((int)local_1c + iVar9);
        }
        goto LAB_004b6ba9;
      }
      local_8 = local_8 + uVar11 * 2;
      uVar8 = (int)local_1c + uVar11;
    }
    else {
LAB_004b6ba9:
      if (0 < (int)uVar11) {
        local_34 = uVar11;
        local_28 = param_4;
        do {
          *(undefined2 *)((local_8 - (int)param_4) + (int)local_28) = (undefined2)local_50;
          uVar7 = FUN_00438f12();
          local_34 = local_34 - 1;
          *local_28 = uVar7;
          local_28 = local_28 + 1;
        } while (local_34 != 0);
      }
      uVar8 = (int)local_1c + uVar11;
      local_8 = local_8 + uVar11 * 2;
      puVar12 = param_4 + uVar11;
      if (local_38 != 0) {
        local_8 = local_8 + local_38 * 2;
        uVar8 = uVar8 + local_38;
        puVar12 = puVar12 + local_38;
      }
    }
    puVar10 = (ushort *)(uVar8 + (uVar8 & 1));
    param_4 = puVar12;
  } while( true );
}

