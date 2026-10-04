
void FUN_0049f661(ushort *param_1,undefined4 *param_2,ushort *param_3,int param_4,int param_5,
                 int *param_6)

{
  int iVar1;
  ushort *puVar2;
  ushort uVar3;
  ushort *puVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  int iVar10;
  int local_18;
  int local_10;
  ushort *local_c;
  int local_8;
  
  iVar1 = *(int *)param_1;
  puVar4 = (ushort *)*param_2;
  puVar9 = param_1;
  iVar10 = local_18;
  param_3 = (ushort *)((int)param_3 + 0x10);
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          puVar6 = puVar4;
          iVar5 = iVar1;
          puVar2 = param_3 + 1;
          uVar3 = *param_3;
          uVar7 = uVar3 & 0x1fff;
          uVar8 = uVar3 & 0xe000;
          param_3 = puVar2;
          if ((uVar3 & 0xe000) != 0) break;
          iVar10 = *param_6 + param_5;
          param_6 = param_6 + 1;
          iVar1 = iVar5 + *(int *)(param_1 + 2) * 2;
          puVar4 = puVar6 + param_2[1];
          puVar9 = puVar6;
          local_18 = iVar10;
          local_8 = iVar5;
        }
        iVar1 = iVar5;
        puVar4 = puVar6;
        if (uVar8 != 0x6000) break;
        puVar9 = puVar9 + uVar7;
        local_8 = local_8 + uVar7 * 2;
      }
      if (uVar8 != 0x8000) break;
      iVar1 = iVar5 + *(int *)(param_1 + 2) * uVar7 * 2;
      puVar4 = puVar6 + param_2[1] * uVar7;
      puVar9 = puVar6 + param_2[1] * uVar7 + -param_2[1];
      local_8 = iVar1 + *(int *)(param_1 + 2) * -2;
    }
    if (uVar8 != 0xc000) break;
    local_10 = 0;
    if ((uVar3 & 0x1fff) != 0) {
      local_c = puVar9;
      do {
        if (iVar10 <= (int)(uint)*local_c) {
          *local_c = (ushort)iVar10;
          *(undefined2 *)((local_8 - (int)puVar9) + (int)local_c) =
               *(undefined2 *)(param_4 + (uint)*(byte *)(local_10 + (int)puVar2) * 2);
          iVar10 = local_18;
        }
        local_10 = local_10 + 1;
        local_c = local_c + 1;
      } while (local_10 < (int)uVar7);
    }
    puVar9 = puVar9 + uVar7;
    param_3 = (ushort *)((int)puVar2 + uVar7 + ((int)puVar2 + uVar7 & 1));
    local_8 = local_8 + uVar7 * 2;
  }
  return;
}

