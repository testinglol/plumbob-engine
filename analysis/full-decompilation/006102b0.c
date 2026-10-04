
void FUN_006102b0(char *param_1,char *param_2,int param_3,char param_4,char param_5)

{
  char cVar1;
  char cVar2;
  
  if (0 < param_3) {
    do {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      cVar2 = param_5;
      if ((cVar1 != param_4) && (cVar2 = cVar1, cVar1 == param_5)) {
        cVar2 = param_4;
      }
      *param_2 = cVar2;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

