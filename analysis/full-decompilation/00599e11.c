
uint __thiscall FUN_00599e11(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  uint local_8;
  
  iVar4 = 0;
  piVar1 = (int *)(param_1 + 0x1c);
  local_8 = 0;
  if ((*(int *)(param_1 + 0x20) - *piVar1) / 0xc != 0) {
    do {
      cVar3 = FUN_004317d5(*piVar1 + iVar4,param_2);
      if (cVar3 != '\0') {
        return local_8;
      }
      local_8 = local_8 + 1;
      iVar4 = iVar4 + 0xc;
    } while (local_8 < (uint)((*(int *)(param_1 + 0x20) - *piVar1) / 0xc));
  }
  puVar2 = param_2;
  FUN_0059af9f(param_2);
  param_2 = (undefined4 *)FUN_00598764(*puVar2);
  FUN_0059afcc(&param_2);
  return (*(int *)(param_1 + 0x20) - *piVar1) / 0xc - 1;
}

