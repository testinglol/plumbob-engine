
void FUN_004b67e3(uint *param_1,undefined4 *param_2,ushort *param_3,uint param_4)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int in_stack_00000020;
  int *in_stack_00000024;
  int *in_stack_00000028;
  int local_58;
  uint local_54;
  int local_34;
  uint local_30;
  uint local_28;
  ushort *local_20;
  ushort *local_1c;
  ushort *local_10;
  ushort *local_8;
  
  local_20 = (ushort *)*param_2;
  uVar2 = param_3[1];
  uVar4 = *param_1;
  uVar5 = param_1[1];
  iVar6 = in_stack_00000028[1];
  iVar7 = in_stack_00000028[3];
  uVar12 = uVar4;
  local_8 = param_3 + 8;
  do {
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            puVar1 = local_8 + 1;
            uVar3 = *local_8;
            uVar11 = uVar3 & 0x1fff;
            uVar9 = uVar3 & 0xe000;
            if ((uVar3 & 0xe000) != 0) break;
            local_10 = local_20;
            local_20 = local_20 + param_2[1];
            if (uVar12 < uVar4 + iVar6 * uVar5 * 2) {
              local_8 = (ushort *)((int)local_8 + uVar11);
            }
            else {
              if (uVar4 + ((uint)uVar2 - iVar7) * uVar5 * 2 <= uVar12) {
                return;
              }
              local_54 = uVar12 + *in_stack_00000028 * 2;
              local_28 = uVar12 + ((uint)*param_3 - in_stack_00000028[2]) * 2;
              local_8 = puVar1;
            }
            local_58 = *in_stack_00000024 + in_stack_00000020;
            in_stack_00000024 = in_stack_00000024 + 1;
            param_4 = uVar12;
            uVar12 = uVar12 + param_1[1] * 2;
          }
          if (uVar9 != 0x6000) break;
          local_10 = local_10 + uVar11;
          param_4 = param_4 + uVar11 * 2;
          local_8 = puVar1;
        }
        if (uVar9 != 0x8000) break;
        uVar12 = uVar12 + param_1[1] * uVar11 * 2;
        local_20 = local_20 + param_2[1] * uVar11;
        local_10 = local_20 + -param_2[1];
        param_4 = uVar12 + param_1[1] * -2;
        local_8 = puVar1;
      }
      if (uVar9 == 0xa000) {
        return;
      }
      local_8 = puVar1;
    } while (uVar9 != 0xc000);
    local_34 = 0;
    if ((param_4 < local_54) || (local_28 <= param_4 + uVar11 * 2)) {
      uVar9 = uVar11 * 2 + param_4;
      if ((local_54 < uVar9) && (param_4 < local_28)) {
        if (local_28 < uVar9) {
          local_34 = (int)((uVar11 * 2 - local_28) + param_4) >> 1;
          uVar11 = uVar11 - local_34;
        }
        if (param_4 < local_54) {
          iVar10 = (int)(local_54 - param_4) >> 1;
          uVar11 = uVar11 - iVar10;
          local_10 = local_10 + iVar10;
          param_4 = param_4 + iVar10 * 2;
          local_8 = (ushort *)((int)puVar1 + iVar10);
        }
        goto LAB_004b68d4;
      }
      local_8 = (ushort *)((int)puVar1 + uVar11);
      local_10 = local_10 + uVar11;
    }
    else {
LAB_004b68d4:
      if (0 < (int)uVar11) {
        local_1c = local_10;
        local_30 = uVar11;
        do {
          if (local_58 <= (int)(uint)*local_1c) {
            *local_1c = (ushort)local_58;
            uVar8 = FUN_00438f12();
            *(undefined2 *)((param_4 - (int)local_10) + (int)local_1c) = uVar8;
          }
          local_1c = local_1c + 1;
          local_30 = local_30 - 1;
        } while (local_30 != 0);
      }
      local_8 = (ushort *)((int)local_8 + uVar11);
      local_10 = local_10 + uVar11;
      uVar9 = param_4 + uVar11 * 2;
      if (local_34 != 0) {
        local_8 = (ushort *)((int)local_8 + local_34);
        local_10 = local_10 + local_34;
        uVar9 = uVar9 + local_34 * 2;
      }
    }
    param_4 = uVar9;
    local_8 = (ushort *)((int)local_8 + ((uint)local_8 & 1));
  } while( true );
}

