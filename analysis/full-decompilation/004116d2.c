
undefined4 * __thiscall FUN_004116d2(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if ((param_2 + 0x15 != *(undefined4 **)(param_1 + 4)) &&
     (iVar1 = ((int)*(undefined4 **)(param_1 + 4) - (int)(param_2 + 0x15)) / 0x54, puVar4 = param_2,
     0 < iVar1)) {
    do {
      puVar3 = puVar4 + 0x15;
      puVar5 = puVar4;
      for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      iVar1 = iVar1 + -1;
      puVar4 = puVar4 + 0x15;
    } while (iVar1 != 0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0x54;
  return param_2;
}

