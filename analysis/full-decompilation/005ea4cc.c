
void __thiscall FUN_005ea4cc(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  if ((*(int *)(param_1 + 0xe4) != 0) && (*(char *)(param_1 + 0xe8) != '\0')) {
    piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
    (**(code **)(*piVar1 + 0x14))(*(undefined4 *)(param_1 + 0xe4));
  }
  *(undefined1 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xe4) = param_2;
  return;
}

