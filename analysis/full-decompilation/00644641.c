
void FUN_00644641(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  
  if (DAT_00705350 == 0) {
    FUN_0063ccc0();
  }
  iVar5 = 0;
  for (pcVar6 = DAT_00703af4; *pcVar6 != '\0'; pcVar6 = pcVar6 + sVar2 + 1) {
    if (*pcVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen(pcVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  DAT_00703ad0 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_00703af4;
  pcVar6 = DAT_00703af4;
  while (cVar1 != '\0') {
    sVar2 = _strlen(pcVar6);
    if (*pcVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_006358b0(*puVar3,pcVar6);
      puVar3 = puVar3 + 1;
    }
    pcVar6 = pcVar6 + sVar2 + 1;
    cVar1 = *pcVar6;
  }
  FUN_00634ecc(DAT_00703af4);
  DAT_00703af4 = (char *)0x0;
  *puVar3 = 0;
  DAT_0070534c = 1;
  return;
}

