
void FUN_0043991e(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0x1f < (int)(param_2 - param_1 & 0xfffffff0U)) {
    iVar1 = param_2 - param_1 >> 4;
    iVar2 = (iVar1 + -2) / 2;
    iVar3 = iVar2 * 0x10 + param_1;
    while( true ) {
      FUN_004393d9(iVar3);
      FUN_00439978(param_1,iVar2,iVar1);
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      iVar3 = iVar3 + -0x10;
    }
  }
  return;
}

