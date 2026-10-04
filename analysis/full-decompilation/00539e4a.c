
undefined4 __fastcall FUN_00539e4a(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x90))(1,0);
    FUN_005dbf4d();
    if ((undefined4 *)param_1[0x4b] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4b])(1);
    }
    param_1[0x4b] = 0;
    if ((undefined4 *)param_1[0x56] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x56])(1);
    }
    param_1[0x56] = 0;
    if ((undefined4 *)param_1[0x57] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x57])(1);
    }
    param_1[0x57] = 0;
    if ((undefined4 *)param_1[0x58] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x58])(1);
    }
    param_1[0x58] = 0;
    if ((undefined4 *)param_1[0x59] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x59])(1);
    }
    param_1[0x59] = 0;
    if ((undefined4 *)param_1[0x5a] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x5a])(1);
    }
    param_1[0x5a] = 0;
    if ((undefined4 *)param_1[0x7d] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x7d])(1);
    }
    if ((undefined4 *)param_1[0x7e] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x7e])(1);
    }
    if ((undefined4 *)param_1[0x7f] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x7f])(1);
    }
    if ((undefined4 *)param_1[0x80] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x80])(1);
    }
    if ((undefined4 *)param_1[0x81] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x81])(1);
    }
    param_1[0x7d] = 0;
    param_1[0x7e] = 0;
    param_1[0x7f] = 0;
    param_1[0x80] = 0;
    param_1[0x81] = 0;
    if ((undefined4 *)param_1[0x82] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x82])();
      piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      (**(code **)(*piVar2 + 0x14))(param_1[0x82]);
      do {
        iVar3 = (**(code **)(*(int *)param_1[0x82] + 4))();
      } while (iVar3 != 0);
      param_1[0x82] = 0;
    }
    if ((undefined4 *)param_1[0x83] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x83])();
      piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      (**(code **)(*piVar2 + 0x14))(param_1[0x83]);
      do {
        iVar3 = (**(code **)(*(int *)param_1[0x83] + 4))();
      } while (iVar3 != 0);
      param_1[0x83] = 0;
    }
  }
  return 1;
}

