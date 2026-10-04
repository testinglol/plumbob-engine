
undefined4 * FUN_00501d71(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  
  do {
    cVar3 = FUN_00501cfd(*param_1,param_3);
    if (cVar3 == '\0') {
      do {
        puVar1 = param_2 + -1;
        param_2 = param_2 + -1;
        cVar3 = FUN_00501cfd(param_3,*puVar1);
      } while (cVar3 != '\0');
      if (param_2 <= param_1) {
        return param_1;
      }
      uVar2 = *param_1;
      *param_1 = *param_2;
      *param_2 = uVar2;
    }
    param_1 = param_1 + 1;
  } while( true );
}

