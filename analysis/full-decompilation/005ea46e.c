
void __thiscall FUN_005ea46e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0xe4) != 0) && (*(char *)(param_1 + 0xe8) != '\0')) {
    piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
    (**(code **)(*piVar1 + 0x14))(*(undefined4 *)(param_1 + 0xe4));
  }
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
  uVar2 = (**(code **)(*piVar1 + 0x10))(param_2,param_3,param_4,0);
  *(undefined4 *)(param_1 + 0xe4) = uVar2;
  *(undefined1 *)(param_1 + 0xe8) = 1;
  return;
}

