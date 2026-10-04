
void FUN_004e52e0(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = *param_2;
  if (iVar2 < *param_1) {
    iVar4 = (int)param_2 - (int)param_1 >> 2;
    if (0 < iVar4) {
      piVar3 = param_2 + 1;
      do {
        piVar1 = (int *)((int)param_2 + (-4 - (int)(param_2 + 1)) + (int)piVar3);
        piVar3 = piVar3 + -1;
        iVar4 = iVar4 + -1;
        *piVar3 = *piVar1;
      } while (iVar4 != 0);
    }
    *param_1 = iVar2;
  }
  else {
    while( true ) {
      iVar4 = param_2[-1];
      if (iVar4 <= iVar2) break;
      *param_2 = iVar4;
      param_2 = param_2 + -1;
    }
    *param_2 = iVar2;
  }
  return;
}

