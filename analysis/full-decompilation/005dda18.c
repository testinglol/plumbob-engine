
void __thiscall FUN_005dda18(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  
  if ((param_4 - param_2 == param_1[0x21] - param_1[0x1f]) &&
     (param_5 - param_3 == param_1[0x22] - param_1[0x20])) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  param_1[0x1f] = param_2;
  param_1[0x20] = param_3;
  param_1[0x21] = param_4;
  param_1[0x22] = param_5;
  if ((param_1[0x16] != 0) && (bVar1)) {
    (**(code **)(*param_1 + 0x174))(1,0);
  }
  (**(code **)(*param_1 + 0x198))();
  (**(code **)(*param_1 + 0x88))();
  if (bVar1) {
    if ((undefined4 *)param_1[0x34] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x34])(1);
    }
    param_1[0x34] = 0;
  }
  cVar2 = (**(code **)(*param_1 + 0x8c))(8);
  if (cVar2 != '\0') {
    piVar3 = (int *)FUN_004b46a0();
    (**(code **)(*piVar3 + 0x170))(param_1 + 3);
  }
  return;
}

