
undefined4 * __thiscall FUN_004b4015(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  uVar3 = iVar1 - (int)param_3 >> 4;
  if (0 < (int)uVar3) {
    puVar4 = param_3;
    puVar5 = param_2;
    for (iVar2 = (uVar3 & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  *(int *)(param_1 + 4) = iVar1 + ((int)param_3 - (int)param_2 >> 4) * -0x10;
  return param_2;
}

