
undefined4 __thiscall FUN_00633de0(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 == DAT_00689080) || (param_2 == DAT_00689084)) {
    if (param_1[0xc] < 0) {
      FUN_00633e5e(param_1 + 0xd);
    }
    if ((param_1[0x13] == -1) || (iVar2 = (**(code **)(*param_1 + 4))(), iVar2 == -1)) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = FUN_0063d7a8(param_1[0x13],param_2);
    }
    if (param_1[0xc] < 0) {
      FUN_00633e69(param_1 + 0xd);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

