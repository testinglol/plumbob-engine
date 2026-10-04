
int __fastcall FUN_00527af9(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0x110) - *(int *)(param_1 + 0x10c) >> 2 != 0) {
    local_8 = 0;
    for (piVar2 = *(int **)(param_1 + 0x118); piVar2 != *(int **)(param_1 + 0x11c);
        piVar2 = piVar2 + 1) {
      iVar3 = *piVar2;
      if (local_8 < *(int *)(iVar3 + 0x84) - *(int *)(iVar3 + 0x7c)) {
        local_8 = *(int *)(iVar3 + 0x84) - *(int *)(iVar3 + 0x7c);
      }
    }
    iVar3 = **(int **)(param_1 + 0x118);
    iVar4 = **(int **)(param_1 + 0x10c);
    if (*(int *)(iVar3 + 0x88) - *(int *)(iVar3 + 0x80) <
        *(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80)) {
      iVar3 = *(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80);
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x88) - *(int *)(iVar3 + 0x80);
    }
    local_14 = (int *)0x0;
    iVar4 = ((((*(int *)(param_1 + 0x84) - *(int *)(iVar4 + 0x84)) - *(int *)(param_1 + 0x7c)) -
             local_8) + -8 + *(int *)(iVar4 + 0x7c)) / 2;
    local_8 = iVar3;
    if (*(int *)(param_1 + 0x110) - *(int *)(param_1 + 0x10c) >> 2 != 0) {
      do {
        piVar2 = local_14;
        FUN_004cb21d(iVar4,(((*(int *)(*(int *)(param_1 + 0xf8) + 0x80) -
                             ((*(int *)(param_1 + 0x110) - *(int *)(param_1 + 0x10c) >> 2) -
                             (int)local_14) * local_8) - *(int *)(*(int *)(param_1 + 0xf8) + 0x88))
                           - *(int *)(param_1 + 0x80)) + -0x20 + *(int *)(param_1 + 0x88));
        piVar1 = local_14;
        iVar3 = *(int *)(*(int *)(param_1 + 0x10c) + (int)piVar2 * 4);
        FUN_004cb21d((*(int *)(iVar3 + 0x84) - *(int *)(iVar3 + 0x7c)) + 8 + iVar4,
                     (((*(int *)(*(int *)(param_1 + 0xf8) + 0x80) -
                       ((*(int *)(param_1 + 0x110) - *(int *)(param_1 + 0x10c) >> 2) - (int)piVar2)
                       * local_8) - *(int *)(*(int *)(param_1 + 0xf8) + 0x88)) -
                     *(int *)(param_1 + 0x80)) + -0x20 + *(int *)(param_1 + 0x88));
        local_14 = (int *)((int)piVar1 + 1);
      } while (local_14 < (uint)(*(int *)(param_1 + 0x110) - *(int *)(param_1 + 0x10c) >> 2));
    }
  }
  local_24 = *(int *)(param_1 + 0xf8);
  iVar3 = 0;
  if ((local_24 != 0) &&
     (iVar4 = *(int *)(local_24 + 0x7c),
     *(int *)(local_24 + 0x84) != iVar4 && -1 < *(int *)(local_24 + 0x84) - iVar4)) {
    iVar3 = *(int *)(local_24 + 0x84) - *(int *)(local_24 + 0x7c);
  }
  local_20 = *(int *)(param_1 + 0xfc);
  if ((local_20 != 0) && (iVar3 < *(int *)(local_20 + 0x84) - *(int *)(local_20 + 0x7c))) {
    iVar3 = *(int *)(local_20 + 0x84) - *(int *)(local_20 + 0x7c);
  }
  local_8 = ((*(int *)(param_1 + 0x84) - (iVar3 * 2 + 0x20)) - *(int *)(param_1 + 0x7c)) / 3;
  if (local_8 < 0x10) {
    local_8 = 0x10;
  }
  local_10 = 0;
  local_14 = &local_24;
  local_18 = 2;
  local_1c = (local_8 + iVar3) * 2 + 0x20;
  local_c = local_8;
  do {
    iVar4 = *local_14;
    FUN_004ec186(iVar3);
    FUN_004cb21d(local_c + 0x10 + local_10,
                 ((*(int *)(iVar4 + 0x80) - *(int *)(iVar4 + 0x88)) - *(int *)(param_1 + 0x80)) +
                 -0x10 + *(int *)(param_1 + 0x88));
    local_10 = local_10 + iVar3;
    local_c = local_c + local_8;
    local_14 = local_14 + 1;
    local_18 = local_18 + -1;
  } while (local_18 != 0);
  return local_1c + local_8;
}

