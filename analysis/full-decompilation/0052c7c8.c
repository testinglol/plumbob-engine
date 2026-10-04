
void __fastcall FUN_0052c7c8(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 == '\0') {
    return;
  }
  if ((undefined4 *)param_1[0x35] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x35])(1);
    param_1[0x35] = 0;
  }
  if ((undefined4 *)param_1[0x36] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x36])(1);
    param_1[0x36] = 0;
  }
  if ((undefined4 *)param_1[0x37] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x37])(1);
    param_1[0x37] = 0;
  }
  if ((undefined4 *)param_1[0x38] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x38])(1);
    param_1[0x38] = 0;
  }
  if ((undefined4 *)param_1[0x7b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x7b])(1);
    param_1[0x7b] = 0;
  }
  if ((undefined4 *)param_1[0x39] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x39])(1);
    param_1[0x39] = 0;
  }
  if ((undefined4 *)param_1[0x3a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x3a])(1);
    param_1[0x3a] = 0;
  }
  if ((undefined4 *)param_1[0x3b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x3b])(1);
    param_1[0x3b] = 0;
  }
  if (param_1[0x7a] != 0) {
    cVar1 = (**(code **)(*param_1 + 0x38))(param_1[0x7a]);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x24))(param_1[0x7a]);
    }
    FUN_005da4c7(param_1[0x7a]);
    param_1[0x7a] = 0;
  }
  FUN_0052ea87(param_1[0x3c],param_1[0x3d]);
  FUN_0052a419(param_1[0x43],param_1[0x44]);
  FUN_0052a419(param_1[0x46],param_1[0x47]);
  FUN_0052ea87(param_1[0x3f],param_1[0x40]);
  FUN_0052a419(param_1[0x49],param_1[0x4a]);
  FUN_0052a419(param_1[0x4c],param_1[0x4d]);
  FUN_0052a419(param_1[0x4f],param_1[0x50]);
  FUN_0052a419(param_1[0x52],param_1[0x53]);
  FUN_0052a419(param_1[0x55],param_1[0x56]);
  if ((undefined4 *)param_1[0x70] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x70])(1);
    param_1[0x70] = 0;
  }
  FUN_005dbf4d();
  return;
}

