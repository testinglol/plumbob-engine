
void __fastcall FUN_0052ade6(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  
  cVar2 = (**(code **)(*param_1 + 200))();
  puVar1 = (undefined4 *)param_1[0x35];
  if (cVar2 == '\0') {
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    param_1[0x35] = 0;
  }
  else {
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    param_1[0x35] = 0;
    _memset(param_1 + 0x36,0,0x18);
    param_1[0x3d] = 0;
    param_1[0x3e] = 0;
  }
  FUN_005dbf4d();
  return;
}

