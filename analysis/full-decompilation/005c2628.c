
undefined4 * __thiscall
FUN_005c2628(int *param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *local_c;
  int *piStack_8;
  
  iVar3 = param_3;
  local_c = param_1;
  piStack_8 = param_1;
  if (param_3 == *(int *)(*param_1 + 8)) {
    if ((param_1[1] == 0) || (cVar1 = FUN_005c1797(param_3 + 0x10), cVar1 == '\0'))
    goto LAB_005c26d3;
LAB_005c2657:
    FUN_005c2a8c(param_2,param_3,iVar3,param_4);
  }
  else {
    if (param_3 == *param_1) {
      cVar1 = FUN_005c1797(param_4);
      if (cVar1 != '\0') {
        iVar3 = *(int *)(*param_1 + 0xc);
LAB_005c26cb:
        param_3 = 0;
        goto LAB_005c2657;
      }
    }
    else {
      FUN_0042a392();
      cVar1 = FUN_005c1797(param_4);
      if ((cVar1 != '\0') && (cVar1 = FUN_005c1797(param_3 + 0x10), cVar1 != '\0')) {
        if (*(int *)(param_3 + 0xc) != 0) goto LAB_005c2657;
        goto LAB_005c26cb;
      }
    }
LAB_005c26d3:
    puVar2 = (undefined4 *)FUN_005c2b18(&local_c,param_4);
    *param_2 = *puVar2;
  }
  return param_2;
}

