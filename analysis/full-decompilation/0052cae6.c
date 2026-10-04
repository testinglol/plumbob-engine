
undefined4 __fastcall FUN_0052cae6(int *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  int *piVar7;
  undefined *puVar8;
  undefined4 uVar9;
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
  int *local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  local_8 = FUN_004e99a9();
  cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
  if (cVar2 != '\0') {
    if ((param_1[0x35] != 0) && (local_8 != -1)) {
      local_10 = &DAT_006f3cd8;
      local_14 = &DAT_0066dab0;
      do {
        iVar5 = *local_14;
        iVar3 = FUN_004ea79e(local_8);
        local_c = (int)*(short *)(iVar3 + iVar5 * 2) / 100;
        if (10 < local_c) {
          local_c = 10;
        }
        if (local_c < 0) {
          local_c = 0;
        }
        iVar5 = param_1[0x36];
        uVar9 = 0;
        iVar3 = *(int *)param_1[0x17];
        puVar6 = local_4c;
        piVar7 = local_10;
        FUN_004df599(local_5c,param_1 + 7);
        uVar4 = FUN_004df599(puVar6,piVar7);
        (**(code **)(iVar3 + 0x9c))(param_1[0x36],iVar5 + 0x14,uVar4,uVar9);
        if (0 < local_c) {
          iVar5 = param_1[0x35];
          local_3c = *(int *)(iVar5 + 0x14);
          local_38 = *(undefined4 *)(iVar5 + 0x18);
          local_34 = *(int *)(iVar5 + 0x1c);
          local_30 = *(undefined4 *)(iVar5 + 0x20);
          iVar3 = local_34 - local_3c;
          local_1c = param_1[7] + *local_10;
          local_18 = local_10[1] + param_1[8];
          local_2c = local_3c;
          local_28 = local_38;
          local_24 = local_34;
          local_20 = local_30;
          FUN_004ba5ac(&local_1c);
          iVar5 = local_c * 4;
          if ((iVar5 <= iVar3) && (local_c != 10)) {
            local_24 = local_2c + iVar5;
            local_34 = iVar5 + local_3c;
          }
          (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x35],&local_3c,&local_2c,0);
        }
        local_14 = local_14 + 1;
        local_10 = local_10 + 2;
      } while ((int)local_14 < 0x66dac8);
    }
    (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
  }
  cVar2 = FUN_004cff80();
  if (cVar2 == '\0') {
    if (*(char *)(DAT_006e486c + 100) == '\x03') {
      uVar4 = 10;
    }
    else {
      uVar4 = 0xb;
    }
    puVar8 = &DAT_006f3be8;
  }
  else {
    uVar4 = 0xb;
    puVar8 = &DAT_006f3be0;
  }
  FUN_0051eb1f(param_1 + 0x71,param_1[0x17],param_1 + 7,puVar8,uVar4);
  if ((char)param_1[0x7c] == '\0') {
    if ((local_8 != -1) && ((int *)param_1[0x17] != (int *)0x0)) {
      cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(4);
      if (cVar2 != '\0') {
        local_14 = (int *)0x0;
        local_10 = &DAT_006f3cd8;
        do {
          iVar3 = 0;
          iVar5 = FUN_0040542d();
          if (iVar5 != 0) {
            iVar3 = FUN_00405165(local_8,local_14);
          }
          local_c = CONCAT31(local_c._1_3_,0 < iVar3);
          FUN_005e4ae7(local_c);
          if ((char)local_c != '\0') {
            iVar5 = param_1[7] + *local_10 + -1 + iVar3 * 4;
            local_18 = (*(int *)(param_1[0x35] + 0x20) - *(int *)(param_1[0x35] + 0x18)) + -1 +
                       local_10[1] + param_1[8];
            iVar1 = ((int *)param_1[0x17])[8];
            if (iVar1 < local_18) {
              local_18 = iVar1;
            }
            local_24 = iVar5;
            (**(code **)(*(int *)param_1[0x17] + 0x7c))
                      (iVar5,local_10[1] + param_1[8],iVar5,local_18,DAT_006f2a44,1);
            (**(code **)(*(int *)param_1[0x17] + 0x7c))
                      (iVar5 + iVar3 * -4 + -0xf,local_18,iVar5,local_18,DAT_006f2a44,1);
          }
          local_10 = local_10 + 2;
          local_14 = (int *)((int)local_14 + 1);
        } while ((int)local_10 < 0x6f3d08);
        (**(code **)(*(int *)param_1[0x17] + 0x24))(4);
      }
    }
  }
  else {
    (**(code **)(*param_1 + 0x16c))();
    *(undefined1 *)(param_1 + 0x7c) = 0;
  }
  if ((*(int *)(param_1[0x42] + 0x158) != 0) &&
     (*(char *)(*(int *)(param_1[0x42] + 0x158) + 0xe0) == '\0')) {
    (**(code **)(*DAT_006f3adc + 0x168))();
  }
  if (local_8 != -1) {
    cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar2 != '\0') {
      FUN_004ea85e(local_8);
      iVar5 = 0;
      do {
        if (iVar5 == 0) {
          uVar4 = 0;
          iVar3 = FUN_0040542d();
          if (iVar3 != 0) {
            uVar4 = FUN_004051e0(local_8);
          }
          FUN_0052d282(uVar4);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 1);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
  }
  iVar5 = local_8;
  if ((char)param_1[0x7c] == '\0') {
    FUN_0052c99f(local_8);
    FUN_0052d4b9(iVar5);
    FUN_0052d519(iVar5);
    FUN_0052d577(iVar5);
  }
  return 1;
}

