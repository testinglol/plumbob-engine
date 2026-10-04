
void __thiscall FUN_00456c3e(undefined4 *param_1,int param_2)

{
  int *piVar1;
  
  for (piVar1 = (int *)*param_1; piVar1 != (int *)param_1[1]; piVar1 = piVar1 + 3) {
    if ((piVar1[1] == param_2) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
      if ((undefined4 *)piVar1[1] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar1[1])(1);
      }
      piVar1[1] = 0;
    }
  }
  return;
}

