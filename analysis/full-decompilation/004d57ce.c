
undefined4 __thiscall
FUN_004d57ce(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1[0x35] == 1) {
    (**(code **)(*param_1 + 0xfc))(param_2,param_3,param_4);
    param_1[0x35] = 0;
    iVar2 = FUN_00492d2c();
    if (iVar2 != 0) {
      FUN_005d9912(iVar2);
    }
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_005dd7f2(param_2,param_3,param_4);
  }
  return uVar1;
}

