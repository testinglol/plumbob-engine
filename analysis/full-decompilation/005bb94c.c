
undefined4 * __thiscall FUN_005bb94c(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  
  FUN_005bb9b7(*(int *)(param_1 + 0x10) + 1);
  iVar3 = FUN_00580d6d(param_2);
  puVar1 = *(undefined4 **)(iVar3 * 4 + *(int *)(param_1 + 4));
  for (puVar4 = puVar1; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    cVar2 = FUN_004317d5(puVar4 + 1,param_2);
    if (cVar2 != '\0') goto LAB_005bb9ab;
  }
  puVar4 = (undefined4 *)FUN_005bbde3(param_2);
  *puVar4 = puVar1;
  *(undefined4 **)(iVar3 * 4 + *(int *)(param_1 + 4)) = puVar4;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
LAB_005bb9ab:
  return puVar4 + 1;
}

