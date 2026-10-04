
void __thiscall FUN_00575bc0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 4);
  uVar4 = FUN_005b8dba(*param_3);
  for (puVar5 = *(undefined4 **)(*(int *)(param_1 + 4) + (uVar4 % (uint)(iVar1 - iVar2 >> 2)) * 4);
      puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
    cVar3 = FUN_004317d5(puVar5 + 1,param_3);
    if (cVar3 != '\0') break;
  }
  param_2[1] = param_1;
  *param_2 = puVar5;
  return;
}

