
undefined4 __fastcall FUN_005f6677(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar1 != '\0') {
    local_18 = *(int *)(param_1 + 0x10c);
    local_14 = *(undefined4 *)(param_1 + 0x110);
    local_10 = *(int *)(param_1 + 0x114);
    local_c = *(undefined4 *)(param_1 + 0x118);
    local_28 = *(int *)(param_1 + 0x10c);
    local_24 = *(undefined4 *)(param_1 + 0x110);
    local_20 = *(int *)(param_1 + 0x114);
    local_1c = *(int *)(param_1 + 0x118);
    iVar3 = *(int *)(param_1 + 0x114) - *(int *)(param_1 + 0x10c);
    local_8 = local_1c - *(int *)(param_1 + 0x110);
    if (*(int *)(param_1 + 0xd4) == 1) {
      if (*(int *)(param_1 + 0x150) == 1) {
        local_18 = local_18 + iVar3;
        local_10 = local_10 + iVar3;
      }
      FUN_005f71d7(param_1 + 0x1c);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(undefined4 *)(param_1 + 0x108),&local_18,&local_28,0);
      local_14 = *(undefined4 *)(param_1 + 0x110);
      local_c = *(undefined4 *)(param_1 + 0x118);
      local_10 = *(int *)(param_1 + 0x114) + iVar3 * 3;
      local_18 = *(int *)(param_1 + 0x10c) + iVar3 * 3;
      local_28 = local_20;
      local_20 = *(int *)(param_1 + 0x24) - iVar3;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0xbc))
                (*(undefined4 *)(param_1 + 0x108),&local_18,&local_28,0,0);
      local_14 = *(undefined4 *)(param_1 + 0x110);
      local_c = *(undefined4 *)(param_1 + 0x118);
      if (*(int *)(param_1 + 0x150) == 2) {
        local_10 = iVar3 * 5;
      }
      else {
        local_10 = iVar3 * 4;
      }
      local_18 = *(int *)(param_1 + 0x10c) + local_10;
      local_10 = *(int *)(param_1 + 0x114) + local_10;
      local_28 = local_20;
      local_20 = *(undefined4 *)(param_1 + 0x24);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(undefined4 *)(param_1 + 0x108),&local_18,&local_28,0);
      local_18 = *(int *)(param_1 + 0x10c) + iVar3 * 2;
      local_c = *(undefined4 *)(param_1 + 0x118);
      local_28 = *(int *)(param_1 + 0x10c);
      local_14 = *(undefined4 *)(param_1 + 0x110);
      local_24 = *(undefined4 *)(param_1 + 0x110);
      iVar2 = *(int *)(param_1 + 0x20);
      local_20 = *(undefined4 *)(param_1 + 0x114);
      local_10 = *(int *)(param_1 + 0x114) + iVar3 * 2;
      iVar3 = *(int *)(param_1 + 0xf4) + *(int *)(param_1 + 0x1c);
    }
    else {
      if (*(int *)(param_1 + 0x150) == 1) {
        local_18 = local_18 + iVar3;
        local_10 = local_10 + iVar3;
      }
      FUN_005f71d7(param_1 + 0x1c);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(undefined4 *)(param_1 + 0x108),&local_18,&local_28,0);
      local_14 = *(undefined4 *)(param_1 + 0x110);
      local_c = *(undefined4 *)(param_1 + 0x118);
      local_18 = *(int *)(param_1 + 0x10c) + iVar3 * 3;
      local_10 = *(int *)(param_1 + 0x114) + iVar3 * 3;
      local_24 = local_1c;
      local_1c = *(int *)(param_1 + 0x28) - local_8;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0xbc))
                (*(undefined4 *)(param_1 + 0x108),&local_18,&local_28,0,0);
      local_14 = *(undefined4 *)(param_1 + 0x110);
      local_c = *(undefined4 *)(param_1 + 0x118);
      if (*(int *)(param_1 + 0x150) == 2) {
        local_10 = iVar3 * 5;
      }
      else {
        local_10 = iVar3 * 4;
      }
      local_18 = *(int *)(param_1 + 0x10c) + local_10;
      local_10 = *(int *)(param_1 + 0x114) + local_10;
      local_24 = local_1c;
      local_1c = *(undefined4 *)(param_1 + 0x28);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(undefined4 *)(param_1 + 0x108),&local_18,&local_28,0);
      local_18 = *(int *)(param_1 + 0x10c) + iVar3 * 2;
      local_c = *(undefined4 *)(param_1 + 0x118);
      local_28 = *(int *)(param_1 + 0x10c);
      local_14 = *(undefined4 *)(param_1 + 0x110);
      local_24 = *(undefined4 *)(param_1 + 0x110);
      local_20 = *(undefined4 *)(param_1 + 0x114);
      local_10 = *(int *)(param_1 + 0x114) + iVar3 * 2;
      iVar2 = *(int *)(param_1 + 0xf8) + *(int *)(param_1 + 0x20);
      iVar3 = *(int *)(param_1 + 0x1c);
    }
    local_1c = local_c;
    FUN_005df565(iVar3,iVar2);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
              (*(undefined4 *)(param_1 + 0x108),&local_18,&local_28,0);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  return 1;
}

