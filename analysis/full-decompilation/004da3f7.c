
undefined4 FUN_004da3f7(undefined4 param_1,char *param_2)

{
  size_t sVar1;
  char *pcVar2;
  
  sVar1 = _strlen(param_2);
  for (pcVar2 = param_2 + sVar1; (param_2 != pcVar2 && (*pcVar2 != '/')); pcVar2 = pcVar2 + -1) {
  }
  FUN_005b870f(pcVar2 + 1);
  return param_1;
}

