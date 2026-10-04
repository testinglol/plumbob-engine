
int __fastcall FUN_0048f140(char *param_1)

{
  char cVar1;
  
  cVar1 = FUN_0048f12a();
  if (cVar1 != '\0') {
    return 0;
  }
  return ((int)param_1[4] - (int)param_1[1]) * ((int)param_1[3] - (int)*param_1);
}

