
undefined4 __fastcall FUN_005f5e36(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  int *piVar3;
  int iVar4;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar1 == '\0') {
    return 1;
  }
  local_14 = *(int *)(param_1 + 0x10c);
  local_10 = *(int *)(param_1 + 0x110);
  local_c = *(int *)(param_1 + 0x114);
  local_8 = *(int *)(param_1 + 0x118);
  FUN_004df599(&local_24,param_1 + 0x1c);
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
            (*(undefined4 *)(param_1 + 0x108),&local_14,&local_24,0);
  if (*(int *)(param_1 + 0xd4) == 1) {
    iVar4 = *(int *)(param_1 + 0x114) - *(int *)(param_1 + 0x10c);
    local_14 = local_14 + iVar4;
    local_c = local_c + iVar4;
    local_24 = local_24 + iVar4;
    local_1c = *(int *)(param_1 + 0x24) - iVar4;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0xbc))
              (*(undefined4 *)(param_1 + 0x108),&local_14,&local_24,0,0);
    local_14 = local_14 + iVar4;
    local_c = local_c + iVar4;
    local_24 = local_1c;
    local_1c = *(int *)(param_1 + 0x24);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
              (*(undefined4 *)(param_1 + 0x108),&local_14,&local_24,0);
    local_14 = local_14 + iVar4;
    local_c = local_c + iVar4;
    puVar2 = local_44;
  }
  else {
    if (*(int *)(param_1 + 0xd4) != 2) goto LAB_005f5fd7;
    iVar4 = *(int *)(param_1 + 0x118) - *(int *)(param_1 + 0x110);
    local_10 = local_10 + iVar4;
    local_8 = local_8 + iVar4;
    local_20 = local_18;
    local_18 = *(int *)(param_1 + 0x28) - iVar4;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0xbc))
              (*(undefined4 *)(param_1 + 0x108),&local_14,&local_24,0,0);
    local_10 = local_10 + iVar4;
    local_8 = local_8 + iVar4;
    local_20 = local_18;
    local_18 = *(int *)(param_1 + 0x28);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
              (*(undefined4 *)(param_1 + 0x108),&local_14,&local_24,0);
    local_10 = local_10 + iVar4;
    local_8 = local_8 + iVar4;
    puVar2 = local_34;
  }
  piVar3 = (int *)FUN_004df599(puVar2,param_1 + 0x1c);
  local_24 = *piVar3;
  local_20 = piVar3[1];
  local_1c = piVar3[2];
  local_18 = piVar3[3];
  FUN_004ba5ac(param_1 + 0xf4);
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
            (*(undefined4 *)(param_1 + 0x108),&local_14,&local_24,0);
LAB_005f5fd7:
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  return 1;
}

