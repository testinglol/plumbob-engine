
void FUN_005db8fb(int param_1,int param_2,undefined4 param_3,int param_4)

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
             FUN_005dba17(param_1,((param_2 - param_1 >> 4) - (param_2 - param_1 >> 0x1f) >> 1) *
                                  0x10 + param_1,param_2 + -0x10);
    iVar3 = FUN_005dba4f(param_1,param_2,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    FUN_005db8fb(iVar3,param_2,0,param_4);
    uVar1 = iVar3 - param_1;
    param_2 = iVar3;
  }
  FUN_005dbab7(param_1,param_2,param_2,0);
  return;
}

