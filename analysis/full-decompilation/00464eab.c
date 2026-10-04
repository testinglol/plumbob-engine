
int FUN_00464eab(int *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  iVar1 = FUN_00464dcd(param_1,param_2);
  if (iVar1 == 0) {
    iVar2 = -1;
  }
  else {
    FUN_0046f824(local_44,0,0x40);
    local_50[0] = &PTR_FUN_0066651c;
    FUN_0046f847(0,0xffffffff);
    iVar2 = *param_3;
    uVar3 = (**(code **)(*param_1 + 8))(param_4,local_50,1);
    (**(code **)(iVar2 + 0x74))(iVar1,uVar3);
    iVar2 = FUN_00401f6f();
    if (iVar2 == 0) {
      (**(code **)(*param_3 + 0x7c))(iVar1);
      iVar2 = FUN_00401f6f();
      if (iVar2 != 0) {
        (**(code **)(*param_3 + 0x80))();
        return iVar2;
      }
      (**(code **)(*param_3 + 100))(iVar1);
      iVar2 = 0;
    }
    FUN_00420028(iVar1);
  }
  return iVar2;
}

