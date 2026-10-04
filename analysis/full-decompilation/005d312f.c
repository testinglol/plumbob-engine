
int FUN_005d312f(int param_1,int param_2,code *param_3)

{
  char cVar1;
  
  while( true ) {
    if (param_1 == param_2) {
      return param_1;
    }
    cVar1 = (*param_3)(param_1);
    if (cVar1 != '\0') break;
    param_1 = param_1 + 0x20;
  }
  return param_1;
}

