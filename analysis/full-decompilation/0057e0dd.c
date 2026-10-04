
void __fastcall FUN_0057e0dd(int *param_1)

{
  char cVar1;
  
  if ((char)param_1[0x71] == '\0') {
    (**(code **)(*param_1 + 0x2c))(0,0,0);
  }
  cVar1 = (**(code **)(*param_1 + 0x74))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x58))();
    return;
  }
  FUN_0057e3dc();
  return;
}

