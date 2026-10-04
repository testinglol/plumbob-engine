
void __thiscall FUN_005d2455(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != *(int **)(param_1 + 8)) {
    do {
      if (*param_2 == *piVar1) {
        return;
      }
      piVar1 = piVar1 + 0x42;
    } while (piVar1 != *(int **)(param_1 + 8));
  }
  return;
}

