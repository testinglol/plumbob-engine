
undefined4 * __thiscall FUN_00576813(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 4);
  uVar4 = FUN_005b8dba(*param_3);
  iVar6 = (uVar4 % (uint)(iVar6 - iVar1 >> 2)) * 4;
  puVar2 = *(undefined4 **)(iVar6 + *(int *)(param_1 + 4));
  puVar5 = puVar2;
  while( true ) {
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)FUN_00576bb5(param_3);
      *puVar5 = puVar2;
      *(undefined4 **)(iVar6 + *(int *)(param_1 + 4)) = puVar5;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      *param_2 = puVar5;
      param_2[1] = param_1;
      *(undefined1 *)(param_2 + 2) = 1;
      return param_2;
    }
    cVar3 = FUN_004317d5(puVar5 + 1,param_3);
    if (cVar3 != '\0') break;
    puVar5 = (undefined4 *)*puVar5;
  }
  *(undefined1 *)(param_2 + 2) = 0;
  *param_2 = puVar5;
  param_2[1] = param_1;
  return param_2;
}

