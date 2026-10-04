
bool __thiscall FUN_004a3ace(int *param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  
  if ((param_2 != 0) && (cVar1 = FUN_005b8f4a(param_1[3]), cVar1 != '\0')) {
    if (*param_1 == 0) {
      pvVar2 = _malloc((param_1[1] / 2) * param_1[1]);
      *param_1 = (int)pvVar2;
      if (pvVar2 == (void *)0x0) {
        return false;
      }
    }
    cVar1 = FUN_005b904f(*param_1,(param_1[1] / 2) * param_1[1]);
    return cVar1 != '\0';
  }
  return false;
}

