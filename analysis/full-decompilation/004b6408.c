
void FUN_004b6408(int *param_1,undefined4 *param_2,ushort *param_3)

{
  int iVar1;
  ushort *puVar2;
  ushort uVar3;
  ushort *puVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  int in_stack_00000020;
  int *in_stack_00000024;
  int local_38;
  uint local_24;
  ushort *local_14;
  int local_c;
  ushort *local_8;
  
  iVar1 = *param_1;
  puVar4 = (ushort *)*param_2;
  param_3 = (ushort *)((int)param_3 + 0x10);
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          puVar9 = puVar4;
          iVar8 = iVar1;
          puVar2 = param_3 + 1;
          uVar3 = *param_3;
          uVar6 = uVar3 & 0x1fff;
          uVar7 = uVar3 & 0xe000;
          param_3 = puVar2;
          if ((uVar3 & 0xe000) != 0) break;
          local_38 = *in_stack_00000024 + in_stack_00000020;
          in_stack_00000024 = in_stack_00000024 + 1;
          iVar1 = iVar8 + param_1[1] * 2;
          puVar4 = puVar9 + param_2[1];
          local_c = iVar8;
          local_8 = puVar9;
        }
        iVar1 = iVar8;
        puVar4 = puVar9;
        if (uVar7 != 0x6000) break;
        local_c = local_c + uVar6 * 2;
        local_8 = local_8 + uVar6;
      }
      if (uVar7 != 0x8000) break;
      iVar1 = iVar8 + param_1[1] * uVar6 * 2;
      puVar4 = puVar9 + param_2[1] * uVar6;
      local_c = iVar1 + param_1[1] * -2;
      local_8 = puVar9 + param_2[1] * uVar6 + -param_2[1];
    }
    if (uVar7 != 0xc000) break;
    if ((uVar3 & 0x1fff) != 0) {
      local_14 = local_8;
      local_24 = uVar6;
      do {
        if (local_38 <= (int)(uint)*local_14) {
          *local_14 = (ushort)local_38;
          uVar5 = FUN_00438f12();
          *(undefined2 *)((local_c - (int)local_8) + (int)local_14) = uVar5;
        }
        local_14 = local_14 + 1;
        local_24 = local_24 - 1;
      } while (local_24 != 0);
    }
    param_3 = (ushort *)((int)puVar2 + uVar6 + ((int)puVar2 + uVar6 & 1));
    local_c = local_c + uVar6 * 2;
    local_8 = local_8 + uVar6;
  }
  return;
}

