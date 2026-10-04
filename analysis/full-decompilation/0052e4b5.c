
void __fastcall FUN_0052e4b5(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 == '\x01') {
    param_1[0x3a] = 0;
    if ((undefined4 *)param_1[0x35] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x35])(1);
    }
    param_1[0x35] = 0;
    if ((undefined4 *)param_1[0x36] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x36])(1);
    }
    param_1[0x36] = 0;
    FUN_0052ea87(param_1[0x37],param_1[0x38]);
    FUN_0052a419(param_1[0x3c],param_1[0x3d]);
    FUN_0052a419(param_1[0x3f],param_1[0x40]);
    FUN_0052a419(param_1[0x42],param_1[0x43]);
    if ((undefined4 *)param_1[0x45] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x45])(1);
    }
    param_1[0x45] = 0;
  }
  FUN_005dbf4d();
  return;
}

