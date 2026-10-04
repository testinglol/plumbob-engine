
undefined4 __fastcall FUN_00515f6b(int *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  
  cVar2 = (**(code **)(*param_1 + 200))();
  if (cVar2 != '\0') {
    (**(code **)(*param_1 + 0x90))(1,0);
    FUN_005dbf4d();
    param_1[0x36] = 0;
    if ((undefined4 *)param_1[0x67] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x67])(1);
    }
    param_1[0x67] = 0;
    if ((undefined4 *)param_1[0x68] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x68])(1);
    }
    param_1[0x68] = 0;
    if ((undefined4 *)param_1[0x69] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x69])(1);
    }
    param_1[0x69] = 0;
    if ((undefined4 *)param_1[0x6a] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x6a])(1);
    }
    param_1[0x6a] = 0;
    iVar4 = 0x2a;
    piVar3 = param_1 + 0x38;
    do {
      if ((*piVar3 != 0) && (iVar1 = *(int *)(*piVar3 + 0xac), iVar1 != 0)) {
        FUN_005160c1();
        FUN_006321f0(iVar1);
      }
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    _memset(param_1 + 0x38,0,0xa8);
    if (param_1[0x65] != 0) {
      FUN_0050fc0a(0);
      FUN_005da4c7(param_1[0x65]);
      param_1[0x65] = 0;
    }
    if ((undefined4 *)param_1[0x66] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x66])(1);
    }
    param_1[0x66] = 0;
    if ((undefined4 *)param_1[0x6b] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x6b])(1);
    }
    param_1[0x6b] = 0;
    if ((undefined4 *)param_1[0x6c] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x6c])(1);
    }
    param_1[0x6c] = 0;
  }
  return 1;
}

