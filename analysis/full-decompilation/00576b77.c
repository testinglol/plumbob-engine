
void FUN_00576b77(int *param_1,undefined4 param_2,int *param_3)

{
  undefined4 extraout_ECX;
  undefined4 uVar1;
  int *piVar2;
  int local_c;
  
  local_c = *param_3;
  if ((param_1 != param_3) && (param_1 != (int *)local_c)) {
    piVar2 = &local_c;
    FUN_00602c56(&param_3);
    uVar1 = extraout_ECX;
    FUN_00602c56(&param_1);
    FUN_00576c38(uVar1,piVar2);
  }
  return;
}

