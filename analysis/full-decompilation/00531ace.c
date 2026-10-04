
undefined4 __fastcall FUN_00531ace(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined1 local_5c [16];
  undefined1 local_4c [16];
  int local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  local_14 = FUN_004e99a9();
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar1 != '\0') {
    if ((*(int *)(param_1 + 0xd4) != 0) && (local_14 != -1)) {
      local_c = &DAT_006f4438;
      local_10 = &DAT_0066e360;
      do {
        iVar4 = *local_10;
        iVar2 = FUN_004ea79e(local_14);
        local_8 = (int)*(short *)(iVar2 + iVar4 * 2) / 100;
        if (local_8 < 0xb) {
          if (local_8 < 0) {
            local_8 = 0;
          }
        }
        else {
          local_8 = 10;
        }
        iVar4 = *(int *)(param_1 + 0xd8);
        uVar7 = 0;
        iVar2 = **(int **)(param_1 + 0x5c);
        puVar5 = local_4c;
        piVar6 = local_c;
        FUN_004df599(local_5c,param_1 + 0x1c);
        uVar3 = FUN_004df599(puVar5,piVar6);
        (**(code **)(iVar2 + 0x9c))(*(undefined4 *)(param_1 + 0xd8),iVar4 + 0x14,uVar3,uVar7);
        if (0 < local_8) {
          iVar4 = *(int *)(param_1 + 0xd4);
          local_3c = *(int *)(iVar4 + 0x14);
          local_38 = *(undefined4 *)(iVar4 + 0x18);
          local_34 = *(int *)(iVar4 + 0x1c);
          local_30 = *(undefined4 *)(iVar4 + 0x20);
          iVar2 = local_34 - local_3c;
          local_18 = local_c[1] + *(int *)(param_1 + 0x20);
          local_1c = *local_c + *(int *)(param_1 + 0x1c);
          local_2c = local_3c;
          local_28 = local_38;
          local_24 = local_34;
          local_20 = local_30;
          FUN_004ba5ac(&local_1c);
          iVar4 = local_8 * 4;
          if ((iVar4 <= iVar2) && (local_8 != 10)) {
            local_24 = local_2c + iVar4;
            local_34 = iVar4 + local_3c;
          }
          (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                    (*(undefined4 *)(param_1 + 0xd4),&local_3c,&local_2c,0);
        }
        local_10 = local_10 + 1;
        local_c = local_c + 2;
      } while ((int)local_10 < 0x66e36c);
    }
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  FUN_004cff80();
  local_18 = 8;
  local_1c = 0xd;
  FUN_0051eb1f(param_1 + 0xec,*(undefined4 *)(param_1 + 0x5c),param_1 + 0x1c,&local_1c,0xb);
  return 1;
}

