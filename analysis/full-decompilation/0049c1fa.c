
bool __thiscall FUN_0049c1fa(int *param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  
  if ((param_2 != 0) && (cVar1 = FUN_005b8f4a(param_1[5]), cVar1 != '\0')) {
    if (*param_1 == 0) {
      pvVar2 = _malloc(param_1[4] * param_1[3]);
      *param_1 = (int)pvVar2;
    }
    if (*param_1 != 0) {
      cVar1 = FUN_005b904f(*param_1,param_1[4] * param_1[3]);
      return cVar1 != '\0';
    }
  }
  return false;
}

