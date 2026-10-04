
int __thiscall FUN_005d2475(int *param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = param_3;
  *param_3 = 0;
  iVar3 = FUN_005d2455(param_2);
  if (iVar3 == param_1[2]) {
    iVar3 = (**(code **)(*param_1 + 4))(param_2,&param_3);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = FUN_005d24e1(param_3,0,*param_2);
    if (iVar3 != 0) {
      if (param_3 == (int *)0x0) {
        return iVar3;
      }
      (**(code **)(*param_3 + 8))();
      return iVar3;
    }
    *piVar2 = (int)param_3;
  }
  else {
    piVar1 = *(int **)(iVar3 + 0x104);
    *piVar2 = (int)piVar1;
    (**(code **)(*piVar1 + 4))();
  }
  return 0;
}

