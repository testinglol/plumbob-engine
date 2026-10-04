
void FUN_004e523f(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    iVar1 = *param_1;
    piVar3 = param_1;
    while( true ) {
      iVar2 = piVar3[-1];
      if (iVar2 <= iVar1) break;
      *piVar3 = iVar2;
      piVar3 = piVar3 + -1;
    }
    *piVar3 = iVar1;
  }
  return;
}

