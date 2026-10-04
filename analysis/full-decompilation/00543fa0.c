
undefined4 __fastcall FUN_00543fa0(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((char)param_1[0x48] != '\0') {
    FUN_00473496(DAT_006e5490);
    iVar2 = __ftol();
    iVar4 = param_1[0x41];
    local_c = iVar4;
    local_8 = iVar2;
    iVar3 = __ftol();
    if (iVar4 <= iVar3) {
      iVar2 = iVar2 + 1;
      iVar3 = 0;
    }
    param_1[0x42] = -iVar3;
    param_1[0x40] = iVar2;
    FUN_00544228();
    if (DAT_006e5490 < (uint)param_1[0x47]) {
      (**(code **)(*param_1 + 0x168))();
    }
    else {
      *(undefined1 *)(param_1 + 0x48) = 0;
    }
  }
  if (param_1[0x3b] == 0) goto LAB_00544127;
  if (5 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
    if ((int *)param_1[0x39] == (int *)0x0) goto LAB_00544127;
    cVar1 = (**(code **)(*(int *)param_1[0x39] + 0x8c))(1);
    if (cVar1 != '\0') goto LAB_00544127;
  }
  if ((int *)param_1[0x17] != (int *)0x0) {
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 != '\0') {
      local_28 = param_1[0x1f];
      local_24 = param_1[0x20];
      local_20 = param_1[0x21];
      local_1c = param_1[0x22];
      local_10 = -param_1[0x3c];
      local_c = -param_1[0x3d];
      FUN_004ba5ac(&local_10);
      local_38 = 0;
      local_30 = local_20 - local_28;
      local_2c = local_1c - local_24;
      local_34 = 0;
      FUN_004ba5ac(param_1 + 7);
      (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x3b],&local_28,&local_38,0);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
  }
LAB_00544127:
  iVar4 = param_1[0x3e];
  if ((iVar4 != 0) &&
     (iVar2 = (param_1[0x37] - param_1[0x36] >> 2) - param_1[0x40],
     (uint)((param_1[0x37] - param_1[0x36] >> 2) - param_1[0x40]) < 6)) {
    local_28 = *(int *)(iVar4 + 0x14);
    local_24 = *(int *)(iVar4 + 0x18);
    local_20 = *(int *)(iVar4 + 0x1c);
    local_1c = (*(int *)(iVar4 + 0x20) - local_24) / 3;
    iVar4 = 6 - iVar2;
    local_18 = local_28;
    local_14 = local_24;
    local_10 = local_20;
    local_c = local_1c;
    FUN_004ba5ac(param_1 + 7);
    iVar2 = (local_1c - local_24) * iVar2;
    local_14 = local_14 + iVar2;
    local_c = local_c + iVar2;
    if ((char)param_1[0x48] != '\0') {
      local_14 = local_14 + param_1[0x42];
      local_c = local_c + param_1[0x42];
    }
    if ((int *)param_1[0x17] != (int *)0x0) {
      cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
      if (cVar1 != '\0') {
        if (0 < iVar4) {
          do {
            (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x3e],&local_28,&local_18,0);
            local_14 = local_14 + (local_1c - local_24);
            local_c = local_c + (local_1c - local_24);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
      }
    }
  }
  return 1;
}

