
void FUN_0041e725(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != param_2) {
    iVar2 = 0;
    for (iVar1 = param_2 - param_1 >> 3; iVar1 != 1; iVar1 = iVar1 >> 1) {
      iVar2 = iVar2 + 1;
    }
    FUN_0041e89b(param_1,param_2,0,iVar2 * 2);
    FUN_0041e921(param_1,param_2);
  }
  return;
}

