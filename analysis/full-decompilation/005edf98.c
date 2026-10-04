
void __thiscall FUN_005edf98(int *param_1,int param_2,undefined4 param_3)

{
  DWORD DVar1;
  
  if (((char)param_1[0x6c] != '\0') &&
     (((param_2 == 0x1b || (param_2 == 0xd)) && (param_1[0x6d] != 0)))) {
    DVar1 = timeGetTime();
    if (999 < DVar1 - param_1[0x6d]) {
      FUN_005db1e2();
      (**(code **)(*param_1 + 0x118))();
    }
  }
  FUN_005dd72f(param_2,param_3);
  return;
}

