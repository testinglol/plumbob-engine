
void __fastcall FUN_005e967d(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    if ((undefined4 *)param_1[0x35] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x35])(1);
    }
    param_1[0x35] = 0;
  }
  FUN_005dbf4d();
  return;
}

