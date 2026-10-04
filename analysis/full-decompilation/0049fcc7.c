
void FUN_0049fcc7(undefined4 *param_1,int param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  puVar6 = (ushort *)(param_2 + 0x10);
  iVar4 = param_2;
  puVar1 = (undefined4 *)*param_1;
  puVar7 = param_1;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          puVar9 = puVar1;
          uVar2 = *puVar6;
          uVar5 = uVar2 & 0x1fff;
          uVar8 = uVar2 & 0xe000;
          puVar6 = puVar6 + 1;
          if ((uVar2 & 0xe000) != 0) break;
          iVar4 = *param_4 + param_3;
          param_4 = param_4 + 1;
          puVar1 = (undefined4 *)((int)puVar9 + param_1[1] * 2);
          puVar7 = puVar9;
          param_2 = iVar4;
        }
        puVar1 = puVar9;
        if (uVar8 != 0x6000) break;
        puVar7 = (undefined4 *)((int)puVar7 + uVar5 * 2);
      }
      if (uVar8 != 0x8000) break;
      puVar1 = (undefined4 *)((int)puVar9 + param_1[1] * uVar5 * 2);
      puVar7 = (undefined4 *)((int)puVar1 + param_1[1] * -2);
    }
    if (uVar8 != 0xc000) break;
    if ((uVar2 & 0x1fff) != 0) {
      uVar3 = (undefined2)iVar4;
      puVar9 = puVar7;
      for (uVar8 = uVar5 >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar9 = CONCAT22(uVar3,uVar3);
        puVar9 = puVar9 + 1;
      }
      for (uVar8 = (uint)((uVar2 & 1) != 0); iVar4 = param_2, uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined2 *)puVar9 = uVar3;
        puVar9 = (undefined4 *)((int)puVar9 + 2);
      }
    }
    puVar6 = (ushort *)((int)puVar6 + uVar5 + ((int)puVar6 + uVar5 & 1));
    puVar7 = (undefined4 *)((int)puVar7 + uVar5 * 2);
  }
  return;
}

