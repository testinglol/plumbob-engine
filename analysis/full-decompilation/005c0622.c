
bool FUN_005c0622(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 local_20c [512];
  uint local_c;
  int local_8;
  
  piVar1 = param_1;
  local_8 = FUN_005bfe47();
  if ((param_3 == -2) || (param_3 == -1)) {
    param_3 = FUN_005bfe47();
  }
  if (local_8 == param_3) {
    if (param_1 != param_2) {
      iVar3 = *param_2;
      uVar2 = (**(code **)(*param_1 + 0x1c))();
      uVar2 = (**(code **)(*param_1 + 0x14))(uVar2);
      (**(code **)(iVar3 + 0xc))(uVar2);
    }
    return true;
  }
  if (local_8 == 0x10) {
    return false;
  }
  iVar3 = (**(code **)(*param_1 + 0x1c))();
  local_c = iVar3 * 6;
  if (local_c < 0x200) {
    param_1 = (int *)0x0;
  }
  else {
    puVar4 = operator_new(local_c);
    param_1 = (int *)puVar4;
    if (puVar4 != (undefined1 *)0x0) goto LAB_005c06b6;
  }
  puVar4 = local_20c;
LAB_005c06b6:
  *puVar4 = 0;
  uVar2 = (**(code **)(*piVar1 + 0x18))(iVar3,local_8,puVar4,&local_c,param_3);
  iVar5 = FUN_005bfeb2(uVar2);
  (**(code **)(*param_2 + 0xc))(puVar4,local_c);
  FUN_006321f0(param_1);
  return iVar5 == iVar3;
}

