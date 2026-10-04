
void FUN_0044a0b4(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  
  while( true ) {
    if (param_2 - param_1 >> 2 < 0x11) {
      return;
    }
    if (param_4 == 0) break;
    param_4 = param_4 + -1;
    puVar1 = (undefined4 *)
             FUN_0044a2b2(param_1,param_1 + ((param_2 - param_1 >> 2) - (param_2 - param_1 >> 0x1f)
                                            >> 1) * 4,param_2 + -4,param_5,param_5);
    iVar2 = FUN_0044a347(param_1,param_2,*puVar1);
    FUN_0044a0b4(iVar2,param_2,0,param_4,param_5);
    param_2 = iVar2;
  }
  FUN_0044a640(param_1,param_2,param_2,0,param_5);
  return;
}

