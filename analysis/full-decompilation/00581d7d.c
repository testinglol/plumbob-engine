
undefined4 * __thiscall FUN_00581d7d(int param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_005828cf(*(int *)(param_1 + 0x10) + 1);
  iVar3 = (*param_2 % (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2)) * 4;
  puVar1 = *(undefined4 **)(iVar3 + *(int *)(param_1 + 4));
  for (puVar2 = puVar1; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if (puVar2[1] == *param_2) goto LAB_00581dd2;
  }
  puVar2 = (undefined4 *)FUN_005825c5(param_2);
  *puVar2 = puVar1;
  *(undefined4 **)(iVar3 + *(int *)(param_1 + 4)) = puVar2;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
LAB_00581dd2:
  return puVar2 + 1;
}

