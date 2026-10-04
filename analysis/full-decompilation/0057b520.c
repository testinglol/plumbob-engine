
int __thiscall FUN_0057b520(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  
  piVar1 = *(int **)(param_1 + 0x14);
  piVar3 = (int *)*piVar1;
  if (piVar3 != piVar1) {
    do {
      cVar2 = FUN_004317d5(piVar3[2],param_2);
      if (cVar2 != '\0') break;
      piVar3 = (int *)*piVar3;
    } while (piVar3 != piVar1);
    if (piVar3 != piVar1) {
      return piVar3[2];
    }
  }
  return 0;
}

