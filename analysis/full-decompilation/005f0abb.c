
void FUN_005f0abb(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_2[1];
  iVar2 = *param_2;
  *piVar1 = iVar2;
  *(int **)(iVar2 + 4) = piVar1;
  FUN_005eed47();
  FUN_0040189d(param_2,0x40);
  *param_1 = iVar2;
  return;
}

