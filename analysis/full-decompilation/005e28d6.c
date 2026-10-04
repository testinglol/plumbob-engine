
undefined4 __fastcall FUN_005e28d6(int *param_1)

{
  if (param_1[0x13] != 0) {
    FUN_00606366();
    if ((undefined4 *)param_1[0x13] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x13])(1);
    }
    param_1[0x13] = 0;
  }
  (**(code **)(*param_1 + 0xe4))();
  *(undefined1 *)(param_1 + 1) = 0;
  return 1;
}

