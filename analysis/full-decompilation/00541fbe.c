
void FUN_00541fbe(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (7 < (int)(param_2 - param_1 & 0xfffffffcU)) {
    iVar1 = param_2 - param_1 >> 2;
    iVar3 = (iVar1 + -2) / 2;
    iVar2 = param_1 + iVar3 * 4;
    while( true ) {
      FUN_005412dc(iVar2);
      FUN_00542013(param_1,iVar3,iVar1);
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      iVar2 = iVar2 + -4;
    }
  }
  return;
}

