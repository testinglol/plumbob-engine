
void __thiscall FUN_005edffa(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  
  if (((char)param_1[0x6c] != '\0') && (param_1[0x6d] != 0)) {
    DVar1 = timeGetTime();
    if (999 < DVar1 - param_1[0x6d]) {
      FUN_005db1e2();
      (**(code **)(*param_1 + 0x118))();
    }
  }
  FUN_005dd76b(param_2,param_3,param_4);
  return;
}

