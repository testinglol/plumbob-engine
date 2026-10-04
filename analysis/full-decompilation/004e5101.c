
void FUN_004e5101(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != param_2) {
    iVar2 = 0;
    for (iVar1 = param_2 - param_1 >> 2; iVar1 != 1; iVar1 = iVar1 >> 1) {
      iVar2 = iVar2 + 1;
    }
    FUN_004e513c(param_1,param_2,0,iVar2 * 2);
    FUN_004e51b0(param_1,param_2);
  }
  return;
}

