
undefined4 * FUN_00430b03(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,code *param_4)

{
  undefined4 uVar1;
  char cVar2;
  
  do {
    cVar2 = (*param_4)(param_1,&param_3);
    if (cVar2 == '\0') {
      do {
        param_2 = param_2 + -1;
        cVar2 = (*param_4)(&param_3,param_2);
      } while (cVar2 != '\0');
      if (param_2 <= param_1) {
        return param_1;
      }
      uVar1 = *param_1;
      *param_1 = *param_2;
      *param_2 = uVar1;
    }
    param_1 = param_1 + 1;
  } while( true );
}

