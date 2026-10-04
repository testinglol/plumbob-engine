
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0051b3db(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
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
  
  if ((*(char *)(param_1 + 0x61) == '\0') && (*(int *)(param_1 + 0xb4) == 0)) {
    return 1;
  }
  FUN_0051eb6f();
  local_8 = FUN_004e99a9();
  cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar2 == '\0') {
    return 1;
  }
  local_50 = *(int *)(param_1 + 0x1c);
  piVar6 = (int *)(param_1 + 0x1c);
  local_48 = *(undefined4 *)(param_1 + 0x24);
  local_44 = *(int *)(param_1 + 0x28);
  local_4c = *(int *)(param_1 + 0x20) + 0x32;
  local_34 = local_44 + -0x32 + -*(int *)(param_1 + 0x20);
  local_3c = *(int *)(param_1 + 0x20) + -*(int *)(param_1 + 0x20);
  local_38 = *(int *)(param_1 + 0x24) - local_50;
  local_40 = 0;
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
            (*(undefined4 *)(param_1 + 0xd4),&local_40,&local_50,0);
  uVar8 = 0;
  puVar7 = &DAT_006f3a70;
  iVar4 = **(int **)(param_1 + 0x5c);
  piVar5 = &local_30;
  local_c = *(int *)(param_1 + 0x2ec) + 0x14;
  FUN_004df599(&local_20,piVar6);
  uVar3 = FUN_004df599(piVar5,puVar7);
  (**(code **)(iVar4 + 0x9c))(*(undefined4 *)(param_1 + 0x2ec),local_c,uVar3,uVar8);
  if (local_8 == -1) {
    local_8 = 0;
  }
  else {
    FUN_004ea7e2(local_8);
    local_8 = __ftol();
  }
  if (_DAT_0066657c <= ((float)local_8 + _DAT_0066674c) * _DAT_0066c7b4 - _DAT_00667678) {
    iVar4 = __ftol();
    if (5 < iVar4) {
      iVar4 = 5;
    }
  }
  else {
    iVar4 = __ftol();
    if (iVar4 < -5) {
      iVar4 = -5;
    }
  }
  iVar1 = *(int *)(param_1 + 0x178);
  if ((iVar1 == 0) || (-1 < iVar4)) {
    iVar1 = *(int *)(param_1 + 0x17c);
    if ((iVar1 == 0) || (iVar4 < 1)) {
      local_30 = *(int *)(iVar1 + 0x14);
      local_2c = *(undefined4 *)(iVar1 + 0x18);
      local_28 = *(undefined4 *)(iVar1 + 0x1c);
      local_24 = *(int *)(iVar1 + 0x20);
      local_10 = *piVar6 + _DAT_006f3a88;
      local_c = *(int *)(param_1 + 0x20) + _DAT_006f3a8c;
      local_20 = local_30;
      local_1c = local_2c;
      local_18 = local_28;
      local_14 = local_24;
      FUN_004ba5ac(&local_10);
      local_2c = local_24 + -2;
      local_1c = local_14 + -2;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(undefined4 *)(param_1 + 0x17c),&local_30,&local_20,0);
      iVar4 = *(int *)(param_1 + 0x178);
      local_30 = *(int *)(iVar4 + 0x14);
      local_2c = *(int *)(iVar4 + 0x18);
      local_28 = *(int *)(iVar4 + 0x1c);
      local_24 = *(undefined4 *)(iVar4 + 0x20);
      local_10 = DAT_006f3a90 + *piVar6;
      local_c = *(int *)(param_1 + 0x20) + _DAT_006f3a94;
      local_20 = local_30;
      local_1c = local_2c;
      local_18 = local_28;
      local_14 = local_24;
      FUN_004ba5ac(&local_10);
      local_24 = local_2c + 2;
      piVar6 = &local_20;
      local_14 = local_1c + 2;
      iVar4 = **(int **)(param_1 + 0x5c);
      piVar5 = &local_30;
      goto LAB_0051b70e;
    }
    local_30 = *(int *)(iVar1 + 0x14);
    local_2c = *(int *)(iVar1 + 0x18);
    local_28 = *(int *)(iVar1 + 0x1c);
    local_24 = *(int *)(iVar1 + 0x20);
    iVar4 = (local_24 + iVar4 * -5) - local_2c;
    local_20 = local_30;
    local_1c = local_2c;
    local_18 = local_28;
    local_14 = local_24;
    FUN_004ba5ac(&DAT_006f3a88);
    local_2c = local_2c + iVar4;
    local_1c = local_1c + iVar4;
    FUN_004ba5ac(piVar6);
    piVar6 = &local_30;
    iVar4 = **(int **)(param_1 + 0x5c);
    piVar5 = &local_20;
    uVar3 = *(undefined4 *)(param_1 + 0x17c);
  }
  else {
    local_20 = *(int *)(iVar1 + 0x14);
    local_1c = *(int *)(iVar1 + 0x18);
    local_18 = *(int *)(iVar1 + 0x1c);
    local_14 = local_1c + iVar4 * -5;
    if ((local_18 <= local_20) || (local_14 <= local_1c)) goto LAB_0051b71b;
    local_30 = local_20;
    local_2c = local_1c;
    local_28 = local_18;
    local_24 = local_14;
    FUN_004ba5ac(&DAT_006f3a90);
    FUN_004ba5ac(piVar6);
    piVar6 = &local_30;
    iVar4 = **(int **)(param_1 + 0x5c);
    piVar5 = &local_20;
LAB_0051b70e:
    uVar3 = *(undefined4 *)(param_1 + 0x178);
  }
  (**(code **)(iVar4 + 0x9c))(uVar3,piVar5,piVar6,0);
LAB_0051b71b:
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  return 1;
}

