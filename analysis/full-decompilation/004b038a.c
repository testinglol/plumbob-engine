
void __thiscall FUN_004b038a(int param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  
  cVar2 = FUN_004b4616(0,1);
  if ((cVar2 != '\0') && (cVar2 = (**(code **)(*param_2 + 0x20))(0x40), cVar2 == '\0')) {
    return;
  }
  cVar2 = FUN_004b4616(0,2);
  if (((cVar2 != '\0') && ((int *)param_2[0x17] != (int *)0x0)) &&
     (cVar2 = (**(code **)(*(int *)param_2[0x17] + 0x20))(0x40), cVar2 == '\0')) {
    cVar2 = FUN_004b4616(0,1);
    if (cVar2 == '\0') {
      return;
    }
    (**(code **)(*param_2 + 0x24))(0x10);
    return;
  }
  cVar2 = FUN_004b4616(0,1);
  if (cVar2 == '\0') {
    DAT_006f0bcc = 0;
    DAT_006f0bbc = 0;
  }
  else {
    DAT_006f0bcc = (**(code **)(*param_2 + 0xcc))();
    DAT_006f0bbc = (**(code **)(*param_2 + 0xd0))();
  }
  cVar2 = FUN_004b4616(0,2);
  if ((cVar2 == '\0') || (piVar1 = (int *)param_2[0x17], piVar1 == (int *)0x0)) {
    DAT_006f0bd0 = 0;
    DAT_006f0bd4 = 0;
  }
  else {
    DAT_006f0bd0 = (**(code **)(*piVar1 + 0xcc))();
    DAT_006f0bd4 = (**(code **)(*piVar1 + 0xd0))();
  }
  *(undefined1 *)(param_1 + 0x78) = 1;
  *(undefined4 *)(param_1 + 0x7c) = 3;
  *(int **)(param_1 + 0x80) = param_2;
  return;
}

