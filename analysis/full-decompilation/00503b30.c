
void __fastcall FUN_00503b30(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  
  cVar2 = (**(code **)(*param_1 + 200))();
  if (cVar2 != '\0') {
    param_1[0x36] = 0;
    if (param_1[0x3f] != 0) {
      FUN_0050fc0a(0);
      FUN_005da4c7(param_1[0x3f]);
      param_1[0x3f] = 0;
    }
    FUN_006321f0(param_1[0x41]);
    param_1[0x41] = 0;
    FUN_006321f0(param_1[0x42]);
    param_1[0x42] = 0;
    puVar1 = (undefined4 *)param_1[0x43];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    param_1[0x43] = 0;
    FUN_006321f0(param_1[0x44]);
    param_1[0x44] = 0;
    FUN_006321f0(param_1[0x45]);
    param_1[0x45] = 0;
    puVar1 = (undefined4 *)param_1[0x46];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    param_1[0x46] = 0;
    if ((undefined4 *)param_1[0x40] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x40])(1);
    }
    param_1[0x40] = 0;
    if ((undefined4 *)param_1[0x48] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x48])(1);
    }
    param_1[0x48] = 0;
    if ((undefined4 *)param_1[0x49] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x49])(1);
    }
    param_1[0x49] = 0;
  }
  FUN_005dbf4d();
  return;
}

