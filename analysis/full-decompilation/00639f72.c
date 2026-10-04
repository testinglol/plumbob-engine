
char * FUN_00639f72(char *param_1,char *param_2)

{
  char cVar1;
  char *_Str;
  int iVar2;
  size_t sVar3;
  char *_Str_00;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  bool bVar8;
  uint local_c;
  char *local_8;
  
  local_c = 0;
  local_8 = (char *)0x0;
  _Str = (char *)FUN_006384a8(&PTR_LAB_006893ac);
  if (((_Str == (char *)0x0) ||
      ((iVar2 = FUN_00639cdd(_Str,0), iVar2 == -1 &&
       ((_Str = (char *)FUN_0063a11e(_Str), local_8 = _Str, _Str == (char *)0x0 ||
        (iVar2 = FUN_00639cdd(_Str,0), iVar2 == -1)))))) &&
     ((param_1 == (char *)0x0 || (iVar2 = FUN_00639cdd(param_1,0), _Str = param_1, iVar2 == -1)))) {
    FUN_00634ecc(local_8);
    _Str = &DAT_006cc070;
    iVar2 = FUN_00639cdd(&DAT_006cc070,0);
    if (iVar2 == -1) {
      _Str = &DAT_006c26dc;
    }
  }
  if (param_2 != (char *)0x0) {
    local_c = _strlen(param_2);
  }
  sVar3 = _strlen(_Str);
  uVar7 = sVar3 + 0xc + local_c;
  _Str_00 = param_2;
  if ((uVar7 < 0x105) && (_Str_00 = _malloc(uVar7), _Str_00 != (char *)0x0)) {
    *_Str_00 = '\0';
    FUN_006358c0(_Str_00,_Str);
    sVar3 = _strlen(_Str);
    cVar1 = _Str[sVar3 - 1];
    if (cVar1 == '\\') {
      pcVar4 = (char *)FUN_006375b5(_Str,0x5c);
      bVar8 = _Str + (sVar3 - 1) == pcVar4;
    }
    else {
      bVar8 = cVar1 == '/';
    }
    if (!bVar8) {
      FUN_006358c0(_Str_00,&DAT_006cc070);
    }
    if (param_2 != (char *)0x0) {
      FUN_006358c0(_Str_00,param_2);
    }
    sVar3 = _strlen(_Str_00);
    FUN_0063d88b(3);
    iVar2 = DAT_006dddd4;
    if (DAT_00703d68 < local_c) {
      iVar2 = 1;
    }
    DAT_006dddd4 = iVar2 + 1;
    DAT_00703d68 = local_c;
    uVar7 = DAT_006dddd4 - iVar2;
    while (uVar7 < 0x8000) {
      FUN_0063b31d(DAT_006dddd4,_Str_00 + sVar3,10);
      iVar5 = FUN_00639cdd(_Str_00,0);
      if ((iVar5 != 0) && (piVar6 = (int *)FUN_0063d796(), *piVar6 != 0xd)) goto LAB_0063a101;
      DAT_006dddd4 = DAT_006dddd4 + 1;
      uVar7 = DAT_006dddd4 - iVar2;
    }
    FUN_00634ecc(_Str_00);
    _Str_00 = (char *)0x0;
LAB_0063a101:
    FUN_0063d8ec(3);
  }
  FUN_00634ecc(local_8);
  return _Str_00;
}

