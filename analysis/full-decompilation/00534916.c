
void FUN_00534916(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  while( true ) {
    if ((param_2 - param_1) / 0x28 < 0x11) {
      return;
    }
    if (param_4 == 0) break;
    param_4 = param_4 + -1;
    uVar1 = FUN_0043957e();
    FUN_00533d58(uVar1);
    iVar2 = FUN_00534b33(param_1,param_2);
    FUN_00534916(iVar2,param_2,0,param_4,param_5);
    param_2 = iVar2;
  }
  FUN_00534caa();
  return;
}

