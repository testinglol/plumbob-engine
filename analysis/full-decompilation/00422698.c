
void __fastcall FUN_00422698(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_2;
  if (*param_1 <= *param_2) {
    piVar1 = param_1;
  }
  *param_1 = *piVar1;
  piVar1 = param_1 + 1;
  piVar2 = param_2 + 1;
  if (*piVar1 <= param_2[1]) {
    piVar2 = piVar1;
  }
  *piVar1 = *piVar2;
  piVar1 = param_2 + 2;
  if (param_2[2] <= param_1[2]) {
    piVar1 = param_1 + 2;
  }
  param_1[2] = *piVar1;
  param_1 = param_1 + 3;
  piVar1 = param_2 + 3;
  if (param_2[3] <= *param_1) {
    piVar1 = param_1;
  }
  *param_1 = *piVar1;
  return;
}

