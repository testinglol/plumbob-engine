
undefined4 * __thiscall FUN_005bb337(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = FUN_00580d6d(param_3);
  puVar1 = *(undefined4 **)(iVar3 * 4 + *(int *)(param_1 + 4));
  puVar4 = puVar1;
  while( true ) {
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)FUN_005bbd6c(param_3);
      *puVar4 = puVar1;
      *(undefined4 **)(iVar3 * 4 + *(int *)(param_1 + 4)) = puVar4;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      *param_2 = puVar4;
      param_2[1] = param_1;
      *(undefined1 *)(param_2 + 2) = 1;
      return param_2;
    }
    cVar2 = FUN_004317d5(puVar4 + 1,param_3);
    if (cVar2 != '\0') break;
    puVar4 = (undefined4 *)*puVar4;
  }
  *(undefined1 *)(param_2 + 2) = 0;
  *param_2 = puVar4;
  param_2[1] = param_1;
  return param_2;
}

