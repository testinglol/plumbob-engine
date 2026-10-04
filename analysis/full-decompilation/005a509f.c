
void __thiscall FUN_005a509f(int param_1,undefined4 *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = FUN_00580d6d(param_3);
  for (puVar3 = *(undefined4 **)(*(int *)(param_1 + 4) + iVar2 * 4); puVar3 != (undefined4 *)0x0;
      puVar3 = (undefined4 *)*puVar3) {
    cVar1 = FUN_004317d5(puVar3 + 1,param_3);
    if (cVar1 != '\0') break;
  }
  param_2[1] = param_1;
  *param_2 = puVar3;
  return;
}

