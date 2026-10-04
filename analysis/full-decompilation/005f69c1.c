
undefined4 __fastcall FUN_005f69c1(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(1);
  if (cVar1 != '\0') {
    iVar2 = (**(code **)(*param_1 + 0x1cc))();
    iVar3 = (**(code **)(*param_1 + 0x1d0))();
    local_18 = param_1[7];
    if (param_1[0x35] == 1) {
      local_14 = param_1[8];
      local_c = local_14 + iVar3;
      local_10 = local_18 + iVar2;
      (**(code **)(*(int *)param_1[0x17] + 0x40))(param_1[0x19],&local_18,0);
      local_18 = param_1[7] + iVar2;
      local_14 = param_1[8];
      local_c = local_14 + iVar3;
      local_10 = param_1[9] - iVar2;
      local_8 = local_10;
      (**(code **)(*(int *)param_1[0x17] + 0x40))(~param_1[0x19],&local_18,0);
      local_14 = param_1[8];
      local_18 = local_8;
      local_10 = local_8 + iVar2;
      local_c = local_14 + iVar3;
      (**(code **)(*(int *)param_1[0x17] + 0x40))(param_1[0x19],&local_18,0);
      local_18 = param_1[0x3d] + param_1[7];
      local_14 = param_1[8];
      iVar4 = *(int *)param_1[0x17];
    }
    else {
      local_14 = param_1[8];
      local_c = local_14 + iVar3;
      local_10 = local_18 + iVar2;
      (**(code **)(*(int *)param_1[0x17] + 0x40))(param_1[0x19],&local_18,0);
      local_18 = param_1[7];
      local_14 = iVar3 + param_1[8];
      local_10 = local_18 + iVar2;
      local_c = param_1[10] - iVar3;
      local_8 = local_c;
      (**(code **)(*(int *)param_1[0x17] + 0x40))(~param_1[0x19],&local_18,0);
      local_18 = param_1[7];
      local_14 = local_8;
      local_c = local_8 + iVar3;
      local_10 = local_18 + iVar2;
      (**(code **)(*(int *)param_1[0x17] + 0x40))(param_1[0x19],&local_18,0);
      local_18 = param_1[7];
      local_14 = param_1[0x3e] + param_1[8];
      iVar4 = *(int *)param_1[0x17];
    }
    local_c = local_14 + iVar3;
    local_10 = local_18 + iVar2;
    (**(code **)(iVar4 + 0x40))(param_1[0x19],&local_18,0);
    (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
  }
  return 1;
}

