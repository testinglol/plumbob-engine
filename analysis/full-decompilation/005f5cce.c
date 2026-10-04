
undefined4 __fastcall FUN_005f5cce(int *param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(1);
  if (cVar2 != '\0') {
    (**(code **)(*(int *)param_1[0x17] + 0x40))(param_1[0x19],param_1 + 7,0);
    (**(code **)(*(int *)param_1[0x17] + 0x24))(1);
  }
  cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(4);
  if (cVar2 != '\0') {
    if (param_1[0x35] == 1) {
      uVar1 = param_1[0x19];
      local_8 = *(int *)param_1[0x17];
      iVar3 = (param_1[0x22] - param_1[0x20]) / 2 + param_1[8];
      iVar4 = param_1[9] - param_1[0x3c];
      iVar5 = (param_1[0x22] - param_1[0x20]) / 2 + param_1[8];
      iVar6 = param_1[7] + param_1[0x3c];
    }
    else {
      uVar1 = param_1[0x19];
      local_8 = *(int *)param_1[0x17];
      iVar3 = (param_1[10] - param_1[0x3c]) + -1;
      iVar4 = param_1[9] - (param_1[0x21] - param_1[0x1f]) / 2;
      iVar5 = param_1[8] + param_1[0x3c];
      iVar6 = (param_1[0x21] - param_1[0x1f]) / 2 + param_1[7];
    }
    (**(code **)(local_8 + 0x7c))(iVar6,iVar5,iVar4,iVar3,~uVar1,1);
    (**(code **)(*(int *)param_1[0x17] + 0x24))(4);
  }
  cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(1);
  if (cVar2 != '\0') {
    iVar3 = param_1[0x3d];
    iVar4 = param_1[0x3e];
    iVar5 = param_1[7];
    iVar6 = param_1[8];
    local_8 = (**(code **)(*param_1 + 0x1cc))();
    local_8 = local_8 + iVar3 + iVar5;
    local_c = (**(code **)(*param_1 + 0x1d0))();
    local_10 = local_8;
    local_c = local_c + iVar4 + iVar6;
    local_18 = iVar3 + iVar5;
    local_14 = iVar4 + iVar6;
    (**(code **)(*(int *)param_1[0x17] + 0x40))(~param_1[0x19],&local_18,0);
    (**(code **)(*(int *)param_1[0x17] + 0x24))(1);
  }
  return 1;
}

