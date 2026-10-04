
void FUN_0059db21(undefined4 param_1,short param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  iVar1 = FUN_00457d80();
  pcVar3 = (char *)0x0;
  if (iVar1 != 0) {
    pcVar2 = (char *)FUN_004705f2(param_2 + 1,0xffffffff);
    if ((pcVar2 == (char *)0x0) || (*pcVar2 != '\0')) {
      pcVar3 = pcVar2;
    }
  }
  FUN_0059dabd(param_1,pcVar3);
  return;
}

