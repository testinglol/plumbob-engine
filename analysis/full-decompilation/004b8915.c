
void FUN_004b8915(char *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  
  param_1[0x20] = '\0';
  sVar1 = _strlen(param_2);
  do {
    sVar3 = sVar1;
    sVar1 = sVar3 - 1;
    if ((int)sVar1 < 0) goto LAB_004b8958;
  } while (param_2[sVar1] != '.');
  if ((-1 < (int)sVar1) && (sVar2 = _strlen(param_2), sVar1 != sVar2 - 1)) {
    _strncpy(param_1,param_2 + sVar3,0x20);
    return;
  }
LAB_004b8958:
  *param_1 = '\0';
  return;
}

