
undefined4 * __thiscall FUN_004609a6(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = (iVar1 - (int)param_3) / 0xc;
  if (0 < iVar2) {
    puVar4 = param_3;
    puVar5 = param_2;
    for (uVar3 = iVar2 * 3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  *(int *)(param_1 + 4) = iVar1 + (((int)param_3 - (int)param_2) / 0xc) * -0xc;
  return param_2;
}

