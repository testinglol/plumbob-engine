
void __fastcall FUN_004ff9de(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x90))(1,0);
    (**(code **)(*param_1 + 0x174))(0,0);
    if ((undefined4 *)param_1[0x35] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x35])(1);
    }
    param_1[0x35] = 0;
  }
  FUN_005dbf4d();
  return;
}

