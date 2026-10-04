
void FUN_005c0c20(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = param_2 - param_1;
  while( true ) {
    if ((int)(uVar1 & 0xfffffff0) < 0x101) {
      return;
    }
    if (param_4 == 0) break;
    param_4 = param_4 + -1;
    puVar2 = (undefined4 *)
             FUN_005c0d25(param_1,((param_2 - param_1 >> 4) - (param_2 - param_1 >> 0x1f) >> 1) *
                                  0x10 + param_1,param_2 + -0x10,param_5,param_5);
    iVar3 = FUN_005c0d5d(param_1,param_2,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    FUN_005c0c20(iVar3,param_2,0,param_4,param_5);
    uVar1 = iVar3 - param_1;
    param_2 = iVar3;
  }
  FUN_005c0de5(param_1,param_2,param_2,0,param_5);
  return;
}

