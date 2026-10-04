
int __thiscall FUN_005d27ca(undefined4 *param_1,int *param_2,char *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = param_2;
  *param_2 = 0;
  piVar3 = (int *)*param_1;
  do {
    if (piVar3 == (int *)param_1[1]) {
      iVar2 = FUN_005d29f9(param_3,&param_2);
      if (iVar2 == 0) {
LAB_005d282a:
        *piVar1 = (int)param_2;
        iVar2 = 0;
      }
      else if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))();
      }
      return iVar2;
    }
    iVar2 = _strcmp(param_3,(char *)(*piVar3 + 0x14));
    if (iVar2 == 0) {
      (**(code **)(*(int *)*piVar3 + 4))();
      param_2 = (int *)*piVar3;
      goto LAB_005d282a;
    }
    piVar3 = piVar3 + 1;
  } while( true );
}

