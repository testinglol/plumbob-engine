
int FUN_005c1976(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_005c26e9(&param_3,param_3);
  iVar1 = *(int *)(param_3 + 0x18);
  iVar3 = *(int *)(param_3 + 0x14);
  while( true ) {
    if (iVar3 == iVar1) {
      return 0;
    }
    iVar2 = FUN_005c19b7(param_1,param_2,iVar3);
    if (iVar2 != 0) break;
    iVar3 = iVar3 + 4;
  }
  return iVar2;
}

