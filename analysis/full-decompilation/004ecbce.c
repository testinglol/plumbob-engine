
undefined4 __fastcall FUN_004ecbce(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((*(int *)(param_1 + 0xfc) != 0) &&
      ((uint)(*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) < 4)) &&
     (*(int **)(param_1 + 0x5c) != (int *)0x0)) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar1 != '\0') {
      local_14 = *(int *)(param_1 + 0x7c);
      local_c = *(int *)(param_1 + 0x84);
      local_10 = *(int *)(param_1 + 0x80);
      local_8 = *(int *)(param_1 + 0x88);
      local_24 = 3;
      local_18 = (local_8 - local_10) + 10;
      local_1c = (local_c - local_14) + 3;
      local_20 = 10;
      FUN_004ba5ac(param_1 + 0x1c);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(undefined4 *)(param_1 + 0xfc),&local_14,&local_24,0);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  iVar3 = *(int *)(param_1 + 0x108);
  if ((iVar3 != 0) &&
     (iVar2 = (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) - *(int *)(param_1 + 0x110)
     , (uint)((*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) - *(int *)(param_1 + 0x110)
             ) < 4)) {
    local_24 = *(int *)(iVar3 + 0x14);
    local_20 = *(int *)(iVar3 + 0x18);
    local_1c = *(undefined4 *)(iVar3 + 0x1c);
    local_18 = (*(int *)(iVar3 + 0x20) - local_20) / 3;
    iVar3 = 4 - iVar2;
    local_14 = local_24;
    local_10 = local_20;
    local_c = local_1c;
    local_8 = local_18;
    FUN_004ba5ac(param_1 + 0x1c);
    iVar2 = (local_18 - local_20) * iVar2;
    local_10 = local_10 + iVar2;
    local_8 = local_8 + iVar2;
    if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
      cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
      if (cVar1 != '\0') {
        if (0 < iVar3) {
          do {
            (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                      (*(undefined4 *)(param_1 + 0x108),&local_24,&local_14,0);
            local_10 = local_10 + (local_18 - local_20);
            local_8 = local_8 + (local_18 - local_20);
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
      }
    }
  }
  return 1;
}

