
undefined4 __fastcall FUN_005dbf4d(int *param_1)

{
  (**(code **)(*param_1 + 0x98))();
  (**(code **)(*param_1 + 0x174))(0,0);
  (**(code **)(*param_1 + 0xcc))(0);
  if ((undefined4 *)param_1[0x34] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x34])(1);
  }
  param_1[0x34] = 0;
  return 1;
}

