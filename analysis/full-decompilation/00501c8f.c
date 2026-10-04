
undefined4 * FUN_00501c8f(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  
  cVar1 = FUN_00501cfd(*param_1,*param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_00501cfd(*param_1,*param_3);
    if (cVar1 != '\0') {
      return param_1;
    }
    cVar1 = FUN_00501cfd(*param_2,*param_3);
    if (cVar1 != '\0') {
      return param_3;
    }
  }
  else {
    cVar1 = FUN_00501cfd(*param_2,*param_3);
    if (cVar1 == '\0') {
      cVar1 = FUN_00501cfd(*param_1,*param_3);
      if (cVar1 == '\0') {
        return param_1;
      }
      return param_3;
    }
  }
  return param_2;
}

