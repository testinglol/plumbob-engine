
int __fastcall FUN_005e5c2c(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  iVar4 = 0;
  iVar5 = *(int *)(param_1 + 0xf8);
  if ((iVar5 != 0) &&
     (iVar1 = *(int *)(iVar5 + 0x7c),
     *(int *)(iVar5 + 0x84) != iVar1 && -1 < *(int *)(iVar5 + 0x84) - iVar1)) {
    iVar4 = *(int *)(iVar5 + 0x84) - *(int *)(iVar5 + 0x7c);
  }
  iVar1 = *(int *)(param_1 + 0xfc);
  if ((iVar1 != 0) && (iVar4 < *(int *)(iVar1 + 0x84) - *(int *)(iVar1 + 0x7c))) {
    iVar4 = *(int *)(iVar1 + 0x84) - *(int *)(iVar1 + 0x7c);
  }
  iVar2 = *(int *)(param_1 + 0x100);
  if ((iVar2 != 0) && (iVar4 < *(int *)(iVar2 + 0x84) - *(int *)(iVar2 + 0x7c))) {
    iVar4 = *(int *)(iVar2 + 0x84) - *(int *)(iVar2 + 0x7c);
  }
  uVar3 = *(uint *)(param_1 + 0xe4) & 0xffff;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_8 = (int *)0x0;
  if (uVar3 == 0) {
    local_8 = (int *)0x1;
    local_24 = iVar5;
  }
  else if (uVar3 != 0) {
    if (uVar3 < 3) {
      local_8 = (int *)0x2;
      local_24 = iVar5;
      local_20 = iVar1;
    }
    else if (uVar3 == 3) {
      local_8 = (int *)0x3;
      local_24 = iVar5;
      local_20 = *(int *)(param_1 + 0x100);
      local_1c = iVar1;
    }
  }
  iVar5 = 0x20;
  if (local_8 != (int *)0x0) {
    local_c = (((*(int *)(param_1 + 0x84) - (int)local_8 * iVar4) - *(int *)(param_1 + 0x7c)) +
              -0x20) / ((int)local_8 + 1);
    if (local_c < 0x10) {
      local_c = 0x10;
    }
    if (local_8 != (int *)0x0) {
      local_14 = 0;
      local_10 = local_c;
      local_18 = (int)local_8;
      iVar5 = (local_c + iVar4) * (int)local_8 + 0x20;
      local_8 = &local_24;
      do {
        FUN_004ec186(iVar4);
        FUN_004cb21d(local_10 + 0x10 + local_14,
                     ((*(int *)(*local_8 + 0x80) - *(int *)(*local_8 + 0x88)) -
                     *(int *)(param_1 + 0x80)) + -0x10 + *(int *)(param_1 + 0x88));
        local_14 = local_14 + iVar4;
        local_10 = local_10 + local_c;
        local_8 = local_8 + 1;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    iVar5 = iVar5 + local_c;
  }
  return iVar5;
}

