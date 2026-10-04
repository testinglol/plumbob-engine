
void FUN_0041eafa(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar1 = *param_2;
  iVar2 = param_2[1];
  if (iVar1 < *param_1) {
    piVar4 = param_2 + 2;
    iVar3 = (int)param_2 - (int)param_1 >> 3;
    piVar5 = param_2;
    param_2 = (int *)iVar3;
    if (0 < iVar3) {
      do {
        param_2 = (int *)((int)param_2 + -1);
        piVar4[-2] = piVar5[-2];
        piVar4[-1] = piVar5[-1];
        piVar4 = piVar4 + -2;
        piVar5 = piVar5 + -2;
      } while (param_2 != (int *)0x0);
    }
    *param_1 = iVar1;
    param_1[1] = iVar2;
  }
  else {
    FUN_0041ebe0(param_2,iVar1,iVar2);
  }
  return;
}

