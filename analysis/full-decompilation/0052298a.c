
void __fastcall FUN_0052298a(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    param_1[0x46] = 0;
    param_1[0x47] = 0;
    param_1[0x48] = 0;
    param_1[0x44] = 0;
    if ((undefined4 *)param_1[0x4a] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4a])(1);
      param_1[0x4a] = 0;
    }
    if ((undefined4 *)param_1[0x4b] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4b])(1);
      param_1[0x4b] = 0;
    }
    if ((undefined4 *)param_1[0x4c] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4c])(1);
      param_1[0x4c] = 0;
    }
    FUN_005a5e48(0);
  }
  FUN_005dbf4d();
  return;
}

