
void FUN_0043d6ae(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5)

{
  char *_Str;
  size_t sVar1;
  char *local_58;
  undefined1 local_50 [32];
  undefined **local_30;
  char *local_2c;
  undefined1 local_24 [32];
  
  FUN_0046f824(local_24,0,0x20);
  local_30 = &PTR_FUN_006666e4;
  FUN_0046f824(local_50,0,0x20);
  FUN_0046fa40(param_4);
  FUN_0046fa40(param_3);
  _Str = (char *)FUN_0046edbd(param_3,param_4);
  sVar1 = _strlen(param_5);
  FUN_00412d8a(param_5,param_5 + sVar1);
  sVar1 = _strlen(s__line_006c3a44);
  FUN_00412d8a(s__line_006c3a44,s__line_006c3a44 + sVar1);
  sVar1 = _strlen(local_2c);
  FUN_00412d8a(local_2c,local_2c + sVar1);
  sVar1 = _strlen(s___col_006c3a3c);
  FUN_00412d8a(s___col_006c3a3c,s___col_006c3a3c + sVar1);
  sVar1 = _strlen(local_58);
  FUN_00412d8a(local_58,local_58 + sVar1);
  sVar1 = _strlen(s___text___006c3a30);
  FUN_00412d8a(s___text___006c3a30,s___text___006c3a30 + sVar1);
  if (_Str == (char *)0x0) {
    _Str = &DAT_006de560;
  }
  sVar1 = _strlen(_Str);
  FUN_00412d8a(_Str,_Str + sVar1);
  sVar1 = _strlen(&DAT_006c3a2c);
  FUN_00412d8a(&DAT_006c3a2c,&DAT_006c3a2c + sVar1);
  return;
}

