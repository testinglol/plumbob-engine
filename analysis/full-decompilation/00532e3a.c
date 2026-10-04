
void __fastcall FUN_00532e3a(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    param_1[0x3e] = 0;
    param_1[0x3f] = 0;
    if ((undefined4 *)param_1[0x40] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x40])(1);
    }
    param_1[0x40] = 0;
  }
  FUN_005dbf4d();
  return;
}

