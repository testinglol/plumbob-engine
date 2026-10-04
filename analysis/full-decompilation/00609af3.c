
char FUN_00609af3(char *param_1)

{
  int iVar1;
  char cVar2;
  
  if (*param_1 == '\0') {
    cVar2 = '\0';
  }
  else {
    iVar1 = FUN_00608ca3(*param_1);
    cVar2 = (iVar1 != 0) + '\x01';
  }
  return cVar2;
}

