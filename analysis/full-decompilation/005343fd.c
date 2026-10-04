
void __thiscall FUN_005343fd(int *param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  char cVar2;
  int **ppiVar3;
  int *piVar4;
  int *piVar5;
  int *local_8;
  
  piVar1 = (int *)((int *)*param_1)[1];
  piVar5 = (int *)*param_1;
  local_8 = param_1;
  while (piVar4 = piVar1, piVar4 != (int *)0x0) {
    cVar2 = FUN_00430155(piVar4 + 4,param_3);
    if (cVar2 == '\0') {
      piVar1 = (int *)piVar4[2];
      piVar5 = piVar4;
    }
    else {
      piVar1 = (int *)piVar4[3];
    }
  }
  local_8 = piVar5;
  if (piVar5 != (int *)*param_1) {
    cVar2 = FUN_00430155(param_3,piVar5 + 4);
    if (cVar2 == '\0') {
      ppiVar3 = &local_8;
      goto LAB_00534453;
    }
  }
  ppiVar3 = &param_3;
LAB_00534453:
  *param_2 = *ppiVar3;
  return;
}

