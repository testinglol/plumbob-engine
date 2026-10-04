
void FUN_004b6def(int *param_1,undefined4 *param_2,int param_3,ushort *param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,int *param_8)

{
  int iVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  int local_2c;
  uint local_1c;
  ushort *local_c;
  
  puVar5 = (ushort *)(param_3 + 0x10);
  iVar1 = *param_1;
  puVar8 = (ushort *)*param_2;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          iVar7 = iVar1;
          uVar2 = *puVar5;
          uVar4 = uVar2 & 0x1fff;
          uVar6 = uVar2 & 0xe000;
          puVar5 = puVar5 + 1;
          if ((uVar2 & 0xe000) != 0) break;
          local_2c = *param_8 + param_7;
          param_8 = param_8 + 1;
          param_4 = puVar8;
          iVar1 = iVar7 + param_1[1] * 2;
          puVar8 = puVar8 + param_2[1];
          param_3 = iVar7;
        }
        iVar1 = iVar7;
        if (uVar6 != 0x6000) break;
        param_3 = param_3 + uVar4 * 2;
        param_4 = param_4 + uVar4;
      }
      if (uVar6 != 0x8000) break;
      iVar1 = iVar7 + param_1[1] * uVar4 * 2;
      puVar8 = puVar8 + param_2[1] * uVar4;
      param_3 = iVar1 + param_1[1] * -2;
      param_4 = puVar8 + -param_2[1];
    }
    if (uVar6 != 0xc000) break;
    if ((uVar2 & 0x1fff) != 0) {
      local_1c = uVar4;
      local_c = param_4;
      do {
        if (local_2c <= (int)(uint)*local_c) {
          *local_c = (ushort)local_2c;
          uVar3 = FUN_00438f12();
          *(undefined2 *)((param_3 - (int)param_4) + (int)local_c) = uVar3;
        }
        local_c = local_c + 1;
        local_1c = local_1c - 1;
      } while (local_1c != 0);
    }
    puVar5 = (ushort *)((int)puVar5 + uVar4 + ((int)puVar5 + uVar4 & 1));
    param_4 = param_4 + uVar4;
    param_3 = param_3 + uVar4 * 2;
  }
  return;
}

