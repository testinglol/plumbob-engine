
void FUN_00439404(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = param_2 - param_1;
  while( true ) {
    if ((int)(uVar1 & 0xfffffff0) < 0x101) {
      return;
    }
    if (param_4 == 0) break;
    param_4 = param_4 + -1;
    uVar2 = FUN_0043957e();
    FUN_004393d9(uVar2);
    iVar3 = FUN_004395d7(param_1,param_2);
    FUN_00439404(iVar3,param_2,0,param_4,param_5);
    uVar1 = iVar3 - param_1;
    param_2 = iVar3;
  }
  FUN_00439657();
  return;
}

