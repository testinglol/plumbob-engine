
uint __fastcall FUN_005ecc17(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piStack_8;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x138))();
  if (*(char *)((int)param_1 + 0x91) == '\0') {
    cVar1 = (**(code **)(*(int *)(param_1[0x1e] + 0x48) + 0x18))();
    if ((cVar1 == '\0') || (*(char *)((int)param_1 + 0x75) == '\0')) {
      iVar3 = (**(code **)(*piVar2 + 0x1c))(param_1[0x12],param_1 + 5,param_1 + 0x19);
    }
    else {
      iVar3 = (**(code **)(*piVar2 + 0x2c))();
    }
    piStack_8 = (int *)(iVar3 << 0x18);
  }
  else {
    piStack_8 = param_1;
    if (DAT_006d6f9c == '\0') {
      cVar1 = (**(code **)(*(int *)(param_1[0x1e] + 0x48) + 0x18))();
      if (cVar1 != '\0') goto LAB_005ecc8c;
    }
    FUN_005cfd5f();
  }
LAB_005ecc8c:
  return (uint)piStack_8 >> 0x18;
}

