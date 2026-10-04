
undefined4 __fastcall FUN_0050f90d(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
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
  
  if (param_1[0x21] == param_1[0x1f]) {
    return 1;
  }
  if (param_1[0x22] == param_1[0x20]) {
    return 1;
  }
  if (DAT_006e5490 < (uint)param_1[0x3c]) {
    FUN_00473496(DAT_006e5490);
    local_8 = param_1[0x22] - param_1[0x20];
    local_8 = __ftol();
  }
  else {
    if ((char)param_1[0x38] == '\0') {
      if ((char)param_1[0x44] == '\0') {
        return 1;
      }
      goto LAB_0050faec;
    }
    local_8 = 0;
  }
  FUN_004e609e();
  cVar1 = FUN_004e6133();
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 != '\0') {
      iVar3 = param_1[0x42];
      local_24 = *(int *)(iVar3 + 0x14);
      local_20 = *(int *)(iVar3 + 0x18);
      local_1c = *(int *)(iVar3 + 0x1c);
      local_34 = local_24 + param_1[7];
      local_2c = local_1c + param_1[7];
      local_28 = param_1[8] + *(int *)(iVar3 + 0x20);
      local_18 = *(int *)(iVar3 + 0x20) - local_8;
      local_30 = local_20 + param_1[8] + local_8;
      piVar6 = &local_34;
      iVar4 = *(int *)param_1[0x17];
      piVar5 = &local_24;
LAB_0050fac2:
      (**(code **)(iVar4 + 0x9c))(iVar3,piVar5,piVar6,0);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
  }
  else if (DAT_006e5490 < (uint)param_1[0x3c]) {
    local_c = 0;
    local_8 = 0;
    iVar3 = param_1[0x17];
    FUN_00473496(DAT_006e5490);
    uVar2 = __ftol();
    (*DAT_006f0674)(iVar3,param_1 + 7,iVar3,param_1 + 7,param_1[0x42],&local_c,uVar2);
  }
  else {
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 != '\0') {
      iVar3 = param_1[0x42];
      local_14 = *(int *)(iVar3 + 0x14);
      local_10 = *(int *)(iVar3 + 0x18);
      local_c = *(int *)(iVar3 + 0x1c);
      local_8 = *(int *)(iVar3 + 0x20);
      local_24 = local_14 + param_1[7];
      local_20 = local_10 + param_1[8];
      local_1c = local_c + param_1[7];
      local_18 = local_8 + param_1[8];
      piVar6 = &local_24;
      iVar4 = *(int *)param_1[0x17];
      piVar5 = &local_14;
      goto LAB_0050fac2;
    }
  }
  if ((char)param_1[0x38] != '\0') {
    return 1;
  }
  if (DAT_006e5490 < (uint)param_1[0x3c]) {
    return 1;
  }
LAB_0050faec:
  (**(code **)(*param_1 + 0x98))();
  FUN_005ddfdc(0);
  FUN_0050fc6a(0);
  (**(code **)(*param_1 + 0x168))();
  *(undefined1 *)(param_1 + 0x44) = 0;
  return 1;
}

