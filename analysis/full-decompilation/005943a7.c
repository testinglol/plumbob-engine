
char * FUN_005943a7(char *param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)FUN_0041e684(~uVar3);
  if (param_2 == '\0') {
    uVar4 = 0xffffffff;
    do {
      pcVar6 = param_1;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar6 = param_1 + 1;
      cVar1 = *param_1;
      param_1 = pcVar6;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar6 = pcVar6 + -uVar4;
    pcVar8 = pcVar2;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  else {
    cVar1 = *param_1;
    if (cVar1 != '\0') {
      iVar7 = (int)pcVar2 - (int)param_1;
      do {
        cVar1 = FUN_0063813a((int)cVar1);
        param_1[iVar7] = cVar1;
        cVar1 = param_1[1];
        param_1 = param_1 + 1;
      } while (cVar1 != '\0');
    }
  }
  pcVar2[~uVar3 - 1] = '\0';
  return pcVar2;
}

