
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060edb0(undefined4 param_1,float *param_2,float *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float local_74;
  float local_70 [14];
  undefined1 local_38 [56];
  
  local_74 = *param_3 - *param_2;
  if (local_74 == _DAT_0066657c) {
    uVar1 = __ftol(param_4,param_2,param_5);
    FUN_0060f000(param_1,uVar1);
    return;
  }
  pfVar4 = param_2;
  if (local_74 < _DAT_0066657c) {
    local_74 = -local_74;
    pfVar4 = param_3;
    param_3 = param_2;
  }
  FUN_0060eeb0(pfVar4,param_3,local_38,local_74);
  pfVar5 = local_70;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar5 = pfVar5 + 1;
  }
  iVar2 = __ftol();
  for (iVar3 = __ftol(); iVar3 < iVar2; iVar3 = iVar3 + 1) {
    FUN_0060f000(param_1,iVar3,param_4,local_70,param_5);
    FUN_0060ef70(local_70,local_38);
  }
  return;
}

