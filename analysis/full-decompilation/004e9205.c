
undefined4 FUN_004e9205(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined2 local_10 [6];
  
  uVar2 = FUN_004e988f(param_1);
  iVar3 = FUN_004e8d49(uVar2);
  if ((((iVar3 != 0) && (piVar4 = (int *)FUN_004e8a7a(), piVar4 != (int *)0x0)) &&
      (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0)) &&
     (cVar1 = (**(code **)(*piVar4 + 0x20))(), cVar1 != '\0')) {
    local_10[0] = 0x7d2;
    local_10[1] = 0x7d3;
    local_10[2] = 0x7d4;
    local_10[3] = 0x7d5;
    local_10[4] = 0x7d6;
    local_10[5] = 0x7d7;
    puVar6 = local_10;
    iVar3 = 6;
    do {
      iVar5 = (**(code **)(*piVar4 + 0x38))(0x424d505f,*puVar6,0);
      if (iVar5 != 0) {
        (**(code **)(*piVar4 + 0x80))(iVar5);
      }
      puVar6 = puVar6 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return 1;
  }
  return 0;
}

