
void __fastcall FUN_0050d576(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    param_1[0x36] = 0;
    if ((undefined4 *)param_1[0x37] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x37])(1);
    }
    param_1[0x37] = 0;
    if ((undefined4 *)param_1[0x38] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x38])(1);
    }
    param_1[0x38] = 0;
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
  }
  FUN_005dbf32();
  return;
}

