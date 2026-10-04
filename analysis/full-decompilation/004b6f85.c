
void FUN_004b6f85(undefined4 *param_1,int *param_2,ushort *param_3,undefined2 *param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int *param_8)

{
  int iVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  int local_2c;
  uint local_1c;
  undefined2 *local_14;
  int local_8;
  
  param_3 = (ushort *)((int)param_3 + 0x10);
  puVar6 = (undefined2 *)*param_1;
  iVar1 = *param_2;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          iVar7 = iVar1;
          uVar2 = *param_3;
          uVar4 = uVar2 & 0x1fff;
          uVar5 = uVar2 & 0xe000;
          param_3 = param_3 + 1;
          if ((uVar2 & 0xe000) != 0) break;
          local_2c = *param_8 + param_7;
          param_8 = param_8 + 1;
          param_4 = puVar6;
          puVar6 = puVar6 + param_1[1];
          iVar1 = iVar7 + param_2[1] * 2;
          local_8 = iVar7;
        }
        iVar1 = iVar7;
        if (uVar5 != 0x6000) break;
        param_4 = param_4 + uVar4;
        local_8 = local_8 + uVar4 * 2;
      }
      if (uVar5 != 0x8000) break;
      iVar1 = iVar7 + param_2[1] * uVar4 * 2;
      param_4 = puVar6 + param_1[1] * uVar4 + -param_1[1];
      puVar6 = puVar6 + param_1[1] * uVar4;
      local_8 = iVar1 + param_2[1] * -2;
    }
    if (uVar5 != 0xc000) break;
    if ((uVar2 & 0x1fff) != 0) {
      local_1c = uVar4;
      local_14 = param_4;
      do {
        *(undefined2 *)((local_8 - (int)param_4) + (int)local_14) = (undefined2)local_2c;
        uVar3 = FUN_00438f12();
        local_1c = local_1c - 1;
        *local_14 = uVar3;
        local_14 = local_14 + 1;
      } while (local_1c != 0);
    }
    param_3 = (ushort *)((int)param_3 + uVar4 + ((int)param_3 + uVar4 & 1));
    param_4 = param_4 + uVar4;
    local_8 = local_8 + uVar4 * 2;
  }
  return;
}

