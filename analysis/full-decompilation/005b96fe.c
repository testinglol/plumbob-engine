
void FUN_005b96fe(char *param_1)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char local_108 [260];
  
  FUN_006358b0(local_108,param_1);
  iVar5 = -1;
  pcVar4 = local_108;
  sVar2 = _strlen(param_1);
  iVar3 = 0;
  if (0 < (int)sVar2) {
    do {
      cVar1 = *pcVar4;
      if ((cVar1 < 'A') || ('Z' < cVar1)) {
        if (cVar1 == '/') {
          *pcVar4 = '\\';
        }
        else if (cVar1 != '\\') goto LAB_005b9756;
        iVar5 = iVar3;
      }
      else {
        *pcVar4 = cVar1 + ' ';
      }
LAB_005b9756:
      pcVar4 = pcVar4 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)sVar2);
    if (-1 < iVar5) {
      FUN_005b8775(local_108,iVar5 + 1);
      goto LAB_005b9782;
    }
  }
  FUN_005d4bbf(&DAT_006de560);
LAB_005b9782:
  FUN_005d49b7(local_108 + iVar5 + 1);
  return;
}

