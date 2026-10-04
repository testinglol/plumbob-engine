
void FUN_004b65f9(undefined4 *param_1,int *param_2,ushort *param_3)

{
  int iVar1;
  ushort *puVar2;
  ushort uVar3;
  undefined2 *puVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  undefined2 *puVar8;
  int iVar9;
  int in_stack_00000020;
  int *in_stack_00000024;
  int local_38;
  uint local_24;
  undefined2 *local_20;
  int local_c;
  undefined2 *local_8;
  
  puVar4 = (undefined2 *)*param_1;
  iVar1 = *param_2;
  param_3 = (ushort *)((int)param_3 + 0x10);
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          iVar9 = iVar1;
          puVar8 = puVar4;
          puVar2 = param_3 + 1;
          uVar3 = *param_3;
          uVar6 = uVar3 & 0x1fff;
          uVar7 = uVar3 & 0xe000;
          param_3 = puVar2;
          if ((uVar3 & 0xe000) != 0) break;
          local_38 = *in_stack_00000024 + in_stack_00000020;
          in_stack_00000024 = in_stack_00000024 + 1;
          puVar4 = puVar8 + param_1[1];
          iVar1 = iVar9 + param_2[1] * 2;
          local_c = iVar9;
          local_8 = puVar8;
        }
        puVar4 = puVar8;
        iVar1 = iVar9;
        if (uVar7 != 0x6000) break;
        local_c = local_c + uVar6 * 2;
        local_8 = local_8 + uVar6;
      }
      if (uVar7 != 0x8000) break;
      iVar1 = iVar9 + param_2[1] * uVar6 * 2;
      puVar4 = puVar8 + param_1[1] * uVar6;
      local_c = iVar1 + param_2[1] * -2;
      local_8 = puVar8 + param_1[1] * uVar6 + -param_1[1];
    }
    if (uVar7 != 0xc000) break;
    if ((uVar3 & 0x1fff) != 0) {
      local_20 = local_8;
      local_24 = uVar6;
      do {
        *(undefined2 *)((local_c - (int)local_8) + (int)local_20) = (undefined2)local_38;
        uVar5 = FUN_00438f12();
        local_24 = local_24 - 1;
        *local_20 = uVar5;
        local_20 = local_20 + 1;
      } while (local_24 != 0);
    }
    param_3 = (ushort *)((int)puVar2 + uVar6 + ((int)puVar2 + uVar6 & 1));
    local_c = local_c + uVar6 * 2;
    local_8 = local_8 + uVar6;
  }
  return;
}

