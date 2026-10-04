
void __thiscall FUN_005c3387(int *param_1,int *param_2)

{
  int *piVar1;
  
  if (*param_1 == 1) {
    FUN_005c33c0(0);
  }
  else {
    piVar1 = (int *)param_1[1];
    if ((param_2 != piVar1) && (piVar1 != (int *)0x0)) {
      (*(code *)**(undefined4 **)(*(int *)(*piVar1 + 4) + (int)piVar1))(1);
    }
  }
  *param_1 = 0;
  param_1[1] = (int)param_2;
  return;
}

