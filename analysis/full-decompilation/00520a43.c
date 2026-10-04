
undefined4 * FUN_00520a43(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,code *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  
  uVar1 = *param_2;
  uVar2 = *param_1;
  cVar4 = (*param_4)(uVar2,uVar1);
  uVar3 = *param_3;
  if (cVar4 == '\0') {
    cVar4 = (*param_4)(uVar2,uVar3);
    if (cVar4 != '\0') {
      return param_1;
    }
    cVar4 = (*param_4)(uVar1,uVar3);
    if (cVar4 != '\0') {
      return param_3;
    }
  }
  else {
    cVar4 = (*param_4)(uVar1);
    if (cVar4 == '\0') {
      cVar4 = (*param_4)(uVar2,uVar3);
      if (cVar4 == '\0') {
        return param_1;
      }
      return param_3;
    }
  }
  return param_2;
}

