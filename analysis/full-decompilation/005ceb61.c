
undefined4 __thiscall FUN_005ceb61(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(param_2 + 200);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    for (piVar1 = *(int **)(param_1 + 0x84); piVar1 != *(int **)(param_1 + 0x88);
        piVar1 = piVar1 + 1) {
      if (*piVar1 == param_2) {
        if (piVar1 == *(int **)(param_1 + 0x88)) {
          return 0;
        }
        if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar1)(1);
        }
        FUN_005db2f2(piVar1);
        if (param_2 != *(int *)(param_1 + 0x90)) {
          return 0;
        }
        FUN_005cebc6(0);
        return 0;
      }
    }
  }
  else {
    *(undefined4 *)(param_2 + 4) = 0;
  }
  return 0;
}

