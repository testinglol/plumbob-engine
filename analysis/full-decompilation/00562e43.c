
void __fastcall FUN_00562e43(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    if ((undefined4 *)param_1[0x66] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x66])(1);
    }
    param_1[0x66] = 0;
    if ((undefined4 *)param_1[0x67] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x67])(1);
    }
    param_1[0x67] = 0;
    param_1[0x74] = 0;
    param_1[0x75] = 0;
  }
  FUN_005e38e0();
  return;
}

