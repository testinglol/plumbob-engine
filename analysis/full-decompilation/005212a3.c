
undefined4 __thiscall FUN_005212a3(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  DWORD DVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  undefined1 local_50 [16];
  undefined1 local_40 [16];
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
  
  if (param_1[0x77] == 0) {
    iVar2 = (**(code **)(*param_1 + 0xc4))();
    param_1[0x77] = iVar2;
  }
  else if ((char)param_2 == '\0') {
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 != '\0') {
      (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x77],param_1[0x77] + 0x14,param_1 + 7,0);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
  }
  if (param_1[0x66] != -1) {
    iVar2 = FUN_004ea79e(param_1[0x66]);
    param_2 = (int)*(short *)(iVar2 + param_1[0x65] * 2) / 100;
    (**(code **)(*param_1 + 0x1b0))();
    iVar2 = param_1[0x79];
    if (iVar2 != 0) {
      if (param_2 < 0xb) {
        if (param_2 < 0) {
          param_2 = 0;
        }
      }
      else {
        param_2 = 10;
      }
      local_30 = *(int *)(iVar2 + 0x14);
      local_2c = *(int *)(iVar2 + 0x18);
      local_28 = *(int *)(iVar2 + 0x1c);
      local_24 = *(int *)(iVar2 + 0x20);
      local_8 = local_28 - local_30;
      piVar4 = param_1 + 7;
      local_10 = *piVar4 + param_1[0x7e];
      local_c = param_1[8] + param_1[0x7f] + -1;
      local_20 = local_30;
      local_1c = local_2c;
      local_18 = local_28;
      local_14 = local_24;
      FUN_004ba5ac(&local_10);
      local_28 = param_2 * 4;
      if (local_8 < param_2 * 4) {
        local_28 = local_8;
      }
      local_18 = local_20 + local_28;
      local_28 = local_28 + local_30;
      cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
      if (cVar1 != '\0') {
        uVar9 = 0;
        local_8 = param_1[0x78] + 0x14;
        local_c = *(int *)param_1[0x17];
        puVar8 = local_40;
        FUN_004df599(local_50,param_1 + 0x7e);
        uVar3 = FUN_004df599(puVar8,piVar4);
        (**(code **)(local_c + 0x9c))(param_1[0x78],local_8,uVar3,uVar9);
        if (0 < param_2) {
          (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x79],&local_30,&local_20,0);
        }
        (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
      }
    }
    piVar4 = (int *)FUN_005e40a5();
    if (piVar4 != (int *)0x0) {
      param_2 = (**(code **)(*piVar4 + 0x1c))();
      piVar5 = (int *)FUN_005e7743();
      iVar2 = *piVar4;
      iVar6 = (**(code **)(*piVar5 + 0x50))(param_1[0x3c]);
      (**(code **)(iVar2 + 0x20))(*(undefined4 *)(iVar6 + param_1[0x3a] * 4));
      FUN_004df599(&local_30,param_1 + 7);
      if (*(char *)(DAT_006e486c + 100) == '\x13') {
        local_2c = local_2c + -3;
        local_24 = local_24 + -3;
      }
      (**(code **)(*piVar4 + 0x80))
                (param_1[0x17],&local_30,param_1[0x13],param_1[0x14] - param_1[0x13],2);
      (**(code **)(*piVar4 + 0x20))(param_2);
    }
    if ((char)param_1[0x5b] != '\0') {
      FUN_005d9928(&local_c,&param_2);
      DVar7 = timeGetTime();
      if ((uint)param_1[0x56] < DVar7 - param_1[0x57]) {
        if (param_1[0x12] != 0) {
          FUN_005da644(param_1[0x12],3,0x13,param_1,0);
        }
        *(undefined1 *)(param_1 + 0x5b) = 0;
      }
      else {
        (**(code **)(*param_1 + 0x168))();
      }
    }
  }
  return 1;
}

