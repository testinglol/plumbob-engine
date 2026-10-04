
void FUN_0041eaa6(int *param_1,int *param_2,int *param_3)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_0041ec0f(param_1,param_2,0,0);
  uVar1 = extraout_ECX;
  for (piVar2 = param_2; piVar2 < param_3; piVar2 = piVar2 + 2) {
    if (*piVar2 < *param_1) {
      uVar4 = 0;
      uVar3 = uVar1;
      FUN_004c97cc(piVar2);
      FUN_0041eb7e(param_1,param_2,piVar2,uVar1,uVar3,uVar4);
      uVar1 = extraout_ECX_00;
    }
  }
  FUN_0041ebb6(param_1,param_2);
  return;
}

