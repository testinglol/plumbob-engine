
undefined4 __fastcall FUN_005ee090(int *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  DWORD DVar4;
  int iVar5;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  if (param_1[0x6d] == 0) {
    DVar4 = timeGetTime();
    param_1[0x6d] = DVar4;
  }
  if ((((char)param_1[0x5c] != '\0') && ((int *)param_1[0x17] != (int *)0x0)) &&
     (param_1[param_1[0x35] + 0x36] != 0)) {
    cVar3 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar3 != '\0') {
      iVar5 = param_1[param_1[0x35] + 0x36];
      local_28 = *(int *)(iVar5 + 0x14);
      local_24 = *(int *)(iVar5 + 0x18);
      local_20 = *(int *)(iVar5 + 0x1c);
      local_1c = *(int *)(iVar5 + 0x20);
      local_18 = local_28;
      local_14 = local_24;
      local_10 = local_20;
      local_c = local_1c;
      FUN_004ba5ac(param_1 + 7);
      iVar5 = (((param_1[10] - param_1[8]) - local_1c) + local_24) / 2;
      local_14 = local_14 + iVar5;
      local_c = local_c + iVar5;
      iVar5 = (((param_1[9] - param_1[7]) - local_20) + local_28) / 2;
      local_18 = local_18 + iVar5;
      local_10 = local_10 + iVar5;
      (**(code **)(*(int *)param_1[0x17] + 0x9c))
                (param_1[param_1[0x35] + 0x36],&local_28,&local_18,0);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
  }
  FUN_005ee2fe(param_1 + 0x5d);
  FUN_005ee2fe(param_1 + 0x61);
  FUN_005ee47b();
  FUN_005ee60b();
  if (param_1[param_1[0x35] * 3 + 0x3f] == param_1[param_1[0x35] * 3 + 0x3e]) {
    param_1[0x65] = 0;
    param_1[0x66] = 0;
    param_1[0x67] = 0;
    param_1[0x68] = 0;
  }
  else {
    piVar1 = param_1 + 0x65;
    *piVar1 = param_1[0x1f];
    param_1[0x66] = param_1[0x20];
    param_1[0x67] = param_1[0x21];
    param_1[0x68] = param_1[0x22];
    iVar5 = param_1[0x66];
    iVar2 = *piVar1;
    param_1[0x66] = param_1[0x66] + -iVar5;
    param_1[0x68] = param_1[0x68] + -iVar5;
    *piVar1 = *piVar1 + -iVar2;
    param_1[0x67] = param_1[0x67] + -iVar2;
    if (param_1[0x68] < 0x2bd) {
      iVar5 = (**(code **)(*(int *)param_1[0x4a] + 0x58))();
      iVar5 = iVar5 * 3;
    }
    else {
      iVar5 = (**(code **)(*(int *)param_1[0x4a] + 0x58))();
      iVar5 = iVar5 * 5;
    }
    param_1[0x66] = param_1[0x68] - iVar5;
    iVar5 = (**(code **)(*(int *)param_1[0x4a] + 0x58))();
    param_1[0x68] = iVar5 + param_1[0x66];
    FUN_004ba5ac(param_1 + 7);
    if ((char)param_1[0x5c] == '\0') {
      FUN_005ee2fe(piVar1);
    }
    local_8 = (**(code **)(*(int *)param_1[0x4a] + 0x1c))();
    (**(code **)(*(int *)param_1[0x4a] + 0x20))(0xffffff);
    (**(code **)(*(int *)param_1[0x4a] + 0x80))
              (param_1[0x17],piVar1,param_1[param_1[0x35] * 3 + 0x3e],
               param_1[param_1[0x35] * 3 + 0x3f] - param_1[param_1[0x35] * 3 + 0x3e],1);
    (**(code **)(*(int *)param_1[0x4a] + 0x20))(local_8);
  }
  if ((DAT_006e5490 < (uint)param_1[0x57]) || (DAT_006e5490 < (uint)param_1[0x5b])) {
    (**(code **)(*param_1 + 0x168))();
  }
  return 1;
}

