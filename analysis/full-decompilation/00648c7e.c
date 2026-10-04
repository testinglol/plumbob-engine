
undefined4 FUN_00648c7e(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  size_t sVar1;
  void *pvVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  char cVar7;
  int *piVar8;
  size_t sVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  
  sVar9 = 2;
  sVar3 = sVar9;
  for (piVar8 = param_1; (char *)*piVar8 != (char *)0x0; piVar8 = piVar8 + 1) {
    sVar1 = _strlen((char *)*piVar8);
    sVar3 = sVar3 + 1 + sVar1;
  }
  pvVar2 = _malloc(sVar3);
  *param_3 = (int)pvVar2;
  if (pvVar2 == (void *)0x0) {
    *param_4 = 0;
LAB_00648d9f:
    puVar5 = (undefined4 *)FUN_0063d796();
    *puVar5 = 0xc;
    puVar5 = (undefined4 *)FUN_0063d79f();
    *puVar5 = 8;
LAB_00648db5:
    uVar6 = 0xffffffff;
  }
  else {
    piVar8 = param_2;
    if (param_2 == (int *)0x0) {
      *param_4 = 0;
      puVar5 = param_4;
      puVar11 = param_4;
    }
    else {
      for (; (char *)*piVar8 != (char *)0x0; piVar8 = piVar8 + 1) {
        sVar3 = _strlen((char *)*piVar8);
        sVar9 = sVar9 + 1 + sVar3;
      }
      if (DAT_00703af4 == (char *)0x0) {
        DAT_00703af4 = (char *)FUN_00644947();
        if (DAT_00703af4 != (char *)0x0) goto LAB_00648d1c;
        goto LAB_00648db5;
      }
LAB_00648d1c:
      puVar5 = (undefined4 *)0x0;
      if (*DAT_00703af4 != '\0') {
        cVar7 = *DAT_00703af4;
        pcVar4 = DAT_00703af4;
        do {
          if (cVar7 == '=') break;
          sVar3 = _strlen(pcVar4);
          puVar5 = (undefined4 *)((int)puVar5 + sVar3 + 1);
          cVar7 = DAT_00703af4[(int)puVar5];
          pcVar4 = DAT_00703af4 + (int)puVar5;
        } while (cVar7 != '\0');
      }
      pcVar4 = DAT_00703af4 + (int)puVar5;
      puVar11 = puVar5;
      while ((((*pcVar4 == '=' && (pcVar4[1] != '\0')) && (pcVar4[2] == ':')) && (pcVar4[3] == '='))
            ) {
        sVar3 = _strlen(pcVar4 + 4);
        puVar11 = (undefined4 *)((int)puVar11 + sVar3 + 5);
        pcVar4 = DAT_00703af4 + (int)puVar11;
      }
      pvVar2 = _malloc((int)puVar11 + (sVar9 - (int)puVar5));
      *param_4 = pvVar2;
      if (pvVar2 == (void *)0x0) {
        FUN_00634ecc(*param_3);
        *param_3 = 0;
        goto LAB_00648d9f;
      }
    }
    puVar10 = (undefined1 *)*param_3;
    param_3 = param_1;
    if (*param_1 != 0) {
      FUN_006358b0(puVar10,*param_1);
      param_3 = param_1 + 1;
      sVar3 = _strlen((char *)*param_1);
      puVar10 = puVar10 + sVar3 + 1;
      goto LAB_00648ddc;
    }
    while( true ) {
      puVar10 = puVar10 + 1;
LAB_00648ddc:
      if (*param_3 == 0) break;
      FUN_006358b0(puVar10,*param_3);
      sVar3 = _strlen((char *)*param_3);
      puVar10 = puVar10 + sVar3;
      *puVar10 = 0x20;
      param_3 = param_3 + 1;
    }
    puVar10[-1] = 0;
    *puVar10 = 0;
    puVar10 = (undefined1 *)*param_4;
    if (param_2 != (int *)0x0) {
      FUN_00636510(puVar10,DAT_00703af4 + (int)puVar5,(int)puVar11 - (int)puVar5);
      puVar10 = puVar10 + ((int)puVar11 - (int)puVar5);
      for (; *param_2 != 0; param_2 = param_2 + 1) {
        FUN_006358b0(puVar10,*param_2);
        sVar3 = _strlen((char *)*param_2);
        puVar10 = puVar10 + sVar3 + 1;
      }
    }
    if (puVar10 != (undefined1 *)0x0) {
      if (puVar10 == (undefined1 *)*param_4) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *puVar10 = 0;
    }
    FUN_00634ecc(DAT_00703af4);
    DAT_00703af4 = (char *)0x0;
    uVar6 = 0;
  }
  return uVar6;
}

