
char __thiscall FUN_005bf236(int *param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x10))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x14))();
  }
  cVar1 = FUN_005bf78a(param_1 + 1,param_2);
  if (cVar1 == '\0') {
    FUN_005bfa81();
  }
  (**(code **)(param_1[1] + 0x2c))(param_2);
  return cVar1;
}

