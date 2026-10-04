
undefined4 __thiscall FUN_006345f6(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((uint)param_1[9] < (uint)param_1[10]) {
    uVar1 = FUN_005c4410(param_2);
  }
  else {
    uVar1 = 1;
    iVar2 = (**(code **)(*param_1 + 0xc))(0xffffffff,1);
    if (iVar2 == -1) {
      uVar1 = 0xffffffff;
    }
    else if ((param_1[2] == 0) && (param_1[0xb] != 0)) {
      iVar2 = param_1[10];
      FUN_00635190(iVar2 + 1,iVar2,(param_1[0xb] - iVar2) + -1);
      *(char *)param_1[10] = (char)uVar1;
    }
  }
  return uVar1;
}

