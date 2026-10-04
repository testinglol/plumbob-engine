
undefined4 FUN_00464f5b(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_2;
  uVar1 = (**(code **)(*param_1 + 8))(param_3,FUN_00465037);
  iVar2 = (**(code **)(iVar2 + 0x38))(uVar1);
  if (iVar2 == 0) {
    uVar1 = FUN_00401f6f();
  }
  else {
    FUN_00464faf(param_1,iVar2,param_4);
    FUN_00465a06(iVar2);
    uVar1 = 0;
  }
  return uVar1;
}

