
void __thiscall FUN_00402122(undefined4 *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  if ((short)param_2 < 0x100) {
    (**(code **)(*(int *)param_1[4] + 0x10))(param_2,param_3);
  }
  else if ((short)param_2 == 0x7fff) {
    FUN_0046f847(s____error____006c0a54,0xffffffff);
  }
  else {
    piVar2 = (int *)(**(code **)*param_1)(param_2);
    if (((piVar2 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0x28))(), cVar1 != '\0')) &&
       (iVar3 = (**(code **)(*piVar2 + 0x38))(0x42484156,param_2,param_1[5]), iVar3 != 0)) {
      (**(code **)(*piVar2 + 0x48))(iVar3,param_3);
      return;
    }
    *(undefined2 *)(param_3 + 8) = 0;
    **(undefined1 **)(param_3 + 4) = 0;
  }
  return;
}

