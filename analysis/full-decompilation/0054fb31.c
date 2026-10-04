
void __fastcall FUN_0054fb31(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = (**(code **)(*param_1 + 200))();
  if (cVar2 != '\0') {
    if ((undefined4 *)param_1[0x35] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x35])(1);
    }
    param_1[0x35] = 0;
    if ((undefined4 *)param_1[0x36] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x36])(1);
    }
    param_1[0x36] = 0;
    param_1[0x38] = 0;
    iVar3 = 0;
    do {
      FUN_006321f0(*(undefined4 *)(param_1[0x3b] + iVar3));
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x9c);
    FUN_006321f0(param_1[0x3b]);
    param_1[0x3b] = 0;
    puVar1 = (undefined4 *)param_1[0x37];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    param_1[0x37] = 0;
  }
  FUN_005dbf4d();
  return;
}

