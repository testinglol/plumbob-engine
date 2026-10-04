
void __fastcall FUN_005325ae(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 == '\x01') {
    if ((undefined4 *)param_1[0x35] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x35])(1);
    }
    param_1[0x35] = 0;
    if ((undefined4 *)param_1[0x36] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x36])(1);
    }
    param_1[0x36] = 0;
    FUN_0052ea87(param_1[0x37],param_1[0x38]);
    FUN_0052a419(param_1[0x3e],param_1[0x3f]);
    FUN_0052a419(param_1[0x41],param_1[0x42]);
    if ((undefined4 *)param_1[0x44] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x44])(1);
    }
    param_1[0x44] = 0;
  }
  FUN_005dbf4d();
  return;
}

