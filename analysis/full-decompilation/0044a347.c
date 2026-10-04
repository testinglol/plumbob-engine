
undefined4 * __thiscall
FUN_0044a347(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
            code *param_5)

{
  char cVar1;
  
  while( true ) {
    while (cVar1 = (*param_5)(*param_2,param_4,param_1), cVar1 != '\0') {
      param_2 = param_2 + 1;
    }
    do {
      param_3 = param_3 + -1;
      cVar1 = (*param_5)(param_4,*param_3);
    } while (cVar1 != '\0');
    if (param_3 <= param_2) break;
    param_1 = *param_2;
    *param_2 = *param_3;
    *param_3 = param_1;
    param_2 = param_2 + 1;
  }
  return param_2;
}

