
void __fastcall FUN_0050ef7f(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    param_1[0x43] = 0;
    param_1[0x44] = 0;
    param_1[0x42] = 0;
    if ((undefined4 *)param_1[0x46] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x46])(1);
    }
    param_1[0x46] = 0;
  }
  FUN_005dbf4d();
  return;
}

