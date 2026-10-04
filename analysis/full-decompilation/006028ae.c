
uint * __thiscall FUN_006028ae(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint extraout_ECX;
  uint uVar2;
  uint *puVar3;
  uint local_10 [2];
  undefined1 local_8 [4];
  
  puVar3 = param_2;
  FUN_005a5c09(&param_2,param_2);
  uVar2 = extraout_ECX;
  if ((param_2 == (uint *)*param_1) || (uVar2 = *puVar3, uVar2 < param_2[4])) {
    local_10[0] = *puVar3;
    local_10[1] = 0;
    puVar3 = local_10;
    FUN_00602c56(&param_2);
    puVar1 = (undefined4 *)FUN_0060298c(local_8,uVar2,puVar3);
    param_2 = (uint *)*puVar1;
  }
  return param_2 + 5;
}

