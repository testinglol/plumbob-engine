
undefined4 __fastcall FUN_00543f28(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x174))(0,0);
  }
  FUN_005dbf4d();
  if ((undefined4 *)param_1[0x3a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x3a])(1);
  }
  param_1[0x3a] = 0;
  param_1[0x39] = 0;
  FUN_0052ea87(param_1[0x36],param_1[0x37]);
  param_1[0x3b] = 0;
  if ((undefined4 *)param_1[0x3e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x3e])(1);
  }
  param_1[0x3e] = 0;
  return 1;
}

