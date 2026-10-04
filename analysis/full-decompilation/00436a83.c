
void FUN_00436a83(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,
                 char param_5)

{
  char *pcVar1;
  size_t sVar2;
  undefined *puVar3;
  
  pcVar1 = (char *)FUN_00470631(param_3,0xffffffff);
  if (((param_5 == '\0') || (pcVar1 == (char *)0x0)) || (*pcVar1 != '!')) {
    puVar3 = &DAT_006de560;
  }
  else {
    puVar3 = &DAT_006c12fc;
  }
  FUN_005d4bbf(puVar3);
  pcVar1 = (char *)FUN_004705f2(param_3,0xffffffff);
  if (pcVar1 != (char *)0x0) {
    sVar2 = _strlen(pcVar1);
    if (sVar2 != 0) goto LAB_00436ae1;
  }
  pcVar1 = param_4;
  if (param_4 == (char *)0x0) {
    pcVar1 = s_Missing_string____006c29ac;
  }
LAB_00436ae1:
  sVar2 = _strlen(pcVar1);
  FUN_00412d8a(pcVar1,pcVar1 + sVar2);
  return;
}

