
undefined4 __fastcall FUN_00562e9d(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  (**(code **)(*param_1 + 0x1b0))();
  if (param_1[0x67] == 0) {
    iVar2 = (**(code **)(*param_1 + 0xc4))();
    param_1[0x67] = iVar2;
  }
  else {
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 != '\0') {
      (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x67],param_1[0x67] + 0x14,param_1 + 7,0);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
  }
  piVar3 = (int *)FUN_005e40a5();
  if (piVar3 != (int *)0x0) {
    local_c = (**(code **)(*piVar3 + 0x1c))();
    piVar4 = (int *)FUN_005e7743();
    iVar2 = *piVar3;
    iVar5 = (**(code **)(*piVar4 + 0x50))(param_1[0x3c]);
    (**(code **)(iVar2 + 0x20))(*(undefined4 *)(iVar5 + param_1[0x3a] * 4));
    local_14 = param_1[0x70] + param_1[7];
    iVar2 = *piVar3;
    local_10 = param_1[0x71] + param_1[8];
    local_8 = param_1[0x17];
    uVar6 = FUN_005d49d6(0,0,0);
    uVar6 = FUN_004096c2(uVar6);
    (**(code **)(iVar2 + 0x78))(local_8,local_14,local_10,uVar6);
    local_14 = param_1[0x72] + param_1[7];
    local_10 = param_1[0x73] + param_1[8];
    iVar2 = *piVar3;
    local_8 = param_1[0x17];
    uVar6 = FUN_005d49d6(0,0,0);
    uVar6 = FUN_004096c2(uVar6);
    (**(code **)(iVar2 + 0x78))(local_8,local_14,local_10,uVar6);
    (**(code **)(*piVar3 + 0x20))(local_c);
  }
  iVar2 = param_1[0x66];
  if ((iVar2 != 0) && (0 < param_1[0x65])) {
    local_34 = *(int *)(iVar2 + 0x14);
    local_30 = *(undefined4 *)(iVar2 + 0x18);
    local_2c = *(undefined4 *)(iVar2 + 0x1c);
    local_28 = *(undefined4 *)(iVar2 + 0x20);
    local_10 = param_1[0x6f] - param_1[0x20];
    local_14 = param_1[0x6e] - param_1[0x1f];
    local_24 = local_34;
    local_20 = local_30;
    local_1c = local_2c;
    local_18 = local_28;
    FUN_004ba5ac(param_1 + 7);
    FUN_004ba5ac(&local_14);
    iVar2 = param_1[0x66];
    iVar5 = *(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x14);
    local_2c = param_1[0x65] * 6;
    if (local_2c - iVar5 != 0 && iVar5 <= local_2c) {
      local_2c = *(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x14);
    }
    local_1c = local_24 + local_2c;
    local_2c = local_2c + local_34;
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 != '\0') {
      (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x66],&local_34,&local_24,0);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
  }
  return 1;
}

