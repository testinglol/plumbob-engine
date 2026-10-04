
void __thiscall FUN_005de0ed(int param_1,undefined4 param_2,char param_3)

{
  int *piVar1;
  
  if ((*(char *)(param_1 + 0x6c) == '\0') || (param_3 != '\0')) {
    piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    (**(code **)(*piVar1 + 0x24))();
    FUN_005ecd7f(param_2,param_1);
  }
  return;
}

