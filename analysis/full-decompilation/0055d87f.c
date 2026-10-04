
void __thiscall FUN_0055d87f(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_44 [16];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24 [3];
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1 + 400);
  if (iVar1 == 0) {
    return;
  }
  local_18 = *(undefined4 *)(iVar1 + 0x20);
  local_c = param_2;
  local_8 = param_3;
  iVar2 = *(int *)(iVar1 + 0x1c) / 3;
  local_24[0] = 0;
  local_24[1] = 0;
  local_24[2] = iVar2;
  local_10 = local_18;
  puVar3 = (undefined4 *)FUN_004df599(local_44,param_1 + 0x140);
  local_34 = *puVar3;
  local_30 = puVar3[1];
  local_2c = puVar3[2];
  local_28 = puVar3[3];
  iVar1 = *(int *)(param_1 + 0x1d8);
  if (iVar1 == 0) {
LAB_0055d91c:
    local_24[0] = 0;
    iVar2 = local_24[2];
  }
  else {
    if (iVar1 != 1) {
      local_24[0] = 0;
      if (iVar1 < 2) goto LAB_0055d921;
      if (iVar1 < 4) {
        local_24[0] = local_24[2] * 2;
        iVar2 = local_24[2] * 3;
        goto LAB_0055d921;
      }
      if (iVar1 != 4) {
        if (iVar1 != 5) goto LAB_0055d921;
        goto LAB_0055d91c;
      }
    }
    iVar2 = local_24[2] * 2;
    local_24[0] = local_24[2];
  }
LAB_0055d921:
  local_24[1] = 0;
  local_18 = local_10;
  local_24[2] = iVar2;
  FUN_004ba5ac(&local_c);
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
            (*(undefined4 *)(param_1 + 400),local_24,&local_34,0);
  return;
}

