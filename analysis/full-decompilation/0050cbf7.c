
undefined4 __fastcall FUN_0050cbf7(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x90))(1,0);
    FUN_005dbf4d();
    param_1[0x41] = 0;
    if ((undefined4 *)param_1[0x42] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x42])(1);
    }
    param_1[0x42] = 0;
  }
  return 1;
}

