
undefined4 FUN_006450f5(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  char *pcVar4;
  int iVar5;
  void *pvVar6;
  undefined **ppuVar7;
  undefined4 local_c;
  
  pcVar1 = (char *)FUN_006375b5(param_2,0x5c);
  pcVar2 = (char *)FUN_006375b5(param_2,0x2f);
  pcVar4 = param_2;
  if (pcVar2 == (char *)0x0) {
    if ((pcVar1 != (char *)0x0) ||
       (pcVar1 = (char *)FUN_0063b432(param_2,0x3a), pcVar1 != (char *)0x0)) goto LAB_0064516a;
    sVar3 = _strlen(param_2);
    pcVar4 = _malloc(sVar3 + 3);
    if (pcVar4 != (char *)0x0) {
      FUN_006358b0(pcVar4,&DAT_006d2c30);
      FUN_006358c0(pcVar4,param_2);
      pcVar1 = pcVar4 + 2;
      goto LAB_0064516a;
    }
LAB_006451c3:
    local_c = 0xffffffff;
  }
  else {
    if ((pcVar1 == (char *)0x0) || (pcVar1 < pcVar2)) {
      pcVar1 = pcVar2;
    }
LAB_0064516a:
    local_c = 0xffffffff;
    iVar5 = FUN_006375b5(pcVar1,0x2e);
    if (iVar5 == 0) {
      sVar3 = _strlen(pcVar4);
      pvVar6 = _malloc(sVar3 + 5);
      if (pvVar6 == (void *)0x0) goto LAB_006451c3;
      FUN_006358b0(pvVar6,pcVar4);
      sVar3 = _strlen(pcVar4);
      ppuVar7 = &PTR_DAT_006dddcc;
      do {
        FUN_006358b0(sVar3 + (int)pvVar6,*ppuVar7);
        iVar5 = FUN_00639cdd(pvVar6,0);
        if (iVar5 != -1) {
          local_c = FUN_0064523e(param_1,pvVar6,param_3,param_4);
          break;
        }
        ppuVar7 = ppuVar7 + -1;
      } while (0x6dddbf < (int)ppuVar7);
      FUN_00634ecc(pvVar6);
    }
    else {
      iVar5 = FUN_00639cdd(pcVar4,0);
      if (iVar5 != -1) {
        local_c = FUN_0064523e(param_1,pcVar4,param_3,param_4);
      }
    }
    if (pcVar4 != param_2) {
      FUN_00634ecc(pcVar4);
    }
  }
  return local_c;
}

