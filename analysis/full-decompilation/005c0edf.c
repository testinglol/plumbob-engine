
void FUN_005c0edf(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (0x1f < (int)((int)param_2 - param_1 & 0xfffffff0U)) {
    iVar1 = (int)param_2 - param_1 >> 4;
    iVar2 = (iVar1 + -2) / 2;
    param_2 = (undefined4 *)(iVar2 * 0x10 + param_1);
    while( true ) {
      FUN_005c0f9b(param_1,iVar2,iVar1,*param_2,param_2[1],param_2[2],param_2[3],param_3);
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      param_2 = param_2 + -4;
    }
  }
  return;
}

