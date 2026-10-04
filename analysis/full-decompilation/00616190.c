
byte * FUN_00616190(int *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  int iVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  
  puVar12 = param_2;
  for (iVar6 = 0x300; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  iVar6 = *param_1;
  iVar3 = *(int *)(iVar6 + 0x24);
  iVar10 = 0;
  if (0 < iVar3) {
    puVar4 = (undefined1 *)((int)param_2 + 1);
    puVar7 = (undefined1 *)(iVar6 + 0x2a);
    do {
      uVar1 = puVar7[1];
      *(int *)(puVar4 + 3) = iVar10;
      puVar4[-1] = uVar1;
      *puVar4 = *puVar7;
      puVar4[1] = puVar7[-1];
      puVar4[2] = puVar7[-2];
      iVar10 = iVar10 + 1;
      puVar7 = puVar7 + 4;
      puVar4 = puVar4 + 0xc;
    } while (iVar10 < iVar3);
  }
  iVar3 = *(int *)(iVar6 + 0x10);
  iVar6 = *(int *)(iVar6 + 0x14);
  iVar10 = param_1[2];
  pbVar5 = (byte *)param_1[1];
  pbVar11 = pbVar5;
  if (0 < iVar6) {
    do {
      pbVar8 = pbVar11;
      iVar9 = iVar3;
      if (0 < iVar3) {
        do {
          bVar2 = *pbVar8;
          param_2[(uint)bVar2 * 3 + 2] = param_2[(uint)bVar2 * 3 + 2] + 1;
          iVar9 = iVar9 + -1;
          pbVar5 = (byte *)(param_2 + (uint)bVar2 * 3 + 2);
          pbVar8 = pbVar8 + 1;
        } while (iVar9 != 0);
      }
      iVar6 = iVar6 + -1;
      pbVar11 = pbVar11 + iVar10;
    } while (iVar6 != 0);
  }
  return pbVar5;
}

