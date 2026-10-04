
void FUN_005c3270(char *param_1,char *param_2)

{
  char cVar1;
  size_t sVar2;
  
  sVar2 = _strlen(param_2);
  if (param_2[sVar2 - 4] == '.') {
    *param_1 = param_2[sVar2 - 3];
    param_1[1] = param_2[sVar2 - 2];
    cVar1 = param_2[sVar2 - 1];
    param_1[3] = '\0';
    param_1[2] = cVar1;
    return;
  }
  if (param_2[sVar2 - 3] == '.') {
    *param_1 = param_2[sVar2 - 2];
    cVar1 = param_2[sVar2 - 1];
    param_1[2] = '\0';
    param_1[1] = cVar1;
    return;
  }
  if (param_2[sVar2 - 2] == '.') {
    cVar1 = param_2[sVar2 - 1];
    param_1[1] = '\0';
    *param_1 = cVar1;
  }
  return;
}

