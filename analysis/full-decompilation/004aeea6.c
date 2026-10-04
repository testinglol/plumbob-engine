
char __fastcall FUN_004aeea6(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1 != '\x7f';
  if (param_1[2] != '\x7f') {
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}

