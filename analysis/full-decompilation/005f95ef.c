
undefined4 __thiscall FUN_005f95ef(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  int *local_8;
  
  local_8 = param_1;
  cVar1 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar1 == '\0') {
    return 1;
  }
  param_1[10] = param_2;
  if ((char)param_1[0xb] != '\0') {
    *(undefined1 *)(param_1 + 0xb) = 0;
    (**(code **)(*param_1 + 100))();
  }
  if (*(char *)((int)param_1 + 0x25) != '\0') {
    uVar2 = (**(code **)(*param_1 + 0xdc))(param_3,1);
    return uVar2;
  }
  cVar1 = (**(code **)(*param_1 + 0x5c))();
  if ((cVar1 == '\0') && (cVar1 = (**(code **)(*param_1 + 0x60))(), cVar1 == '\0')) {
    return 0;
  }
  if (param_4 == 0) {
    param_4 = param_1[0xd];
  }
  if ((char)param_3 != '\0') {
    *(undefined1 *)(param_1 + 9) = 1;
  }
  bVar4 = (char)param_1[9] != '\0';
  cVar1 = (**(code **)(*param_1 + 0x24))();
  if (cVar1 == '\0') {
    local_8 = (int *)param_1[0x20];
  }
  else {
    local_8 = (int *)param_1[0x28];
    if (param_4 == 1) {
      (**(code **)(*local_8 + 0x34))(local_8,0);
      (**(code **)(*param_1 + 0x78))(param_2);
      goto LAB_005f969d;
    }
    if (param_4 == 2) {
      return 1;
    }
    if ((param_4 == 3) && (cVar1 = (**(code **)(*param_1 + 0xe4))(&local_8), cVar1 == '\0')) {
      return 0;
    }
  }
  (**(code **)(*param_1 + 0x78))(param_1[10]);
  iVar3 = (**(code **)(*local_8 + 0x30))(local_8,0,0,bVar4);
  if ((iVar3 != 0) &&
     (((iVar3 != -0x7787ff6a || (iVar3 = (**(code **)(*local_8 + 0x50))(local_8), iVar3 != 0)) ||
      (iVar3 = (**(code **)(*local_8 + 0x30))(local_8,0,0,bVar4), iVar3 != 0)))) {
    return 0;
  }
LAB_005f969d:
  if ((param_1[0x1e] != 0) && (cVar1 = (**(code **)(*(int *)param_1[0x19] + 0x1c))(), cVar1 == '\0')
     ) {
    FUN_005fa8e9();
  }
  return 1;
}

