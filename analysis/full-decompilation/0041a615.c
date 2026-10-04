
int FUN_0041a615(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar1 = param_1 - param_2;
    for (iVar3 = param_3; 0 < iVar3; iVar3 = iVar3 - param_2) {
      param_2 = 0xc800;
      if (iVar3 < 0xc800) {
        param_2 = iVar3;
      }
      iVar2 = FUN_004131a0(param_1);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = FUN_00413178(param_4,&param_2);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = FUN_004131a0(iVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = FUN_00412f9f(param_4,&param_2);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar1 = iVar1 + param_2;
      param_1 = param_1 + param_2;
    }
  }
  return 0;
}

