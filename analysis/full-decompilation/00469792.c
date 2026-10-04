
int __thiscall FUN_00469792(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != *(int **)(param_1 + 0x10)) {
    piVar2 = piVar1;
    do {
      if ((((param_2[1] < piVar2[3]) && (piVar2[1] < param_2[3])) && (*param_2 < piVar2[2])) &&
         (*piVar2 < param_2[2])) {
        return ((int)piVar2 - (int)piVar1) / 0x14;
      }
      piVar2 = piVar2 + 5;
    } while (piVar2 != *(int **)(param_1 + 0x10));
  }
  return -1;
}

