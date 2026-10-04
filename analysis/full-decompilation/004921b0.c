
int FUN_004921b0(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  
  while( true ) {
    if (param_1 == param_2) {
      return param_1;
    }
    cVar1 = FUN_0046198c(param_3);
    if (cVar1 != '\0') break;
    param_1 = param_1 + 3;
  }
  return param_1;
}

