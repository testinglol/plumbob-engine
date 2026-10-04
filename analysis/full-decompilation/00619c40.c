
int FUN_00619c40(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  do {
    piVar4 = (int *)FUN_005a9320((*param_1 + 8) * param_2 + 8);
    if (piVar4 != (int *)0x0) {
      iVar2 = param_1[2];
      piVar4[1] = (int)(param_1 + 2);
      param_1[2] = (int)piVar4;
      *piVar4 = iVar2;
      *(int **)(iVar2 + 4) = piVar4;
      piVar4 = piVar4 + 2;
      if (param_2 != 0) {
        piVar1 = param_1 + 6;
        iVar2 = *param_1;
        iVar5 = param_2;
        do {
          iVar3 = *piVar1;
          piVar4[1] = (int)piVar1;
          *piVar4 = iVar3;
          *(int **)(iVar3 + 4) = piVar4;
          *piVar1 = (int)piVar4;
          piVar4 = (int *)((int)piVar4 + iVar2 + 8);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      return param_2;
    }
    param_2 = param_2 >> 1;
  } while (param_2 != 0);
  return 0;
}

