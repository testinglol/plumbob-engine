
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00648501(void)

{
  char cVar1;
  char cVar2;
  char *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  char *_Source;
  int local_8;
  
  FUN_0063d88b(0xc);
  DAT_006de228 = 0xffffffff;
  DAT_006de218 = 0xffffffff;
  DAT_00703d90 = 0;
  _Str1 = (char *)FUN_006384c9(&DAT_0068a394);
  if (_Str1 == (char *)0x0) {
    FUN_0063d8ec(0xc);
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_00703d98);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_006de184 = DAT_00703d98 * 0x3c;
    DAT_00703d90 = 1;
    if (DAT_00703dde != 0) {
      DAT_006de184 = DAT_006de184 + DAT_00703dec * 0x3c;
    }
    if ((DAT_00703e32 == 0) || (DAT_00703e40 == 0)) {
      DAT_006de188 = 0;
      _DAT_006de18c = 0;
    }
    else {
      DAT_006de188 = 1;
      _DAT_006de18c = (DAT_00703e40 - DAT_00703dec) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_00703bfc,0x220,(LPCWSTR)&DAT_00703d9c,-1,PTR_DAT_006de210,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 == 0) || (local_8 != 0)) {
      *PTR_DAT_006de210 = 0;
    }
    else {
      PTR_DAT_006de210[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_00703bfc,0x220,(LPCWSTR)&DAT_00703df0,-1,PTR_DAT_006de214,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 != 0) && (local_8 == 0)) {
      PTR_DAT_006de214[0x3f] = 0;
      return;
    }
LAB_00648772:
    *PTR_DAT_006de214 = 0;
  }
  else {
    if ((*_Str1 != '\0') &&
       ((DAT_00703e44 == (char *)0x0 || (iVar4 = _strcmp(_Str1,DAT_00703e44), iVar4 != 0)))) {
      FUN_00634ecc(DAT_00703e44);
      sVar5 = _strlen(_Str1);
      DAT_00703e44 = _malloc(sVar5 + 1);
      if (DAT_00703e44 != (char *)0x0) {
        FUN_006358b0(DAT_00703e44,_Str1);
        FUN_0063d8ec(0xc);
        _strncpy(PTR_DAT_006de210,_Str1,3);
        _Source = _Str1 + 3;
        PTR_DAT_006de210[3] = 0;
        cVar1 = *_Source;
        if (cVar1 == '-') {
          _Source = _Str1 + 4;
        }
        iVar4 = FUN_00635ed7(_Source);
        DAT_006de184 = iVar4 * 0xe10;
        for (; (cVar2 = *_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
            _Source = _Source + 1) {
        }
        if (*_Source == ':') {
          _Source = _Source + 1;
          iVar4 = FUN_00635ed7(_Source);
          DAT_006de184 = DAT_006de184 + iVar4 * 0x3c;
          for (; ('/' < *_Source && (*_Source < ':')); _Source = _Source + 1) {
          }
          if (*_Source == ':') {
            _Source = _Source + 1;
            iVar4 = FUN_00635ed7(_Source);
            DAT_006de184 = DAT_006de184 + iVar4;
            for (; ('/' < *_Source && (*_Source < ':')); _Source = _Source + 1) {
            }
          }
        }
        if (cVar1 == '-') {
          DAT_006de184 = -DAT_006de184;
        }
        DAT_006de188 = (int)*_Source;
        if (DAT_006de188 != 0) {
          _strncpy(PTR_DAT_006de214,_Source,3);
          PTR_DAT_006de214[3] = 0;
          return;
        }
        goto LAB_00648772;
      }
    }
    FUN_0063d8ec(0xc);
  }
  return;
}

