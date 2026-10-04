
void FUN_0043e5bf(int *param_1)

{
  char cVar1;
  
  cVar1 = FUN_00411d07(param_1);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*param_1 + 0x28))();
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x18))();
    }
    if (param_1 != (int *)0x0) {
      (**(code **)*param_1)(1);
    }
  }
  return;
}

