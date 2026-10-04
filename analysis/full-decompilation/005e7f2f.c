
int * __thiscall FUN_005e7f2f(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int extraout_ECX;
  int iVar2;
  int *piVar3;
  int local_10 [2];
  undefined1 local_8 [4];
  
  piVar3 = param_2;
  FUN_005e8243(&param_2,param_2);
  iVar2 = extraout_ECX;
  if ((param_2 == (int *)*param_1) || (iVar2 = *piVar3, iVar2 < param_2[4])) {
    local_10[0] = *piVar3;
    local_10[1] = 0;
    piVar3 = local_10;
    FUN_00602c56(&param_2);
    puVar1 = (undefined4 *)FUN_005e8132(local_8,iVar2,piVar3);
    param_2 = (int *)*puVar1;
  }
  return param_2 + 5;
}

