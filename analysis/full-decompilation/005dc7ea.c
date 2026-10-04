
char __thiscall FUN_005dc7ea(int param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = '\0';
  if (*(char *)(param_1 + 0x3c) == '\0') {
    *(undefined1 *)(param_1 + 0x3c) = 1;
  }
  piVar2 = (int *)**(int **)(param_1 + 0x38);
  if (piVar2 != *(int **)(param_1 + 0x38)) {
    while ((int *)piVar2[2] != param_2) {
      cVar1 = (**(code **)(*(int *)piVar2[2] + 0x40))(param_2);
      if ((cVar1 != '\0') || (piVar2 = (int *)*piVar2, piVar2 == (int *)*(int *)(param_1 + 0x38)))
      goto LAB_005dc823;
    }
    cVar1 = '\x01';
  }
LAB_005dc823:
  *(undefined1 *)(param_1 + 0x3c) = 0;
  return cVar1;
}

