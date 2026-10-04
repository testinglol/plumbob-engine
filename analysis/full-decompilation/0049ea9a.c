
void __thiscall FUN_0049ea9a(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = (int *)(param_1 + 4);
  if ((*(int *)(param_1 + 8) - *piVar1 & 0xfffffffcU) != 0) {
    piVar2 = *(int **)(param_1 + 8);
    piVar3 = (int *)*piVar1;
    if (piVar3 != piVar2) {
      do {
        if (*piVar3 == param_2) break;
        piVar3 = piVar3 + 1;
      } while (piVar3 != piVar2);
      if (piVar2 != piVar3) {
        return;
      }
    }
  }
  if (*(int *)(param_1 + 8) - *piVar1 >> 2 == *(int *)(param_1 + 0x10)) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -4;
  }
  FUN_0049ec7f(*piVar1,1,&param_2);
  return;
}

