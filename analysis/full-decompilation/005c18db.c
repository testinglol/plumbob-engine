
undefined4 __thiscall FUN_005c18db(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *local_8;
  
  piVar3 = (int *)*param_1;
  local_8 = param_1;
  FUN_005c26e9(&local_8,param_2);
  if (local_8 == piVar3) {
    uVar5 = 2;
  }
  else {
    piVar3 = (int *)FUN_005c2358(param_2);
    iVar1 = piVar3[1];
    iVar4 = *piVar3;
    while ((iVar4 != iVar1 && (cVar2 = FUN_005c17a6(param_3), cVar2 == '\0'))) {
      iVar4 = iVar4 + 4;
    }
    if (iVar4 == piVar3[1]) {
      FUN_005c244d(param_3);
      uVar5 = 0;
    }
    else {
      uVar5 = 3;
    }
  }
  return uVar5;
}

