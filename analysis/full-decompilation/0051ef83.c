
void __thiscall FUN_0051ef83(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  if (*(int *)(param_1 + 300) - *(int *)(param_1 + 0x128) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x128) + (int)local_8 * 4);
      if (DAT_006d74f0 == 0) {
        *(undefined4 *)(iVar1 + 0x154) = 0;
      }
      else {
        *(int *)(iVar1 + 0x158) = DAT_006d74f0;
        *(uint *)(iVar1 + 0x154) = (uint)((char)param_2 != '\0');
      }
      local_8 = (int *)((int)local_8 + 1);
      *(undefined1 *)(iVar1 + 0x16c) = 0;
    } while (local_8 < (uint)(*(int *)(param_1 + 300) - *(int *)(param_1 + 0x128) >> 2));
  }
  local_8 = (int *)0x0;
  if (*(int *)(param_1 + 0x138) - *(int *)(param_1 + 0x134) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x134) + (int)local_8 * 4);
      if (DAT_006d74f0 == 0) {
        *(undefined4 *)(iVar1 + 0x154) = 0;
      }
      else {
        *(int *)(iVar1 + 0x158) = DAT_006d74f0;
        *(uint *)(iVar1 + 0x154) = (uint)((char)param_2 != '\0');
      }
      local_8 = (int *)((int)local_8 + 1);
      *(undefined1 *)(iVar1 + 0x16c) = 0;
    } while (local_8 < (uint)(*(int *)(param_1 + 0x138) - *(int *)(param_1 + 0x134) >> 2));
  }
  local_8 = (int *)0x0;
  if (*(int *)(param_1 + 0x144) - *(int *)(param_1 + 0x140) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x140) + (int)local_8 * 4);
      if (DAT_006d74f0 == 0) {
        *(undefined4 *)(iVar1 + 0x154) = 0;
      }
      else {
        *(int *)(iVar1 + 0x158) = DAT_006d74f0;
        *(uint *)(iVar1 + 0x154) = (uint)((char)param_2 != '\0');
      }
      local_8 = (int *)((int)local_8 + 1);
      *(undefined1 *)(iVar1 + 0x16c) = 0;
    } while (local_8 < (uint)(*(int *)(param_1 + 0x144) - *(int *)(param_1 + 0x140) >> 2));
  }
  local_8 = (int *)0x0;
  if (*(int *)(param_1 + 0x150) - *(int *)(param_1 + 0x14c) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x14c) + (int)local_8 * 4);
      if (DAT_006d74f0 == 0) {
        *(undefined4 *)(iVar1 + 0x154) = 0;
      }
      else {
        *(int *)(iVar1 + 0x158) = DAT_006d74f0;
        *(uint *)(iVar1 + 0x154) = (uint)((char)param_2 != '\0');
      }
      local_8 = (int *)((int)local_8 + 1);
      *(undefined1 *)(iVar1 + 0x16c) = 0;
    } while (local_8 < (uint)(*(int *)(param_1 + 0x150) - *(int *)(param_1 + 0x14c) >> 2));
  }
  uVar3 = 0;
  if (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2 != 0) {
    do {
      iVar2 = DAT_006d74f0;
      iVar1 = *(int *)(*(int *)(param_1 + 0xf0) + uVar3 * 4);
      if (DAT_006d74f0 == 0) {
        *(undefined4 *)(iVar1 + 0x154) = 0;
      }
      else {
        *(undefined4 *)(iVar1 + 0x154) = 2;
        *(int *)(iVar1 + 0x158) = iVar2;
      }
      *(undefined1 *)(iVar1 + 0x16c) = 0;
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2));
  }
  local_8 = (int *)(param_1 + 0x35c);
  local_c = 0x13;
  do {
    iVar1 = *local_8;
    if (DAT_006d74f0 == 0) {
      *(undefined4 *)(iVar1 + 0x154) = 0;
    }
    else {
      *(int *)(iVar1 + 0x158) = DAT_006d74f0;
      *(uint *)(iVar1 + 0x154) = (uint)((char)param_2 != '\0');
    }
    local_8 = local_8 + 1;
    local_c = local_c + -1;
    *(undefined1 *)(iVar1 + 0x16c) = 0;
  } while (local_c != 0);
  iVar1 = *(int *)(param_1 + 0x1c4);
  if (DAT_006d74f0 == 0) {
    *(undefined4 *)(iVar1 + 0x154) = 0;
  }
  else {
    *(int *)(iVar1 + 0x158) = DAT_006d74f0;
    *(uint *)(iVar1 + 0x154) = (uint)((char)param_2 != '\0');
  }
  *(undefined1 *)(iVar1 + 0x16c) = 0;
  if (*(int *)(param_1 + 0x110) != 0) {
    FUN_0053128b(param_2);
  }
  if (*(int *)(param_1 + 0x114) != 0) {
    FUN_00531f19(param_2);
  }
  if (*(int *)(param_1 + 0x118) != 0) {
    FUN_00531f19(param_2);
  }
  if (*(int *)(param_1 + 0x120) != 0) {
    FUN_00531f19(param_2);
  }
  if (*(int *)(param_1 + 0x124) != 0) {
    FUN_00533028(param_2);
  }
  if (*(int *)(param_1 + 0x11c) != 0) {
    FUN_0052d3f4(param_2);
  }
  return;
}

