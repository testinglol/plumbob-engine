
undefined4 __fastcall FUN_00525f3d(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x174))(0,0);
    (**(code **)(*param_1 + 0xcc))(0);
    if ((char)param_1[0x47] != '\0') {
      if ((undefined4 *)param_1[0x40] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)param_1[0x40])(1);
      }
      param_1[0x40] = 0;
      *(undefined1 *)(param_1 + 0x47) = 0;
    }
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    if ((undefined4 *)param_1[0x46] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x46])(1);
    }
    param_1[0x46] = 0;
  }
  return 1;
}

