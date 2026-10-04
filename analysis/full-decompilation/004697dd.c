
int * __thiscall FUN_004697dd(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = (int *)0x0;
  piVar4 = (int *)**(undefined4 **)(param_1 + 4);
  piVar1 = (int *)(*(undefined4 **)(param_1 + 4))[1];
  if (piVar4 != piVar1) {
    do {
      if ((((param_2[1] < piVar4[3]) && (piVar4[1] < param_2[3])) && (*param_2 < piVar4[2])) &&
         ((*piVar4 < param_2[2] && (piVar3 = piVar4, piVar4[4] == 0x7fffffff)))) {
        return piVar4;
      }
      piVar4 = piVar4 + 5;
    } while (piVar4 != piVar1);
  }
  puVar2 = *(undefined4 **)(param_1 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    piVar4 = (int *)*puVar2;
    if (piVar4 != (int *)puVar2[1]) {
      do {
        if (((param_2[1] < piVar4[3]) && (piVar4[1] < param_2[3])) &&
           ((*param_2 < piVar4[2] &&
            ((*piVar4 < param_2[2] && (piVar3 = piVar4, piVar4[4] == 0x7fffffff)))))) {
          return piVar4;
        }
        piVar4 = piVar4 + 5;
      } while (piVar4 != (int *)puVar2[1]);
    }
  }
  return piVar3;
}

