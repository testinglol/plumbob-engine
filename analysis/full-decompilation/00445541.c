
int __fastcall FUN_00445541(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  if (DAT_006e4f14 == 0) {
    iVar2 = FUN_00445724();
    piVar3 = (int *)(*(int *)(*DAT_006e486c + 0x10) + 300);
    iVar4 = *(int *)(*(int *)(*DAT_006e486c + 0x10) + 0x130) - *piVar3 >> 2;
    if (iVar2 == 0) {
      local_10 = -1;
    }
    else {
      local_10 = 0;
      while ((local_10 < iVar4 &&
             (iVar5 = FUN_0044097d(*(undefined4 *)(*piVar3 + local_10 * 4)), iVar5 != iVar2))) {
        local_10 = local_10 + 1;
      }
    }
    local_14 = local_10;
    if (local_10 == iVar4) {
      local_8 = 0;
    }
    else {
      do {
        local_14 = local_14 + 1;
        if (local_10 + 1 + iVar4 <= local_14) {
          return 0;
        }
        local_8 = FUN_0044097d(*(undefined4 *)(*piVar3 + (local_14 % iVar4) * 4));
      } while (local_8 == 0);
      FUN_00445489(local_8);
    }
  }
  else {
    local_8 = 0;
    for (local_c = *(int **)(param_1 + 0x84); local_c != (int *)*(int *)(param_1 + 0x88);
        local_c = (int *)((int)local_c + 4)) {
      cVar1 = FUN_0045e67a();
      if (cVar1 != '\0') {
        local_c = (int *)((int)local_c + 4);
        if (local_c == *(int **)(param_1 + 0x88)) {
          local_c = *(int **)(param_1 + 0x84);
        }
        local_8 = *local_c;
        break;
      }
    }
    if ((local_8 == 0) && (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x84) >> 2 != 0)) {
      local_8 = **(int **)(param_1 + 0x84);
    }
    FUN_00445489(local_8);
  }
  return local_8;
}

