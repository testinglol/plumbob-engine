
int __thiscall FUN_005bb421(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *local_c;
  int local_8;
  
  iVar4 = FUN_00580d6d(param_2);
  local_8 = 0;
  puVar1 = *(undefined4 **)(iVar4 * 4 + *(int *)(param_1 + 4));
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    local_c = puVar1;
    while (puVar5 = puVar2, puVar5 != (undefined4 *)0x0) {
      cVar3 = FUN_004317d5(puVar5 + 1,param_2);
      if (cVar3 == '\0') {
        puVar2 = (undefined4 *)*puVar5;
        local_c = puVar5;
      }
      else {
        *local_c = *puVar5;
        FUN_005bbdc8(puVar5);
        local_8 = local_8 + 1;
        puVar2 = (undefined4 *)*local_c;
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
      }
    }
    cVar3 = FUN_004317d5(puVar1 + 1,param_2);
    if (cVar3 != '\0') {
      *(undefined4 *)(iVar4 * 4 + *(int *)(param_1 + 4)) = *puVar1;
      FUN_005bbdc8(puVar1);
      local_8 = local_8 + 1;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    }
  }
  return local_8;
}

