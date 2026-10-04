
undefined4 __thiscall FUN_005d0eb4(uint param_1,undefined4 *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint local_c;
  uint local_8;
  
  local_c = param_1;
  local_8 = param_1;
  if (param_2 == (undefined4 *)0x0) {
    if (*(char *)(param_1 + 0xc0) == '\0') goto LAB_005d0f41;
    FUN_005c6150();
    *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_1 + 0xa8);
    *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_1 + 0xac);
    *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0xb0);
    *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0xb4);
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0xb8);
    *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_1 + 0xbc);
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  }
  else {
    *(undefined4 *)(param_1 + 0xf8) = *param_2;
    *(undefined4 *)(param_1 + 0xfc) = param_2[1];
    *(undefined4 *)(param_1 + 0x100) = param_2[2];
    FUN_00462be8(param_2 + 3);
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
    *(undefined1 *)(param_1 + 0xc0) = 0;
  }
  *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfffffffb;
LAB_005d0f41:
  *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfffffffe;
  uVar2 = 0;
  uVar4 = 0xffffffff;
  param_2 = (undefined4 *)0x0;
  local_c = 0xffffffff;
  local_8 = 0;
  if (*(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0xec) >> 2 != 0) {
    puVar5 = *(uint **)(param_1 + 0xe0);
    puVar1 = puVar5 + 1;
    do {
      puVar3 = puVar5;
      if (uVar4 <= *puVar5) {
        puVar3 = &local_c;
      }
      uVar4 = *puVar3;
      local_c = uVar4;
      puVar3 = puVar1;
      if (*puVar1 <= uVar2) {
        puVar3 = &local_8;
      }
      param_2 = (undefined4 *)((int)param_2 + 1);
      uVar2 = *puVar3;
      puVar5 = puVar5 + 2;
      puVar1 = puVar1 + 2;
      local_8 = uVar2;
    } while (param_2 < (uint)(*(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0xec) >> 2));
  }
  return 1;
}

