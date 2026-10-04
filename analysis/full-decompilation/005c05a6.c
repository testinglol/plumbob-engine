
uint FUN_005c05a6(int *param_1,undefined4 param_2,uint *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_005bfe47();
  if ((param_4 == -2) || (param_4 == -1)) {
    param_4 = FUN_005bfe47();
  }
  if (iVar1 == param_4) {
    uVar2 = (**(code **)(*param_1 + 0x1c))();
    if (uVar2 < *param_3) {
      uVar2 = (**(code **)(*param_1 + 0x1c))();
      *param_3 = uVar2;
    }
    uVar3 = (**(code **)(*param_1 + 0x18))(*param_3);
    FUN_00636510(param_2,uVar3);
    uVar2 = *param_3;
  }
  else {
    uVar3 = (**(code **)(*param_1 + 0x1c))(iVar1,param_2,param_3,param_4);
    uVar3 = (**(code **)(*param_1 + 0x18))(uVar3);
    uVar2 = FUN_005bfeb2(uVar3);
  }
  return uVar2;
}

