
void __fastcall FUN_005ea3e3(int param_1)

{
  int *piVar1;
  
  if ((*(char *)(param_1 + 0xf0) == '\0') || (*(undefined4 **)(param_1 + 0xec) == (undefined4 *)0x0)
     ) {
    if (*(int *)(param_1 + 0xec) != 0) {
      FUN_005e3581();
    }
  }
  else {
    (**(code **)**(undefined4 **)(param_1 + 0xec))(1);
  }
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined1 *)(param_1 + 0xf0) = 0;
  if ((*(int *)(param_1 + 0xe4) != 0) && (*(char *)(param_1 + 0xe8) != '\0')) {
    piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
    (**(code **)(*piVar1 + 0x14))(*(undefined4 *)(param_1 + 0xe4));
    *(undefined4 *)(param_1 + 0xe4) = 0;
  }
  FUN_005dbf4d();
  return;
}

