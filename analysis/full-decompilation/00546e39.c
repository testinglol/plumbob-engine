
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00546e39(int param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  piVar1 = (int *)(param_1 + 0x10c);
  if ((0 < *(int *)(param_1 + 0x10c)) || (0 < *(int *)(param_1 + 0x110))) {
    local_3c = *(undefined4 *)(param_1 + 0x7c);
    local_38 = *(undefined4 *)(param_1 + 0x80);
    local_34 = *(undefined4 *)(param_1 + 0x84);
    local_30 = *(undefined4 *)(param_1 + 0x88);
    FUN_004df599(&local_4c,piVar1);
    FUN_0055ffd5(*(undefined4 *)(param_1 + 0x5c),&local_3c,&local_4c,DAT_006f2a68);
  }
  if ((*(int **)(param_1 + 0x5c) != (int *)0x0) &&
     (cVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10), cVar3 != '\0')) {
    iVar2 = *(int *)(param_1 + 0x108);
    local_4c = *(undefined4 *)(iVar2 + 0x14);
    local_48 = *(undefined4 *)(iVar2 + 0x18);
    local_44 = *(undefined4 *)(iVar2 + 0x1c);
    local_40 = *(undefined4 *)(iVar2 + 0x20);
    local_c = *(int *)(param_1 + 0x1c) + *piVar1;
    local_8 = *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x110);
    local_3c = local_4c;
    local_38 = local_48;
    local_34 = local_44;
    local_30 = local_40;
    FUN_004ba5ac(&local_c);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
              (*(undefined4 *)(param_1 + 0x108),&local_4c,&local_3c,0);
    iVar2 = *(int *)(param_1 + 0x188);
    if (iVar2 != 0) {
      local_2c = *(int *)(iVar2 + 0x14);
      local_28 = *(undefined4 *)(iVar2 + 0x18);
      local_24 = *(undefined4 *)(iVar2 + 0x1c);
      local_20 = *(undefined4 *)(iVar2 + 0x20);
      local_c = *piVar1 + _DAT_006f4fb8;
      local_8 = *(int *)(param_1 + 0x110) + _DAT_006f4fbc;
      local_1c = local_2c;
      local_18 = local_28;
      local_14 = local_24;
      local_10 = local_20;
      FUN_004ba5ac(&local_c);
      iVar2 = *(int *)(param_1 + 0x188);
      iVar4 = *(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x14);
      local_14 = *(int *)(param_1 + 0x124) * 6;
      if (local_14 - iVar4 != 0 && iVar4 <= local_14) {
        local_14 = *(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x14);
      }
      local_24 = local_2c + local_14;
      local_14 = local_14 + local_1c;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(iVar2,&local_2c,&local_1c,0);
    }
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    return 1;
  }
  return 0;
}

