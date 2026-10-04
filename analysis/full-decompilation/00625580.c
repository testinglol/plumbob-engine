
int * FUN_00625580(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = ((param_3 < 9) - 1 & 0x18) + 8;
  iVar6 = (int)(uVar1 * param_1 + ((int)(uVar1 * param_1) >> 0x1f & 7U)) >> 3;
  piVar2 = (int *)FUN_005a9320(0xc);
  *piVar2 = 0;
  piVar2[1] = 0;
  piVar2[2] = 0;
  puVar3 = (undefined4 *)FUN_005a9320(0x2890);
  *piVar2 = (int)puVar3;
  for (iVar4 = 0xa24; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  uVar7 = iVar6 * param_2;
  puVar3 = (undefined4 *)FUN_005a9320(uVar7);
  piVar2[1] = (int)puVar3;
  for (uVar5 = uVar7 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  iVar4 = *piVar2;
  *(undefined4 *)(iVar4 + 4) = 0x2890;
  *(undefined4 *)(iVar4 + 8) = 200;
  *(uint *)(iVar4 + 0x18) = uVar1;
  *(int *)(iVar4 + 0x1c) = param_3;
  *(int *)(iVar4 + 0x10) = param_1;
  *(int *)(iVar4 + 0x14) = param_2;
  uVar5 = uVar1 / 3;
  piVar2[2] = iVar6;
  uVar7 = 8;
  if (uVar5 < 9) {
    uVar7 = uVar5;
  }
  *(uint *)(iVar4 + 0x43c) = uVar7;
  uVar7 = 8;
  if (uVar5 < 9) {
    uVar7 = uVar5;
  }
  *(uint *)(iVar4 + 0x440) = uVar7;
  uVar7 = 8;
  if (uVar5 < 9) {
    uVar7 = uVar5;
  }
  *(uint *)(iVar4 + 0x444) = uVar7;
  if (8 < uVar5) {
    uVar5 = 8;
  }
  *(uint *)(iVar4 + 0x438) = uVar1 + uVar5 * -3;
  return piVar2;
}

