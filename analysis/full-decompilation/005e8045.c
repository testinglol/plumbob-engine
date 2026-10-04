
int * __thiscall FUN_005e8045(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int local_18 [4];
  uint local_8;
  
  piVar3 = param_2;
  FUN_005e8243(&param_2,param_2);
  if ((param_2 == (int *)*param_1) || (*piVar3 < param_2[4])) {
    iVar2 = *piVar3;
    local_8 = local_8 & 0xffffff00;
    local_18[1] = 0;
    local_18[2] = local_8;
    piVar3 = local_18;
    local_18[0] = iVar2;
    FUN_00602c56(&param_2);
    puVar1 = (undefined4 *)FUN_005e8182(&local_8,iVar2,piVar3);
    param_2 = (int *)*puVar1;
  }
  return param_2 + 5;
}

