
void __fastcall FUN_004a7901(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  piVar2 = param_2;
  if (*param_2 <= *param_1) {
    piVar2 = param_1;
  }
  iVar1 = *piVar2;
  piVar2 = param_2 + 2;
  *param_1 = iVar1;
  piVar3 = piVar2;
  if (iVar1 <= *piVar2) {
    piVar3 = param_1;
  }
  *param_1 = *piVar3;
  piVar3 = param_1 + 1;
  piVar4 = param_2 + 1;
  piVar6 = piVar4;
  if (param_2[1] <= param_1[1]) {
    piVar6 = piVar3;
  }
  *piVar3 = *piVar6;
  piVar6 = param_2 + 3;
  piVar5 = piVar6;
  if (*piVar3 <= param_2[3]) {
    piVar5 = piVar3;
  }
  *piVar3 = *piVar5;
  piVar3 = param_1 + 2;
  if (param_1[2] <= *piVar2) {
    piVar2 = piVar3;
  }
  iVar1 = *piVar2;
  *piVar3 = iVar1;
  if (*param_2 <= iVar1) {
    param_2 = piVar3;
  }
  *piVar3 = *param_2;
  param_1 = param_1 + 3;
  if (*param_1 <= *piVar6) {
    piVar6 = param_1;
  }
  iVar1 = *piVar6;
  *param_1 = iVar1;
  if (*piVar4 <= iVar1) {
    piVar4 = param_1;
  }
  *param_1 = *piVar4;
  return;
}

