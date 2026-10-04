
void FUN_0041e89b(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = param_2 - param_1;
  while( true ) {
    if ((int)(uVar1 & 0xfffffff8) < 0x81) {
      return;
    }
    if (param_4 == 0) break;
    param_4 = param_4 + -1;
    puVar2 = (undefined4 *)
             FUN_0041e9a2(param_1,param_1 + ((param_2 - param_1 >> 3) - (param_2 - param_1 >> 0x1f)
                                            >> 1) * 8,param_2 + -8);
    iVar3 = FUN_0041e9d7(param_1,param_2,*puVar2,puVar2[1]);
    FUN_0041e89b(iVar3,param_2,0,param_4);
    uVar1 = iVar3 - param_1;
    param_2 = iVar3;
  }
  FUN_0041eaa6(param_1,param_2,param_2,0);
  return;
}

