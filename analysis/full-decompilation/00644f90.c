
int FUN_00644f90(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *_Str;
  size_t sVar4;
  char *pcVar5;
  size_t sVar6;
  char *pcVar7;
  bool bVar8;
  int local_c;
  
  local_c = FUN_006450f5(param_1,param_2,param_3,param_4);
  if ((((local_c == -1) && (piVar2 = (int *)FUN_0063d796(), *piVar2 == 2)) &&
      (iVar3 = FUN_0063b432(param_2,0x2f), iVar3 == 0)) &&
     ((iVar3 = FUN_006384a8(&DAT_00689f70), iVar3 != 0 &&
      (_Str = _malloc(0x104), _Str != (char *)0x0)))) {
    do {
      do {
        iVar3 = FUN_0064528f(iVar3,_Str,0x103);
        if ((iVar3 == 0) || (*_Str == '\0')) goto LAB_006450e6;
        sVar4 = _strlen(_Str);
        cVar1 = _Str[sVar4 - 1];
        if (cVar1 == '\\') {
          pcVar5 = (char *)FUN_006375b5(_Str,0x5c);
          bVar8 = _Str + (sVar4 - 1) == pcVar5;
        }
        else {
          bVar8 = cVar1 == '/';
        }
        if (!bVar8) {
          FUN_006358c0(_Str,&DAT_006cc070);
        }
        sVar4 = _strlen(_Str);
        sVar6 = _strlen(param_2);
        if (0x103 < sVar4 + sVar6) goto LAB_006450e6;
        FUN_006358c0(_Str,param_2);
        local_c = FUN_006450f5(param_1,_Str,param_3,param_4);
        if (local_c != -1) goto LAB_006450e6;
        piVar2 = (int *)FUN_0063d796();
      } while (*piVar2 == 2);
      pcVar5 = (char *)FUN_0063b432(_Str,0x5c);
      if ((_Str != pcVar5) && (pcVar5 = (char *)FUN_0063b432(_Str,0x2f), _Str != pcVar5)) break;
      pcVar5 = _Str + 1;
      pcVar7 = (char *)FUN_0063b432(pcVar5,0x5c);
    } while ((pcVar5 == pcVar7) || (pcVar7 = (char *)FUN_0063b432(pcVar5,0x2f), pcVar5 == pcVar7));
LAB_006450e6:
    FUN_00634ecc(_Str);
  }
  return local_c;
}

