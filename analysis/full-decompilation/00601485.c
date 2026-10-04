
void __thiscall FUN_00601485(int *param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int **ppiVar3;
  int *piVar4;
  int *local_8;
  
  local_8 = param_1;
  local_8 = (int *)*param_1;
  piVar4 = local_8;
  if ((int *)local_8[1] != (int *)0x0) {
    piVar1 = (int *)local_8[1];
    do {
      if (piVar1[4] < *param_3) {
        piVar2 = (int *)piVar1[3];
      }
      else {
        piVar2 = (int *)piVar1[2];
        piVar4 = piVar1;
      }
      piVar1 = piVar2;
    } while (piVar2 != (int *)0x0);
  }
  if ((piVar4 == local_8) || (*param_3 < piVar4[4])) {
    ppiVar3 = &local_8;
  }
  else {
    ppiVar3 = &param_3;
  }
  *param_2 = *ppiVar3;
  return;
}

