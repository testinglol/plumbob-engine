
void FUN_0049f7a1(undefined4 *param_1,undefined4 *param_2,ushort *param_3,int param_4,int param_5,
                 int *param_6)

{
  undefined4 *puVar1;
  ushort *puVar2;
  int iVar3;
  ushort uVar4;
  undefined2 *puVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  undefined2 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  int local_18;
  undefined2 *local_14;
  int local_10;
  undefined4 *local_c;
  undefined2 *local_8;
  
  iVar7 = local_18;
  puVar5 = (undefined2 *)*param_1;
  puVar1 = (undefined4 *)*param_2;
  param_3 = (ushort *)((int)param_3 + 0x10);
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          puVar11 = puVar1;
          puVar9 = puVar5;
          puVar2 = param_3 + 1;
          uVar4 = *param_3;
          uVar8 = uVar4 & 0x1fff;
          uVar10 = uVar4 & 0xe000;
          param_3 = puVar2;
          if ((uVar4 & 0xe000) != 0) break;
          iVar7 = *param_6 + param_5;
          param_6 = param_6 + 1;
          puVar5 = puVar9 + param_1[1];
          puVar1 = (undefined4 *)((int)puVar11 + param_2[1] * 2);
          local_18 = iVar7;
          local_c = puVar11;
          local_8 = puVar9;
        }
        puVar5 = puVar9;
        puVar1 = puVar11;
        if (uVar10 != 0x6000) break;
        local_c = (undefined4 *)((int)local_c + uVar8 * 2);
        local_8 = local_8 + uVar8;
      }
      if (uVar10 != 0x8000) break;
      puVar1 = (undefined4 *)((int)puVar11 + param_2[1] * uVar8 * 2);
      puVar5 = puVar9 + param_1[1] * uVar8;
      local_c = (undefined4 *)((int)puVar1 + param_2[1] * -2);
      local_8 = puVar9 + param_1[1] * uVar8 + -param_1[1];
    }
    if (uVar10 != 0xc000) break;
    if ((uVar4 & 0x1fff) != 0) {
      uVar6 = (undefined2)iVar7;
      puVar11 = local_c;
      for (uVar10 = uVar8 >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar11 = CONCAT22(uVar6,uVar6);
        puVar11 = puVar11 + 1;
      }
      for (uVar10 = (uint)((uVar4 & 1) != 0); iVar7 = local_18, uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined2 *)puVar11 = uVar6;
        puVar11 = (undefined4 *)((int)puVar11 + 2);
      }
    }
    local_10 = 0;
    if ((uVar4 & 0x1fff) != 0) {
      local_14 = local_8;
      do {
        iVar3 = local_10 + 1;
        *local_14 = *(undefined2 *)(param_4 + (uint)*(byte *)(local_10 + (int)puVar2) * 2);
        local_14 = local_14 + 1;
        local_10 = iVar3;
      } while (iVar3 < (int)uVar8);
    }
    param_3 = (ushort *)((int)puVar2 + uVar8 + ((int)puVar2 + uVar8 & 1));
    local_c = (undefined4 *)((int)local_c + uVar8 * 2);
    local_8 = local_8 + uVar8;
  }
  return;
}

