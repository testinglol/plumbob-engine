
undefined4 FUN_00565e28(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined1 local_c [4];
  int local_8;
  
  local_8 = 0;
  iVar3 = FUN_005d8a86(0);
  piVar2 = param_2;
  while( true ) {
    if (iVar3 == 0) {
      return 0;
    }
    FUN_005d823b(param_3);
    piVar1 = (int *)*piVar2;
    FUN_004301c9(&param_2,param_3);
    if (param_2 == piVar1) break;
    local_8 = local_8 + 1;
    iVar3 = FUN_005d8a86(local_8);
  }
  FUN_004300be(local_c,param_3);
  if (iVar3 == 0) {
    return 0;
  }
  return 1;
}

