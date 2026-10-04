
undefined4 * __thiscall FUN_00581ac3(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  
  FUN_00582711(*(int *)(param_1 + 0x10) + 1);
  iVar3 = FUN_00580d6d(param_2);
  puVar1 = *(undefined4 **)(iVar3 * 4 + *(int *)(param_1 + 4));
  for (puVar4 = puVar1; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    cVar2 = FUN_004317d5(puVar4 + 1,param_2);
    if (cVar2 != '\0') goto LAB_00581b22;
  }
  puVar4 = (undefined4 *)FUN_00582554(param_2);
  *puVar4 = puVar1;
  *(undefined4 **)(iVar3 * 4 + *(int *)(param_1 + 4)) = puVar4;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
LAB_00581b22:
  return puVar4 + 1;
}

