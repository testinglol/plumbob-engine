
void FUN_006101c0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int local_4;
  
  piVar1 = *(int **)(param_1 + 0x14);
  iVar7 = 0;
  local_4 = 0;
  if (piVar1 != (int *)0x0) {
    if (0 < *(int *)(param_1 + 0x10)) {
      local_4 = *piVar1;
    }
    if (1 < *(int *)(param_1 + 0x10)) {
      iVar7 = piVar1[2];
    }
  }
  puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0xc);
  uVar6 = puVar2[1];
  puVar4 = (undefined4 *)FUN_005a9320(uVar6);
  if (puVar4 != (undefined4 *)0x0) {
    puVar8 = puVar2;
    puVar9 = puVar4;
    for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    uVar3 = puVar2[iVar7 + 10];
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    puVar4[local_4 + 10] = uVar3;
    puVar4[iVar7 + 10] = puVar2[local_4 + 10];
  }
  return;
}

