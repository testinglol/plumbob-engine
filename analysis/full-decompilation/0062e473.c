
void __thiscall FUN_0062e473(int param_1,int param_2,int param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  int local_8;
  
  iVar2 = param_2 * 0xa0 + param_3 * 0x48;
  iVar1 = iVar2 + param_1;
  local_8 = *(int *)(iVar2 + 0x34e4 + param_1) + param_5;
  if ((*(int *)(iVar1 + 0x34f4) == 0) || (*(int *)(iVar1 + 0x34f8) != 2)) {
    iVar2 = (uint)*(byte *)(param_1 + 0x4a0f) * 0x25;
    local_18 = (uint)*(short *)(&DAT_0067d77a + (*(int *)(iVar1 + 0x3518) + iVar2) * 2);
    local_1c = (uint)*(short *)(&DAT_0067d77c +
                               (*(int *)(iVar1 + 0x351c) + *(int *)(iVar1 + 0x3518) + iVar2) * 2);
  }
  else {
    local_18 = 0x24;
    local_1c = 0x240;
  }
  param_5 = 0;
  local_c = 0;
  if ((*(uint *)(iVar1 + 0x34e8) & 0x7fffffff) != 0) {
    local_20 = param_4;
    do {
      if (local_c < local_18) {
        iVar2 = *(int *)(iVar1 + 0x3500);
      }
      else if (local_c < local_1c) {
        iVar2 = *(int *)(iVar1 + 0x3504);
      }
      else {
        iVar2 = *(int *)(iVar1 + 0x3508);
      }
      FUN_0062c23c(&DAT_0067d1f0 + iVar2 * 0x28,&local_10,&local_14,&local_24,&local_28);
      local_c = local_c + 2;
      *local_20 = local_10;
      param_5 = param_5 + 2;
      local_20[1] = local_14;
      local_20 = local_20 + 2;
    } while (local_c < (uint)(*(int *)(iVar1 + 0x34e8) << 1));
  }
  iVar2 = *(int *)(param_2 * 0xa0 + (param_3 * 9 + 0x6a5) * 8 + param_1);
  iVar1 = FUN_0062cc3d();
  if (iVar1 < local_8) {
    puVar3 = param_4 + param_5;
    do {
      if (0x23f < param_5) break;
      FUN_0062c23c(&DAT_0067d6f0 + iVar2 * 0x28,&local_10,&local_14,&local_24,&local_28);
      *puVar3 = local_24;
      puVar3[1] = local_28;
      puVar3[2] = local_10;
      param_5 = param_5 + 4;
      puVar3[3] = local_14;
      puVar3 = puVar3 + 4;
      iVar1 = FUN_0062cc3d();
    } while (iVar1 < local_8);
  }
  if (local_8 < iVar1) {
    FUN_0062cd10(iVar1 - local_8);
    param_5 = param_5 + -4;
  }
  iVar2 = FUN_0062cc3d();
  if (iVar2 < local_8) {
    FUN_0062cc47(local_8 - iVar2);
  }
  if (param_5 < 0x240) {
    *(short *)(param_1 + 0x4a04 + param_2 * 2) = (short)param_5;
    puVar3 = param_4 + param_5;
    for (iVar2 = 0x240 - param_5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x4a04 + param_2 * 2) = 0x240;
  }
  return;
}

