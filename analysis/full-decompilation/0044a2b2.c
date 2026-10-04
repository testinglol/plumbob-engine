
undefined4 * FUN_0044a2b2(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,code *param_4)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = (*param_4)(*param_1,*param_2);
  if (cVar1 == '\0') {
    cVar1 = (*param_4)(*param_1,*param_3);
    puVar2 = param_1;
    if ((cVar1 == '\0') && (cVar1 = (*param_4)(*param_2,*param_3), puVar2 = param_2, cVar1 != '\0'))
    {
      puVar2 = param_3;
    }
  }
  else {
    cVar1 = (*param_4)(*param_2,*param_3);
    puVar2 = param_2;
    if ((cVar1 == '\0') && (cVar1 = (*param_4)(*param_1,*param_3), puVar2 = param_1, cVar1 != '\0'))
    {
      puVar2 = param_3;
    }
  }
  return puVar2;
}

