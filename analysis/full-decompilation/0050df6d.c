
void __fastcall FUN_0050df6d(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    param_1[0x39] = 0;
    if ((undefined4 *)param_1[0x3b] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x3b])(1);
    }
    param_1[0x3b] = 0;
    if ((undefined4 *)param_1[0x3c] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x3c])(1);
    }
    param_1[0x3c] = 0;
    param_1[0x3d] = 0;
    param_1[0x3f] = 0;
    param_1[0x3e] = 0;
  }
  FUN_005dbf32();
  return;
}

